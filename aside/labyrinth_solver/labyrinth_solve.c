/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-25 - 09:13 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: moving radar
 */

#include "labyrinth_solver.h"

int labyrinth_solve(struct map *map,
          t_accurate_pos pos,
          t_bunny_window *win,
          t_bunny_pixelarray *px)
{
    double direction;
    int round;

    round = 0;
    direction = 0.5 * M_PI;
    while (direction != 1) {
        refresh_map(map, px);
        if (moving(map, &pos, &direction) == 2) {
            draw_level_end(*map, px, win, 3);
            return 2;
        }
        div_or_mult_pos(&pos, map->tile_size, '*');
        draw_pacman(px, pos, direction, map->tile_size / 4);
        div_or_mult_pos(&pos, map->tile_size, '/');
        refresh(win, px);
        //bunny_usleep(1e3);
        round += 1;
    }
    return round;
}
