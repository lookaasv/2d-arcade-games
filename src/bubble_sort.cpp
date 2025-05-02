#include "raylib.h"

void bubbleSort(int *h_arr, int *states, int *flag, int w, int *counter)
{
    if ((*counter) < w)
    {
        for (int j = 0; j < w - 1 - (*counter); j++)
        {
            if (h_arr[j] > h_arr[j+1])
            {
                states[j] = 0;
                states[j+1] = 0;
                int temp = h_arr[j];
                h_arr[j] = h_arr[j+1];
                h_arr[j+1] = temp;
            }
            else
            {
                states[j] = 1;
                states[j+1] = 1;
            }

        }
    }
    else
    {
        (*flag) = 1;
    }
    (*counter)++;
    if (w - (*counter) >= 0)
    {
        states[w - (*counter)] = 2;
    }
}


int button(int x, int y, const char *text, int *begin)
{
    struct Rectangle r1 = {.x = x - 10, .y = y - 5, .width= MeasureText(text, 80) + 20, .height= 50};
    if (CheckCollisionPointRec(GetMousePosition(), r1))
    {
        DrawText(text, x - 30, y-15, 100, RED);
        if (IsMouseButtonPressed(0))
        {
            if (*begin == 0)
            {
                *begin = 1;
            }
            else if(*begin == 1)
            {
                *begin = 0;
            }
            return 1;
        }
    }
    else
    {
        DrawText(text, x, y, 80, RED);
        return 0;
    }
    return 0;
}

int main(void)
{
    // INITIALIZARE
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Bubble Sort");
    SetTargetFPS(60); // SETEAZA APLICATIA SA RULEZE LA 60 CADRE PE SECUNDA

    int n = 4; //LATIMEA BARILOR
    const int w = 200; //NUMARUL BARILOR

    //VECTORUL BARILOR SI A STATUSULUI LOR
    int h_arr[w], states[w];

    int counter = 0, flag= 0, id1 = 0, id2 = 0, begin = 0;
    int *countptr = &counter, *flagptr = &flag, *beginptr = &begin;

    // CICLUL PRINCIPAL AL APLICATIEI
    while (!WindowShouldClose())    // DETECTEAZA DACA FEREASTRA A FOST INCHISA SAU 'ESC' A FOST APASAT
    {
        if (id1 == 1)
        {
            bubbleSort(h_arr, states, flagptr, w, countptr);
        }

        // DRAW FUNCTION
        Color color = WHITE;
        BeginDrawing();
            ClearBackground(BLACK);
            if (begin == 1)
            {
                for (int i = 0; i < w; i++)
                {
                    if (states[i] == 0)
                    {
                        color = RED;
                    }else if (states[i] == 2)
                    {
                        color = GREEN;
                    }else
                    {
                        color = WHITE;
                    }
                    DrawRectangle(i*n, screenHeight - h_arr[i], n, h_arr[i], color);
                }
                if (flag == 1)
                {
                   if (button(screenWidth/2 - 100, screenHeight/2, "Gata", beginptr) == 1)
                   {
                       CloseWindow();
                       return 0;
                   }

                }
            }
            else
            {
                for (int i = 0; i < w ; i++)
                {
                    h_arr[i] = GetRandomValue(10, 440);
                    states[i] = 1;
                }
                int counter = 0, flag= 0;
                int *countptr = &counter, *flagptr = &flag;

                id1 = button(screenWidth/5, screenHeight/4, "Bubble Sort", beginptr);
            }
        EndDrawing();
    }
    CloseWindow();        // INCHIDE FEREASTRA
    return 0;
}
