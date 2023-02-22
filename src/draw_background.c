/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-22 - 11:23 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw_background
 */

#include "graphic.h"

void draw_background(struct display *ds)
{
    int i;
    unsigned int *tableau;

    i = 0;
    tableau = (unsigned int *)ds->px_fp->pixels;
    while (i <= (ds->px_fp->clipable.clip_width
                 * ds->px_fp->clipable.clip_height) / 2) {
        tableau[i] = ds->col_up;
        i = i + 1;
    }
    while (i <= (ds->px_fp->clipable.clip_width
                 * ds->px_fp->clipable.clip_height)) {
        tableau[i] = ds->col_bottom;
        i = i + 1;
    }
}
