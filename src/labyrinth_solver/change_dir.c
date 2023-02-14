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
    t_bunny_position n;
    t_bunny_position s;
    t_bunny_position e;
    t_bunny_position o;

    nb = 0;
    n = give_t_pos(pos, 1.5 * M_PI);
    s = give_t_pos(pos, 0.5 * M_PI);
    e = give_t_pos(pos, 2 * M_PI);
    o = give_t_pos(pos, M_PI);
    if (map->map[(map->width * n.y) + n.x] == 1) {
        nb += 1000;
    }
    if (map->map[(map->width * s.y) + s.x] == 1) {
        nb += 100;
    }
    if (map->map[(map->width * e.y) + e.x] == 1) {
        nb += 10;
    }
    if (map->map[(map->width * o.y) + o.x] == 1) {
        nb += 1;
    }
    check_nb(nb, dir);
    return nb;
}
