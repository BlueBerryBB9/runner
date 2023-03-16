/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-27 - 09:50 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: radar include
 */

#include <lapin.h>
#include <math.h>
#include "map.h"

#ifndef LABYRINTH_SOLVER_H_

#define LABYRINTH_SOLVER_H_

typedef t_bunny_accurate_position t_accurate_pos;

/*
 * struct map {
 *     int tile_size;
 *     int width;
 *     int height;
 *     int *map;
 * };
 */

int change_dir(struct map *map,
               t_accurate_pos *pos,
               double *dir);

void draw_pacman(t_bunny_pixelarray *px,
                 t_accurate_pos pos,
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

int check_nb(int nb, double *dir);

void draw_level_end(struct map map,
                    t_bunny_pixelarray *px,
                    t_bunny_window *win,
                    int time);

t_bunny_position give_acc_pos(t_accurate_pos *pos, double angle);

int labyrinth_solve(struct map *map,
                    t_accurate_pos pos,
                    t_bunny_window *win,
                    t_bunny_pixelarray *px);

int moving(struct map *map,
           t_accurate_pos *pos,
           double *dir);

t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,
                            double len);

t_bunny_position pos_from_accurate(const t_accurate_pos *start);

void div_or_mult_pos(t_accurate_pos *pos, int coef, char c);

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);

/*
 * void draw_map(struct map *map, t_bunny_pixelarray *px);
 */

void refresh(t_bunny_window *win, t_bunny_pixelarray *px);

/*
 * void refresh_map(struct map *map, t_bunny_pixelarray *px);
 */

#endif
