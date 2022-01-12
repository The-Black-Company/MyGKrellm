#ifndef WINDOW_HPP_
#define WINDOW_HPP_

class window
{
protected:
  WINDOW *_win;
  int _width;
  int _height;
  int _x;
  int _y;
  
public:
  window (int, int, int, int);

  ~window();

  void resh();

  void print(int, int, const char *);
};

#endif
