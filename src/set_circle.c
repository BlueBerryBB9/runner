/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-13 - 11:01 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: set circle
 */

#include "graphic.h"

void stu_set_circle(t_bunny_pixelarray *pxa,
                            int x,
                            int y,
                            int radius,
                            int colour)
{
    t_bunny_position pos;
    int i;

    i = 0;
    while (i <= 360) {
        pos.x = (cos(deg_to_rads(i)) * radius) + x;
        pos.y = (sin(deg_to_rads(i)) * radius) + y;
        put_pixel(pxa, &pos, colour);
        i = i + 1;
    }
    return ;
}
