#ifndef MODULERAM_HPP_
#define MODULERAM_HPP_

class ModuleRAM : public IMonitorModule
{
  std::string _MemTotal;
  std::string _MemDispo;
  std::string _MemUse;
  int _ID;
  
public :
  ModuleRAM ();
  
  void print ();

  std::string GetMemTotal ();

  std::string GetMemDispo ();

  std::string GetMemUse ();

  void SM_PRINT_WINDOW (window *);

  void refresh ();

  int GetID();

  void SetID(int);
};

#endif
