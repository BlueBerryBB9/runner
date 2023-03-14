/*
 * E89 Pedagogical & Technical Lab
 * project:     open window
 * created on:  2022-10-18 - 16:42 +0200
 * 1st author:  martin.leroy - martin.leroy
 * description: make colour
 */

#include "color.h"

unsigned int mk_colour(unsigned char r,
                       unsigned char g,
                       unsigned char b,
                       unsigned char a)
{
    union colour col;
    col.full = 0;

    col.rgba[0] = r;
    col.rgba[1] = g;
    col.rgba[2] = b;
    col.rgba[3] = a;

    return (col.full);
}
