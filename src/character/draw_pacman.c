/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-13 - 11:31 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw pacman
 */

#include "character.h"

static void mk_body(t_bunny_pixelarray *px, t_accurate_pos pos, int radius)
{
    int rad;
    t_bunny_position bpos;

    rad = 0;
    bpos = pos_from_accurate(&pos);
    while (rad != radius) {
        stu_set_circle(px, bpos.x, bpos.y, rad, YELLOW);
        rad += 1;
    }
    stu_set_circle(px, bpos.x, bpos.y, radius, WHITE);
}

static void mk_mouth(t_bunny_pixelarray *px,
                     t_accurate_pos pos,
                     double direction,
                     int radius)
{
    t_accurate_pos apos;
    t_bunny_position bpos;
    t_bunny_position bupos;
    double dir;

    dir = -1 *(M_PI / 8);
    bupos = pos_from_accurate(&pos);
    while (dir <= M_PI / 8) {
        apos = move_forward(&pos, direction + dir, radius + 1);
        bpos = pos_from_accurate(&apos);
        stu_draw_line(px, &bupos, &bpos, BLACK);
        dir += M_PI / 90;
    }
}

void draw_pacman(t_bunny_pixelarray *px,
                 t_accurate_pos pos,
                 double direction,
                 int radius)
{
    mk_body(px, pos, radius);
    mk_mouth(px, pos, direction, radius);
}
