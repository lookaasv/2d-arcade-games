#include "raylib.h"
#include<vector>
#include<string>
#include<bits/stdc++.h>

int MAX_PARTICLES1 = 20;
int MAX_PARTICLES2;

using namespace std;

Vector2 operator + (Vector2 const &v1, Vector2 const &v2)
{
    Vector2 v{v1.x + v2.x, v1.y + v2.y};
    return v;
}

class Particle1 final
{
    public:
        Vector2 acc{0.0f, 0.05f};
        Vector2 position;
        Vector2 velocity{(float)GetRandomValue(-5, 5)*.1f, (float)GetRandomValue(-20, 20)*.1f};
        float size{5.0f};
        Particle1(Vector2& pos): position{pos}{}
        void draw()
        {
            //DrawCircle(position.x, position.y, size, RED); //V1
            //DrawRectangle(position.x, position.y, size, size, ORANGE); //V2
            DrawCircleLines(position.x, position.y, size, RAYWHITE); ///V3
        }
        void update()
        {
            velocity = velocity + acc;
            position = position + velocity;
            if (GetRandomValue(0, 100)<30) size -= 1;
        }
};

class Particle2 final
{
    public:
        Vector2 acc{0.0f, 0.05f};
        Vector2 position;
        Vector2 velocity{(float)GetRandomValue(-5, 5)*.1f, (float)GetRandomValue(-5, 5)*.1f};
        float size{1.0f};
        static float particleSize;
        Particle2(Vector2& pos): position{pos}{}
        void draw()
        {
            DrawCircle(position.x, position.y, size, RED); ///V1
            //DrawRectangle(position.x, position.y, size, size, ORANGE); //V2
            //DrawCircleLines(position.x, position.y, size, RAYWHITE); //V3
        }
        void update()
        {
            velocity = velocity + acc;
            position = position + velocity;
            if (GetRandomValue(0, 100)<30) size -= 1;
            particleSize = size;
        }
};

float Particle2::particleSize = 1.0f;

class System1 final
{
    public:
        vector<Particle1> system;
        System1(Vector2& pos) noexcept
        {
            system.reserve(MAX_PARTICLES1);
            for (int i = 0; i < MAX_PARTICLES1; i++)
            {
                system.emplace_back(pos);
            }
        }
        void draw()
        {
            for (vector<Particle1>::iterator obj = system.begin(); obj < system.end(); obj++)
            {
                (*obj).draw();
            }
        }
        void update()
        {
            system.erase
            (
                std::remove_if( system.begin(), system.end(), []( auto& p )
                {
                   p.update(); return p.size <= 0;
                } ),
                system.end()
            );
        }
};

class System2 final
{
    public:
        vector<Particle2> system;
        System2(Vector2& pos) noexcept
        {
            system.reserve(MAX_PARTICLES2);
            for (int i = 0; i < MAX_PARTICLES2; i++)
            {
                system.emplace_back(pos);
            }
        }
        void draw()
        {
            for (vector<Particle2>::iterator obj = system.begin(); obj < system.end(); obj++) {
                (*obj).draw();
            }
        }
        void update()
        {
            system.erase
            (
                std::remove_if( system.begin(), system.end(), []( auto& p )
                {
                   p.update(); return p.size <= 0;
                } ),
                system.end()
            );
        }
};

const int screenWidth = 960; //16:9 aspect ratio
const int screenHeight = 540; //16:9 aspect ratio
const float initialBallSpeed = 250.0f;
float initialPaddleSpeed = 250.0f;
const float paddleWidth = 25.0f;
const float paddleHeight = 100.0f;
const float ballRadius = 10.0f;

struct Ball
{
    Vector2 position;
    Vector2 speed;
    float radius;
    int hits;
};

struct Paddle
{
    Vector2 position;
    float height;
    float width;
};

void InitBall(Ball &ball)
{
    ball.position = { (float)screenWidth / 2, (float)screenHeight / 2 };
    ball.speed = { initialBallSpeed, initialBallSpeed };
    ball.radius = ballRadius;
    ball.hits = 0;
}

void InitPaddle(Paddle &paddle, int player)
{
    if (player == 1)
        paddle.position = { 0 + paddleWidth, (float)screenHeight / 2 };
    if (player == 2)
        paddle.position = { screenWidth - paddleWidth*2, (float)screenHeight / 2 }; //times 2 because of compensation of the width of paddle
    paddle.height = paddleHeight;
    paddle.width = paddleWidth;
}

void UpdateBall(Ball &ball, float deltaTime)
{
    ball.position.x += ball.speed.x * deltaTime;
    ball.position.y += ball.speed.y * deltaTime;

    if (ball.position.y <= ball.radius) {
        ball.speed.y *= -1;
        ball.position.y = ball.radius;
    }

    if (ball.position.y >= screenHeight - ball.radius) {
        ball.speed.y *= -1;
        ball.position.y = screenHeight - ball.radius;
    }
}

void ControlPaddle(Paddle &paddle, float deltaTime, int player)
{
    if (player == 1) {
        if (IsKeyDown(KEY_W))
            paddle.position.y -= initialPaddleSpeed * deltaTime;
        if (IsKeyDown(KEY_S))
            paddle.position.y += initialPaddleSpeed * deltaTime;
    }
    else if (player == 2) {
        if (IsKeyDown(KEY_UP))
            paddle.position.y -= initialPaddleSpeed * deltaTime;
        if (IsKeyDown(KEY_DOWN))
            paddle.position.y += initialPaddleSpeed * deltaTime;
    }

    if (paddle.position.y <= 0)
        paddle.position.y = 0;
    if (paddle.position.y + paddle.height >= screenHeight)
        paddle.position.y = screenHeight - paddle.height;
}

