#include "common_header.h"

class Solution_12
{
private:
  std::unordered_map<int, char> int_to_roman_ =
  {
    {1, 'I'},
    {5, 'V'},
    {10, 'X'},
    {50, 'L'},
    {100, 'C'},
    {500, 'D'},
    {1000, 'M'}
  };

  std::string writeThisDigit(int num, int digit, int ten_digit, int five_digit)
  {
    char char_dist = int_to_roman_[digit];
    char char_ten_dist = int_to_roman_[ten_digit];

    std::string return_string;
    switch (num)
    {
      case 3:
        return_string.push_back(char_dist);
      case 2:
        return_string.push_back(char_dist);
      case 1:
        return_string.push_back(char_dist);
        break;
      case 4:
        return_string.push_back(char_dist);
      case 5:
        return_string.push_back(char_ten_dist);
    }
    if (num <= 3 && five_digit > 0)
      return_string.insert(return_string.begin(), int_to_roman_[five_digit]);

    return return_string;
  }

public:
    std::string intToRoman(int num)
    {
      int cur_num = num;
      int digit_factor = -1;
      std::string return_string;
      while (cur_num != 0)
      {
        int digit_num = cur_num % 10;
        cur_num /= 10;
        digit_factor++;

        if (digit_num <= 5)
        {
          return_string = writeThisDigit(digit_num, pow(10, digit_factor), 5 * pow(10, digit_factor), 0) + return_string;
        }
        else
        {
          return_string = writeThisDigit(digit_num - 5, pow(10, digit_factor), 10 * pow(10, digit_factor), 5 * pow(10, digit_factor)) + return_string;
        }
      }
      return return_string;
    }
};