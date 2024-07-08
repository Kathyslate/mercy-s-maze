#include "maze.h"
#include "enemy.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

// Global variables (assuming defined in maze.h)
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
point_t pos;
point_t dir;
point_t plane;
double time;

Enemy enemy;  // Define global enemy instance

int main(int argc, char *argv[]) {
    int *maze;  // 2D array defining maze map
    char *mapName;
    bool textured;

    // Initial values for global variables
    pos.x = 1;
    pos.y = 12;
    dir.x = 1;
    dir.y = -0.66;
    plane.x = 0;
    plane.y = 0.66;
    time = 0;

    // Check user arguments and set options
    mapName = "\0";
    textured = true;
    if (argc == 3) {
        if (strcmp(argv[2], "no_tex") == 0)
            textured = false;
        mapName = argv[1];
    } else if (argc == 2) {
        if (strcmp(argv[1], "no_tex") == 0) {
            mapName = "maps/map_0";
            textured = false;
        } else
            mapName = argv[1];
    } else if (argc == 1)
        mapName = "maps/map_0";

    // Start SDL and create window and renderer
    printf("Initializing SDL...\n");
    if (!initSDL()) {
        fprintf(stderr, "Failed to initialize SDL\n");
        return (1);
    }
    printf("SDL initialized successfully\n");

    // Parse maze file
    printf("Parsing maze map...\n");
    maze = NULL;
    maze = parseMap(mapName, maze);
    if (maze == NULL) {
        fprintf(stderr, "Failed to parse maze map\n");
        return (1);
    }
    printf("Maze map parsed successfully\n");

    // Initialize enemy
    enemy.x = 5.0;  // Example initial position
    enemy.y = 5.0;
    enemy.speed = 0.05;  // Example speed, adjust as needed
    enemy.health = 100;  // Example health, adjust as needed
    enemy.texture = IMG_LoadTexture(renderer, "textures/enemy.png");  // Load enemy texture
    if (enemy.texture == NULL) {
        fprintf(stderr, "Failed to load enemy texture\n");
        return (1);
    }
    printf("Enemy initialized successfully\n");

    if (textured) {
        printf("Loading textures...\n");
        loadTextures(mapName);
        printf("Textures loaded successfully\n");
    }

    // Game loop
    while (!quit()) {
        // Clear the buffer
        clearBuffer();

        if (!textured)
            renderBGFlat();  // Render background if no textures

        // Draw walls, textured floor, and textured ceiling
        raycaster(maze, textured);

        // Update and render the enemy
        updateEnemy();
        renderEnemy();

        // Handle user input
        input(maze);

        // Present the rendered frame
        SDL_RenderPresent(renderer);
    }

    // Close SDL, renderer, and window
    printf("Closing SDL...\n");
    closeSDL();
    free(maze);
    freeEnemy();  // Free enemy resources
    printf("SDL closed successfully\n");
    return (0);
}

