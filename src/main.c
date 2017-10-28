#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

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

int rand_number(int min_num, int max_num);
void add_body(WINDOW *win, int position_height, int position_width);

int main()
{

  int ch, i, k;
  int cur_height1, cur_height2, cur_width1, cur_width2;
  SNAKE_POSITION *s_position;
  FOOD_POSITION *f_position;
  WINDOW *score_box_win, *game_win;

  s_position->num_body = 2;
  initscr();
  cbreak(); /* pass everthing immediatelly */
  keypad(stdscr, TRUE); /* when player press the keys we need to know that keys */ 
  noecho();
  curs_set(FALSE);

  getmaxyx(stdscr, height, width); /* take the screen borders */
  game_win = newwin(height - 2, width - 2, 1, 1);
  getmaxyx(game_win, gawi_height, gawi_width);

  sstart_height = rand_number(0, height); /* hight value of start position (snake)*/
  sstart_width = rand_number(0, width); /* width value of start position (snake) */
  
  score = 0;
  while ((ch = getch() == KEY_F(1))) { 
    i = 0;
    k = 0;
    while (i == height && k == width)
      {
	clear();
	/* start the game */
	create_snake(stdscr, s_position, height, width, i);
	create_food(stdscr, f_position, height, width);
	refresh();

	cur_height1 = (s_position->height + i) + 1;
	cur_height2 = (s_position->height + i) + 2;
	cur_width1 = (s_position->width + k) + 1;
	cur_width2 = (s_postion->width + k) + 2;

	if (cur_height2 - cur_height1 > cur_width2 - cur_width1)
	  {
	    switch (ch)
	      {
	      case KEY_LEFT:
		turn_left();
		refresh();
	      case KEY_RIGHT:
		turn_right();
		refresh();
	      default:
		hold_position();
		refresh();
	      } /* end switch left and right */
	  } /* end of if */
	else if (cur_height2 == food_height && cur_width2 == food_width)
	  {
	    score += 10;
	    create_food(height, width);
	    num_body++;
	    add_body(stdscr, num_body);
	  }
	else 
	  {
	    switch(ch)
	      {
	      case KEY_UP:
		turn_up();
		refresh();
	      case KEY_DOWN:
		turn_down();
		refresh();
	      default:
		hold_position();
		refresh();
	      } /* end switch up and down */
	  } /* end of else */
	
      } /* end of internal while */
  } /* end of external while*/

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

int create_snake(WINDOW *win, SNAKE_POSITION *s_position, int height, int width, int cnt)
{
  int i;
  s_position->height = rand_number(0, height);
  s_position->width = rand_number(0, width);
  
  for (i = 0; i <= s_position->num_body; i++)
    mvwprintw(win, (win, s_position->height + i), s_position->width, "x");
  mvwprintw(win, (win, s_position->height + i) + 1, s_position_width, "$");

  return s_position;
}


/* create_food(): initialize random height and width
 * and print the food in initialized position.
 */
void create_food(WINDOW *win, FOOD_POSITION *f_position, int height, int width)
{
  f_position->height = rand_num(0, height);
  f_position->width = rand_num(0, width);
  
  return f_position;
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
