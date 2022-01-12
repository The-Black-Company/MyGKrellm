#ifndef MODULECPU_HPP_
#define MODULECPU_HPP_

class ModuleCPU : public IMonitorModule
{
  std::string _CPUModele;
  std::string _CPUFrequence;
  std::string _CPUCore;
  int _ID;
  
public :
  ModuleCPU ();

  void print ();

  std::string GetCore ();

  std::string GetFrequency ();

  std::string GetModel ();

  void SM_PRINT_WINDOW (window *);
  
  void refresh ();

  int GetID();

  void SetID(int);
};

#endif
