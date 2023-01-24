/*
 * E89 Pedagogical & Technical Lab
 * project:     tp laser
 * created on:  2023-01-16 - 15:24 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: include
 */

#include <lapin.h>
#include <math.h>
#include <stdio.h>
#include "map.h"

#ifndef LASER_H_

#define LASER_H_

typedef t_bunny_accurate_position t_accurate_pos;

t_accurate_pos move_forward(const t_accurate_pos *start,
                            double               angle,
                            double               len);

t_bunny_position pos_from_accurate(const t_accurate_pos *start);

void put_pixel(t_bunny_pixelarray *px,
               t_bunny_position *pos,
               unsigned int color);

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle);

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle);

void draw_impact(struct map *map,
                 t_bunny_pixelarray *pxa,
                 const t_accurate_pos *start, double angle);

t_accurate_pos div_or_mult_pos(t_accurate_pos *pos, int coef, char c);

#endif
