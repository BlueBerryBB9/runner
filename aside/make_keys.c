/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-20 - 09:37 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: make kays act
 */

#include "graphic.h"

void make_keys(t_bunny_event_state state,
               t_bunny_keysim keycode,
               struct display *ds)
{
    
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
