#include "snake.h"

int main()
{
  
  int ch;
  T_BRD t_brd, *tp_brd;
  S_PST s_pst, *sp_pst;
  F_PST f_pst, *fp_pst;
  SCR scr, *pscr;
  
  Status stat = SUCCESS;
  Direction dir = LEFT;

  tp_brd = &t_brd;
  sp_pst = &s_pst;
  fp_pst = &f_pst;
  pscr = &scr;

  initscr();
  noecho();
  curs_set(false);
  keypad(stdscr, true);

  getmaxyx(stdscr, tp_brd->height, tp_brd->width);
  
  create_snake(sp_pst, tp_brd);
  create_food(stdscr, fp_pst, tp_brd);
  
  while (1)
    {
      while ((ch = getch() != KEY_F(1)))
	{
	  clear();
	  switch (dir)
	    {
	    case KEY_LEFT:
	      dir = LEFT;
	    case KEY_RIGHT:
	      dir = RIGHT;
	    case KEY_UP:
	      dir = UP;
	    case KEY_DOWN:
	      dir = DOWN;
	    default:
	      dir = dir;
	    }
	  create_body(stdscr, sp_pst, tp_brd, pscr, dir);
	  refresh();
	}
    }
  
  return 0;
}


