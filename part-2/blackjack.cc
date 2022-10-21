// Alex Labitigan
// CPSC 120-12
// 2022-10-17
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab 07-01
// Partners: @Menulk09
//
// Blackjack with functions
//

#include <iostream>
#include <string>
#include <vector>

bool IsAce(const std::string& card_name) {
  bool ace = false;
  if (card_name == "A") {
    ace = true;
  }
  return ace;
}
bool IsFaceCard(const std::string& card_name) {
  bool face_card = false;
  if (card_name == "J" || card_name == "K" || card_name == "Q") {
    face_card = true;
  }
  return face_card;
}
bool IsNumberCard(const std::string& card_name) {
  bool num_card = false;
  if (card_name == "2" || card_name == "3" || card_name == "4" ||
      card_name == "5" || card_name == "6" || card_name == "7" ||
      card_name == "8" || card_name == "9" || card_name == "10") {
    num_card = true;
  }
  return num_card;
}
bool IsCardName(const std::string& str) {
  bool valid = false;
  bool ace_card = IsAce(str);
  bool face_card = IsFaceCard(str);
  bool number_card = IsNumberCard(str);
  if (ace_card || face_card || number_card) {
    valid = true;
  }
  return valid;
}
bool AllArgumentsValid(const std::vector<std::string>& arguments) {
  bool valid_argument = true;
  for (int i = 1; i < arguments.size(); i++) {
    if (!IsCardName(arguments[i])) {
      valid_argument = false;
    }
  }
  return valid_argument;
}
int CardPoints(const std::string& card_name) {
  int score{0};
  if (IsAce(card_name)) {
    score += 1;
  }
  if (IsFaceCard(card_name)) {
    score += 10;
  }
  if (IsNumberCard(card_name)) {
    score = stoi(card_name);
  }
  return score;
}
bool HandContainsAce(const std::vector<std::string>& arguments) {
  bool ace_hand = false;
  for (int i = 1; i < arguments.size(); i++) {
    if (IsAce(arguments[i])) {
      ace_hand = true;
    }
  }
  return ace_hand;
}
bool IsBust(int score) {
  bool bust = false;
  if (score > 21) {
    bust = true;
  }
  return bust;
}
int HandScore(const std::vector<std::string>& arguments) {
  int score{0};
  for (int i = 1; i < arguments.size(); i++) {
    score += CardPoints(arguments[i]);
  }
  if (HandContainsAce(arguments)) {
    if (!IsBust(score + 10)) {
      score += 10;
    }
  }
  return score;
}
void PrintScore(int score) {
  if (IsBust(score)) {
    std::cout << "Score is " << score << ", BUST\n";
  } else {
    std::cout << "Score is " << score << "\n";
  }
}
int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  bool valid = AllArgumentsValid(arguments);
  if (!valid) {
    std::cout << "error: invalid card\n";
    return 1;
  }
  PrintScore(HandScore(arguments));
  return 0;
}