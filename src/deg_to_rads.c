/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-13 - 11:05 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: deg to rads
 */

#include "graphic.h"

double deg_to_rads(int degrees)
{
    double x;

    x = ((double) degrees * (2 * M_PI)) / 360;
    return (x);
}
