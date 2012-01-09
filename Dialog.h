#ifndef DIALOG_H_
#define DIALOG_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Map.h"
class Dialog
{
private:
	char  Words[2000];	//对话内容
	short Height;	//高度
	short Width;	//宽度
	short X;	//在屏幕中显示的位置
	short Y;
	short cHeight; //字符高度
	short count_in_row; //一行中的字符数
	short num_row;//二行
	short cX;	//字符在屏幕中显示的起始位置
	short cY;
	int num; //计数器

    SDL_Surface *Surf;
    TTF_Font *Font;
    SDL_Color *Color;

public:
	Dialog();
	~Dialog();
	short is_over();
	void show(SDL_Surface *dest_surf);
	void set_text(const char *);
	void set_dlg(SDL_Surface *surf, TTF_Font *font, SDL_Color *color);

};

#endif
