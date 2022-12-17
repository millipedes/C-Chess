#include "../board/include/board.h"

int main(void) {
  board * the_board = init_board();
  debug_board(the_board);
  free_board(the_board);
  return 0;
}
