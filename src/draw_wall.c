/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-07 - 15:36 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw wall on first person
 */

#include "graphic.h"

static void clear_column(struct display *ds, double height, int column)
{
    t_bunny_position pos;
    t_bunny_position bpos;
    int col;

    if (height > ds->win->buffer.height) {
        height = ds->win->buffer.height;
    }
    pos.x = column;
    pos.y = ((ds->win->buffer.height - height) / 2);
    bpos.x = column;
    bpos.y = ds->win->buffer.height - pos.y;
    col = (155 * height) / ds->win->buffer.height;
    stu_draw_line(ds->px, &pos, &bpos, mk_colour(75 + col,
                                                    75 + col,
                                                    75 + col,
                                                    255));
}

int draw_wall(struct display *ds, int fov)
{
    double dir;
    double height;
    int column;

    column = 0;
    dir = -1 * deg_to_rads(fov / 2);
    while (ds->direction + dir <= ds->direction + deg_to_rads(fov / 2)
           && column <= ds->win->buffer.width) {
        send_ray_draw_wall(&ds->map,
                           &ds->pos,
                           ds->direction + dir,
                           ds);
        height = (ds->win->buffer.height * ds->map.tile_size) /
            (ds->count * cos(ds->direction - (ds->direction + dir)));
        clear_column(ds, height, column);
        dir += deg_to_rads((fov)) / ds->win->buffer.width;
        column += 1;
    }
    return height;
}
