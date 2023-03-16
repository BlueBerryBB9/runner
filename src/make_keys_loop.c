/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-02-20 - 15:00 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: make keys with loop
 */

#include "graphic.h"

static void manage_keys_loop(struct display *ds, const bool *keys)
{
    ds->step = (double) ds->map.tile_size / (double) 10;

    if (keys[BKS_Z]) {
        ds->pos = move_forward(&ds->pos, ds->direction, ds->step);
    }
    if (keys[BKS_Q]) {
        ds->pos = move_forward(&ds->pos, ds->direction + (1.5 * M_PI), ds->step);
    }
    if (keys[BKS_S]) {
        ds->pos = move_forward(&ds->pos, ds->direction + M_PI, ds->step);
    }
    if (keys[BKS_D]) {
        ds->pos = move_forward(&ds->pos, ds->direction + (0.5 * M_PI), ds->step);
    }
}

static void manage_arrows_loop(struct display *ds, const bool *keys)
{
    ds->step = (double) ds->map.tile_size / (double) 5;

    if (keys[BKS_UP]) {
        ds->pos = move_forward(&ds->pos, ds->direction, ds->step);
    }
    if (keys[BKS_DOWN]) {
        ds->pos = move_forward(&ds->pos, ds->direction + M_PI, ds->step);
    }
    if (keys[BKS_LEFT]) {
        ds->direction -= M_PI / 20;
    }
    if (keys[BKS_RIGHT]) {
        ds->direction += M_PI / 20;
    }
}

void make_keys_loop(const bool *keys, struct display *ds)
{
    manage_keys_loop(ds, keys);
    manage_arrows_loop(ds, keys);
}


