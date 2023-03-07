/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 15:52 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: first person
 */

#include "graphic.h"

int first_person(struct display *ds, int fov)
{
    draw_background(ds, ds->px_fp);
    draw_wall(ds, fov);
    return fov;
}
