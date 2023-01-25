/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-25 - 09:36 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: refresh win
 */

#include "laser.h"

void refresh(t_bunny_window *win, t_bunny_pixelarray *px)
{
    bunny_blit(&win->buffer, &px->clipable, NULL);
    bunny_display(win);
}
