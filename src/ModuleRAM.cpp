#include "lib.h"

ModuleRAM::ModuleRAM ()
{
  _MemTotal = split (cat ("/proc/meminfo", 0), ':', '\n');
  _MemDispo = split (cat ("/proc/meminfo", 2), ':', '\n');
  _MemUse = std::to_string (((std::stod (_MemDispo)) *100) / std::stod (_MemTotal)) + " /100%";
}

void ModuleRAM::print ()
{
  std::cout << _MemTotal << std::endl;
  std::cout << _MemDispo << std::endl;
  std::cout << _MemUse << std::endl;
}

std::string ModuleRAM::GetMemTotal ()
{
  return (_MemTotal);
}

std::string ModuleRAM::GetMemDispo ()
{
  return (_MemDispo);
}

std::string ModuleRAM::GetMemUse ()
{
  return (_MemUse);
}

void ModuleRAM::SM_PRINT_WINDOW (window *screen)
{
  refresh();

  screen->print (1, 1, "Total Memory:");
  screen->print (2, 1, "Available Memory:");
  screen->print (3, 1, "Memory Use:");

  screen->print (1, 14, GetMemTotal ().c_str ());
  screen->print (2, 18, GetMemDispo ().c_str ());
  screen->print (3, 21, GetMemUse ().c_str ());
}

void ModuleRAM::refresh ()
{
  _MemTotal = split (cat ("/proc/meminfo", 0), ':', '\n');
  _MemDispo = split (cat ("/proc/meminfo", 2), ':', '\n');
  _MemUse = std::to_string (((std::stod (_MemDispo)) *100) / std::stod (_MemTotal)) + " /100%";
}

void ModuleRAM::SetID (int i)
{
  _ID = i;
}

int ModuleRAM::GetID ()
{
  return (_ID);
}
