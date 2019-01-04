#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"

class CSnake:public CFramedWindow// <- CFramedWindow <- CWindow <- CView
{
public:
  CSnake(CRect r, char _c = ' ');
private:
  void paint();
  bool handleEvent(int key);
  int score;/* <- definiuje lvl */
  bool h_bool;
  void help();

};

#endif
