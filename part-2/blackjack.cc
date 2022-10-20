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

// Return true if card_name is the name of the ace card ("A"); or
// false otherwise.
// TODO: replace this return statement with one that actually works
// TODO: write statements to implement this function, and delete this comment

bool IsAce(const std::string& card_name) {
  bool ace = false;
  if (card_name == "A")
    ace = true;
  return ace; 
}

// Return true if card_name is the name of the jack ("J"), queen ("Q"),
// or king ("K"); or false otherwise.
// TODO: write statements to implement this function, and delete this comment
// TODO: replace this return statement with one that actually works

bool IsFaceCard(const std::string& card_name) {
  bool face_card = false;
  if (card_name == "J" || "K" || "Q")
    face_card = true;
  return face_card; 
}

// Return true if card_name is the name of a number card ("2" through "10");
// or false otherwise.
// TODO: write statements to implement this function, and delete this comment
// TODO: replace this return statement with one that actually works
bool IsNumberCard(const std::string& card_name) {
  bool num_card = false;
  if (card_name == "2" || "3" || "4" || "5" || "6" || "7" || "8" || "9" || "10")
  num_card = true;
  return num_card;
}

// Return true if card_name is any valid card name; or false otherwise.
// TODO: write statements to implement this function, and delete this comment
// HINT: call IsAce, IsFaceCard, and IsNumberCard, and combine their return values
// TODO: replace this return statement with one that actually works
bool IsCardName(const std::string& str) {
  bool valid = true;
  bool ace_card = IsAce(str);
  bool face_card = IsFaceCard(str);
  bool number_card = IsNumberCard(str);
  if (ace_card && face_card && number_card == false)
    valid = false;

  return valid; 
}

// Return true if every argument (after the command name) is a valid card name;
// or false otherwise.
// The first element of arguments contains the command name, and is ignored by
// this function.
// TODO: write statements to implement this function, and delete this comment
// HINT: write a loop, cand call IsCardName in the body of the loop
// TODO: replace this return statement with one that actually works

bool AllArgumentsValid(const std::vector<std::string>& arguments) {
  // bool valid_argument = false;
  for (int i = 1; i < arguments.size(); i++) {
    if(IsCardName(arguments[i]) == false){
      return false;
    }
  }
  return true; 
}

// Return the number of points that the given card is worth.
// A face card is worth 10 points.
// A number card is worth its number.
// This function ignores the ace bonus, so an ace is worth 1 point.
// This function may assume that card_name is a valid card name.
// TODO: write statements to implement this function, and delete this comment
// HINT: you will need if statements
// HINT: this function is easiest if it calls IsAce, IsFaceCard, and/or IsNumberCard
// TODO: replace this return statement with one that actually works


int CardPoints(const std::string& card_name) {
int score{0};
if(IsAce(card_name) == true){
  score += 1;
}
if(IsFaceCard (card_name) == true){
  score += 10;
}
if (IsNumberCard(card_name) == true){
  score = stoi(card_name);
}
  return score; 
}

// Return true if the arguments contain an ace.
// The first element of arguments contains the command name, and is ignored by
// this function. 
// TODO: write statements to implement this function, and delete this comment
// HINT: write a loop, cand call IsAce in the body of the loop
// TODO: replace this return statement with one that actually works

bool HandContainsAce(const std::vector<std::string>& arguments) {
  bool ace_hand = false;
  for(int i = 1; i < arguments.size(); i++){
    if(IsAce(arguments[i]) == true){
      ace_hand = true;
    }
  }
  return ace_hand; 
}

// Return true if score represents a bust; or false otherwise.
// A bust happens when score exceeds 21.
// TODO: write statements to implement this function, and delete this comment
// TODO: replace this return statement with one that actually works

bool IsBust(int score) {
  
  
  return false; 
}

// Return the total score of the cards named by the arguments.
// Each card contributes points as described for the CardPoints function above.
// In addition, if the hadn contains an ace, the ace counts for another 10
// points, unless that would cause a bust.
// The first element of arguments contains the command name, and is ignored by
// this function. 
int HandScore(const std::vector<std::string>& arguments) {
  // TODO: write statements to implement this function, and delete this comment

  // HINT: First calculate the points, except for the ace bonus.
  // Write a loop, cand call CardPoints in the body of the loop.

  // HINT: After the loop, decide whether to use the ace bonus, just once.
  // Use an if statement, HandContainsAce, and IsBust.
  // If the hand contains an ace, and adding 10 points would not cause bust,
  // add 10 points to the score.

  return 0; // TODO: replace this return statement with one that actually works
}

// Print out a description of the score.
// If there is no bust (score is less than or equal to 21), print output
// "Score is *SCORE*"
// If there is a bust (score is greater than 21), print output
// "Score is *SCORE*, BUST"
void PrintScore(int score) {
  // TODO: write statements to implement this function, and delete this comment
  // HINT: You will need an if statement. This function is easiest if it calls IsBust
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);

  // TODO: validate input.
  // If any of the arguments are invalid, print
  // "error: invalid card"
  // on its own line, and return a non-zero exit code.
  // HINT: call AllArgumentsValid

  // TODO: calculate the score of the hand, and print out a message
  // HINT: call HandScore, then PrintScore
  PrintScore(HandScore(arguments));

  return 0;
}
