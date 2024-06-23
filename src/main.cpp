#include <fmt/format.h>
#include <raylib.h>

int main() {
    fmt::print("Hello, World!\n");

    InitWindow(800, 450, "raylib [core] example - basic window");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
