/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-01-26 - 16:19 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: get ratio
 */

float get_ratio(int a, int b, int x)
{
    float ratio;

    ratio = ((float)x - (float)a) / ((float)b - (float)a);

    return (ratio);
}
