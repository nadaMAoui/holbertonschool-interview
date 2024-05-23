#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 4
#define SLIDE_RIGHT 6

int slide_line(int *line, size_t size, int direction);
void slide_right(int *line, int size);
void slide_left(int *line, int size);

#endif