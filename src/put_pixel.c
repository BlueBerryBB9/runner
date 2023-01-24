#include <lapin.h>
#include <unistd.h>
#include <stdlib.h>

void put_pixel(t_bunny_pixelarray *px,
               t_bunny_position *pos,
               unsigned int color)
{
    int i;
    int width;
    int height;
    unsigned int *tableau;

    width = px->clipable.clip_width;
    height = px->clipable.clip_height;

    i = pos->x + pos->y * width;
    if (i > (width * height)) {
        return;
    }
    tableau = (unsigned int *)px->pixels;
    tableau[i] = color;
}
