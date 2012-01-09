
#ifndef ASSIST_H
#define ASSIST_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

int SDL_BlitText(const char *text, SDL_Surface *dest_surf,
        int x_offset, int y_offset,
        TTF_Font *font, SDL_Color color);

void CreateBmpSurface(SDL_Surface ** surf, const char *bmp_path);

#endif
