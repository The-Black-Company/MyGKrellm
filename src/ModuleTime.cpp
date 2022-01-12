#include "lib.h"

ModuleTime::ModuleTime ()
{
  _timestamp = time (NULL);
  _timeInfos = localtime (& _timestamp);
  _Hour = std::to_string (_timeInfos->tm_hour) + ":" + std::to_string (_timeInfos->tm_min) + ":" + std::to_string (_timeInfos->tm_sec);
  _Date = std::to_string (_timeInfos->tm_mday) + "/" + std::to_string (_timeInfos->tm_mon + 1) + "/" + std::to_string (_timeInfos->tm_year + 1900);
}

void ModuleTime::print ()
{
  std::cout << _Hour << std::endl;
  std::cout << _Date << std::endl;
}

std::string ModuleTime::GetHour ()
{
  return (_Hour);
}

std::string ModuleTime::GetDate ()
{
  return (_Date);
}

void ModuleTime::SM_PRINT_WINDOW (window *screen)
{
  _timestamp = time (NULL);
  refresh ();
  screen->print (1, 1, "Date:");
  screen->print (2, 1, "Hour:");

  screen->print (1, 21, GetDate ().c_str ());
  screen->print (2, 21, GetHour ().c_str ());
}

void ModuleTime::refresh ()
{
    _timeInfos = localtime (& _timestamp);
    _Date = std::to_string (_timeInfos->tm_mday) + "/" + std::to_string (_timeInfos->tm_mon + 1) + "/" + std::to_string (_timeInfos->tm_year + 1900);
    _Hour = std::to_string (_timeInfos->tm_hour) + "h " + std::to_string (_timeInfos->tm_min) + "m " + std::to_string (_timeInfos->tm_sec) + "s";
}

void ModuleTime::SetID (int i)
{
  _ID = i;
}

int ModuleTime::GetID ()
{
  return (_ID);
}
