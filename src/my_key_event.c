/*
 * E89 Pedagogical & Technical Lab
 * project:     Runner
 * created on:  2023-02-20 - 09:05 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: my key event
 */

#include "graphic.h"

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

t_bunny_response my_key_event(t_bunny_event_state state,
                              t_bunny_keysym keycode,
                              void *data)
{
    struct display *ds;
    //t_bunny_position bpos;
    t_accurate_pos send_pos;

    ds = data;
    send_pos = ds->pos;
    if (state == GO_UP){
        return (GO_ON);
    }
    if (keycode == BKS_ESCAPE){
        return (EXIT_ON_SUCCESS);
    }
    make_keys(keycode, ds);
    wall_collision(&ds->map, &ds->pos, send_pos);
    if (if_end(ds) == 1) {
        return (EXIT_ON_SUCCESS);
    }
    refresh_map(&ds->map, ds->px);
    first_person(ds, ds->fov);
    refresh(ds->win_fp, ds->px_fp);
    //draw_pacman(ds->px, ds->pos, ds->direction, ds->map.tile_size / 5);
    /*
     * bpos = pos_from_accurate(&ds->pos);
     * put_pixel(ds->px, &bpos, GREEN);
     */
    refresh(ds->win, ds->px);
    return (GO_ON);
}
