/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-27 - 09:50 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: radar include
 */

#include "graphic.h"

#ifndef RADAR_H_

#define RADAR_H_

int change_dir(struct map *map,
                 t_accurate_pos *pos,
               double *dir);

int check_nb(int nb, double *dir);

t_bunny_position give_t_pos(t_accurate_pos *pos, double angle);

int moving(struct map *map,
           t_accurate_pos *pos,
           double *dir);

int labyrinth_solve(struct map *map,
                    t_accurate_pos *pos,
                    t_bunny_window *win,
                    t_bunny_pixelarray *px);

#endif
