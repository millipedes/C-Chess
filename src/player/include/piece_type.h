#ifndef PTYP_H
#define PTYP_H

#include <stdlib.h>

typedef enum {
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN
} piece_type;

const char * piece_type_to_string(piece_type the_piece_type);
char piece_type_char(piece_type the_piece_type);

#endif
