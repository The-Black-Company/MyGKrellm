#include "lib.h"

window::window (int w, int h, int x, int y)
  :_width(h), _height(w), _x(x), _y(y)
{
  _win = subwin (stdscr, _width, _height, _x, _y);
  box (_win, ACS_VLINE, ACS_HLINE);
  wrefresh (_win);
}

window::~window ()
{
}

void window::resh ()
{
  wrefresh (_win);
}

void window::print (int x, int y, const char *str)
{
  _win = subwin (stdscr, _width, _height, _x, _y);
  box (_win, ACS_VLINE, ACS_HLINE);
  mvwprintw (_win, x, y, str);
  wrefresh (_win);
}
