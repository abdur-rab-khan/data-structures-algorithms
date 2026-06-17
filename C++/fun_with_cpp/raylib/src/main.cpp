#include <raylib.h>

int main() {
    InitWindow(800, 450, "Hello");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello Raylib! Welcome to my world!", 20, 20, 20, BLUE);
        EndDrawing();
    }

    CloseWindow();
}