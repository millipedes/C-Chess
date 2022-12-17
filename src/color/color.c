#include "include/color.h"

const char * color_to_string(color the_color) {
  switch(the_color) {
    case WHITE: return "White";
    case BLACK: return "Black";
  }
  return NULL;
}
