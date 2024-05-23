#include "slide_line.h"

/**
 * slide_right - slides and merges an array of integers to the right
 * @line: pointer to the array of integers
 * @size: size of the array
 * Return: Nothing
 */
void slide_right(int *line, int size)
{
    int i, j;

    /* Merge the array */
    for (i = size - 1; i > 0; i--)
    {
        for (j = i - 1; line[j] == 0 && j >= 0; j--)
            ;
        if (line[i] == line[j])
        {
            line[i] += line[j];
            line[j] = 0;
        }
    }

    /* Slide the array to the right */
    for (i = size - 1; i > 0; i--)
    {
        if (!line[i])
        {
            for (j = i - 1; line[j] == 0 && j >= 0; j--)
                ;
            if (j < 0)
                j = 0;
            if (line[j])
            {
                line[i] = line[j];
                line[j] = 0;
            }
        }
    }
}

/**
 * slide_left - slides and merges an array of integers to the left
 * @line: pointer to the array of integers
 * @size: size of the array
 * Return: Nothing
 */
void slide_left(int *line, int size)
{
    int i, j;

    /* Merge the array */
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; line[j] == 0 && j < size; j++)
            ;
        if (line[i] == line[j])
        {
            line[i] += line[j];
            line[j] = 0;
        }
    }

    /* Slide the array to the left */
    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == 0)
        {
            for (j = i + 1; line[j] == 0 && j < size; j++)
                ;
            if (j == size)
                j = size - 1;
            if (line[j] != 0)
            {
                line[i] = line[j];
                line[j] = 0;
            }
        }
    }
}

/**
 * slide_line - function that slides and merges an array of integers
 * @line: pointer to the array of integers
 * @size: size of the array
 * @direction: the direction in which to merge the array
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if ((direction != SLIDE_LEFT && direction != SLIDE_RIGHT) || !line)
        return (0);

    if (direction == SLIDE_RIGHT)
        slide_right(line, (int)size);

    if (direction == SLIDE_LEFT)
        slide_left(line, (int)size);

    return (1);
}
