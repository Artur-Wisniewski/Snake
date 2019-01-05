#include "snake.h"
#include "screen.h"
CSnake::CSnake(CRect r, char _c /*=' '*/):
CFramedWindow(r, _c),score(0),h_bool(true)
{
    snake_body.dir = RIGHT;
    snake_body.part.push_back(CPoint(4,2));
    snake_body.part.push_back(CPoint(3,2));
    snake_body.part.push_back(CPoint(2,2));
}
void CSnake::paint()
{
    CFramedWindow::paint();
    snake();
    if(h_bool)
        help();
}
void CSnake::help() // void CInputLine::paint() tu mozna było uzyc
{
    char options[5][40] = {"h - toggle help information","p - toggle pause/play mode","r - restart game",
    "arrows - move snake (in play mode) or","move window (in pause mode)"};

        for(int i = 0; i < 5;i++){
            gotoyx( geom.topleft.y + 4 + i,geom.topleft.x + 3);
            printl(options[i]);
        }
}
bool CSnake::handleEvent(int key)
{
    if(!h_bool)
    {
      switch (key)
      {
        case KEY_UP:
          if(snake_body.dir != DOWN)
          snake_body.dir = UP;
          return true;
        case KEY_DOWN:
          if(snake_body.dir != UP)
          snake_body.dir = DOWN;
          return true;
        case KEY_RIGHT:
          if(snake_body.dir != LEFT)
          snake_body.dir = RIGHT;
          return true;
        case KEY_LEFT:
          if(snake_body.dir != RIGHT)
          snake_body.dir = LEFT;
          return true;
      }
    }
  if(key == 'h' || key == 'H')
  {
    if(!h_bool)
    h_bool = true;
    else if(h_bool)
    h_bool = false;
    return true;
  }
  /*else if(key == 'p' || key == 'P')
  {
  }
  else if(key == 'r' || key == 'R')
  {
  }*/
  if(h_bool && CWindow::handleEvent(key));
  return true;
}
void CSnake::snake()
{
    if(!h_bool)//chodzi jesli menu wylaczone
    {
        snake_body.part.pop_back();
        snake_body.part.push_front(snake_body.part.front());
        switch(snake_body.dir)
        {
            case UP:
                snake_body.part.front() +=  CPoint(0, -1);
                if(snake_body.part.front().y == 0)
                    snake_body.part.front().y = geom.size.y - 2;
                break;
            case RIGHT:
                snake_body.part.front() +=  CPoint(1, 0);
                if(snake_body.part.front().x == geom.size.x - 1)
                    snake_body.part.front().x = 1;
                break;
            case DOWN:
                snake_body.part.front() +=  CPoint(0, 1);
                if(snake_body.part.front().y == geom.size.y - 1)
                    snake_body.part.front().y = 1;
                break;
            case LEFT:
                snake_body.part.front() +=  CPoint(-1, 0);
                if(snake_body.part.front().x == 0)
                    snake_body.part.front().x = geom.size.x - 2;
                break;
        }
    }
    for(list< CPoint >::iterator i = snake_body.part.begin(); i != snake_body.part.end(); i++)
    {
        gotoyx(i->y+geom.topleft.y,i->x+geom.topleft.x);
        printc('+');
    }
    gotoyx(snake_body.part.begin()->y+geom.topleft.y,snake_body.part.begin()->x+geom.topleft.x);
    printc('*');


}
