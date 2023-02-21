/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-24 - 09:11 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: main
 */

#include "graphic.h"

int mx[19 * 10] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1,
    1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1,
    1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};


static void init_s_map(struct map *map)
{
    map->width     = 19;
    map->height    = 10;
    map->tile_size = 100;
    map->map       = mx;
}

int main(void)
{
    struct display ds;
    init_s_map(&ds.map);
    ds.pos.x     = 1.5 * ds.map.tile_size;
    ds.pos.y     = 1.5 * ds.map.tile_size;
    ds.direction = 0.5 * M_PI;
    ds.win       = bunny_start(ds.map.width * ds.map.tile_size,
                               ds.map.height * ds.map.tile_size,
                               false,
                               "fl: TP Runner");
    ds.px = bunny_new_pixelarray(ds.win->buffer.width, ds.win->buffer.height);
    clear_pixelarray(ds.px, BLACK);
    draw_map(&ds.map, ds.px);
    refresh(ds.win, ds.px);
    bunny_set_key_response(my_key_event);
    bunny_loop(ds.win, 60, &ds);
    bunny_delete_clipable(&ds.px->clipable);
    bunny_stop(ds.win);
    return (0);
}
