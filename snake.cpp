#include "snake.h"
#include "screen.h"
#include "string"
CSnake::CSnake(CRect r, char _c /*=' '*/):CFramedWindow(r, _c),score(0),h_bool(true) //odpalany jest kontruktor CFrameWindow CSnake jest potomkiem CFrameWindow
{

}
void CSnake::paint()
{
    CFramedWindow::paint();
    help();
}
void CSnake::help()
{
    char options[5][40] = {"h - toggle help information","p - toggle pause/play mode","r - restart game",
    "arrows - move snake (in play mode) or","move window (in pause mode)"};
    if(h_bool)
    {
        for(int i = 0; i < 5;i++){
            gotoyx( geom.topleft.y + 4 + i,geom.topleft.x + 3);
            printl(options[i]);
        }
    }
    else
    {
        CFramedWindow::paint();
        /*empty place for something*/
    }
}
bool CSnake::handleEvent(int key)
{
  //else
  if(key == 'h' || key == 'H')
  {
    if(h_bool == false)
    h_bool = true;
    else if(h_bool == true)
    h_bool = false;
    return true;
  }
  if(h_bool && CWindow::handleEvent(key))
  return true;
  return false;
}
