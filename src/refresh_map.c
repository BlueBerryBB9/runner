/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-17 - 16:05 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: refresh map
 */

#include "graphic.h"

void refresh_map(struct map *map, t_bunny_pixelarray *px)
{
    t_bunny_position origin;

    origin.x = 0;
    origin.y = 0;
    while (origin.y < map->height) {
        while (origin.x < map->width) {
            if (map->map[origin.x + (origin.y * map->width)] == 0) {
                draw_block(map, px, origin, BLACK);
            }
            if (map->map[origin.x + (origin.y * map->width)] == 2) {
                draw_block(map, px, origin, BLUE);
            }
            origin.x += 1;
        }
        origin.x = 0;
        origin.y += 1;
    }
}
