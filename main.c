#include <stdio.h>
#include <stdlib.h>
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

typedef struct Tile
{
    Color color;
    Rectangle rect;
} Tile;

typedef struct TileContainer
{
    int count;
    Tile *tiles;
} TileContainer;

TileContainer *generate_grid(int rows, int cols)
{
   TileContainer *tile_container = NULL;
   Tile *tile = NULL;

   int rect_count = rows*cols;
   int padding = ((WIN_WIDTH - (rows * RECT_LEN))/2);
   tile = (Tile*)malloc((sizeof(Tile) * rect_count));

   if (tile == NULL)
    {
        printf("Failed to allocate memory\n");
        exit(1);
    }
    
   for (int x=0; x<rows; x++)
   {
        for (int y=0; y<cols; y++)
        {
            Rectangle rect;
            rect.x = (x * RECT_LEN) + padding;
            rect.y = (y * RECT_LEN) + padding;
            rect.width = rect.height = RECT_LEN;
            tile[y].rect  = rect;
            // DrawRectangleRounded(rect, RECT_ROUNDNESS, 1, DEFAULT_RECT_COLOR); 
        }
   }

   tile_container->count = rect_count;
   tile_container->tiles = tile;
   return tile_container;
}

void start_randomizer(TileContainer *tile_container)
{
    for (int i=0; i<tile_container->count; i++)
    {
        DrawRectangleRounded(tile_container[i]->tile.rect[i], RECT_ROUNDNESS, 1, DEFAULT_RECT_COLOR); 
    }
}

int main()
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, TITLE);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(CLITERAL (Color) { 0x18, 0x18, 0x18, 0xff });
        
        TileContainer *container = NULL;
        container = generate_grid(GRID_LAYOUT_X, GRID_LAYOUT_Y);
        start_randomizer(container);

        EndDrawing();
    }

    CloseWindow();
    free(container); 
    return 0;
}


