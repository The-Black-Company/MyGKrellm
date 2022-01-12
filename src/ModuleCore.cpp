#include "lib.h"

ModuleCore::ModuleCore (std::string name)
:_size(0)
{
  _name = name;
  initscr ();
  keypad (stdscr, true);
  nonl ();
  cbreak ();
  noecho ();

  /*===========ModuleName===========*/
  ModuleName *_mn = new ModuleName ();
  _mn->setName (_name);
  _mn->refresh ();
  add (_mn);
  AddScreen (75, 5, 0, 0);
  _mn->SetID (_size - 1);

  /*===========CPU===========*/
  ModuleCPU *_cpu = new ModuleCPU ();
  _cpu->refresh ();
  add (_cpu);
  AddScreen (75, 6, 5, 0);
  _cpu->SetID (_size - 1);

  /*===========ModuleSys===========*/
  ModuleSys *_ms = new ModuleSys ();
  _ms->refresh ();
  add (_ms);
  AddScreen (75, 5, 11, 0);
  _ms->SetID (_size - 1);

  /*===========ModuleTime===========*/
  ModuleTime *_mt = new ModuleTime ();
  _mt->refresh ();
  add (_mt);
  AddScreen (75, 5, 16, 0);
  _mt->SetID (_size - 1);

  /*===========ModuleRAM=========*/

  ModuleRAM *_mr = new ModuleRAM ();
  _mr->refresh ();
  add (_mr);
  AddScreen (75, 6, 21, 0);
  _mr->SetID (_size - 1);

}

ModuleCore::~ModuleCore ()
{
  for (int i = 0; i < (int) _screen.size (); ++i)
    delete _screen[i];

  for (int i = 0; i < (int) _module.size (); ++i)
    delete _module[i];

  endwin ();
}

void ModuleCore::add (IMonitorModule *mod)
{
  _module.push_back (mod);
  _size++;
}

void ModuleCore::AddScreen (int w, int h, int x, int y)
{
  window *_new = new window (w, h, x, y);
  _screen.push_back (_new);
}

void ModuleCore::print (int i, int x, int y, const char *str)
{
  window *w;
  w = _screen[i];
  (*w).print (x, y, str);
}

IMonitorModule *ModuleCore::getMod (int i)
{
  return (_module[i]);
}

void ModuleCore::display ()
{
  int key;
  bool end;
  key = -1;
  end = false;
  
  for (int i = 0; i < _size; ++i)
      _module[i]->SM_PRINT_WINDOW (_screen[_module[i]->GetID ()]);
  
  while (end != true)
    {
      key = getch ();
      if (key == KEY_UP) // touche en l'air
      {
        for (int i = 0; i < _size; ++i)
          _module[i]->SM_PRINT_WINDOW (_screen[_module[i]->GetID ()]);
      }
      if (key == KEY_BTAB) // shift tab
          end = true;
    }
}
