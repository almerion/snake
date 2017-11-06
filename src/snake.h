#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#define DELAY 30000

typedef enum Direction {

  UP,
  DOWN,
  LEFT,
  RIGHT,
} Direction;

typedef enum Status {

  FAILURE,
  SUCCESS,
} Status;

typedef struct f_pst { /* food position*/

  int height;
  int width;
} F_PST;

typedef struct s_pst { /* snake position */
  
  int height;
  int width;
  int cbody; /* how many part have snake */
} S_PST;

typedef struct t_brd { /* terminal border*/

  int height;
  int width;
} T_BRD;

typedef struct scr {

  int score;
} SCR;

int rand_number(int min_num, int max_num);
S_PST* create_body(WINDOW *win, S_PST *sp_pst, T_BRD *tp_brd, SCR *pscr, F_PST *fp_pst, Status stat);
F_PST* create_food(WINDOW *win, F_PST *fp_pst, T_BRD *tp_brd);
void game_over(WINDOW *win, T_BRD *tp_brd, SCR *pscr);
S_PST* create_snake(S_PST *sp_pst, T_BRD *tp_brd);
void print_body(WINDOW *win, S_PST *sp_pst);
