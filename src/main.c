#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

enum direction { UP, DOWN, LEFT, RIGTH};
enum status {SUCCESS, FAILURE };

typedef struct flag {

  bool vertical;
  bool horizontal;
}FLAG;

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
SNAKE_POSITION* create_body(WINDOW *win, SNAKE_POSITION *sp_position, TERM_BORDER *tp_border, FLAG *pflag)

int main()
{

  int ch, i, k;
  int cur_height1, cur_height2, cur_width1, cur_width2;
  SNAKE_POSITION *sp_position, s_position;
  FOOD_POSITION *fp_position, f_position;
  TERM_BORDER *tp_border, t_border;
  SCORE *scp, *sc;
  enum direction prev = DOWN;

  sp_position = &s_position;
  fp_position = &f_position;
  tp_border = &t_border;
  scp = &sc

  s_position->num_body = 2;
  initscr();
  cbreak(); /* pass everthing immediatelly */
  keypad(stdscr, TRUE); /* when player press the keys we need to know that keys */ 
  noecho();
  curs_set(FALSE);

  getmaxyx(stdscr, sp_position->height, sp_position->width); /* take the screen borders */
  
  scp->score = 0;
  while ((ch = getch() == KEY_F(1))) { 
    i = 0;
    k = 0;
    while (i == height && k == width)
      {
	clear();
	/* start the game */
	create_body(stdscr,sp_position, tp_border, );
	create_food(stdscr, tp_border);
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
	create_body(stdscr, sp_position, tp_border, prev);
      }
  }

  game_over(stdscr, height, width, score);
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
  int i, k;
  if (prev)
    {
      for (i = 0; i <= sp_position->num_body; i++)
	mvwaddch(win, sp_position->height + i, sp_position->width, '*');
      mvwaddch(win, sp_position->height + i, sp_position->width, '$');
    }
  else
    {
      for (k = 0; i <= sp_position->numbody; k++)
	mvwaddch(win, sp_position->height, sp_position->width + k, '*');
      mvwaddch(win, sp_position->height, sp_position->width + k, '$');
    }

  return sp_position;
}

/* create_food(): initialize random height and width
 * and print the food in initialized position.
 */
FOOD_POSITION* create_food(WINDOW *win, TERM_BORDER *tp_border)
{
  fp_position->height = rand_num(0, tp_border->height);
  fp_position->width = rand_num(0, tp_border->width);

  mvwaddch(win, fp_position->height, fp_position->width, ACS_DIAMOND);
  
  return fp_position;
}

/* game_over(): this function finishes the game as showing 
 * score. */
void game_over(WINDOW *win, int height, int width, int score)
{
  wclear(win);
  mvwprintw(win, 0, 0, "<press q to exit from the game>");
  mvwprintw(win, height / 2, width / 2, "GAME OVER");
  mvwprintw(win, (height / 2) + 1, width / 2, "Your score: %d", score);
}

/* add_body(): it takes the snake current positions
 * and number of vertical body parts. Adds a vertical
 * '|' char. */
void add_body(WINDOW *win, int snake_height, int snake_width, int num_body)
{
  int i = 0;
  for (; i <= num_body; i++)
      mvwprintw(win, snake_height + i, snake_width, "|");
  mvwprintw(win, (snake_height + i) + 1, snake_width, "$");
  wrefresh(win);
}

/* turn_left(): it turns the body of snake to left */
void turn_left(WINDOW *win, SNAKE_POSITION *s_position, int height, int width)
{
  int i = 0;
  int k = 0;
  while ()
    {
      mvwprintw(win, s_position->height - 1, s_position->width + k, "-");
      
    }
}

void turn_right()
{

}

void turn_up()
{

}

void turn_down()
{

}

void hold_position()
{

}

void start_moving()
{

}
