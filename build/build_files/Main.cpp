#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include <math.h>   

#include <iostream>"
using namespace std;


#define PLAYER_SPEED    6.0f
#define PLAYER_MAX_BOMBS    5

class Player
{
private:
    int playerHp;
    Vector2 position;
    float acceleration;
    Color color;

public:
    Player();

    Player(int playerHp, Vector2 posVector, Color color)
    {
        position = posVector;
        this->color = color;
        this->playerHp = playerHp;

    }

    Vector2 getPos()
    {
        return position;
    }       

    void updatePos(float speedX, float speedY)
    {
        position.x += speedX;
        position.y += speedY;
    }
};

static const int screenWidth = 1920;
static const int screenHeight = 1080;

static bool gameOver = false;
static bool pause = false;
static bool victory = false;

static void InitGame(void);         // Initialize game
static void UpdateGame(Player* player);       // Update game (one frame)
static void DrawGame(Player* player);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(Player* player);  // Update and Draw (one frame)

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "Base");

    Vector2 initPos = { screenWidth / 2, screenHeight / 2 };

    Player player(initPos, RED);

    while (!WindowShouldClose())
    {       
        UpdateDrawFrame(&player);    
    }

    //UnloadGame();
    //CloseWindow();

    return 0;
}

void InitGame()
{
    gameOver = false;
    pause = false;
    victory = false;
}

void UpdateGame(Player* player)
{
    if (!gameOver)
    {
        if (IsKeyDown(KEY_UP))
        {
            player->updatePos(0, -PLAYER_SPEED);
        }

        if (IsKeyDown(KEY_DOWN))
        {
            player->updatePos(0, PLAYER_SPEED);
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            player->updatePos(PLAYER_SPEED, 0);
        }

        if (IsKeyDown(KEY_LEFT))
        {
            player->updatePos(-PLAYER_SPEED, 0);
        }
    }
}

void DrawGame(Player* player)
{
    BeginDrawing();

    ClearBackground(BLACK);

    Vector2 playersize = { 50, 50 };

    DrawRectangleV(player->getPos(), playersize, RED);

    /*if (!gameOver)
    {
        
    }*/ 

    EndDrawing();
}

void UpdateDrawFrame(Player* player)
{
    DrawGame(player);
    UpdateGame(player);    
}


/*void UnloadGame(void)
{

}*/