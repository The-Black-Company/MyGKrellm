#ifndef MODULENET_HPP_
#define MODULENET_HPP_

class ModuleNet : public IMonitorModule
{
  int		_ID;
  
public :
  ModuleNet ();
  
  void print ();

  void SM_PRINT_WINDOW (window *);

void refresh ();

  int GetID();

  void SetID(int);
};

#endif
