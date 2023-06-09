/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-30 - 09:05 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: draw end screen
 */

#include "graphic.h"

int mxx[19 * 10] = {
    1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
};

static void draw_end_color(struct map *map,
                                t_bunny_pixelarray *px,
                                int color)
{
    t_bunny_position origin;

    origin.x = 0;
    origin.y = 0;
    while (origin.y < map->height) {
        while (origin.x < map->width) {
            if (map->map[origin.x + (origin.y * map->width)] == 1) {
                draw_block(map, px, origin, color);
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

void draw_level_end(struct map map,
                    t_bunny_pixelarray *px,
                    t_bunny_window *win,
                    int time)
{
    struct map nmap;

    map = map;
    nmap.width     = 19;
    nmap.height    = 10;
    nmap.tile_size = win->buffer.width / nmap.width;
    nmap.map       = mxx;
    while (time != 0) {
        if (time % 2 == 0) {
            clear_pixelarray(px, mk_colour(255, 215, 0, 1));
            draw_end_color(&nmap, px, WHITE);
        } else {
            clear_pixelarray(px, WHITE);
            draw_end_color(&nmap, px, mk_colour(255, 215, 0, 1));
        }
        refresh(win, px);
        bunny_usleep(1e6);
        time -= 1;
    }
}
