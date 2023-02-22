/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-21 - 15:52 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: first person
 */

#include "graphic.h"

/*
 * static void draw_wall(struct display *ds, int fov)
 * {
 *     double dir;
 * 
 *     dir = -1 * deg_to_rads(fov);
 *     while (ds->direction + dir != ds->direction + deg_to_rads(fov)) {
 * 
 *     }
 * }
 */

int first_person(struct display *ds, int fov)
{
    draw_background(ds);
    //draw_wall(ds, fov);
    return fov;
}
