// Alex Labitigan
// CPSC 120-12
// 2022-10-17
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab 07-01
// Partners: @
//
// Date difference
//

#include <iostream>

// Given a month, day, and year, calculate the Julian day number using the
// Fliegel & Van Flandern equation.

  
// TODO: write statements to implement this function, and delete this comment
// TODO: replace this return statement with one that actually works
int JulianDay(int month, int day, int year) {

int JulianDay;
JulianDay = day - 32075 + 1461
      * (year + 4800 + (month - 14) / 12) / 4
      + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3
      * ((year + 4900 + (month - 14) / 12) / 100) / 4;

  return JulianDay; 
}

// Return the number of days between a start date and end date.
// TODO: write statements to implement this function, and delete this comment
// TODO: replace this return statement with one that actually works

int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {


  int start_number_of_days_since_epoch{0};
  int start_julian_day =
      start_day - 32075 +
      1461 * (start_year + 4800 + (start_month - 14) / 12) / 4 +
      367 * (start_month - 2 - (start_month - 14) / 12 * 12) / 12 -
      3 * ((start_year + 4900 + (start_month - 14) / 12) / 100) / 4;
  start_number_of_days_since_epoch = start_julian_day;

  int end_number_of_days_since_epoch{0};
  int end_julian_day =
      end_day - 32075 + 1461 * (end_year + 4800 + (end_month - 14) / 12) / 4 +
      367 * (end_month - 2 - (end_month - 14) / 12 * 12) / 12 -
      3 * ((end_year + 4900 + (end_month - 14) / 12) / 100) / 4;
  end_number_of_days_since_epoch = end_julian_day;

  int date_dif = end_julian_day - start_julian_day;

  return date_dif; 
}

// Print the given date to standard output in the format MM/DD/YYYY
  // TODO: write statements to implement this function, and delete this comment
void PrintDate(int month, int day, int year) {
  std::cout << month << "/" << day << "/" << year;
}

int main(int argc, char* argv[]) {
  // TODO: prompt the user for
  //   - start month
  //   - start day
  //   - start year
  //   - end month
  //   - end day
  //   - end year
  std::cout << "Let's find the number of days between two dates...\n";
  int start_month, start_day,  start_year, end_month, end_day,
  end_year;
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

int diff = DateDifference(start_month,start_day,start_year,end_month,end_day,
  end_year);
  std::cout << "The number of days between ";
  PrintDate(start_month,start_day,start_year);
  std::cout << " and ";
  PrintDate(end_month,end_day,end_year);
  std::cout << " is " << diff << " days\n";

  // TODO: call DateDifference, and store its return value in a variable

  // TODO: output "The number of days between"
  // TODO: call PrintDate to print out the start date
  // TODO: output " and "
  // TODO: call PrintDate to print out the end date
  // TODO: output " is DAYS days\n", where DAYS is the difference claculated
  //       by DateDifference above

  return 0;
}
