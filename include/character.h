/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-13 - 11:07 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw pacan function
 */

#include <lapin.h>
#include <math.h>

#ifndef CHARACTER_H_

#define CHARACTER_H_

void draw_pacman(t_bunny_pixelarray *px,
                   t_bunny_position pos,
                   double direction,
                   int radius);

void stu_set_circle(t_bunny_pixelarray *pxa,
                    int x,
                    int y,
                    int radius,
                    int colour);

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);

#endif
