#include "include/move_processor.h"

move * init_move(char file, int rank, piece_type type) {
  move * the_move = calloc(1, sizeof(struct MOVE_T));
  the_move->file = file;
  the_move->rank = rank;
  the_move->type = type;
  return the_move;
}

void debug_move(move * the_move) {
  printf("[MOVE]\n");
  printf("%c%d %s\n", the_move->file, the_move->rank,
      piece_type_to_string(the_move->type));
}

void find_piece(move * the_move, square *** the_board) {
  int ftoi = (int)(the_move->file - 97);
  switch(the_move->type) {
    case KING:
      // return the_player->king;
      break;
    case QUEEN:
      for(int i = 0; i < RANKS; i++)
        for(int j = 0; j < FILES; j++) {
          // Rank
          if(the_board[i][ftoi]->occupation->type == QUEEN) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[i][ftoi]->occupation;
            the_board[i][ftoi]->occupation = NULL;
            break;
          // File
          } else if(the_board[the_move->rank][j]->occupation->type == QUEEN) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank][j]->occupation;
            the_board[the_move->rank][j]->occupation = NULL;
            break;
          // + + Diagonal (valid ? check queen : 0)
          } else if(PP_DIAG(the_move, the_board, i, j, QUEEN)) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank + i][ftoi + j]->occupation;
            the_board[the_move->rank + i][ftoi + j]->occupation = NULL;
            break;
          // - - Diagonal (valid ? check queen : 0)
          } else if(MM_DIAG(the_move, the_board, i, j, QUEEN)) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank - i][ftoi - j]->occupation;
            the_board[the_move->rank - i][ftoi - j]->occupation = NULL;
            break;
          // + - Diagonal (valid ? check queen : 0)
          } else if(PM_DIAG(the_move, the_board, i, j, QUEEN)) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank + i][ftoi - j]->occupation;
            the_board[the_move->rank + i][ftoi - j]->occupation = NULL;
            break;
          // - + Diagonal (valid ? check queen : 0)
          } else if(MP_DIAG(the_move, the_board, i, j, QUEEN)) {
            the_board[the_move->rank][ftoi]->occupation
              = the_board[the_move->rank - i][ftoi + j]->occupation;
            the_board[the_move->rank - i][ftoi + j]->occupation = NULL;
            break;
          }
        }
      break;
    case ROOK:
      break;
    case BISHOP:
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

// board * move(board * the_board, char * the_move) {
//   // Is first char lower case ? => pawn move : => Piece Move
//   if(the_move[0] >= 97 || the_move[0] <= 122) {
//     if(the_move[1] != 'x') {
//     }
//   }
// }
