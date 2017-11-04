#include "snake.h"

int rand_number(int min_num, int max_num)
{
  int rand_num = 0;
  srand(time(NULL));
  rand_num = (rand() % (max_num - min_num));
  
  return rand_num;
}

S_PST* create_body(WINDOW *win, S_PST *sp_pst, T_BRD *tp_brd, SCR *pscr, Direction dir)
{
  int i = sp_pst->cbody;
  int height = sp_pst->height;
  int width = sp_pst->width;
  
  if (sp_pst->height == tp_brd->height|| sp_pst->width == tp_brd->width)
    game_over(win, tp_brd, pscr);
      
  switch (dir)
    {
    case LEFT:
      mvwaddch(win, height, width--, ACS_BLOCK);
      mvwprintw(win, 0, 0, "height = %d", height);
      mvwprintw(win, 1, 0, "width = %d", width);
    case RIGHT:
      mvwaddch(win, height, width++, ACS_BLOCK);
      mvwprintw(win, 0, 0, "height = %d", height);
      mvwprintw(win, 1, 0, "width = %d", width);
    case UP:
      mvwaddch(win, height, width--, ACS_BLOCK);
      mvwprintw(win, 0, 0, "height = %d", height);
      mvwprintw(win, 1, 0, "width = %d", width);
    case DOWN:
      mvwaddch(win, height++, width, ACS_BLOCK);
      mvwprintw(win, 0, 0, "height = %d", height);
      mvwprintw(win, 1, 0, "width = %d", width);
    default:
      mvwaddch(win, height--, width, ACS_BLOCK);
      mvwprintw(win, 0, 0, "height = %d", height);
      mvwprintw(win, 1, 0, "width = %d", width);
    }

  mvwprintw(win, 2, 0, "dir = %s", get_dir(dir));
  
  i--;
  usleep(DELAY);
  wrefresh(win);

  sp_pst->height = height;
  sp_pst->width = width;

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

