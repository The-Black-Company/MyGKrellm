#include "lib.h"

ModuleName::ModuleName ()
{
  _MachineName = cat ("/proc/sys/kernel/hostname", 0);
  _UserName = "";
}

void ModuleName::print ()
{
  std::cout << _MachineName << std::endl;
  std::cout << _UserName << std::endl;
}

std::string ModuleName::GetMachineName ()
{
    return (_MachineName);
}

std::string ModuleName::GetUserName ()
{
    return (_UserName);
}

void ModuleName::SM_PRINT_WINDOW (window *screen)
{
  refresh ();
  screen->print (1, 1, "MachineName:");
  screen->print (2, 1, "UserName:");

  screen->print (1, 21, GetMachineName ().c_str ());
  screen->print (2, 21, GetUserName ().c_str ());
}

void ModuleName::SetID (int i)
{
  _ID = i;
}

int ModuleName::GetID ()
{
  return (_ID);
}

void ModuleName::setName (std::string name)
{
  _UserName = name;
}

void ModuleName::refresh ()
{
  _MachineName = cat ("/proc/sys/kernel/hostname", 0);
}
