#include "raylib.h"
int main()
{
    int width {800};
    int height {450};
    InitWindow(width,  height,"Erik's window");

    // Circle coordintates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    // Circle Edges
int l_circle_x{circle_x - circle_radius};
int r_circle_x{circle_x + circle_radius};
int u_circle_y{circle_y - circle_radius};
int b_circle_y{circle_y + circle_radius};

    // Axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};

    // Condition Finish game
    bool collision_with_axe{false};


    SetTargetFPS(60 );
    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

    if(collision_with_axe)
    {
        DrawText("Game Over!", width, height, 50, RED);
    }
        else
        {
    // Game logic begins

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            // Move the axe
            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            } 

            if(IsKeyDown(KEY_D) && circle_x < width )
            {
                circle_x += 10;
            }
            if(IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }
            // Game logic ends
            }
            
        EndDrawing();
    
    }
}