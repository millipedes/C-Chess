#include "include/piece_type.h"

const char * piece_type_to_string(piece_type the_piece_type) {
  switch(the_piece_type) {
    case KING:   return "King";
    case QUEEN:  return "Queen";
    case ROOK:   return "Rook";
    case BISHOP: return "Bishop";
    case KNIGHT: return "Knight";
    case PAWN:   return "Pawn";
  }
  return NULL;
}

char piece_type_char(piece_type the_piece_type) {
  switch(the_piece_type) {
    case KING:   return 'K';
    case QUEEN:  return 'Q';
    case ROOK:   return 'R';
    case BISHOP: return 'B';
    case KNIGHT: return 'K';
    case PAWN:   return 'P';
  }
  return ' ';
}
