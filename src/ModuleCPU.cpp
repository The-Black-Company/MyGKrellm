#include "lib.h"

ModuleCPU::ModuleCPU ()
{
  _CPUModele = split (cat ("/proc/cpuinfo", "model name", 10), ':', '@');
  _CPUFrequence = split (cat ("/proc/cpuinfo", "model name", 10), '@', '\n');
  _CPUCore = split (cat ("/proc/cpuinfo", "cpu cores", 9), ':', '\n');
}

void ModuleCPU::print ()
{
  std::cout << _CPUModele << std::endl;
  std::cout << _CPUFrequence << std::endl;
  std::cout << _CPUCore << std::endl;
}

std::string ModuleCPU::GetModel ()
{
  return (_CPUModele);
}

std::string ModuleCPU::GetCore ()
{
  return (_CPUCore);
}

std::string ModuleCPU::GetFrequency ()
{
  return (_CPUFrequence);
}

void ModuleCPU::SM_PRINT_WINDOW (window *screen)
{
  refresh ();
  screen->print (1, 1, "Model:");
  screen->print (2, 1, "Frequency:");
  screen->print (3, 1, "Core:");

  screen->print (1, 21, GetModel ().c_str ());
  screen->print (2, 21, GetFrequency ().c_str ());
  screen->print (3, 21, GetCore ().c_str ());
}

void ModuleCPU::refresh ()
{
  _CPUModele = split (cat ("/proc/cpuinfo", "model name", 10), ':', '@');
  _CPUFrequence = split (cat ("/proc/cpuinfo", "model name", 10), '@', '\n');
  _CPUCore = split (cat("/proc/cpuinfo", "cpu cores", 9), ':', '\n');
}

void ModuleCPU::SetID (int i)
{
  _ID = i;
}

int ModuleCPU::GetID ()
{
  return (_ID);
}
