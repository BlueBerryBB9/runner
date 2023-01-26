/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-26 - 16:21 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: get value
 */

int get_value(int a, int b, float ratio)
{
    int x;

    x = (ratio * (b - a)) + a;
    return (x);
}
