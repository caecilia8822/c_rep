#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Block Game");

    Rectangle p = {350, 550, 100, 20};
    Rectangle b = {350, 100, 100, 30};

    float x = 400, y = 300;
    float sx = 4, sy = 4;

    bool block = true;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_LEFT)) p.x -= 5;
        if (IsKeyDown(KEY_RIGHT)) p.x += 5;
      
        x += sx;
        y += sy;
      
        if (x < 0 || x > 800) sx *= -1;
        if (y < 0) sy *= -1;

        if (CheckCollisionCircleRec((Vector2){x,y},10,p))
            sy *= -1;

        if (block &&
            CheckCollisionCircleRec((Vector2){x,y},10,b))
        {
            block = false;
            sy *= -1;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangleRec(p, BLUE);

        if (block)
            DrawRectangleRec(b, RED);

        DrawCircle(x, y, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();
}
