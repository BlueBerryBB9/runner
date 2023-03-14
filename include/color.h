/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-14 - 14:43 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: color include
 */

#ifndef COLOR_H

#define COLOR_H

union colour {
    unsigned int full;
    unsigned char rgba[4];
};

#endif
