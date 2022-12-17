#include "include/player.h"

player * init_player(square *** board, color piece_color) {
  player * the_player = calloc(1, sizeof(struct PLAYER_T));
  the_player->piece_color = piece_color;
  int offset = 0;
  // If player's pieces are white, put them @ bottom of board
  if(!the_player->piece_color)
    offset = 6;
  else
    offset = 1;
  the_player->qty_queen = 0;
  the_player->qty_rook = 0;
  the_player->qty_bishop = 0;
  the_player->qty_knight = 0;
  the_player->qty_pawn = 0;
  the_player->move_no = 0;
  // Pawns
  for(int i = 0; i < FILES; i++)
    add_piece(the_player, PAWN, board[offset][i]);
  // Rooks
  add_piece(the_player, ROOK, board[offset==6 ? offset + 1 : offset - 1][0]);
  add_piece(the_player, ROOK, board[offset==6 ? offset + 1 : offset - 1][7]);
  // Knights
  add_piece(the_player, KNIGHT, board[offset==6 ? offset + 1 : offset - 1][1]);
  add_piece(the_player, KNIGHT, board[offset==6 ? offset + 1 : offset - 1][6]);
  // Bishops
  add_piece(the_player, BISHOP, board[offset==6 ? offset + 1 : offset - 1][2]);
  add_piece(the_player, BISHOP, board[offset==6 ? offset + 1 : offset - 1][5]);
  // Queen
  add_piece(the_player, QUEEN, board[offset==6 ? offset + 1 : offset - 1][3]);
  // King
  add_piece(the_player, QUEEN, board[offset==6 ? offset + 1 : offset - 1][4]);
  return the_player;
}

player * add_piece(player * the_player, piece_type type, square * the_square) {
  switch(type) {
    case KING:
      the_player->king = init_piece(KING, the_player->piece_color);
      the_square->occupation = the_player->king;
      break;
    case QUEEN:
      the_player->qty_queen++;
      if(!the_player->queen)
        the_player->queen = calloc(1, sizeof(struct PIECE_T *));
      else
        the_player->queen = realloc(the_player->queen, the_player->qty_queen
            * sizeof(struct PIECE_T *));
      the_player->queen[the_player->qty_queen - 1] = init_piece(QUEEN,
          the_player->piece_color);
      the_square->occupation = the_player->queen[the_player->qty_queen - 1];
      break;
    case ROOK:
      the_player->qty_rook++;
      if(!the_player->rook)
        the_player->rook = calloc(1, sizeof(struct PIECE_T *));
      else
        the_player->rook = realloc(the_player->rook, the_player->qty_rook
            * sizeof(struct PIECE_T *));
      the_player->rook[the_player->qty_rook - 1] = init_piece(ROOK,
          the_player->piece_color);
      the_square->occupation = the_player->rook[the_player->qty_rook - 1];
      break;
    case BISHOP:
      the_player->qty_bishop++;
      if(!the_player->bishop)
        the_player->bishop = calloc(1, sizeof(struct PIECE_T *));
      else
        the_player->bishop = realloc(the_player->bishop, the_player->qty_bishop
            * sizeof(struct PIECE_T *));
      the_player->bishop[the_player->qty_bishop - 1] = init_piece(BISHOP,
          the_player->piece_color);
      the_square->occupation = the_player->bishop[the_player->qty_bishop - 1];
      break;
    case KNIGHT:
      the_player->qty_knight++;
      if(!the_player->knight)
        the_player->knight = calloc(1, sizeof(struct PIECE_T *));
      else
        the_player->knight = realloc(the_player->knight, the_player->qty_knight
            * sizeof(struct PIECE_T *));
      the_player->knight[the_player->qty_knight - 1] = init_piece(KNIGHT,
          the_player->piece_color);
      the_square->occupation = the_player->knight[the_player->qty_knight - 1];
      break;
    case PAWN:
      the_player->qty_pawn++;
      if(!the_player->pawn)
        the_player->pawn = calloc(1, sizeof(struct PIECE_T *));
      else
        the_player->pawn = realloc(the_player->pawn, the_player->qty_pawn
            * sizeof(struct PIECE_T *));
      the_player->pawn[the_player->qty_pawn - 1] = init_piece(PAWN,
          the_player->piece_color);
      the_square->occupation = the_player->pawn[the_player->qty_pawn - 1];
      break;
  }
  return the_player;
}

// player * remove_piece(player * the_player, piece_type type,
//     square * occupation) {
// }

void debug_player(player * the_player) {
  printf("[PLAYER]: %s\n", color_to_string(the_player->piece_color));
  printf("Move No: %d\n", the_player->move_no);
  printf("[King]\n");
  debug_piece(the_player->king);
  printf("[Queen]: %d\n", the_player->qty_queen);
  for(int i = 0; i < the_player->qty_queen; i++)
    debug_piece(the_player->queen[i]);
  printf("[Rook]: %d\n", the_player->qty_rook);
  for(int i = 0; i < the_player->qty_rook; i++)
    debug_piece(the_player->rook[i]);
  printf("[Bishop]: %d\n", the_player->qty_bishop);
  for(int i = 0; i < the_player->qty_bishop; i++)
    debug_piece(the_player->bishop[i]);
  printf("[Knight]: %d\n", the_player->qty_knight);
  for(int i = 0; i < the_player->qty_knight; i++)
    debug_piece(the_player->knight[i]);
  printf("[Pawn]: %d\n", the_player->qty_pawn);
  for(int i = 0; i < the_player->qty_pawn; i++)
    debug_piece(the_player->pawn[i]);
}

void free_player(player * the_player) {
  if(the_player) {
    if(the_player->king)
      free_piece(the_player->king);
    if(the_player->queen) {
      for(int i = 0; i < the_player->qty_queen; i++)
        if(the_player->queen)
          free_piece(the_player->queen[i]);
      free(the_player->queen);
    }
    if(the_player->rook) {
      for(int i = 0; i < the_player->qty_rook; i++)
        if(the_player->rook)
          free_piece(the_player->rook[i]);
      free(the_player->rook);
    }
    if(the_player->bishop) {
      for(int i = 0; i < the_player->qty_bishop; i++)
        if(the_player->bishop)
          free_piece(the_player->bishop[i]);
      free(the_player->bishop);
    }
    if(the_player->knight) {
      for(int i = 0; i < the_player->qty_knight; i++)
        if(the_player->knight)
          free_piece(the_player->knight[i]);
      free(the_player->knight);
    }
    if(the_player->pawn) {
      for(int i = 0; i < the_player->qty_pawn; i++)
        if(the_player->pawn)
          free_piece(the_player->pawn[i]);
      free(the_player->pawn);
    }
    free(the_player);
  }
}
