/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 15:52 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: first person
 */

#include "graphic.h"

static void clear_column(struct display *ds, int height, int column)
{
    t_bunny_position pos;
    t_bunny_position bpos;

    pos.x = column * (ds->win_fp->buffer.width / 135);
    pos.y = ((ds->win_fp->buffer.height - height) / 2);
    bpos.x = pos.x;
    bpos.y = ds->win_fp->buffer.height -
        ((ds->win_fp->buffer.height - height) / 2);
    while (pos.x != (column + 1) * (ds->win_fp->buffer.width / 135)) {
        stu_draw_line(ds->px_fp, &pos, &bpos, WHITE);
        pos.x += 1;
        bpos.x = pos.x;
    }
}

static void draw_column(struct display *ds, int height, int column)
{
    if (height > ds->win_fp->buffer.height) {
        height = ds->win_fp->buffer.height;
    }
    clear_column(ds, height, column);
}

static int draw_wall(struct display *ds, int fov)
{
    double dir;
    int height;
    int column;

    column = 0;
    dir = -1 * deg_to_rads(fov / 2);
    while (ds->direction + dir <= ds->direction + deg_to_rads(fov / 2)
           || column != 136) {
        send_ray_draw_wall(&ds->map,
                           &ds->pos,
                           ds->direction + dir,
                           ds);
        height = (ds->win_fp->buffer.height * ds->map.tile_size) / ds->count;
        draw_column(ds, height, column);
        dir += deg_to_rads((fov)) / 135;
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
