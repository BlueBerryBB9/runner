
/*
 * E89 Pedagogical & Technical Lab
 * project:     tr laser
 * created on:  2023-01-16 - 15:10 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: move forward
 */

#include "graphic.h"

t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,
                            double len)
{
    t_accurate_pos pos;

    pos.x = (cos(angle) * len) + start->x;
    pos.y = (sin(angle) * len) + start->y;
    return pos;
}
