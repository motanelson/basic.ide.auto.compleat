// Copyright 2011 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <emscripten.h>
SDL_Surface *screen = NULL;
int i=100;
int x=0;
int y=0;
int xxx=10;
int yyy=10;
void kernel_main(){
  int xx=x+20;
  int yy=y+20;
  
  SDL_Color color;
  SDL_Color color2;
  SDL_Rect outlineRect= { xx, y, 70, 110 };
  SDL_Rect outlineRect3= { x, yy, 110, 70 };
  SDL_Rect outlineRect2= { 0, 0, 800, 600 };
  color.r=255;
  color.g=255;
  color.b=0;
  color2.r=0;
  color2.g=0;
  color2.b=0;
       
     
     SDL_FillRect( screen, &outlineRect2 ,SDL_MapRGB(screen->format, color2.r, color2.g, color2.b));     
     SDL_FillRect( screen, &outlineRect ,SDL_MapRGB(screen->format, color.r, color.g, color.b));
     SDL_FillRect( screen, &outlineRect3 ,SDL_MapRGB(screen->format, color.r, color.g, color.b));
     SDL_Flip(screen);
     if(x>690)xxx=-10;
     if (y>490)yyy=-10;
     if(x<10)xxx=10;
     if (y<10)yyy=10;
     y=y+yyy;
     x=x+xxx;
   

  


}

int main() {
  SDL_Color color;
  SDL_Rect outlineRect= { 100, 100, 100, 100 };
  color.r=255;
  color.g=255;
  color.b=0;
  printf("run\n");
  SDL_Init(SDL_INIT_VIDEO);
  screen =(SDL_Surface *) SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
#ifdef TEST_SDL_LOCK_OPTS
  EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif
    
  emscripten_set_main_loop(kernel_main,1,0);
  printf("\n\nrender\n ");
  
  

  return 0;
}
