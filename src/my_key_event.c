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
    if (map->map[(map->width
                     * ((int) pos->y / map->tile_size))
                    + ((int) pos->x / map->tile_size)] == 1) {
        pos->x = send_pos.x;
        pos->y = send_pos.y;
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
    t_bunny_position bpos;
    t_accurate_pos send_pos;

    ds = data;
    send_pos = ds->pos;
    //printf("keycode: %d\n state %d\nposy %f\nposx %f\n", keycode, state, ds->pos.y, ds->pos.x);
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
    //first_person(ds);
    refresh_map(&ds->map, ds->px);
    //draw_pacman(ds->px, ds->pos, ds->direction, 12);
    bpos = pos_from_accurate(&ds->pos);
    put_pixel(ds->px, &bpos, RED);
    refresh(ds->win, ds->px);
    return (GO_ON);
}
