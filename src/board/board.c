#include "include/board.h"

board * init_board(void) {
  board * the_board = calloc(1, sizeof(struct BOARD_T));
  the_board->squares = calloc(RANKS, sizeof(struct SQUARE_T **));
  for(int i = 0; i < RANKS; i++)
    the_board->squares[i] = calloc(FILES, sizeof(struct SQUARE_T *));
  for(int i = 0; i < RANKS; i++)
    for(int j = 0; j < FILES; j++)
      the_board->squares[i][j] = init_square((char)(j + 97), i,
          (i + j) % 2 ? BLACK : WHITE);
  the_board->white = init_player(the_board->squares, WHITE);
  the_board->black = init_player(the_board->squares, BLACK);
  return the_board;
}

void debug_board(board * the_board) {
  for(int i = 0; i < RANKS; i++) {
    for(int j = 0; j < FILES; j++)
      if(the_board->squares[i][j]->occupation)
        print_piece_char(the_board->squares[i][j]->occupation);
      else
        printf("+");
    printf("\n");
  }
}

void print_piece_char(piece * the_piece) {
  printf("%s", the_piece->piece_color ? BLACK_P : WHITE_P);
  printf("%c", piece_type_char(the_piece->type));
  printf(END_P);
}

void free_board(board * the_board) {
  if(the_board) {
    if(the_board->white)
      free_player(the_board->white);
    if(the_board->black)
      free_player(the_board->black);
    if(the_board->squares) {
      for(int i = 0; i < RANKS; i++) {
        for(int j = 0; j < FILES; j++) {
          if(the_board->squares[i][j])
            free_square(the_board->squares[i][j]);
        }
        if(the_board->squares[i])
          free(the_board->squares[i]);
      }
      free(the_board->squares);
    }
    free(the_board);
  }
}
