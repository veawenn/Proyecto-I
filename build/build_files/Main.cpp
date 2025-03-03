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
    Vector2 speed;
    float acceleration;
    Color color;

public:
	Player();

    Player(Vector2 posVector, Color color)
    {
        position = posVector;
        this->color = color;
    }
};

static const int screenWidth = 800;
static const int screenHeight = 450;

static bool gameOver = false;
static bool pause = false;
static bool victory = false;

static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)

int main() 
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);


    while (!WindowShouldClose())
    {
        SetTargetFPS(60);

        while (!WindowShouldClose())
        {
            UpdateDrawFrame();
        }

         UnloadGame();        

         CloseWindow();

         return 0;
    }

    CloseWindow();

    return 0;   
}
