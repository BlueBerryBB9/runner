/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-27 - 09:40 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: check nb
 */

#include "labyrinth_solver.h"

int check_nb(int nb, double *dir)
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
    if_dead_end();
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
    } else if (*dir == 2 * M_PI || *dir == 0) {
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
    return 0;
}
