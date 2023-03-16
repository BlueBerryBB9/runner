/*
 * E89 Pedagogical & Technical Lab
 * project:     runner
 * created on:  2023-03-15 - 15:46 +0100
 * 1st author:  martin.leroy - martin.leroy
 * description: put map into table
 */

#include "graphic.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

static int stu_strchr(const char *s, char accept)
{
    int i;

    i = 0;
    while (s[i] != '\0') {
        if (accept == s[i]) {
            return (1);
        }
        i = i + 1;
    }
    return (0);
}

static int stu_read_chars(const char *str,
                          unsigned int *index,
                          const char *token)
{
    int n;

    n = 0;
    while (stu_strchr(token, str[*index]) == 1) {
        *index += 1;
        n += 1;
    }
    return n;
}

static void found_width_and_height(struct display *ds, const char *buffer)
{
    unsigned int n;

    n = 0;
    ds->map.height = 0;
    ds->map.width = 0;
    while (buffer[n] != '\0') {
        while (stu_read_chars(buffer, &n, " ,0123") == 0) {
            if (buffer[n] == '\0') {
                return;
            }
            n += 1;
        }
        if (buffer[n] == '\0') {
            return;
        }
        ds->map.height += 1;
        n += 1;
    }
    n = 0;
    while (buffer[n] != '\n') {
        if (stu_strchr("012", buffer[n]) == 1) {
            ds->map.width += 1;
        }
        n += 1;
    }
}

static void put_number_in_table(struct display *ds, char *buffer)
{
    int n;
    int i;

    i = 0;
    n = 0;
    while (buffer[n] != '\0') {
        if (buffer[n] == '0'
            || buffer[n] == '1'
            || buffer[n] == '2'
            || buffer[n] == '3') {
            ds->map.map[i] = buffer[n] - '0';
            i += 1;
        }
        n += 1;
    }
}

void put_map_in_table(struct display *ds, char *map_name)
{
    int fd;
    struct stat sa;
    char *buffer;

    fd = open(map_name, O_RDONLY);
    stat(map_name, &sa);
    buffer = malloc(sizeof(char) * sa.st_size + 1);
    buffer[sa.st_size] = '\0';
    read(fd, buffer, sa.st_size);
    close(fd);
    found_width_and_height(ds, buffer);
    ds->map.map = malloc(sizeof(int) * (ds->map.width * ds->map.height));
    put_number_in_table(ds, buffer);
    free(buffer);
}
