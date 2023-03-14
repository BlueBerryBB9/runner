/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-26 - 16:25 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw block
 */

#include "graphic.h"

void draw_block(struct map *map,
                       t_bunny_pixelarray *px,
                       t_bunny_position origin,
                       unsigned int color)
{
    t_bunny_position pos;

    pos.x = origin.x * map->tile_size;
    pos.y = origin.y * map->tile_size;
    while (pos.y < (origin.y + 1) * map->tile_size) {
        while (pos.x < map->tile_size * (origin.x + 1)) {
            put_pixel(px, &pos, color);
            pos.x += 1;
        }
        pos.x = origin.x * map->tile_size;
        pos.y += 1;
    }
}
