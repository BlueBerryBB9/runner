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
//                                 int *i)
{
    t_accurate_pos pos;
    t_bunny_position post;

    pos.x = start->x;
    pos.y = start->y;
    while (pos.x < map->width && pos.y < map->height
           && pos.x > 0 && pos.y > 0) {
        div_or_mult_pos(&pos, map->tile_size, '*');
        pos = move_forward(&pos, angle, step);
        div_or_mult_pos(&pos, map->tile_size, '/');
        post = pos_from_accurate(&pos);
        if (map->map[(map->width * post.y) + post.x] == 0) {
            return pos;
        }
        //*i += 1;
    }
    return pos;
}

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle)
{
    //int i; /* compte le nombre d'opération */
    int step;
    t_accurate_pos pos;
    t_bunny_position post;

    //i = 0;
    step = map->tile_size / 10;
    pos.x = start->x;
    pos.y = start->y;
    while (pos.x < map->width && pos.y < map->height && pos.x > 0 && pos.y > 0) {
        div_or_mult_pos(&pos, map->tile_size, '*');
        pos = move_forward(&pos, angle, step);
        div_or_mult_pos(&pos, map->tile_size, '/');
        post = pos_from_accurate(&pos);
        if (map->map[(map->width * post.y) + post.x] == 1) {
            angle += M_PI;
            step = 1;
            pos = rev_send_ray(map, &pos, angle, step);//, &i);
            return pos;
        }
        //i += 1;
    }
    return pos;
}
