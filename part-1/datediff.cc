// Alex Labitigan
// CPSC 120-12
// 2022-10-17
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab 07-01
// Partners: @Menuk09
//
// Date difference with funcitons
//

#include <iostream>

int JulianDay(int month, int day, int year) {
  int julian_day{0};
  julian_day = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 +
               367 * (month - 2 - (month - 14) / 12 * 12) / 12 -
               3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
  return julian_day;
}

int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  int start_julian_day = JulianDay(start_month, start_day, start_year);
  int end_julian_day = JulianDay(end_month, end_day, end_year);
  int datediff = end_julian_day - start_julian_day;
  return datediff;
}

void PrintDate(int month, int day, int year) {
  std::cout << month << "/" << day << "/" << year;
}

int main(int argc, char* argv[]) {
  std::cout << "Let's find the number of days between two dates...\n";
  int start_month{0};
  int start_day{0};
  int start_year{0};
  int end_month{0};
  int end_day{0};
  int end_year{0};
  std::cout << "Enter a start month: ";
  std::cin >> start_month;
  std::cout << "Enter a start day: ";
  std::cin >> start_day;
  std::cout << "Enter a start year: ";
  std::cin >> start_year;
  std::cout << "Enter an end month: ";
  std::cin >> end_month;
  std::cout << "Enter an end day: ";
  std::cin >> end_day;
  std::cout << "Enter an end year: ";
  std::cin >> end_year;

  int diff = DateDifference(start_month, start_day, start_year, end_month,
                            end_day, end_year);
  std::cout << "The number of days between ";
  PrintDate(start_month, start_day, start_year);
  std::cout << " and ";
  PrintDate(end_month, end_day, end_year);
  std::cout << " is " << diff << " days\n";
  return 0;
}

// Given a month, day, and year, calculate the Julian day number using the
// Fliegel & Van Flandern equation.
// TODO: write statements to implement this function, and delete this comment
// TODO: replace this return statement with one that actually works
// Return the number of days between a start date and end date.
// TODO: write statements to implement this function, and delete this comment
// TODO: replace this return statement with one that actually works
// Print the given date to standard output in the format MM/DD/YYYY
  // TODO: write statements to implement this function, and delete this comment
  // TODO: prompt the user for
  //   - start month
  //   - start day
  //   - start year
  //   - end month
  //   - end day
  //   - end year
  // TODO: call DateDifference, and store its return value in a variable
  // TODO: output "The number of days between"
  // TODO: call PrintDate to print out the start date
  // TODO: output " and "
  // TODO: call PrintDate to print out the end date
  // TODO: output " is DAYS days\n", where DAYS is the difference claculated
  //       by DateDifference above