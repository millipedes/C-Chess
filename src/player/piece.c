#include "include/piece.h"

piece * init_piece(piece_type type, color piece_color) {
  piece * the_piece = calloc(1, sizeof(struct PIECE_T));
  the_piece->piece_color = piece_color;
  the_piece->type = type;
  the_piece->has_moved = 0;
  return the_piece;
}

void debug_piece(piece * the_piece) {
  printf("[PIECE]\n");
  printf("%s\n", the_piece->has_moved ? "Has Moved" : "Has Not Moved");
  printf("%s\n", piece_type_to_string(the_piece->type));
  printf("%s\n", color_to_string(the_piece->piece_color));
}

void free_piece(piece * the_piece) {
  if(the_piece)
    free(the_piece);
}
