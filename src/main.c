/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-24 - 09:11 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: main
 */

#include "graphic.h"

/*
 * static void init_s_map(struct display *ds, char *map)
 * {
 *     put_map_in_table(ds, map);
 * }
 */

static void init_first_person_window(struct display *ds)
{
    int width;

    ds->col.up        = mk_colour(0, 255, 255, 255);
    ds->col.bottom    = mk_colour(57, 255, 20, 255);
    ds->col.crosshair = mk_colour(0, 255, 0, 255);
    width             = 520;
    ds->win           = bunny_start((double) width * (double) 1.9,
                                    width,
                                    false,
                                    "fl: TP Runner - First_person");
    ds->px            = bunny_new_pixelarray(ds->win->buffer.width,
                                             ds->win->buffer.height);
    ds->map.tile_size = 100;
    if (ds->map.width > 60 || ds->map.height > 75){
        ds->div_tile_size = 30;
    } else {
        ds->div_tile_size = 10;
    }
}

static void init_labyrinth_info(struct display *ds)
{
    ds->pos.x     = 1.5;
    ds->pos.y     = 1.5;
    ds->pos.x     *= ds->map.tile_size;
    ds->pos.y     *= ds->map.tile_size;
    ds->direction = 0.5 * M_PI;
    ds->count     = 0;
    ds->fov       = 90;
    ds->coef      = 3;
}

static void stop_window(t_bunny_pixelarray *px, t_bunny_window *win)
{
    bunny_delete_clipable(&px->clipable);
    bunny_stop(win);
}

int main(int ac, char **av)
{
    struct display ds;

    ac = ac;
    if (ac == 1) {
        write(1, "Error : Need a map as argument\n", 31);
        return -1;
    }
    put_map_in_table(&ds, av[1]);
    init_first_person_window(&ds);
    init_labyrinth_info(&ds);
    draw_background(&ds, ds.px);
    draw_wall(&ds, ds.fov);
    draw_map(&ds.map, ds.px, ds.div_tile_size);
    refresh(ds.win, ds.px);
    bunny_set_key_response(my_key_event);
    bunny_set_loop_main_function(my_loop);
    bunny_loop(ds.win, 144, &ds);
    stop_window(ds.px, ds.win);
    return 0;
}
