/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-24 - 12:11 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: div or mult pos
 */

#include "laser.h"

t_accurate_pos div_or_mult_pos(t_accurate_pos *pos, int coef, char c)
{
    if (c == '*') {
        pos->x *= coef;
        pos->y *= coef;
    } else if (c == '/') {
        pos->x /= coef;
        pos->y /= coef;
    }
    return *pos;
}
