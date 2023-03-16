/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-26 - 11:29 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw map
 */

#include "graphic.h"

void draw_map(struct map *map, t_bunny_pixelarray *px, int coef)
{
    t_bunny_position origin;

    origin.x = 0;
    origin.y = 0;
    map->tile_size /= coef;
    while (origin.y < map->height) {
        while (origin.x < map->width) {
            if (map->map[origin.x + (origin.y * map->width)] == 1) {
                draw_block(map, px, origin, WHITE);
            }
            if (map->map[origin.x + (origin.y * map->width)] == 2) {
                draw_block(map, px, origin, BLUE);
            }
            origin.x += 1;
        }
        origin.x = 0;
        origin.y += 1;
    }
    map->tile_size *= coef;
}
