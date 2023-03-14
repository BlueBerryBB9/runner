/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-14 - 14:23 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: loop
 */

#include "graphic.h"

union color {
    unsigned int co_full;
    unsigned char co_rgba[4];
};

t_bunny_response my_loop(void *data)
{
    struct display *ds;
    const bool *keys;
    union color color;
    int col;

    color.co_full = BLACK;
    ds = data;
    keys = bunny_get_keyboard();
    if (keys[BKS_Z]) {
        color.co_rgba[0] = 255;
    }
    if (keys[BKS_S]) {
        color.co_rgba[1] = 255;
    }
    col = color.co_full;
    clear_pixelarray(ds->px, col);
    refresh(ds->win, ds->px);
    return (GO_ON);
}
