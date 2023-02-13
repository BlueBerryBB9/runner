/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-13 - 11:31 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw pacman
 */

#include "graphic.h"

static void mk_body(t_bunny_pixelarray *px, t_bunny_position pos, int radius)
{
    int rad;

    rad = 0;
    while (rad != radius) {
        stu_set_circle(px, pos.x, pos.y, rad, YELLOW);
        rad += 1;
    }
    stu_set_circle(px, pos.x, pos.y, radius, WHITE);
}

static void axe_x(t_bunny_pixelarray *px,
                   t_bunny_position pos,
                   double direction,
                   int radius)
{
    
}

static void mk_mouth(t_bunny_pixelarray *px,
                   t_bunny_position pos,
                   double direction,
                   int radius)
{
    int i;
    t_bunny_position bpos;

    i = -1 * (radius / 4);
    if (direction == 0 || direction == 2 * M_PI) {
        bpos.x = (radius + 1) + pos.x;
        bpos.y = i + pos.y;
    }
    if (direction == M_PI) {
        bpos.x = (-1 * (radius + 1)) + pos.x;
        bpos.y = i + pos.y;
    }
    if (direction == 0.5 * M_PI) {
        bpos.x = i + pos.x;
        bpos.y = (-1 * (radius + 1)) + pos.y;
    }
    if (direction == 1.5 * M_PI) {
        bpos.x = i + pos.x;
        bpos.y = (radius + 1) + pos.y;
    }
    if (direction == 0 || direction == 2 * M_PI || direction == M_PI) {
        while (i != 4) {
            stu_draw_line(px, &pos, &bpos, BLACK);
            bpos.y += 1;
            i += 1;
        }
    } else {
        while (i != 4) {
            stu_draw_line(px, &pos, &bpos, BLACK);
            bpos.x += 1;
            i += 1;
        }
    }
}

void draw_pacman(t_bunny_pixelarray *px,
                   t_bunny_position pos,
                   double direction,
                   int radius)
{
    mk_body(px, pos, radius);
    mk_mouth(px, pos, direction, radius);
    direction += 1;
}
