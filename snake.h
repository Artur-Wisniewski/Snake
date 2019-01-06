#ifndef __SNAKE_H__
#define __SNAKE_H__
#include "cpoint.h"
#include "winsys.h"
#include <list>
enum Directions {UP,RIGHT,DOWN,LEFT};
struct Body{
        Directions dir;
        list<CPoint> part;
};
class CSnake:public CFramedWindow// <- CFramedWindow <- CWindow <- CView
{
  int loop;
  int speed;
  int score;/* <- definiuje lvl co 3 score 1 lvl */
  bool h_bool;
  bool p_bool;
  Body snake_body;
  bool gm_ov_bool;
  CPoint fruit_position;
  void step();
  void bite();
  void help();
  void snake();
  void paint();
  void fruit();
  void level();
  void restart();
  bool is_fruit_bool;
  bool collision(CPoint&);
  bool handleEvent(int key);
public:
  CSnake(CRect r, char _c = ' ');
};

#endif
