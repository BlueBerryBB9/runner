/*
 * E89 Pedagogical & Technical Lab
 * project:     radar
 * created on:  2023-02-14 - 16:58 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: radar include
 */

#include <lapin.h>
#include <math.h>
#include "map.h"

#ifndef RADAR_H_

#define RADAR_H_

typedef t_bunny_accurate_position t_accurate_pos;

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);

void div_or_mult_pos(t_accurate_pos *pos, int coef, char c);

t_bunny_position pos_from_accurate(const t_accurate_pos *start);

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle);

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);

void refresh(t_bunny_window *win, t_bunny_pixelarray *px);

#endif
