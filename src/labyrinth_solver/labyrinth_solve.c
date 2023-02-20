/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-25 - 09:13 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: moving radar
 */

#include "labyrinth_solver.h"
#include "stdio.h"

/*
 * static void fix_angle(double *angle, double direction)
 * {
 *     if (direction == 0.5 * M_PI || direction == 1.5 * M_PI) {
 *         *angle = direction + M_PI;
 *     } else {
 *         *angle = direction;
 *     }
 * }
 */

int labyrinth_solve(struct map *map,
          t_accurate_pos pos,
          t_bunny_window *win,
          t_bunny_pixelarray *px)
{
    double direction;
    t_bunny_position bpos;

    direction = 0;
    while (direction != 1) {
        refresh_map(map, px);
        if (moving(map, &pos, &direction) == 2) {
            //draw_level_end(*map, px, win, 3);
            return 2;
        }
        div_or_mult_pos(&pos, map->tile_size, '*');
        bpos = pos_from_accurate(&pos);
        div_or_mult_pos(&pos, map->tile_size, '/');
        draw_pacman(px, bpos, direction, map->tile_size / 4);
        refresh(win, px);
        //bunny_usleep(1e3);
    }
    return 0;
}
