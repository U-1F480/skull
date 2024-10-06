#include <err.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

// This file contains all that is needed to take a picture and make a grayscale of it  

Uint32 grayscale(Uint32 pixel_color, SDL_PixelFormat *format)
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    SDL_GetRGB(pixel_color,format,&r,&g,&b);
    //formula for grayscale found on the internet : 
    //https://gigi.nullneuron.net/gigilabs/converting-an-image-to-grayscale-using-sdl2/
    Uint8 v = 0.212671f * r + 0.715160f * g + 0.072169f * b; 
    pixel_color = SDL_MapRGB(format,v,v,v);
    return pixel_color;

}

void grayscale_All(SDL_Surface *surface)
{
  int w = surface->w;
  int h = surface->h;
  int pixel_count = w * h;
  Uint32 *pixels = (Uint32 *) surface->pixels;

  SDL_LockSurface(surface);
   
  SDL_PixelFormat *format = surface->format; 
  
    for (int i = 0; i < pixel_count; i++) {
      pixels[i] = grayscale(pixels[i],format);
    }

  SDL_UnlockSurface(surface);
}