void StartCountdown()
{
    int count = 3;
    float timer = 0.0f;
    float countdownTime = 0.2f;

    while (count > 0) {
        timer += GetFrameTime();
        if (timer >= countdownTime) {
            count--;
            timer = 0;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        if (count != 0)
            DrawText(TextFormat("%d", count), (screenWidth - 100)/2, (screenHeight - 200)/2, 200, RAYWHITE);
        EndDrawing();
    }
}

void RestartGame(Ball &ball, Paddle &paddle1, Paddle &paddle2)
{
    StartCountdown();
    int count = 1;
    float timer = 0.0f;
    float countdownTime = 0.2f;
    while (count > 0) {
        timer += GetFrameTime();
        if (timer >= countdownTime) {
            count--;
            timer = 0;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    ball.position = (Vector2){ screenWidth/2, screenHeight/2 };
    ball.speed = (Vector2){ initialBallSpeed, initialBallSpeed };
    initialPaddleSpeed = 250.0f;
    ball.hits = 0;
    MAX_PARTICLES2 = 2*ball.hits;
    Particle2::particleSize = 1.0f;
    paddle1.position = { 0 + paddleWidth, (float)screenHeight / 2 };
    paddle2.position = { screenWidth - paddleWidth*2, (float)screenHeight / 2 };
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Pong Game");
    SetTargetFPS(50);


    vector<System1> P_system1;
    vector<System2> P_system2;
    Vector2 m_pos1;
    Vector2 m_pos2;

    P_system1.reserve(50);
    P_system2.reserve(50);


    int p1Score = 0;
    int p2Score = 0;

    Ball ball;
    InitBall(ball);

    Paddle paddle1;
    Paddle paddle2;
    InitPaddle(paddle1, 1);
    InitPaddle(paddle2, 2);

    RestartGame(ball, paddle1, paddle2); //consistency: only edit restart function for all instances including the first round of the game

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        ///process input
        ControlPaddle(paddle1, deltaTime, 1);
        ControlPaddle(paddle2, deltaTime, 2);
        //if (IsKeyDown(KEY_R)) RestartGame(ball, paddle1, paddle2);

        ///update game
        UpdateBall(ball, deltaTime);
        m_pos2 = (Vector2){(float)ball.position.x, (float)ball.position.y};
        P_system2.emplace_back(m_pos2);
        if (CheckCollisionCircleRec(ball.position, ballRadius, (Rectangle){ paddle1.position.x, paddle1.position.y, paddle1.width, paddle1.height }))
        {
            m_pos1 = (Vector2){(float)ball.position.x + ball.radius, (float)ball.position.y};
            P_system1.emplace_back(m_pos1);
            ball.speed.x *= -1*1.1f;
            initialPaddleSpeed *= 1.1f;
            ball.hits++;
            MAX_PARTICLES2 = 2*ball.hits;
            Particle2::particleSize = (float)ball.hits;
            ball.position.x = paddle1.position.x + paddle1.width + ballRadius;
        }
        if (CheckCollisionCircleRec(ball.position, ballRadius, (Rectangle){ paddle2.position.x, paddle2.position.y, paddle2.width, paddle2.height }))
        {
            m_pos1 = (Vector2){(float)ball.position.x - ball.radius, (float)ball.position.y};
            P_system1.emplace_back(m_pos1);
            ball.speed.x *= -1*1.1f;
            initialPaddleSpeed *= 1.1f;
            ball.hits++;
            MAX_PARTICLES2 = 2*ball.hits;
            Particle2::particleSize = (float)ball.hits;
            ball.position.x = paddle2.position.x - ballRadius;
        }

        if (ball.position.x >= screenWidth)
        {
            p1Score++;
            RestartGame(ball, paddle1, paddle2);
        }
        if (ball.position.x <= 0)
        {
            p2Score++;
            RestartGame(ball, paddle1, paddle2);
        }

        ///draw frame
        BeginDrawing();
        ClearBackground(BLACK);
        P_system1.erase(
            std::remove_if( P_system1.begin(), P_system1.end(), []( System1& sys ){
               sys.update();
               sys.draw();
               return sys.system.size() <= 0;
            } ),
            P_system1.end()
        );
        P_system2.erase(
            std::remove_if( P_system2.begin(), P_system2.end(), []( System2& sys ){
               sys.update();
               sys.draw();
               return sys.system.size() <= 0;
            } ),
            P_system2.end()
        );
        DrawCircleV(ball.position, 10, RAYWHITE);
        DrawRectangleRec( (Rectangle){ paddle1.position.x, paddle1.position.y, paddle1.width, paddle1.height }, RAYWHITE);
        DrawRectangleRec( (Rectangle){ paddle2.position.x, paddle2.position.y, paddle2.width, paddle2.height }, RAYWHITE);
        for (float i = 5; i <= 545; i+=30)
        {
            DrawRectangleRec( (Rectangle){ screenWidth/2, i, 5, 20 }, RAYWHITE);
        }
        DrawText(TextFormat("%d", p1Score), screenWidth/4, screenHeight/4, 100, RAYWHITE);
        DrawText(TextFormat("%d", p2Score), screenWidth*3/4 - 50, screenHeight/4, 100, RAYWHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
