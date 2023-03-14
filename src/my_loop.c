/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-14 - 14:23 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: loop
 */

#include "graphic.h"
#include "color.h"

static void wall_collision(struct map *map,
                           t_accurate_pos *pos,
                           t_accurate_pos send_pos)
{
    if (((int) pos->x / map->tile_size) > map->width
        && ((int) pos->y / map->tile_size) > map->height
        && ((int) pos->x / map->tile_size) < 0
        && ((int) pos->y / map->tile_size) < 0) {
        pos->x = send_pos.x;
        pos->y = send_pos.y;
        return;
    }
    if (map->map[(map->width
                  * ((int) pos->y / map->tile_size))
                 + ((int) pos->x / map->tile_size)] == 1) {
        pos->x = send_pos.x;
        pos->y = send_pos.y;
        return;
    }
}

static int if_end(struct display *ds)
{
    if (ds->map.map[(ds->map.width
                     * ((int) ds->pos.y / ds->map.tile_size))
                    + ((int) ds->pos.x / ds->map.tile_size)] == 2) {
        draw_level_end(ds->map, ds->px, ds->win, 3);
        return 1;
    }
    return 0;
}

t_bunny_response my_loop(void *data)
{
    struct display *ds;
    const bool *keys;
    t_accurate_pos send_pos;

    ds = data;
    keys = bunny_get_keyboard();
    if (keys[BKS_ESCAPE]) {
        return (EXIT_ON_SUCCESS);
    }
    make_keys_loop(keys, ds);
    wall_collision(&ds->map, &ds->pos, send_pos);
    if (if_end(ds) == 1) {
        return (EXIT_ON_SUCCESS);
    }
    refresh_map(&ds->map, ds->px);
    first_person(ds, ds->fov);
    refresh(ds->win_fp, ds->px_fp);
    draw_pacman(ds->px, ds->pos, ds->direction, ds->map.tile_size / 5);
    refresh(ds->win, ds->px);
    return (GO_ON);
}
