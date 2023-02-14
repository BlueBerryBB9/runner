/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-24 - 09:11 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: main
 */


#include "graphic.h"
/*
 * gcc -W -Werror -Wextra -Wall src/\\* -Iinclude/
 * -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm
 */

int main(void)
{
    t_bunny_window           *win;
    t_bunny_pixelarray       *px;
    t_accurate_pos           pos;

    int mx[15 * 12] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
        1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1,
        1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 2, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    struct map map;
    map.width     = 15;
    map.height    = 12;
    map.tile_size = 50;
    map.map       = &mx[0];
    pos.x         = 1.5;
    pos.y         = 1.5;
    win           = bunny_start(map.width * map.tile_size,
                                map.height * map.tile_size,
                                false,
                                "fl: TP Laser");
    px = bunny_new_pixelarray(win->buffer.width, win->buffer.height);
    clear_pixelarray(px, BLACK);
    refresh(win, px);
    draw_map(&map, px);
    if (labyrinth_solve(&map, pos, win, px) == 2) {
        draw_level_end(map, px, win, 6);
    }
    bunny_delete_clipable(&px->clipable);
    bunny_stop(win);
    return (0);
}
