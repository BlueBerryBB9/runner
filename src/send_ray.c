/*
 * E89 Pedagogical & Technical Lab
 * project:     tp laser
 * created on:  2023-01-17 - 16:07 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: send ray
 */

#include "graphic.h"

static t_accurate_pos rev_send_ray(struct map *map,
                                   t_accurate_pos *start,
                                   double angle,
                                   int step)
{
    t_accurate_pos pos;
    t_bunny_position post;

    pos.x = start->x;
    pos.y = start->y;
    div_or_mult_pos(&pos, map->tile_size, '*');
    pos = move_forward(&pos, angle, step);
    div_or_mult_pos(&pos, map->tile_size, '/');
    post = pos_from_accurate(&pos);
    if (map->map[(map->width * post.y) + post.x] == 0) {
        return pos;
    }
    while (pos.x < map->width && pos.y < map->height
           && pos.x > 0 && pos.y > 0) {
        div_or_mult_pos(&pos, map->tile_size, '*');
        pos = move_forward(&pos, angle, step);
        div_or_mult_pos(&pos, map->tile_size, '/');
        post = pos_from_accurate(&pos);
        if (map->map[(map->width * post.y) + post.x] == 0) {
            return pos;
        }
    }
    return pos;
}

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle)
{
    int step;
    t_accurate_pos pos;
    t_bunny_position post;

    step = 10;
    pos.x = start->x;
    pos.y = start->y;
    while (pos.x < map->width && pos.y < map->height && pos.x > 0 && pos.y > 0) {
        pos = move_forward(&pos, angle, (double) step / (double) map->tile_size);
        post = pos_from_accurate(&pos);
        if (map->map[(map->width * post.y) + post.x] == 1) {
            if (step == 1) {
                return pos;
            }
            angle += M_PI;
            step = 1;
            pos = rev_send_ray(map, &pos, angle, step);
            return pos;
        }
    }
    return pos;
}
