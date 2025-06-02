#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define GRID_LAYOUT_X 5
#define GRID_LAYOUT_Y 5
#define RECT_LEN 150
#define RECT_ROUNDNESS 0.5
#define DEFAULT_RECT_COLOR GRAY 
#define RECT_MEM_SIZE sizeof(Rectangle)

const char *TITLE = "Randomizer";

typedef struct Container 
{
    int count; 
    Rectangle rect;
} Container;

void generate_grid(Container *container, int rows, int cols)
{
   int rect_count = rows*cols;
   int padding = ((WIN_WIDTH - (rows * RECT_LEN))/2);
   container = malloc((sizeof(Rectangle) * rect_count) + sizeof(Container));
   printf("size of allocated memeory: %ld \n", sizeof(container));
   if (container == NULL) printf("Failed to allocate memory\n");
    
   for (int x=0; x<rows; x++)
   {
        for (int y=0; y<cols; y++)
        {
            Rectangle rect;
            rect.x = (x * RECT_LEN) + padding;
            rect.y = (y * RECT_LEN) + padding;
            rect.width = rect.height = RECT_LEN;
            container[y].rect = rect;
            // DrawRectangleRounded(rect, RECT_ROUNDNESS, 1, DEFAULT_RECT_COLOR); 
        }
   }
}

void start_randomizer(Container *container)
{
    printf("starting randomizer \n");
    for (int i=0; i<container->count; i++)
    {
        DrawRectangleRounded(container[i].rect, RECT_ROUNDNESS, 1, DEFAULT_RECT_COLOR); 
    }
}

int main()
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, TITLE);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(CLITERAL (Color) { 0x18, 0x18, 0x18, 0xff });
        
        Container *container = NULL;
        generate_grid(container, GRID_LAYOUT_X, GRID_LAYOUT_Y);
        start_randomizer(container);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}


