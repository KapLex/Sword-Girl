
#include "assist.h"

int SDL_BlitText( const char *text, SDL_Surface *dest_surf,
        int x_offset, int y_offset,
        TTF_Font *font, SDL_Color color)
{
    if (text[0] == '\0')
        return 1;

    SDL_Surface *temp = TTF_RenderUTF8_Solid(font, text, color);
    SDL_Rect src, dest;
    src.x = 0;
    src.y = 0;
    src.w = temp->w;
    src.h = temp->h;
    dest.x = x_offset;
    dest.y = y_offset;
    dest.w = temp->w;
    dest.h = temp->h;

    SDL_BlitSurface(temp, &src, dest_surf, &dest);
    SDL_FreeSurface(temp);

    return 0;

}

void CreateBmpSurface(SDL_Surface ** surf, const char *bmp_path)
{
    SDL_Surface *temp = SDL_LoadBMP(bmp_path);
    if (temp == NULL){
        printf("Unable to load bitmap.\n");
        exit(1);
    }
    *surf = SDL_DisplayFormat(temp);
    if (*surf == NULL){
        printf("Unable to convert bitmap.\n");
        exit(1);
    }
    SDL_FreeSurface(temp);
}
