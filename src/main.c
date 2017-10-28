#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int food_height;
int food_width;

int snake_height;
int snake_width;

int num_body;

int rand_number(int min_num, int max_num);
void add_body(WINDOW *win, int position_height, int position_width);

int main()
{
  int width, height; /* holds the screen border's values. */
  int ch, i, k, score;
  int gawi_height, gawi_width;
  int sstart_height, sstart_width;
  int fstart_height, fstart_width;
  int cur_height1, cur_height2, cur_width1, cur_width2;
  WINDOW *score_box_win, *game_win;

  int num_body = 2;
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
    while (i == hight && k == width)
      {
	clear();
	/* start the game */
	create_snake(stdscr, );
	mvprintw(sstart_height + i, sstart_width, "x");
	mvprintw((sstart_height + i) + 1, sstart_width, "x");
	mvprintw((sstart_height + i) + 2, sstart_width, "$");
	refresh();
	  
	create_food(stdscr, height, width);

	cur_height1 = (sstart_height + i) + 1;
	cur_height2 = (sstart_height + i) + 2;
	cur_width1 = (sstart_width + k) + 1;
	cur_width2 = (sstart_height + k) + 2;

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

int create_snake_height(int height)
{
  snake_height = rand_number(0, height);
  return snake_height;
}

int create_snake_width(int width)
{
  snake_width = rand_number(0, width);
  return snake_width;
}

void create_head(WINDOW *win, int height, int width)
{
  mvwprint(win, height);
}

/* create_food(): initialize random height and width
 * and print the food in initialized position.
 */
void create_food(WINDOW *win, int height, int width) 
{
  int food_height = 0;
  int food_width = 0;
  
  food_height = rand_num(0, height);
  food_width = rand_num(0, width);

  mvwprintw(win, food_height, food_width);
  wrefresh(stdscr);
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

void turn_left(WINDOW *win, int height, int width)
{
  int i = 0;
  int k = 0;

  while (i < height && k < width)
    {
      mvwprintw(win, "");
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
