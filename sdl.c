// Copyright 2011 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

int main() {
  SDL_Color color;
  color.r=255;
  color.g=255;
  color.b=0;
  printf("run\n");
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen = SDL_SetVideoMode(800, 640, 32, SDL_SWSURFACE);
#ifdef TEST_SDL_LOCK_OPTS
  EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif
  SDL_Rect outlineRect = { 100, 100, 100, 100 };
          
  SDL_FillRect( screen, &outlineRect ,SDL_MapRGB(screen->format, color.r, color.g, color.b));
 
  SDL_Flip(screen);
  printf("\n\nend\n ");
  SDL_Quit();
  

  return 0;
}