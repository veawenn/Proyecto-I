#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include <math.h>   

#include <vector>   

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

static const float screenWidth = 800;
static const float screenHeight = 450;

static bool gameOver = false;
static bool pause = false;
static bool victory = false;

static void InitGame(void);         // Initialize game
static void UpdateGame(Player* player);       // Update game (one frame)
static void DrawGame(Player* player);         // Draw game (one frame)
static void DrawMap(void);
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(Player* player);  // Update and Draw (one frame)

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "Base");

    InitGame();

    Vector2 initPos = { screenWidth / 2, screenHeight / 2 };

    Player player(50, initPos, RED);

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

    DrawMap();

    /*
    Image bgImage = LoadImage("Bomberman Sprites/General Sprites/Playfield_Sprite.png");
    ImageResize(&bgImage, 992, 416);
    Texture2D bgText = LoadTextureFromImage(bgImage);
    UnloadImage(bgImage);

    DrawTexture(bgText, 0, 50, WHITE);
    */
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

void DrawMap()
{
    int mapSetter[31][13];

    Vector2 cellSize = { 50,50 };
 
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (i == 0 || j == 0)
            {
                Vector2 tempPos = { 0, 0 };
                DrawRectangleV(tempPos, cellSize, WHITE);
            }

            if ((i % 2 == 0) && (j % 2 == 0))
            {
                Vector2 tempPos = { i * 50, j * 50 };
                DrawRectangleV(tempPos, cellSize, WHITE);
            }
        }
    }
}


/*void UnloadGame(void)
{

}*/