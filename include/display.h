/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-17 - 14:40 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: display structure
 */

#include <lapin.h>
#include "map.h"

#ifndef DISPLAY_H_

#define DISPLAY_H_

typedef t_bunny_accurate_position t_accurate_pos;

struct col {
    int up;
    int bottom;
    int wall;
    int crosshair;
};

struct display {
    t_bunny_window *win;
    t_bunny_pixelarray *px;

    struct col col;

    t_accurate_pos pos;
    struct map map;

    double direction;
    double step;
    double count;
    int fov;
    int coef;
};

#endif
