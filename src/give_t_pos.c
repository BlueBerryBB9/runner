/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-27 - 09:39 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: give bunny position
 */

#include "graphic.h"

t_bunny_position give_t_pos(t_accurate_pos *pos, double angle)
{
    t_bunny_position n;
    t_accurate_pos N;

    N = move_forward(pos, angle, 1);
    n = pos_from_accurate(&N);
    return n;

}
