#include "lib.h"

ModuleSys::ModuleSys ()
{
    _Systeme = split(cat ("/proc/version", 0), 'L', '(');
    _Kernel = cat ("/proc/sys/kernel/version", 0);
}

void ModuleSys::print ()
{
  std::cout << _Systeme << std::endl;
  std::cout << _Kernel << std::endl;
}

std::string ModuleSys::GetSysteme ()
{
    return (_Systeme);
}

std::string ModuleSys::GetKernel ()
{
    return (_Kernel);
}

void ModuleSys::SM_PRINT_WINDOW (window *screen)
{
  refresh ();
  screen->print (1, 1, "System:");
  screen->print (2, 1, "Kernel:");

  screen->print (1, 21, GetSysteme ().c_str ());
  screen->print (2, 21, GetKernel ().c_str ());
}

void ModuleSys::refresh ()
{
    _Systeme = split(cat ("/proc/version", 0), 'L', '(', -2);
    _Kernel = cat ("/proc/sys/kernel/version", 0);
}

void ModuleSys::SetID (int i)
{
  _ID = i;
}

int ModuleSys::GetID ()
{
  return (_ID);
}
