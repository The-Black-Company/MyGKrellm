#include "lib.h"

std::string split (std::string str, char begin, char end)
{
  std::string new_str = str.substr (str.find_first_of (begin) + 2, str.find_first_of (end) - str.find_first_of (begin) - 2);
  return (new_str);
}

std::string split (std::string str, char begin, char end, int nb)
{
  std::string new_str = str.substr (str.find_first_of (begin) + 2 + nb, str.find_first_of (end) - str.find_first_of (begin) - 2);
  return (new_str);
}
