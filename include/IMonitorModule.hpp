#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_


class IMonitorModule
{
public :

  virtual ~IMonitorModule () = default;

  virtual void SM_PRINT_WINDOW (window *) = 0;

  virtual void refresh () = 0;

  virtual int GetID () = 0;

  virtual void SetID(int) = 0;
};
  
#endif
