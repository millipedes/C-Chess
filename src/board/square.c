#include "include/square.h"

square * init_square(char file, int rank, color square_color) {
  square * the_square = calloc(1, sizeof(struct SQUARE_T));
  the_square->file = file;
  the_square->rank = rank;
  the_square->occupation = NULL;
  the_square->square_color = square_color;
  return the_square;
}

void debug_square(square * the_square) {
  printf("[SQUARE]:\n");
  printf("%c%d, %s\n", the_square->file, the_square->rank,
      color_to_string(the_square->square_color));
}

void free_square(square * the_square) {
  if(the_square) {
    // Board responsible for freeing pieces
    if(the_square->occupation)
      the_square->occupation = NULL;
    free(the_square);
  }
}
