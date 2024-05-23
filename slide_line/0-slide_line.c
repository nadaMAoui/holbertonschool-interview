#include <stdio.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

int slide_line(int *line, size_t size, int direction)
{

    // Check for invalid direction
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
    {
        return 0;
    }

    // Slide the elements to the specified direction
    int *write_ptr = line;
    for (int i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (write_ptr == line || *write_ptr != line[i])
            {
                *(write_ptr++) = line[i];
            }
            else
            {
                *write_ptr *= 2; // Merge with the previous element if same
                write_ptr++;
            }
        }
    }

    // Fill the remaining spaces with zeros based on direction
    while (write_ptr < line + size)
    {
        *write_ptr++ = 0;
    }

    return 1;
}
