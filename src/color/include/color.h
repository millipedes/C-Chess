#ifndef COL_H
#define COL_H

#include <stdlib.h>

typedef enum {
  WHITE,
  BLACK
} color;

const char * color_to_string(color the_color);

#endif
