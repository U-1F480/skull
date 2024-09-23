#include <err.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

// This file contains all that is needed to take a picture and and boost it's saturation

Uint32 saturation(Uint32 pixel_color, SDL_PixelFormat *format)
{
  
  Uint8 r; 
  Uint8 g;
  Uint8 b; 
  SDL_GetRGB(pixel_color,format,&r,&g,&b);
  //value found in the internet : https://en.wikipedia.org/wiki/Luminance_%28relative%29
  Uint8 Y = 0.2126 * r + 0.7152 * g + 0.0722 * b;
  pixel_color = SDL_MapRGB(format,Y+r,Y+g,Y+b);
  return pixel_color;
  
}

void saturation_All(SDL_Surface *surface)
{
  int w = surface->w;
  int h = surface->h;
  int pixel_count = w * h;
  Uint32 *pixels = (Uint32 *) surface->pixels;

  SDL_LockSurface(surface);
   
  SDL_PixelFormat *format = surface->format; 
  
    for (int i = 0; i < pixel_count; i++) {
      pixels[i] = saturation(pixels[i],format);
    }

  SDL_UnlockSurface(surface);
}

