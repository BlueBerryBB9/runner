/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-13 - 11:07 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw pacan function
 */

#include <lapin.h>

#ifndef CHARACTER_H_

#define CHARACTER_H_

void draw_pacman(t_bunny_pixelarray *px,
                   t_bunny_position pos,
                   double direction,
                   int radius);

#endif
