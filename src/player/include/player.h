#ifndef PLR_H
#define PLR_H

#include "piece.h"
#include "../../main/include/constants_macros.h"
#include "../../board/include/square.h"

typedef struct PLAYER_T {
  piece * king;
  piece ** queen;
  piece ** rook;
  piece ** bishop;
  piece ** knight;
  piece ** pawn;
  color piece_color;
  int qty_queen;
  int qty_rook;
  int qty_bishop;
  int qty_knight;
  int qty_pawn;
  int move_no;
} player;

player * init_player(square *** board, color piece_color);
player * add_piece(player * the_player, piece_type type, square * the_square);
// player * remove_piece(player * the_player, piece_type type,
//     square * occupation);
void debug_player(player * the_player);
void free_player(player * the_player);

#endif
