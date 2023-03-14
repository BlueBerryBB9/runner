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

    ds = data;
    ds = ds;
    state = state;
    keycode = keycode;
    return (GO_ON);
}
