/*
 * E89 Pedagogical & Technical Lab
 * project:     tp laser
 * created on:  2023-01-16 - 15:23 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: convert accurate to pos
 */

#include "graphic.h"

t_bunny_position pos_from_accurate(const t_accurate_pos *start)
{
    t_bunny_position end;

    end.x = (int) start->x;
    end.y = (int) start->y;
    return (end);
}
