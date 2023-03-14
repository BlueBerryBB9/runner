/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-26 - 16:28 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: clear a pixelarray
 */

#include <lapin.h>

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color)
{
    int i;
    unsigned int *tableau;

    i = 0;
    tableau = (unsigned int *) pxa->pixels;
    while (i <= (pxa->clipable.clip_width * pxa->clipable.clip_height)) {
        tableau[i] = color;
        i = i + 1;
    }
    return;
}
