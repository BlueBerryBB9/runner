/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-26 - 16:57 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: put pixel
 */

#include <lapin.h>

void put_pixel(t_bunny_pixelarray *px,
               t_bunny_position *pos,
               unsigned int color)
{
    int i;
    unsigned int *tableau;

    i = pos->x + pos->y * px->clipable.clip_width;
    if (i > (px->clipable.clip_width * px->clipable.clip_height)) {
        return;
    }
    tableau = (unsigned int *) px->pixels;
    tableau[i] = color;
}
