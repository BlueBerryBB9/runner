/*
 * E89 Pedagogical & Technical Lab
 * project:     tr laser
 * created on:  2023-01-18 - 13:42 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw line
 */

#include "graphic.h"

static void if_posax_sup_posbx(t_bunny_position *pos_a,
                               t_bunny_position *pos_b,
                               int *x,
                               int *bx)
{
    *x = pos_a->x;
    *bx = pos_b->x;

    if (pos_a->x > pos_b->x) {
        *bx = pos_a->x;
        *x = pos_b->x;
    }
}

static void if_posay_sup_posby(t_bunny_position *pos_a,
                               t_bunny_position *pos_b,
                               int *y,
                               int *by)
{
    *y = pos_a->y;
    *by = pos_b->y;

    if (pos_a->y > pos_b->y) {
        *by = pos_a->y;
        *y = pos_b->y;
    }
}

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color)
{
    int x;
    int y;
    int bx;
    int by;
    t_bunny_position pos;

    if_posay_sup_posby(pos_a, pos_b, &y, &by);
    if_posax_sup_posbx(pos_a, pos_b, &x, &bx);
    if ((bx - x) > (by - y)) {
        while (x != bx) {
            pos.x = x;
            pos.y = get_value(pos_a->y, pos_b->y,
                              get_ratio(pos_a->x, pos_b->x, x));
            put_pixel(px, &pos, color);
            x = x + 1;
        }
    } else {
        while (y != by) {
            pos.y = y;
            pos.x = get_value(pos_a->x, pos_b->x,
                              get_ratio(pos_a->y, pos_b->y, y));
            put_pixel(px, &pos, color);
            y = y + 1;
        }
    }
}
