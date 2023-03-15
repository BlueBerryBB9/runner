/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-24 - 09:11 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: main
 */

#include "graphic.h"

/*
 * int mx[19 * 10] = {
 *     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 *     1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 1,
 *     1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
 *     1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1,
 *     1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1,
 *     1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1,
 *     1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1,
 *     1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1,
 *     1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
 *     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 * };
 */

static void init_s_map(struct display *ds)
{
    char *map_name;

    map_name = "maps/map1.txt";
    put_map_in_table(ds, map_name);
    printf("map : %ls\n", ds->map.map);
    if (ds->map.width > ds->map.height) {
        ds->ratio = (double) ds->map.width / (double) ds->map.height;
    } else {
        ds->ratio = (double) ds->map.height / (double) ds->map.width;
    }
    printf("ratio %f\n", ds->ratio);
}

static void init_first_person_window(struct display *ds)
{
    int width;

    ds->col.up        = mk_colour(0, 255, 255, 255);
    //ds->col.wall      = mk_colour(0, 128, 128, 255);
    ds->col.bottom    = mk_colour(57, 255, 20, 255);
    ds->col.crosshair = mk_colour(0, 255, 0, 255);
    width             = 600;
    ds->win           = bunny_start((double) width * (double) ds->ratio,
                                    width,
                                    false,
                                    "fl: TP Runner - First_person");
    ds->px            = bunny_new_pixelarray(ds->win->buffer.width,
                                             ds->win->buffer.height);
    ds->map.tile_size = (ds->win->buffer.width / 3) / ds->map.width;
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

int main(void)
{
    struct display ds;
    init_s_map(&ds);
    init_first_person_window(&ds);
    init_labyrinth_info(&ds);
    draw_background(&ds, ds.px);
    draw_wall(&ds, ds.fov);
    draw_map(&ds.map, ds.px);
    refresh(ds.win, ds.px);
    bunny_set_key_response(my_key_event);
    bunny_set_loop_main_function(my_loop);
    bunny_loop(ds.win, 144, &ds);
    stop_window(ds.px, ds.win);
    return (0);
}
