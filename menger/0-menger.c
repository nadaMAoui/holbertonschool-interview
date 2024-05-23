#include "menger.h"

/**
 * menger - draws a 2D menger sponge
 * @level: the level of the menger sponge to draw
 * Return: Nothing
 */
void menger(int level)
{
    int x, y, size = pow(3, level);

    for (y = 0; y < size; y++)
    {
        for (x = 0; x < size; x++)
        {
            printf("%c", sponge_char(y, x));
        }
        printf("\n");
    }
}

/**
 * sponge_char - returns the character to print
 * @y: the y coordinate value
 * @x: the x coordinate value
 * Return: the character to print in the sponge
 */
char sponge_char(int y, int x)
{
    while (y && x)
    {
        if (y % 3 == 1 && x % 3 == 1)
            return (' ');

        y /= 3;
        x /= 3;
    }
    return ('#');
}
