/*
 * E89 Pedagogical & Technical Lab
 * project:     Runner
 * created on:  2023-02-20 - 09:05 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: my key event
 */

#include "graphic.h"

t_bunny_response my_key_event(t_bunny_event_state state,
                              t_bunny_keysym keycode,
                              void *data)
{
    struct display *ds;
    t_accurate_pos send_pos;
    t_bunny_position bpos;

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
    if (ds->map.map[(ds->map.width
                     * ((int) ds->pos.y / ds->map.tile_size))
                    + ((int) ds->pos.x / ds->map.tile_size)] == 2) {
        draw_level_end(ds->map, ds->px, ds->win, 3);
        return 2;
    }
    if (ds->map.map[(ds->map.width
                     * ((int) ds->pos.y / ds->map.tile_size))
                    + ((int) ds->pos.x / ds->map.tile_size)] == 1) {
        ds->pos.x = send_pos.x;
        ds->pos.y = send_pos.y;
    }
    refresh_map(&ds->map, ds->px);
    //draw_map(&ds->map, ds->px);
    //draw_pacman(ds->px, ds->pos, ds->direction, 20);
    bpos = pos_from_accurate(&ds->pos);
    put_pixel(ds->px, &bpos, RED);
    refresh(ds->win, ds->px);
    return (GO_ON);
}
