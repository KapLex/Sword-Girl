#ifndef __MENUH__
#define __MENUH__

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
//*****************************菜单模块**********************************
class Menu
{
public:
	char Name[16];
	int X;
	int Y;
	int Sel;
	int W;
	int H;
    SDL_Surface * Surf;
    TTF_Font *Font;
    SDL_Color *Color;
public:
	~Menu();
	void draw_menu(SDL_Surface *dest_surf);
	void set_menu(const char name[],int x, int y,int w,int h,
				 int sel, SDL_Surface *surf,
                 TTF_Font *font, SDL_Color *color);

};


#endif
