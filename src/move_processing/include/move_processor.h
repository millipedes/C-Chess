#ifndef MVP_H
#define MVP_H

#include "../../board/include/board.h"

#define PP_DIAG(mo, bo, i, j, t) ((mo->file - 97) + j < FILES && \
    (mo->rank + i < RANKS)) ? bo[mo->rank + i][(int)(mo->file - 97) + j] \
     ->occupation->type == t : 0
#define MM_DIAG(mo, bo, i, j, t) ((mo->file - 97) - j >= 0 && \
    (mo->rank - i >= 0)) ? bo[mo->rank - i][(int)(mo->file - 97) - j] \
    ->occupation->type == t : 0
#define PM_DIAG(mo, bo, i, j, t) ((mo->file - 97) - j >= 0 && \
    (mo->rank + i < RANKS)) ? bo[mo->rank + i][(int)(mo->file - 97) - j] \
     ->occupation->type == t : 0
#define MP_DIAG(mo, bo, i, j, t) ((mo->file - 97) + j < FILES && \
    (mo->rank - i >= 0)) ? bo[mo->rank - i][(int)(mo->file - 97) + j] \
     ->occupation->type == t : 0

typedef struct MOVE_T {
  piece_type type;
  char file;
  int rank;
} move;

move * init_move(char file, int rank, piece_type type);
void debug_move(move * the_move);
void find_piece(move * the_move, square *** the_board);
void free_move(move * the_move);

// board * move(board * the_board, char * the_move);

#endif
