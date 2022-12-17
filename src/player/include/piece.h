#ifndef SRC_H
#define SRC_H

#include <stdio.h>

#include "piece_type.h"
#include "../../color/include/color.h"

typedef struct PIECE_T {
  piece_type type;
  color piece_color;
} piece;

piece * init_piece(piece_type type, color piece_color);
void debug_piece(piece * the_piece);
void free_piece(piece * the_piece);

#endif
