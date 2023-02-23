/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 15:52 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: first person
 */

#include "graphic.h"

static void draw_wall(struct display *ds, int fov)
{
    double dir;
    t_bunny_position pos;
    t_accurate_pos acc_pos;

    dir = -1 * deg_to_rads(fov);
    while (ds->direction + dir <= ds->direction + deg_to_rads(fov)) {
        div_or_mult_pos(&ds->pos, ds->map.tile_size, '/');
        acc_pos = send_ray(&ds->map, &ds->pos, ds->direction);
        div_or_mult_pos(&ds->pos, ds->map.tile_size, '*');
        div_or_mult_pos(&acc_pos, ds->map.tile_size, '*');
        pos = pos_from_accurate(&acc_pos);
        put_pixel(ds->px_fp, &pos, RED);
        dir += deg_to_rads((fov * 2)) / 45;
    }
}


int first_person(struct display *ds, int fov)
{
    draw_background(ds);
    draw_wall(ds, fov);
    return fov;
}
