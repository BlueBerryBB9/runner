/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 15:52 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: first person
 */

#include "graphic.h"

/*
 * static void found_height(t_accurate_pos *acc_pos)
 * {
 *     if (!acc_pos)
 *         return;
 *     return;
 * }
 */

static void draw_wall(struct display *ds, int fov)
{
    double dir;
    t_bunny_position send_pos;
    t_bunny_position pos;
    t_accurate_pos acc_pos;

    dir = -1 * deg_to_rads(fov);
    pos = pos_from_accurate(&ds->pos);
    while (ds->direction + dir <= ds->direction + deg_to_rads(fov)) {
        //div_or_mult_pos(&ds->pos, ds->map.tile_size, '/');
        acc_pos = send_ray_draw_wall(&ds->map,
                                     &ds->pos,
                                     ds->direction + dir,
                                     ds);
        printf("x %f\ny %f\n", acc_pos.x, acc_pos.y);
        //div_or_mult_pos(&ds->pos, ds->map.tile_size, '*');
        //div_or_mult_pos(&acc_pos, ds->map.tile_size, '*');
        //found_height(&acc_pos);
        send_pos = pos_from_accurate(&acc_pos);
        stu_draw_line(ds->px, &pos, &send_pos, RED);
        dir += deg_to_rads((fov * 2)) / 45;
    }
}


int first_person(struct display *ds, int fov)
{
    draw_background(ds);
    draw_wall(ds, fov);
    return fov;
}
