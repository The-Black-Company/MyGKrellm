#ifndef MODULENAME_HPP_
#define MODULENAME_HPP_


class ModuleName : public IMonitorModule
{
  std::string _MachineName;
  std::string _UserName;
  int _ID;
  
public :
  ModuleName ();
  
  void print ();

  void setName(std::string);

  std::string GetMachineName ();

  std::string GetUserName ();

  void SM_PRINT_WINDOW (window *);

  void refresh ();

  int GetID();

  void SetID(int);
};

#endif
