#include "include/move_processor.h"

move * init_move(char file, int rank, piece_type type) {
  move * the_move = calloc(1, sizeof(struct MOVE_T));
  the_move->file = file;
  the_move->rank = RANKS - rank;
  the_move->type = type;
  return the_move;
}

void debug_move(move * the_move) {
  printf("[MOVE]\n");
  printf("%c%d %s\n", the_move->file, the_move->rank,
      piece_type_to_string(the_move->type));
}

void find_piece(move * the_move, square *** the_board, color piece_color) {
  int ftoi = (int)(the_move->file - 97);
  switch(the_move->type) {
    case KING:
      for(int i = -1; i < RANKS; i++)
        for(int j = -1; j < FILES; j++)
          // Because of the range of i/j we only need to check + +
          if((ftoi + j >= 0 && the_move->rank + i >= 0 &&
                the_move->rank + i < RANKS && ftoi + j < FILES) ?
              (the_board[the_move->rank + i][ftoi + j]->occupation ?
              (the_board[the_move->rank + i][ftoi + j]->occupation->type
              == KING &&
              the_board[the_move->rank + i][ftoi + j]
              ->occupation->piece_color == piece_color) : 0) : 0) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank + i][ftoi + j]->occupation;
            the_board[the_move->rank + i][ftoi + j]->occupation = NULL;
            break;
          }
      break;
    case QUEEN:
      for(int i = 0; i < RANKS; i++)
        for(int j = 0; j < FILES; j++)
          // Rank
          if(the_board[i][ftoi]->occupation ?
              (the_board[i][ftoi]->occupation->type == QUEEN &&
              the_board[i][ftoi]->occupation->piece_color == piece_color) : 0) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[i][ftoi]->occupation;
            the_board[i][ftoi]->occupation = NULL;
            return;
          // File
          } else if(the_board[the_move->rank][j]->occupation ?
              (the_board[the_move->rank][j]->occupation->type == QUEEN &&
              the_board[the_move->rank][j]->occupation->piece_color
              == piece_color) : 0) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank][j]->occupation;
            the_board[the_move->rank][j]->occupation = NULL;
            return;
          }
      for(int i = 0; i < RANKS; i++)
        // + + Diagonal (valid ? check queen : 0)
        if(PP_DIAG(the_move, the_board, i, i, QUEEN, piece_color)) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank + i][ftoi + i]->occupation;
            the_board[the_move->rank + i][ftoi + i]->occupation = NULL;
            return;
          // - - Diagonal (valid ? check queen : 0)
          } else if(MM_DIAG(the_move, the_board, i, i, QUEEN, piece_color)) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank - i][ftoi - i]->occupation;
            the_board[the_move->rank - i][ftoi - i]->occupation = NULL;
            return;
          // + - Diagonal (valid ? check queen : 0)
          } else if(PM_DIAG(the_move, the_board, i, i, QUEEN, piece_color)) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank + i][ftoi - i]->occupation;
            the_board[the_move->rank + i][ftoi - i]->occupation = NULL;
            return;
          // - + Diagonal (valid ? check queen : 0)
          } else if(MP_DIAG(the_move, the_board, i, i, QUEEN, piece_color)) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank - i][ftoi + i]->occupation;
            the_board[the_move->rank - i][ftoi + i]->occupation = NULL;
            return;
          }
      break;
    case ROOK:
      for(int i = 0; i < RANKS; i++)
        for(int j = 0; j < FILES; j++)
          // Rank
          if(the_board[i][ftoi]->occupation ?
              (the_board[i][ftoi]->occupation->type == ROOK) &&
              the_board[i][ftoi]->occupation->piece_color == piece_color : 0) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[i][ftoi]->occupation;
            the_board[i][ftoi]->occupation = NULL;
            return;
          // File
          } else if(the_board[the_move->rank][j]->occupation ? 
              (the_board[the_move->rank][j]->occupation->type == ROOK) &&
              the_board[the_move->rank][j]->occupation->piece_color
              == piece_color : 0) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank][j]->occupation;
            the_board[the_move->rank][j]->occupation = NULL;
            return;
          }
      break;
    case BISHOP:
      for(int i = 0; i < RANKS; i++)
        // + + Diagonal (valid ? check bishop : 0)
        if(PP_DIAG(the_move, the_board, i, i, BISHOP, piece_color)) {
          the_board[the_move->rank][ftoi]->occupation
            = the_board[the_move->rank + i][ftoi + i]->occupation;
          the_board[the_move->rank + i][ftoi + i]->occupation = NULL;
          return;
        // - - Diagonal (valid ? check bishop : 0)
        } else if(MM_DIAG(the_move, the_board, i, i, BISHOP, piece_color)) {
          the_board[the_move->rank][ftoi]->occupation
            = the_board[the_move->rank - i][ftoi - i]->occupation;
          the_board[the_move->rank - i][ftoi - i]->occupation = NULL;
          return;
        // + - Diagonal (valid ? check bishop : 0)
        } else if(PM_DIAG(the_move, the_board, i, i, BISHOP, piece_color)) {
          the_board[the_move->rank][ftoi]->occupation
            = the_board[the_move->rank + i][ftoi - i]->occupation;
          the_board[the_move->rank + i][ftoi - i]->occupation = NULL;
          return;
        // - + Diagonal (valid ? check bishop : 0)
        } else if(MP_DIAG(the_move, the_board, i, i, BISHOP, piece_color)) {
          the_board[the_move->rank][ftoi]->occupation
            = the_board[the_move->rank - i][ftoi + i]->occupation;
          the_board[the_move->rank - i][ftoi + i]->occupation = NULL;
          return;
        }
      break;
    case KNIGHT:
      break;
    case PAWN:
      break;
  }
}

void free_move(move * the_move) {
  if(the_move)
    free(the_move);
}
