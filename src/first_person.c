/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 15:52 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: first person
 */

#include "graphic.h"

static void draw_crosshair(struct display *ds)
{
    t_bunny_position pos;

    pos.x = ds->win->buffer.width / 2;
    pos.y = ds->win->buffer.height / 2;
    put_pixel(ds->px, &pos, ds->col.crosshair);
    pos.x += 1 * ds->coef;
    put_pixel(ds->px, &pos, ds->col.crosshair);
    pos.x -= 2 * ds->coef;
    put_pixel(ds->px, &pos, ds->col.crosshair);
    pos.x += 1 * ds->coef;
    pos.y += 1 * ds->coef;
    put_pixel(ds->px, &pos, ds->col.crosshair);
    pos.y -= 2 * ds->coef;
    put_pixel(ds->px, &pos, ds->col.crosshair);
}

int first_person(struct display *ds, int fov)
{
    draw_background(ds, ds->px);
    draw_wall(ds, fov);
    draw_crosshair(ds);
    return fov;
}
