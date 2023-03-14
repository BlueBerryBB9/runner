/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-14 - 14:24 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: gfx context include
 */

#ifndef GFX_CONTEXT_H

#define GFX_CONTEXT_H

struct gfx_context {
    t_bunny_window *ctx_win;
    t_bunny_pixelarray *ctx_px;
};

#endif
