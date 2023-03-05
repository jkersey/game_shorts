#include <stdio.h>

/*
** diamond.c
** Jim Kersey 2023
** --------------------
** jim.kersey@gmail.com
**
** Take width and height and output coordinates in the correct
** order for an isometric grid.
**
** input: 8 4
**
**             (0, 0)
**          (0, 1)(1, 0)
**       (0, 2)(1, 1)(2, 0)
**    (0, 3)(1, 2)(2, 1)(3, 0)
**       (1, 3)(2, 2)(3, 1)(4, 0)
**          (2, 3)(3, 2)(4, 1)(5, 0)
**             (3, 3)(4, 2)(5, 1)(6, 0)
**                (4, 3)(5, 2)(6, 1)(7, 0)
**                   (5, 3)(6, 2)(7, 1)
**                      (6, 3)(7, 2)
**                         (7, 3)
*/


void print_spaces(int spaces) {
    for (int i = 0; i < spaces; ++i) {
        printf("   ");
    }
}

void print_coordinates(int width, int x_start, int y_start) {
    for (int i = 0; i < width; ++i) {
        printf("(%d, %d)", x_start + i, y_start - i);
    }
}

void solve(int width, int height) {

    int i;
    int spaces = height;  // Number of leading spaces to align the coordinates
    int row_width = 1;    // Number of coordinates in the row to be drawn
    int x_start = 0;      // The starting x-coordinate of the current row
    int y_start = 0;      // The starting y-coordinate of the current row

    for (i = 0; i < height + width; i++) {
        print_spaces(spaces);
        print_coordinates(row_width, x_start, y_start);
        printf("\n");

        if(i < height - 1) {
            // as i increases, the diamond gets larger and closer
            // to the left edge. The width of the row stops increasing
            // but doesn't start decreasing until the width is reached.
            spaces--;
            row_width++;
            y_start++;
        } else {
            // When you turn the corner from the height, stop
            // incrementing the height and start incrementing
            // the width, and the space from the left edge increases
            x_start++;
            spaces++;
        }

        if(i > width - 2) {
            // Once the width is reached, the row_width starts decreasing
            // Will cancel out the increase in row_width if the height hasn't
            // been reached yet.
            row_width--;
        }
    }
}

int main()
{
    int width, height;

    scanf("%d%d", &width, &height);

    solve(width, height);
}
