#include <stdio.h>

/*
** view.c
** Jim Kersey 2023
** --------------------
** jim.kersey@gmail.com
**
** given a width and height of a map, and an x/y coordinate,
** draw a rectangle centered on that section of the map.
**
*/

typedef struct coordinate_s {
    int x;
    int y;
} coordinate_t;


typedef struct game_map_s {
    int width;
    int height;
} game_map_t;


typedef struct map_view_s {
    game_map_t game_map;
    coordinate_t center;
    int size;
} map_view_t;


void print_spaces(int spaces) {
    for (int i = 0; i < spaces; ++i) {
        printf(" ");
    }
}

void print_coordinates(int width, int x_start, int y_start) {
    // Prints width section of the row
    for (int i = 0; i < width; ++i) {
        printf(". ");
    }
    printf("\n");
}

int start_row_is_odd(int x_start, int y_start) {
    if(x_start % 2 != y_start % 2) {
        return 0;
    } else {
        return 1;
    }
}

void draw_view(
    int top_x, int top_y,
    int view_size,
    int map_width, int map_height) {
    // integers could be negative, draw spaces instead of coordinates
    int x_start = top_x;
    int y_start = top_y;

    int flipper = start_row_is_odd(x_start, y_start);

    if(flipper == 1) {
        print_spaces(1);
        print_coordinates(view_size, x_start, y_start);
        y_start ++;
    }

    for(int i = 0; i < view_size; ++i) {
        print_coordinates(view_size + 1, x_start, y_start);
        x_start++;
        print_spaces(1);
        print_coordinates(view_size, x_start, y_start);
        y_start++;
    }

    if(flipper == 0) {
        print_coordinates(view_size + 1, x_start, y_start);
    }


    printf("\n");
}

void solve(map_view_t view) {
    int start_x = view.center.x - view.size;
    int start_y = view.center.y;

    draw_view(start_x,
              start_y,
              view.size,
              view.game_map.width,
              view.game_map.height);
}

int main() {
    int map_width, map_height;
    int view_size;
    int center_x, center_y;

    scanf("%d%d", &map_width, &map_height);
    scanf("%d", &view_size);
    scanf("%d%d", &center_x, &center_y);

    game_map_t game_map = {map_width, map_height};
    coordinate_t center = {center_x, center_y};

    map_view_t view = {game_map, center, view_size};

    solve(view);
}
