/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-25 - 09:13 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: moving radar
 */

#include "graphic.h"

static t_bunny_position give_t_pos(t_accurate_pos *pos, double angle)
{
    t_bunny_position n;
    t_accurate_pos N;

    N = move_forward(pos, angle, 1);
    n = pos_from_accurate(&N);
    return n;

}

static int check_nb(int nb, double *dir)
{
    if (nb == 1111) {
        return -1;
    } else if (nb == 0) {
        *dir -= 0.5 * M_PI;
        if (*dir == 0) {
            *dir = 2 * M_PI;
        }
        return 0;
    }
    if (*dir == 0.5 * M_PI) {
        if (nb == 1 || nb == 1000 || nb == 1001) {
            *dir = 2 * M_PI;
        } else if (nb == 10 || nb == 11) {
            *dir = 0.5 * M_PI;
        } else if (nb == 1010) {
            *dir = M_PI;
        } else if (nb == 1011) {
            *dir = 1.5 * M_PI;
        }
    } else if (*dir == 1.5 * M_PI) {
        if (nb == 100 || nb == 10 || nb == 110) {
            *dir = M_PI;
        } else if (nb == 1 || nb == 11) {
            *dir = 1.5 * M_PI;
        } else if (nb == 101) {
            *dir = 2 * M_PI;
        } else if (nb == 111) {
            *dir = 0.5 * M_PI;
        }
    } else if (*dir == 2 * M_PI) {
        if (nb == 1000 || nb == 10 || nb == 1010) {
            *dir = 1.5 * M_PI;
        } else if (nb == 1100 || nb == 100) {
            *dir = 2 * M_PI;
        } else if (nb == 110) {
            *dir = 0.5 * M_PI;
        } else if (nb == 1110) {
            *dir = M_PI;
        }
    } else if (*dir == M_PI) {
        if (nb == 100 || nb == 1 || nb == 101) {
            *dir = 0.5 * M_PI;
        } else if (nb == 1000 || nb == 1100) {
            *dir = M_PI;
        } else if (nb == 1001) {
            *dir = 1.5 * M_PI;
        } else if (nb == 1101) {
            *dir = 2 * M_PI;
        }
    }
    //printf("dir: %f\n", *dir);
    return 0;
}

static int change_dir(struct map *map,
                 t_accurate_pos *pos,
                 double *dir)
{
    int nb;
    t_bunny_position n;
    t_bunny_position s;
    t_bunny_position e;
    t_bunny_position o;

    nb = 0;
    n = give_t_pos(pos, 1.5 * M_PI);
    s = give_t_pos(pos, 0.5 * M_PI);
    e = give_t_pos(pos, 2 * M_PI);
    o = give_t_pos(pos, M_PI);
    if (map->map[(map->width * n.y) + n.x] == 1) {
        nb += 1000;
    }
    if (map->map[(map->width * s.y) + s.x] == 1) {
        nb += 100;
    }
    if (map->map[(map->width * e.y) + e.x] == 1) {
        nb += 10;
    }
    if (map->map[(map->width * o.y) + o.x] == 1) {
        nb += 1;
    }
    //printf("nb: %d\n", nb);
    check_nb(nb, dir);
    return nb;
}

static int moving_radar(struct map *map,
                        t_accurate_pos *pos,
                        double *dir)
{
    if (map->map[(map->width * (int) pos->y) + (int) pos->x] == 2) {
        return 2;
    }
    if (*dir == 0.5 * M_PI) {
        pos->y -= 1;
    } else if (*dir == 0 || *dir == 2 * M_PI) {
        pos->x += 1;
    } else if (*dir == 1.5 * M_PI) {
        pos->y += 1;
    } else if (*dir == M_PI) {
        pos->x -= 1;
    }
    change_dir(map, pos, dir);
    return *dir;
}

int radar(struct map *map,
          t_accurate_pos *pos,
          t_bunny_window *win,
          t_bunny_pixelarray *px)
{
    double angle;
    double direction;
    t_accurate_pos post;
    t_bunny_position bpos;
    t_bunny_position bpost;

    direction = 1.5 * M_PI; /* ici: Sud; desc: angle vers Nord, sud, ... */
    angle = 0.5 * M_PI;
    while (direction != 1) {
        div_or_mult_pos(pos, map->tile_size, '*');
        bpos = pos_from_accurate(pos);
        div_or_mult_pos(pos, map->tile_size, '/');
        post = send_ray(map, pos, angle);
        div_or_mult_pos(&post, map->tile_size, '*');
        bpost = pos_from_accurate(&post);
        clear_pixelarray(px, BLACK);
        draw_map(map, px);
        stu_draw_line(px, &bpos, &bpost, GREEN);
        put_pixel(px, &bpos, RED);
        if (moving_radar(map, pos, &direction) == 2) {
            //celebration();
            return 2;
        }
        if (direction == 0.5 * M_PI || direction == 1.5 * M_PI) {
            angle = direction + M_PI;
        } else {
            angle = direction;
        }
        refresh(win, px);
        bunny_usleep(1e5);
    }
    return 0;
}
