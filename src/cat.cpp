#include "lib.h"
//basic cat
std::string cat (const char *std)
{
  std::ifstream file;
  std::string line;

  try
    {
      file.open (std);
    }

  catch (std::system_error& e)
    {
      std::cerr << e.code ().message () << std::ends;
    }

  while (getline (file, line));
  return (line);
}
// this cat get the l line
std::string cat (const char *std, int l)
{
  std::ifstream file;
  std::string line;
  line = "";
  try
    {
      file.open (std);
    }

  catch (std::system_error& e)
    {
      std::cerr << e.code ().message () << std::ends;
    }

  getline (file, line);
  for (int i = 0; i < l; ++i)
    {
      getline (file, line);
    }
  return (line);
}

std::string cat (const char *std, const char *search, int size_search)
{
  std::ifstream file;
  std::string line;

  try
    {
      file.open (std);
    }

  catch (std::system_error& e)
    {
      std::cerr << e.code ().message () << std::ends;
    }

  while (getline (file, line))
    {
      if (line.compare (0, size_search, search, 0, size_search) == 0)
      	{
          return (line);
        }
    }
  return (nullptr);
}
