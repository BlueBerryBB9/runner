/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 15:52 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: first person
 */

#include "graphic.h"

/*
 * static void clear_column(struct display *ds, int height)
 * {
 *     
 * }
 */

/*
 * static void draw_column(struct display *ds, int height, int column)
 * {
 *     if (height > ds->win_fp->buffer.height) {
 *         height = ds->win_fp->buffer.height;
 *     }
 *     clear_column(ds, height);
 * }
 */

static int draw_wall(struct display *ds, int fov)
{
    double dir;
    t_bunny_position send_pos;
    t_bunny_position pos;
    t_accurate_pos acc_pos;
    int height;
    int column_nb;

    column_nb = 0;
    dir = -1 * deg_to_rads(fov / 2);
    pos = pos_from_accurate(&ds->pos);
    while (ds->direction + dir <= ds->direction + deg_to_rads(fov / 2)) {
        acc_pos = send_ray_draw_wall(&ds->map,
                                     &ds->pos,
                                     ds->direction + dir,
                                     ds);
        height = (ds->win_fp->buffer.height * ds->map.tile_size) / ds->count;
        //draw_column(ds, height, column_nb);
        send_pos = pos_from_accurate(&acc_pos);
        stu_draw_line(ds->px, &pos, &send_pos, WHITE);
        dir += deg_to_rads((fov * 2)) / 90;
        column_nb += 1;
    }
    printf("%d\n", height);
    return height;
}

int first_person(struct display *ds, int fov)
{
    draw_background(ds);
    draw_wall(ds, fov);
    return fov;
}
