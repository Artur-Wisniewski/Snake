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
public:
  CSnake(CRect r, char _c = ' ');
private:
  void paint();
  bool handleEvent(int key);
  int score;/* <- definiuje lvl co 3 score 1 lvl */
  bool h_bool;
  bool p_bool;
  Body snake_body;
  int speed;
  bool gm_ov_bool;
  void help();
  void snake();
  void restart();
  bool is_fruit_bool;
  void fruit();
  bool collision(CPoint&);
  void bite();
  void level();
  CPoint fruit_position;
};

#endif
