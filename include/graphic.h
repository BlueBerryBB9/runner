/*
 * E89 Pedagogical & Technical Lab
 * project:     tp laser
 * created on:  2023-01-16 - 15:24 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: include
 */

#include <lapin.h>
#include <math.h>
#include "map.h"
#include "display.h"
#include "labyrinth_solver.h"
#include "character.h"
#include "color.h"

#ifndef GRAPHIC_H_

#define GRAPHIC_H_

typedef t_bunny_accurate_position t_accurate_pos;

void make_keys_loop(const bool *keys, struct display *ds);

void put_map_in_table(struct display *ds, char *map_name);

t_bunny_response my_loop(void *data);

int first_person(struct display *ds, int fov);

int draw_wall(struct display *ds, int fov);

void draw_background(struct display *ds, t_bunny_pixelarray *px);

void draw_level_end(struct map map,
                    t_bunny_pixelarray *px,
                    t_bunny_window *win,
                    int time);

unsigned int mk_colour(unsigned char r,
                       unsigned char g,
                       unsigned char b,
                       unsigned char a);

t_bunny_response my_key_event(t_bunny_event_state state,
                              t_bunny_keysym keycode,
                              void *data);

void make_keys(t_bunny_keysym keycode,
               struct display *ds);

void clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);

void stu_set_circle(t_bunny_pixelarray *pxa,
                    int x,
                    int y,
                    int radius,
                    int colour);

void draw_impact(struct map *map,
                 t_bunny_pixelarray *pxa,
                 const t_accurate_pos *start, double angle);

void put_pixel(t_bunny_pixelarray *px,
               t_bunny_position *pos,
               unsigned int color);

void draw_block(struct map *map,
                t_bunny_pixelarray *px,
                t_bunny_position origin,
                unsigned int color);

int radar(struct map *map,
          t_accurate_pos *pos,
          t_bunny_window *win,
          t_bunny_pixelarray *px,
          double angle);

void refresh(t_bunny_window *win, t_bunny_pixelarray *px);

void refresh_map(struct map *map, t_bunny_pixelarray *px, int coef);

void draw_map(struct map *map, t_bunny_pixelarray *px, int coef);

void stu_draw_line(t_bunny_pixelarray *px,
                   t_bunny_position *pos_a,
                   t_bunny_position *pos_b,
                   unsigned int color);

void div_or_mult_pos(t_accurate_pos *pos, int coef, char c);

t_accurate_pos move_forward(const t_accurate_pos *start,
                            double angle,
                            double len);

t_bunny_position pos_from_accurate(const t_accurate_pos *start);

t_accurate_pos send_ray(struct map *map,
                        const t_accurate_pos *start,
                        double angle);

int send_ray_draw_wall(struct map *map,
                                  const t_accurate_pos *start,
                                  double angle,
                                  struct display *ds);

float get_ratio(int a, int b, int x);

int get_value(int a, int b, float ratio);

double deg_to_rads(int degrees);

#endif
