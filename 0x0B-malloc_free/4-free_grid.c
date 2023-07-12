#include "main.h"
#include <stdlib.h>

void free_grid(int **grid, int height)
{
    if (grid == NULL)
        return;

    for (int i = 0; i < height; i++)
    {
        free(grid[i]);
    }

    free(grid);
}

