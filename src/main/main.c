#include "../move_processing/include/move_processor.h"

int main(void) {
  board * the_board = init_board();
  find_piece(init_move('a', 5, QUEEN), the_board->squares, BLACK);
  // find_piece(init_move('e', 1, QUEEN), the_board->squares, BLACK);
  find_piece(init_move('h', 4, QUEEN), the_board->squares, BLACK);
  find_piece(init_move('h', 5, QUEEN), the_board->squares, BLACK);
  find_piece(init_move('a', 3, BISHOP), the_board->squares, WHITE);
  find_piece(init_move('c', 5, BISHOP), the_board->squares, WHITE);
  find_piece(init_move('e', 3, BISHOP), the_board->squares, WHITE);
  find_piece(init_move('a', 4, ROOK), the_board->squares, WHITE);
  find_piece(init_move('b', 4, ROOK), the_board->squares, WHITE);
  find_piece(init_move('a', 4, QUEEN), the_board->squares, WHITE);
  find_piece(init_move('a', 4, QUEEN), the_board->squares, WHITE);
  // find_piece(init_move('a', 4, ROOK), the_board->squares, WHITE);
  // find_piece(init_move('a', 1, ROOK), the_board->squares, WHITE);
  // find_piece(init_move('a', 4, QUEEN), the_board->squares, BLACK);
  // find_piece(init_move('e', 8, QUEEN), the_board->squares);
  // find_piece(init_move('e', 3, QUEEN), the_board->squares);
  debug_board(the_board);
  free_board(the_board);
  return 0;
}
