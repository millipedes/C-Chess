#ifndef BRD_H
#define BRD_H

#include "../../player/include/player.h"

typedef struct BOARD_T {
  player * white;
  player * black;
  square *** squares;
} board;

board * init_board(void);
void debug_board(board * the_board);
void print_piece_char(piece * the_piece);
void free_board(board * the_board);

#endif
