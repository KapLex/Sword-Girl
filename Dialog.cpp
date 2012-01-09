#include "Dialog.h"
#include "assist.h"

Dialog::Dialog()
{
	strcpy(Words,"");
	Height = 60;
	Width = 300;
	cHeight = 20;
	count_in_row = 48;
	cX = 20;
	cY = 10;
	num_row = 2;
	Surf = NULL;
    Font = NULL;
    Color = NULL;
	X = SCR_W/8;
	Y = SCR_H-Height;
	num = 0;
}

Dialog::~Dialog()
{
//	Words = NULL;
	Surf = NULL;
}

short Dialog::is_over()
{
	if(Words[num] == '\0') {
		return 1;
	}
	else
		return 0;
}

void Dialog::show(SDL_Surface *dest_surf)
{
//	static int num = 0;
 	if(Words[num] == '\0')
		return;

    SDL_Rect dlg_src, dlg_dest;
    dlg_src.x = 0;
    dlg_src.y = 0;
    dlg_src.w = Width;
    dlg_src.h = Height;

    dlg_dest.x = X;
    dlg_dest.y = Y;
    dlg_dest.w = Width;
    dlg_dest.h = Height;

    SDL_BlitSurface(Surf, &dlg_src, dest_surf, &dlg_dest);

    if (!TTF_WasInit()){
        printf("Truetype font engine has not been initialized!\n");
        exit(1);
    }


	char temp[100];
	short x_print = X+cX;
	short y_print = Y+cY;

	for(short i = 0; i<num_row; i++)
	{
		memset(temp, 0, 100);
		for(short j=0; j<count_in_row; j++)
		{
			if (Words[num] == '\0')
			{
				i = num_row - 1;
				break;
			}
			else if(Words[num] == '@')
			{
				i = num_row - 1;
				num++;
				break;
			}
			else
			{
				temp[j] = Words[num];
				num++;
			}
		}
        SDL_BlitText(temp, dest_surf, x_print, y_print, Font, *Color);
		y_print += 20;
		
	}
	if(Words[num] == '\0')
	{
		set_text("");
		num = 0;
	}
}

void Dialog::set_text(const char * text)
{
	memset(Words, 0, 500);
	strcpy(Words, text);
}

void Dialog::set_dlg(SDL_Surface *surf, TTF_Font *font,
        SDL_Color *color)
{
	Surf = surf;
    Font = font;
    Color =color;
}


