/*
 * E89 Pedagogical & Technical Lab
 * project:     Runner
 * created on:  2023-02-20 - 09:05 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: my key event
 */

#include "graphic.h"

t_bunny_response my_key_event(t_bunny_event_state state,
                              t_bunny_keysym keycode,
                              void *data)
{
    struct display *ds;
    t_accurate_pos send_pos;
    t_bunny_position new_pos;
    t_bunny_position new_send_pos;

    ds = data;
    send_pos = ds->pos;
    //printf("keycode: %d\n state %d\nposy %f\nposx %f\n", keycode, state, ds->pos.y, ds->pos.x);
    if (state == GO_UP){
        return (GO_ON);
    }
    if (keycode == BKS_ESCAPE){
        return (EXIT_ON_SUCCESS);
    }
    make_keys(keycode, ds);
    if (ds->map.map[(ds->map.width
                     * ((int) ds->pos.y / ds->map.tile_size))
                    + ((int) ds->pos.x / ds->map.tile_size)] == 2) {
        draw_level_end(ds->map, ds->px, ds->win, 3);
        return 2;
    }
    if (ds->map.map[(ds->map.width
                     * ((int) ds->pos.y / ds->map.tile_size))
                    + ((int) ds->pos.x / ds->map.tile_size)] == 1) {
        ds->pos.x = send_pos.x;
        ds->pos.y = send_pos.y;
    }
    new_pos = pos_from_accurate(&ds->pos);
    refresh_map(&ds->map, ds->px);
    draw_pacman(ds->px, new_pos, 0, 20);
    div_or_mult_pos(&ds->pos, ds->map.tile_size, '/');
    send_pos = send_ray(&ds->map, &ds->pos, ds->direction);
    div_or_mult_pos(&ds->pos, ds->map.tile_size, '*');
    div_or_mult_pos(&send_pos, ds->map.tile_size, '*');
    new_send_pos = pos_from_accurate(&send_pos);
    stu_draw_line(ds->px, &new_pos, &new_send_pos, GREEN);
    refresh(ds->win, ds->px);
    return (GO_ON);
}
