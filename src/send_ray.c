/*
 * E89 Pedagogical & Technical Lab
 * project:     tp laser
 * created on:  2023-01-17 - 16:07 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: send ray
 */

#include "laser.h"
#include "map.h"

static void step_search(int *step)
{
    if (*step % 2 == 0) {
        *step /= 2;
    } else if (*step % 3 == 0) {
        *step /= 3;
    } else if (*step % 5 == 0) {
        *step /= 5;
    } else if (*step % 7 == 0) {
        *step /= 7;
    } else {
        *step /= 10;
    }
    if (*step == 0) {
        *step = 1;
    }
}

static t_accurate_pos rev_send_ray(struct map *map,
                                   const t_accurate_pos *start,
                                   double angle,
                                   int step)
{
    t_accurate_pos pos;
    t_bunny_position post;

    angle *= (2 * M_PI);
    pos.x = start->x;
    pos.y = start->y;
    while (pos.x < map->width && pos.y < map->height && pos.x > 0 && pos.y > 0) {
        pos.x = pos.x * map->tile_size;
        pos.y = pos.y * map->tile_size;
        pos = move_forward(&pos, angle, step);
        pos.x = pos.x / map->tile_size;
        pos.y = pos.y / map->tile_size;
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

        pos.x = start->x;
        pos.y = start->y;
        while (pos.x < map->width && pos.y < map->height && pos.x > 0 && pos.y > 0) {
            pos.x = pos.x * map->tile_size;
            pos.y = pos.y * map->tile_size;
            pos = move_forward(&pos, angle, map->tile_size);
            pos.x = pos.x / map->tile_size;
            pos.y = pos.y / map->tile_size;
            post = pos_from_accurate(&pos);
            if (map->map[(map->width * post.y) + post.x] == 1) {
                while (step != 1) {
                    step_search(&step);
                    pos = rev_send_ray(map, start, angle, step);
                }
                return pos;
            }
        }
        return pos;
    }
