/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-27 - 09:44 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: change pos
 */

#include "graphic.h"

int moving(struct map *map,
           t_accurate_pos *pos,
           double *dir)
{
    if (map->map[(map->width * (int) pos->y) + (int) pos->x] == 2) {
        return 2;
    }
    if (*dir == 0.5 * M_PI) {
        pos->y -= 1;
    } else if (*dir == 0 || *dir == 2 * M_PI) {
        pos->x += 1;
    } else if (*dir == 1.5 * M_PI) {
        pos->y += 1;
    } else if (*dir == M_PI) {
        pos->x -= 1;
    }
    change_dir(map, pos, dir);
        return *dir;
}
