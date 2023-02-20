/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-20 - 09:37 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: make kays act
 */

#include "graphic.h"

static int arrow_or_zqsd(t_bunny_keysym key)
{
    if (key == BKS_Z || key == BKS_S || key == BKS_Q || key == BKS_D) {
        return 1;
    }
    if (key >= BKS_LEFT || key <= BKS_DOWN) {
        return 2;
    }
    return 0;
}

static void manage_keys(struct display *ds, t_bunny_keysym keycode)
{
    ds->step = ds->map.tile_size / 10;

    if (keycode == BKS_Z) {
        move_forward(&ds->pos, ds->direction, ds->step);
    } else if (keycode == BKS_Q) {
        move_forward(&ds->pos, ds->direction + (0.5 * M_PI), ds->step);
    } else if (keycode == BKS_S) {
        move_forward(&ds->pos, ds->direction + M_PI, ds->step);
    } else if (keycode == BKS_D) {
        move_forward(&ds->pos, ds->direction + (1.5 * M_PI), ds->step);
    }
}

static void manage_arrows(struct display *ds, t_bunny_keysym keycode)
{
    ds->step = ds->map.tile_size / 5;

    if (keycode == BKS_UP) {
        move_forward(&ds->pos, ds->direction, ds->step);
    } else if (keycode == BKS_DOWN) {
        move_forward(&ds->pos, ds->direction + M_PI, ds->step);
    } else if (keycode == BKS_LEFT) {
        ds->direction += M_PI / 10;
    } else if (keycode == BKS_RIGHT) {
        ds->direction -= M_PI / 10;
    }
}

void make_keys(t_bunny_keysym keycode,
               struct display *ds)
{
    if (arrow_or_zqsd(keycode) == 1) {
        manage_keys(ds, keycode);
    }
    if (arrow_or_zqsd(keycode) == 2) {
        manage_arrows(ds, keycode);
    }
}


