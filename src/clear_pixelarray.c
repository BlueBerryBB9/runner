#include <lapin.h>

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color)
{
    int i;
    unsigned int *tableau;

    i = 0;
    tableau = (unsigned int *)pxa->pixels;
    while (i <= (pxa->clipable.clip_width * pxa->clipable.clip_height)) {
        tableau[i] = color;
        i = i + 1;
    }
    return;
}
