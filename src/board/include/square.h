#ifndef SQR_H
#define SQR_H

#include <stdio.h>

#include "../../color/include/color.h"
#include "../../player/include/piece.h"

typedef struct SQUARE_T {
  piece * occupation;
  color square_color;
  int rank;
  char file;
} square;

square * init_square(char file, int rank, color square_color);
void debug_square(square * the_square);
void free_square(square * the_square);

#endif
