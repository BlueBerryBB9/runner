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
    1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 1,
    1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1,
    1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

static void init_s_map(struct map *map)
{
    map->width     = 19;
    map->height    = 10;
    map->tile_size = 25;
    map->map       = mx;
}

static void init_first_person_window(struct display *ds)
{
    ds->col_up     = mk_colour(0, 255, 255, 255);
    //ds->col_wall   = mk_colour(0, 128, 128, 255);
    ds->col_bottom = mk_colour(57, 255, 20, 255);
    ds->win_fp     = bunny_start(900,
                                 700,
                                 false,
                                 "fl: TP Runner - First_person");
    ds->px_fp      = bunny_new_pixelarray(ds->win_fp->buffer.width,
                                          ds->win_fp->buffer.height);
}

static void init_labyrinth_info(struct display *ds)
{
    ds->pos.x     = 1.5 * ds->map.tile_size;
    ds->pos.y     = 1.5 * ds->map.tile_size;
    ds->direction = 0.5 * M_PI;
    ds->count     = 0;
    ds->fov       = 70;
}

static void stop_window(t_bunny_pixelarray *px, t_bunny_window *win)
{
    bunny_delete_clipable(&px->clipable);
    bunny_stop(win);
}

int main(void)
{
    struct display ds;
    init_s_map(&ds.map);
    init_first_person_window(&ds);
    init_labyrinth_info(&ds);
    ds.win = bunny_start(ds.map.width * ds.map.tile_size,
                         ds.map.height * ds.map.tile_size,
                         false,
                         "fl: TP Runner - Map");
    ds.px  = bunny_new_pixelarray(ds.win->buffer.width,
                                  ds.win->buffer.height);
    clear_pixelarray(ds.px, BLACK);
    draw_map(&ds.map, ds.px);
    draw_background(&ds, ds.px_fp);
    draw_wall(&ds, ds.fov);
    refresh(ds.win, ds.px);
    refresh(ds.win_fp, ds.px_fp);
    bunny_set_key_response(my_key_event);
    bunny_loop(ds.win_fp, 20, &ds);
    stop_window(ds.px, ds.win);
    stop_window(ds.px_fp, ds.win_fp);
    return (0);
}
