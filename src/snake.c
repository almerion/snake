#include "snake.h"

int rand_number(int min_num, int max_num)
{
  int rand_num = 0;
  srand(time(NULL));
  rand_num = (rand() % (max_num - min_num));
  
  return rand_num;
}

void print_body(WINDOW *win,S_PST *sp_pst)
{
  int i = sp_pst->cbody;
  while(i) {
    mvwaddch(win, sp_pst->height, sp_pst->width, ACS_BLOCK);
    i--;
  }
}


S_PST* create_body(WINDOW *win, S_PST *sp_pst, T_BRD *tp_brd, SCR *pscr, F_PST *fp_pst, Status stat)
{
  int ch = 0;
  while (true)
    {
      ch = getch();
	  wclear(win);
	  switch (ch)
	    {
	    case KEY_RIGHT:
	      sp_pst->width++;
	    case KEY_UP:
	      sp_pst->height--;
	    case KEY_DOWN:
	      sp_pst->height++;
	    case KEY_LEFT:
	      sp_pst->width--;
	    }
	  print_body(win, sp_pst);

    }


  return sp_pst;
}

F_PST* create_food(WINDOW *win, F_PST *fp_pst, T_BRD *tp_brd)
{
  fp_pst->height = rand_number(0, tp_brd->height);
  fp_pst->width = rand_number(0, tp_brd->width);

  mvwaddch(win, fp_pst->height, fp_pst->width, ACS_DIAMOND);
  wrefresh(win);
  return fp_pst;
}

void game_over(WINDOW *win, T_BRD *tp_brd, SCR *pscr)
{
  int ch;

  wclear(win);
  mvwprintw(win, 0, 0, "<press F1 to exit from the game>");
  mvwprintw(win, tp_brd->height / 2, tp_brd->width / 2, "GAME OVER");
  mvwprintw(win, (tp_brd->height / 2) + 1, tp_brd->width / 2, "Your Score: %d", pscr->score);
  
  while ((ch = getch()) != KEY_F(1))
    endwin();
}

S_PST* create_snake(S_PST *sp_pst, T_BRD *tp_brd)
{
  sp_pst->height = rand_number(0, tp_brd->height);
  sp_pst->width = rand_number(0, tp_brd->width);

  return sp_pst;
}

const char* get_dir(Direction dir)
{
  
  switch (dir)
    {
    case LEFT:
      return "left";
    case RIGHT:
      return "right";
    case UP:
      return "up";
    case DOWN:
      return "down";
    default:
      return NULL;
    }
}

