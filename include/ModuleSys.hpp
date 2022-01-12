#ifndef MODULESYS_HPP_
#define MODULESYS_HPP_

class ModuleSys : public IMonitorModule
{
  std::string _Systeme;
  std::string _Kernel;
  int _ID;
  
public :
  ModuleSys ();
  
  void print ();

  std::string GetSysteme ();

  std::string GetKernel ();

  void SM_PRINT_WINDOW (window *);

  void refresh ();

  int GetID();

  void SetID(int);
};

#endif
