/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-23 - 14:29 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: send ray walls
 */

#include "graphic.h"

static t_accurate_pos rev_send_ray_draw_wall(struct map *map,
                                             t_accurate_pos *start,
                                             double angle,
                                             double step,
                                             struct display *ds)
{
    t_accurate_pos pos;
    t_bunny_position post;

    pos.x = start->x;
    pos.y = start->y;
    pos = move_forward(&pos, angle, step);
    post = pos_from_accurate(&pos);
    if (map->map[(map->width * (post.y / map->tile_size))
                 + (post.x / map->tile_size)] == 0) {
        return pos;
    }
    while (pos.x / map->tile_size < map->width
           && pos.y / map->tile_size < map->height
           && pos.x / map->tile_size > 0
           && pos.y / map->tile_size > 0) {
        pos = move_forward(&pos, angle, step);
        post = pos_from_accurate(&pos);
        ds->count -= step;
        if (map->map[(map->width * (post.y / map->tile_size))
                     + (post.x / map->tile_size)] == 0
            || map->map[(map->width * (post.y / map->tile_size))
                        + (post.x / map->tile_size)] == 2) {
            return pos;
        }
    }
    return pos;
}

t_accurate_pos send_ray_draw_wall(struct map *map,
                                  const t_accurate_pos *start,
                                  double angle,
                                  struct display *ds)
{
    double step;
    t_accurate_pos pos;
    t_bunny_position post;

    ds->count = 0;
    step = 10;
    pos.x = start->x;
    pos.y = start->y;
    while ((pos.x / map->tile_size) < map->width
           && (pos.y / map->tile_size) < map->height
           && (pos.x / map->tile_size) > 0
           && (pos.y / map->tile_size) > 0) {
        pos = move_forward(&pos, angle, step);
        post = pos_from_accurate(&pos);
        ds->count += step;
        if (map->map[(map->width * (post.y / map->tile_size))
                     + (post.x / map->tile_size)] == 1) {
            angle += M_PI;
            step = 0.35;
            pos = rev_send_ray_draw_wall(map, &pos, angle, step, ds);
            return pos;
        }
    }
    pos = rev_send_ray_draw_wall(map, &pos, angle, step, ds);
    return pos;
}
