#ifndef MODULECORE_HPP_
#define MODULECORE_HPP_

class		ModuleCore
{
  std::vector <window *> _screen;
  std::vector <IMonitorModule *> _module;
  int _size;
  std::string _name;
  
public :
  ModuleCore (std::string name);

  ~ModuleCore ();

  void add (IMonitorModule *mod);

  void display ();

  IMonitorModule *getMod (int);

  void AddScreen (int w, int h, int x, int y);

  void print (int i, int x, int y, const char *str);
};

#endif
