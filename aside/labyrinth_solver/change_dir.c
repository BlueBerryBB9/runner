/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-27 - 09:42 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: change direction
 */

#include "labyrinth_solver.h"

int change_dir(struct map *map,
                 t_accurate_pos *pos,
                 double *dir)
{
    int nb;

    nb = 0;
    if (map->map[(map->width * ((int) pos->y - 1)) + (int) pos->x] == 1) {
        nb += 1000;
    }
    if (map->map[(map->width * ((int) pos->y + 1)) + (int) pos->x] == 1) {
        nb += 100;
    }
    if (map->map[(map->width * (int) pos->y) + ((int) pos->x + 1)] == 1) {
        nb += 10;
    }
    if (map->map[(map->width * (int) pos->y) + ((int) pos->x - 1)] == 1) {
        nb += 1;
    }
    check_nb(nb, dir);
    return nb;
}
