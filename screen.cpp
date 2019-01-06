/* screen.cpp */
#include "screen.h"
#include "cpoint.h"

#define LINE_MAX 255
static CPoint TopLeft;
static CPoint BottomRight;
static int cury, curx;

void init_screen()
{
  initscr();/* Start curses mode 		  */
  cbreak(); /* Line buffering disabled	we can disable the line buffering to avoid <enter> after input.*/
  noecho();/*These functions control the echoing of characters typed by the user to the terminal.*/
  timeout(20);/* notimeout, timeout, wtimeout - control blocking on input */
  nonl(); /*https://linux.die.net/man/3/nonl*/
  leaveok(stdscr,TRUE);/*reduces the need for cursor motions*/
  intrflush(stdscr, FALSE);/*giving the effect of faster response to the interrupt, but causing curses to have the wrong idea of what is on the screen. */
  keypad(stdscr, TRUE); /*It enables the reading of function keys like F1, F2, arrow keys etc.*/
  curs_set(0);/*The curs_set routine sets the cursor state is set to invisible, normal, or very visible for visibility equal to 0, 1, or 2 */
  if(has_colors() == TRUE)
  {
		start_color();
        use_default_colors();
  }
}

void done_screen()//wywolywane podczas zakonczenia programu
{
  endwin(); /* End curses mode		  */
}

void update_screen()//aktualizuje polozenie obrazu
{
  getscreenanchor(TopLeft.y, TopLeft.x);
  getscreensize(BottomRight.y, BottomRight.x);
  BottomRight += TopLeft;
}

int ngetch()
{
  return wgetch(stdscr);/*getting value from user*/
}

void getscreenanchor(int &y, int &x)
{
  getbegyx(stdscr, y, x);/* get the number of begin rows and columns */
}

void getscreensize(int &y, int &x)
{
  getmaxyx(stdscr, y, x); /* get the number of rows and columns */
}

int gotoyx(int y, int x)
{
  cury=y;
  curx=x;
  return (cury >= TopLeft.y && cury < BottomRight.y && curx >= TopLeft.x && curx < BottomRight.x);
}

void getcursor(int& y, int& x)
{
  y = cury;
  x = curx;
}

void printc(char c)
{
  if(c != '\n' && c != '\r')
  {
    if(cury >= TopLeft.y && cury < BottomRight.y && curx >= TopLeft.x && curx < BottomRight.x)
    {
      wmove(stdscr, cury, curx); /*change current position*/
      addch(c);                     /*put a single character into the current cursor location and advance the position of the cursor.*/
    }
    curx++;
  }
}

int printl(const char* fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);

  char dest[LINE_MAX];
  vsnprintf(dest, LINE_MAX, fmt, ap);

  int i = 0;
  while(dest[i])
    printc(dest[i++]);

  va_end(ap);
  return !ERR;
}
/*Dlaczego moj game loop jest amazing?
    poniewaz czeka na input w roznych czasach
    przyspieszanie dziala na zasadzie czekania jesli dostanie szybko key to wykonuje szybicej instrukcje
    jesli nie dostanie to czeka ten czas oczekiwania
    timeout to czas czekania na przycisk
*/
