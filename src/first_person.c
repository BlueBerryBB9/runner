/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 15:52 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: first person
 */

#include "graphic.h"

static void clear_column(struct display *ds, double height, int column)
{
    t_bunny_position pos;
    t_bunny_position bpos;

    if (height > ds->win_fp->buffer.height) {
        height = ds->win_fp->buffer.height;
    }
    pos.x = column;
    pos.y = ((ds->win_fp->buffer.height - height) / 2);
    bpos.x = column;
    bpos.y = ds->win_fp->buffer.height - pos.y;
    stu_draw_line(ds->px_fp, &pos, &bpos, WHITE);
}

static int draw_wall(struct display *ds, int fov)
{
    double dir;
    double height;
    int column;

    column = 0;
    dir = -1 * deg_to_rads(fov / 2);
    while (ds->direction + dir <= ds->direction + deg_to_rads(fov / 2)
           || column <=ds->win_fp->buffer.width) {
        send_ray_draw_wall(&ds->map,
                           &ds->pos,
                           ds->direction + dir,
                           ds);
        height = (ds->win_fp->buffer.height * ds->map.tile_size) /
            (ds->count * cos(ds->direction - (ds->direction + dir)));
        clear_column(ds, height, column);
        dir += deg_to_rads((fov)) / ds->win_fp->buffer.width;
        column += 1;
    }
    return height;
}

int first_person(struct display *ds, int fov)
{
    draw_background(ds, ds->px_fp);
    draw_wall(ds, fov);
    return fov;
}
