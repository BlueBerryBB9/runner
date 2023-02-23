/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-25 - 09:13 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: moving radar
 */

#include "radar.h"
#include "map.h"

int radar(struct map *map,
          t_accurate_pos *acc_pos,
          t_bunny_window *win,
          t_bunny_pixelarray *px,
          double angle)
{
    int refr;
    t_accurate_pos acc_post;
    t_bunny_position pos;
    t_bunny_position post;

    refr = 720;
    while (refr != 0) {
        div_or_mult_pos(acc_pos, map->tile_size, '*');
        pos = pos_from_accurate(acc_pos);
        div_or_mult_pos(acc_pos, map->tile_size, '/');
        acc_post = send_ray(map, acc_pos, angle);
        div_or_mult_pos(&acc_post, map->tile_size, '*');
        post = pos_from_accurate(&acc_post);
        stu_draw_line(px, &pos, &post, GREEN);
        angle += (M_PI / 180);
        refresh(win, px);
        refr -= 1;
    }
    return 0;
}
