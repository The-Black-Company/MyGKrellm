#ifndef MODULETIME_HPP_
#define MODULETIME_HPP_

class ModuleTime : public IMonitorModule
{
  time_t _timestamp;
  struct tm *_timeInfos;
  std::string _Hour;
  std::string _Date;
  int _ID;

public :
  ModuleTime ();
  
  void print ();

  std::string GetHour ();

  std::string GetDate ();

  void SM_PRINT_WINDOW (window *);

  void refresh ();

  int GetID ();

  void SetID (int);
};

#endif
