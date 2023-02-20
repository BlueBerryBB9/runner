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
    t_bunny_position npos;
    t_bunny_position old;

    ds = data;
    npos = pos_from_accurate(&ds->pos);
    old = npos;
    printf("keycode: %d\n state %d\n posy %f\n", keycode, state, ds->pos.y);
    if (state == GO_UP){
        return (GO_ON);
    }
    if (keycode == BKS_ESCAPE){
        return (EXIT_ON_SUCCESS);
    }
        if (keycode == BKS_UP) {
        ds->pos.y -= 50;
    } else if (keycode == BKS_LEFT) {
        ds->pos.x -= 50;
    } else if (keycode == BKS_RIGHT) {
        ds->pos.x += 50;
    } else if (keycode == BKS_DOWN) {
        ds->pos.y += 50;
    } else if (keycode == BKS_Z) {
        ds->pos.y -= 10;
    } else if (keycode == BKS_Q) {
        ds->pos.x -= 10;
    } else if (keycode == BKS_S) {
        ds->pos.y += 10;
    } else if (keycode == BKS_D) {
        ds->pos.x += 10;
    }
    npos = pos_from_accurate(&ds->pos);
    if (ds->map.map[(ds->map.width
                     * ((int) npos.y / ds->map.tile_size))
                    + ((int) npos.x/ ds->map.tile_size)] == 2) {
        draw_level_end(ds->map, ds->px, ds->win, 3);
        return 2;
    }
    if (ds->map.map[(ds->map.width
                     * ((int) npos.y / ds->map.tile_size))
                    + ((int) npos.x/ ds->map.tile_size)] == 1) {
        npos.x = old.x;
        npos.y = old.y;
    }
    refresh_map(&ds->map, ds->px);
    draw_pacman(ds->px, npos, 0, 20);
    refresh(ds->win, ds->px);
    return (GO_ON);
}
