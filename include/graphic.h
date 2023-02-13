/*
 * E89 Pedagogical & Technical Lab
 * project:     tp laser
 * created on:  2023-01-16 - 15:24 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: include
 */

#include <lapin.h>
#include <math.h>
#include "map.h"

#ifndef GRAPHIC_H_

#define GRAPHIC_H_

typedef t_bunny_accurate_position t_accurate_pos;

#include "labyrinth_solver.h"
#include "draw_pacman.h"

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);

void stu_set_circle(t_bunny_pixelarray *pxa,
                    int x,
                    int y,
                    int radius,
                    int colour);

void draw_impact(struct map *map,
                 t_bunny_pixelarray *pxa,
                 const t_accurate_pos *start, double angle);

void draw_map(struct map *map, t_bunny_pixelarray *px);

void put_pixel(t_bunny_pixelarray *px,
               t_bunny_position *pos,
               unsigned int color);

void draw_block(struct map *map,
                       t_bunny_pixelarray *px,
                       t_bunny_position origin,
                       unsigned int color);

int radar(struct map *map,
          t_accurate_pos *pos,
          t_bunny_window *win,
          t_bunny_pixelarray *px);

void refresh(t_bunny_window *win, t_bunny_pixelarray *px);


void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);

void div_or_mult_pos(t_accurate_pos *pos, int coef, char c);

t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,
                            double len);

t_bunny_position pos_from_accurate(const t_accurate_pos *start);

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle);

float get_ratio(int a, int b, int x);

int get_value(int a, int b, float ratio);

double deg_to_rads(int degrees);

#endif
