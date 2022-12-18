#ifndef MVP_H
#define MVP_H

#include "../../board/include/board.h"

/**
 * @param mo - The move from which we're checking
 * @param bo - The board which we're checking
 * @param  i - The row index offset
 * @param  j - The col index offset
 * @param  t - The piece type to check
 * @param  c - The piece color to check
 */
#define PP_IN_BOUNDS(mo, i, j) ((mo->file - 97) + j < FILES && \
    (mo->rank + i < RANKS))
#define PP_VALID(mo, bo, i, j, t, c) bo[mo->rank + i][(int)(mo->file - 97) + j]\
     ->occupation ? (bo[mo->rank + i][(int)(mo->file - 97) + j] \
     ->occupation->type == t && bo[mo->rank + i][(int)(mo->file - 97) + j] \
     ->occupation->piece_color == c) : 0
#define PP_DIAG(mo, bo, i, j, t, c) PP_IN_BOUNDS(mo, i, j) ? \
  (PP_VALID(mo, bo, i, j, t, c) ? 1 : 0) : 0

#define MM_IN_BOUNDS(mo, i, j) ((mo->file - 97) - j >= 0 && (mo->rank - i >= 0))
#define MM_VALID(mo, bo, i, j, t, c) bo[mo->rank - i][(int)(mo->file - 97) - j]\
     ->occupation ? (bo[mo->rank - i][(int)(mo->file - 97) - j] \
     ->occupation->type == t && bo[mo->rank - i][(int)(mo->file - 97) - j] \
     ->occupation->piece_color == c) : 0
#define MM_DIAG(mo, bo, i, j, t, c) MM_IN_BOUNDS(mo, i, j) ? \
  (MM_VALID(mo, bo, i, j, t, c) ? 1 : 0) : 0

#define PM_IN_BOUNDS(mo, i, j) ((mo->file - 97) - j >= 0 && \
    (mo->rank + i < RANKS))
#define PM_VALID(mo, bo, i, j, t, c) bo[mo->rank + i][(int)(mo->file - 97) - j]\
     ->occupation ? (bo[mo->rank + i][(int)(mo->file - 97) - j] \
     ->occupation->type == t && bo[mo->rank + i][(int)(mo->file - 97) - j] \
     ->occupation->piece_color == c) : 0
#define PM_DIAG(mo, bo, i, j, t, c) PM_IN_BOUNDS(mo, i, j) ? \
  (PM_VALID(mo, bo, i, j, t, c) ? 1 : 0) : 0

#define MP_IN_BOUNDS(mo, i, j) ((mo->file - 97) + j < FILES && \
    (mo->rank - i >= 0))
#define MP_VALID(mo, bo, i, j, t, c) bo[mo->rank - i][(int)(mo->file - 97) + j]\
     ->occupation ? (bo[mo->rank - i][(int)(mo->file - 97) + j] \
     ->occupation->type == t && bo[mo->rank - i][(int)(mo->file - 97) + j] \
     ->occupation->piece_color == c) : 0
#define MP_DIAG(mo, bo, i, j, t, c) MP_IN_BOUNDS(mo, i, j) ? \
  (MP_VALID(mo, bo, i, j, t, c) ? 1 : 0) : 0


typedef struct MOVE_T {
  piece_type type;
  char file;
  int rank;
} move;

move * init_move(char file, int rank, piece_type type);
void debug_move(move * the_move);
void find_piece(move * the_move, square *** the_board, color piece_color);
void free_move(move * the_move);

#endif
