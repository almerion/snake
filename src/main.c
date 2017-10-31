#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY 30000

enum direction { UP, DOWN, LEFT, RIGHT};
enum status {SUCCESS, FAILURE };

typedef struct food_position {

  int height;
  int width;
}FOOD_POSITION;
  
typedef struct snake_position {

  int height;
  int width;
  int num_body;
} SNAKE_POSITION;

typedef struct terminal_border {

  int height;
  int width;
} TERM_BORDER;

typedef struct _score {
  
  int score;
}SCORE;

int rand_number(int min_num, int max_num);
void add_body(WINDOW *win, int position_height, int position_width);
SNAKE_POSITION* create_body(WINDOW *win, SNAKE_POSITION *sp_position, TERM_BORDER *tp_border, enum direction dir);
FOOD_POSITION* create_food(WINDOW *win, TERM_BORDER *tp_border, FOOD_POSITION *fp_position);
void print_food(WINDOW *win, FOOD_POSITION *fp_position);
void game_over(WINDOW *win, TERM_BORDER *tp_border, SCORE *scp);

int main()
{

  int ch, i, k;
  int cur_height1, cur_height2, cur_width1, cur_width2;
  SNAKE_POSITION *sp_position, s_position;
  FOOD_POSITION *fp_position, f_position;
  TERM_BORDER *tp_border, t_border;
  SCORE *scp, sc;
  enum direction prev = DOWN;

  sp_position = &s_position;
  fp_position = &f_position;
  tp_border = &t_border;
  scp = &sc;

  sp_position->num_body = 2;
  initscr();
  cbreak(); /* pass everthing immediatelly */
  keypad(stdscr, true); /* when player press the keys we need to know that keys */ 
  noecho();
  curs_set(false);

  getmaxyx(stdscr, tp_border->height, tp_border->width); /* take the screen borders */
  
  scp->score = 0;
  while ((ch = getch())) { 
    {
      create_food(stdscr, tp_border, fp_position);
      create_body(stdscr, sp_position, tp_border, prev);
      print_food(stdscr, fp_position);
      clear();
      /* start the game */
      refresh();
      switch (ch)
	{
	case KEY_LEFT:
	  if (prev != RIGHT)
	    prev = LEFT;
	  
	case KEY_RIGHT:
	  if (prev != LEFT)
	    prev = RIGHT;
	  
	case KEY_DOWN:
	  if (prev != UP) 
	    prev = DOWN;
	  
	case KEY_UP:
	  if (prev != DOWN)
	    prev = UP;
	  
	default:
	  prev = prev;
	} 
      usleep(DELAY);
      create_body(stdscr, sp_position, tp_border, prev);
    }
  }
  
  game_over(stdscr, tp_border, scp);
  while ((ch = getch() == 'q'))
    endwin();

  return 0;
}

int rand_number(int min_num, int max_num)
{
  int rand_num = 0;
  srand(time(NULL));
  rand_num = (rand() % (max_num - min_num));

  return rand_num;
}

SNAKE_POSITION* create_body(WINDOW *win, SNAKE_POSITION *sp_position, TERM_BORDER *tp_border, enum direction dir)
{
  int i = sp_position->num_body;
  
  sp_position->height = rand_number(0, tp_border->height);
  sp_position->width = rand_number(0, tp_border->width);

  while (i)
    {
      switch (dir)
	{
	case LEFT:
	  mvwaddch(win, sp_position->height--, sp_position->width, ACS_BLOCK);
	case RIGHT:
	  mvwaddch(win, sp_position->height++, sp_position->width, ACS_BLOCK);
	case UP:
	  mvwaddch(win, sp_position->height, sp_position->width--, ACS_BLOCK);
	case DOWN:
	  mvwaddch(win, sp_position->height, sp_position->width++, ACS_BLOCK);
	default:
	  mvwaddch(win, sp_position->height, sp_position->width, ACS_BLOCK);
	}
      i--;
      wrefresh(win);
    }

  return sp_position;
}

/* create_food(): initialize random height and width
 * and print the food in initialized position.
 */
FOOD_POSITION* create_food(WINDOW *win, TERM_BORDER *tp_border, FOOD_POSITION *fp_position)
{
  fp_position->height = rand_number(0, tp_border->height);
  fp_position->width = rand_number(0, tp_border->width);

  mvwaddch(win, fp_position->height, fp_position->width, ACS_DIAMOND);
  
  return fp_position;
}

void print_food(WINDOW *win, FOOD_POSITION *fp_position)
{
  mvwaddch(win, fp_position->height, fp_position->width, ACS_DIAMOND);
}

/* game_over(): this function finishes the game as showing 
 * score. */
void game_over(WINDOW *win, TERM_BORDER *tp_border, SCORE *scp)
{
  wclear(win);
  mvwprintw(win, 0, 0, "<press q to exit from the game>");
  mvwprintw(win, tp_border->height / 2, tp_border->width / 2, "GAME OVER");
  mvwprintw(win, (tp_border->height / 2) + 1, tp_border->width / 2, "Your score: %d", scp->score);
}


