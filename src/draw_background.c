/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-22 - 11:23 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw_background
 */

#include "graphic.h"

void draw_background(struct display *ds, t_bunny_pixelarray *px)
{
    int i;
    unsigned int *tableau;

    i = 0;
    tableau = (unsigned int *) px->pixels;
    while (i <= (px->clipable.clip_width
                 * px->clipable.clip_height) / 2) {
        tableau[i] = ds->col.up;
        i = i + 1;
    }
    while (i <= (px->clipable.clip_width
                 * px->clipable.clip_height)) {
        tableau[i] = ds->col.bottom;
        i = i + 1;
    }
}
