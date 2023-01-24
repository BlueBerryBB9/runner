#include <assert.h>
#include "map.h"
#include "laser.h"

/*
 * gcc -W -Werror -Wextra -Wall src/\\* -Iinclude/
 * -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm
 */

static void refresh(t_bunny_window *win, t_bunny_pixelarray *px)
{
    bunny_blit(&win->buffer, &px->clipable, NULL);
    bunny_display(win);
    bunny_usleep(1e1);
}

int main(void)
{
    int refr;
    t_bunny_window           *win;
    t_bunny_pixelarray       *px;
    t_accurate_pos           pos;
    t_accurate_pos           post;
    t_bunny_position         bpos;
    t_bunny_position         bpost;
    double                   angle;

    int mx[6 * 6] = {
        0, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1,
        1, 1, 0, 0, 1, 1,
        1, 1, 1, 1, 1, 1,
    };
    struct map map;
    map.width     = 6;
    map.height    = 6;
    map.tile_size = 100;
    map.map       = &mx[0];
    pos.x         = 3;
    pos.y         = 3;
    angle         = 0;
    win           = bunny_start(map.width * map.tile_size,
                                map.height * map.tile_size,
                                false,
                                "fl: TP Laser");
    px = bunny_new_pixelarray(win->buffer.width, win->buffer.height);
    clear_pixelarray(px, BLACK);
    refresh(win, px);
    pos = div_or_mult_pos(&pos, map.tile_size, '*');
    bpos = pos_from_accurate(&pos);
    pos = div_or_mult_pos(&pos, map.tile_size, '/');
    refr = 10000;
    while (refr != 0) {
        post = send_ray(&map, &pos, angle);
        post = div_or_mult_pos(&post, map.tile_size, '*');
        bpost = pos_from_accurate(&post);
        //clear_pixelarray(px, BLACK);
        stu_draw_line(px, &bpos, &bpost, GREEN);
        angle += (M_PI / 360);
        refresh(win, px);
        refr -= 1;
    }
    refresh(win, px);
    bunny_delete_clipable(&px->clipable);
    bunny_stop(win);
    return (0);
}
