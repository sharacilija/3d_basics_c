// move around with wasd and space
#include <stdio.h>
#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600

int main(int argc, char const *argv[])
{
    InitWindow(WIDTH, HEIGHT, "3D Cube");

    SetTargetFPS(60);

    Vector3 pos = {5, 0, 0};
    Vector3 target = {0, 0, 0};
    Vector3 up = {0, 0, 1};
    float fovy = 90;
    Camera3D cam = {pos, target, up, fovy, CAMERA_PERSPECTIVE};

    while(!WindowShouldClose())
    {
        UpdateCamera(&cam, CAMERA_FREE);
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(cam);
        printf("cam.position.x = %f\n", cam.position.x);

        Vector3 origin = {0, 0, 0};
        DrawCube(origin, 1, 1, 1, RED);
        DrawCubeWires(origin, 1, 1, 1, WHITE);

        EndMode3D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
