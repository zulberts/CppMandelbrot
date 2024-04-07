#include "SDL2/SDL.h"
#include <numeric>
#include <complex>
#include <iostream>

int is_in_set(std::complex<double> c)
{
    std::complex<double> z(0,0);
    for(int i = 0; i < 25; i++)
    {
        z = std::pow(z,2) + c;
        if(std::norm(z) > 10)
        {
            return i;
        }
    }
    return 0;
}

template <typename T>
T lerp(T a, T b, T t)
{
    return a + (b - a) * t;
}

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000,500,0, &window, &renderer);
    SDL_RenderSetScale(renderer,0.5,0.5);

    for (double x = 0.0; x < 1.0; x+=0.001)
    {
        for (double y = 0.0; y < 1.0; y+=0.001)
        {
            double point_x = lerp(-2.0, 2.0,x);
            double point_y = lerp(-2.0, 2.0,y);
            int iters = is_in_set(std::complex<double>(point_x, point_y));
            if (iters == 0)
            {
                SDL_SetRenderDrawColor(renderer,0,0,0,200);
                SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
            }
            else
            {

                SDL_SetRenderDrawColor(
                    renderer,
                    3 * iters % 25,
                    3 * iters % 25,
                    3 * iters % 25,
                    255);
                SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
            }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
}