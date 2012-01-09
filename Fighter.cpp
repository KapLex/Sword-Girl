#include <stdio.h>
#include "Fighter.h"
#include "assist.h"

Fighter::Fighter()
{
	ID = 0;
	Index = 0;
	strcpy(Name, "");
	HP = 0;
	cHP = 0;
	Attack = 0;
	Defend = 0;
	X = 0;
	Y = 0;
	Width = 0;
	Height = 0;
	Left = 0;
	bAttack = 0;
	Surf = NULL;
	F = NULL;
}

Fighter::~Fighter()
{
	Surf = NULL;
	F = NULL;
}

void Fighter::set_hp(short hp)
{
	cHP = hp;
	if (cHP>HP) {
		cHP = HP;
	}
}

float Fighter::get_hp_percent()
{
	return ((float)cHP/HP);
}

short Fighter::get_damage(short eAttack)
{
	if(eAttack < Defend ) {
		return 1;
	}
	else {
		return (eAttack - Defend);
	}

}

short Fighter::can_defend(short eAttack)
{
	cHP = cHP - get_damage(eAttack);
	if(cHP > 0) {
		return 1;
	}
	else {
		cHP = 0;
		return 0;
	}
}

void Fighter::init_fighter(short id, short i, const char * name, short hp, 
						  short att, short def, short x, short y, short w, short h, 
						  short l, short a, SDL_Surface *surf, const char * path,
                          TTF_Font *font)
{
	ID = id;
	Index = i;
	strcpy(Name, name);
	HP = hp;
	cHP = hp;
	Attack = att;
	Defend = def;
	X =x;
	Y = y;
	Width = w;
	Height = h;
	Left = l;
	bAttack = a;
	Surf =surf;
    Font = font;
	strcpy( SndPath, path);
	F = NULL;
}

void Fighter::draw_self(short n, SDL_Surface *dest_surf,
        int ex, int ey,short eAttack)
{
    SDL_Rect fighter_src, fighter_dest;
    SDL_Color color;

	char damage[20];


	if (bAttack) {
		switch(n) {
		case 0:
		case 5:
            fighter_src.x = 0;
            fighter_src.y = Index * 85;
            fighter_src.w = 60;
            fighter_src.h = 85;

            fighter_dest.x = X;
            fighter_dest.y = Y - Height;
            fighter_dest.w = Width;
            fighter_dest.h = Height;

            SDL_BlitSurface(Surf, &fighter_src, dest_surf, &fighter_dest);
			break;
		case 1:
            fighter_src.x = 0;
            fighter_src.y = Index * 85;
            fighter_src.w = 60;
            fighter_src.h = 85;

			if(Left)
                fighter_dest.x = ex - Width;
			else
                fighter_dest.x = ex + Width;

            fighter_dest.y = Y - Height;
            fighter_dest.w = Width;
            fighter_dest.h = Height;

            SDL_BlitSurface(Surf, &fighter_src, dest_surf, &fighter_dest);
			break;
		case 2:
            fighter_src.x = 61;
            fighter_src.y = Index * 85;
            fighter_src.w = 60;
            fighter_src.h = 85;

			if(Left)
                fighter_dest.x = ex - Width/2;
			else
                fighter_dest.x = ex + Width/2;

            fighter_dest.y = Y - Height;
            fighter_dest.w = Width;
            fighter_dest.h = Height;

            SDL_BlitSurface(Surf, &fighter_src, dest_surf, &fighter_dest);
			break;
		case 3:
		case 4:
            fighter_src.x = 121;
            fighter_src.y = Index * 85;
            fighter_src.w = 60;
            fighter_src.h = 85;

			if(Left)
                fighter_dest.x = ex - Width/2;
			else
                fighter_dest.x = ex + Width/2;

            fighter_dest.y = Y - Height;
            fighter_dest.w = Width;
            fighter_dest.h = Height;

            SDL_BlitSurface(Surf, &fighter_src, dest_surf, &fighter_dest);
			break;
		}
	}
	else {
        fighter_src.x = 0;
        fighter_src.y = Index*85;
        fighter_src.w = 60;
        fighter_src.h = 85;

        fighter_dest.y = Y - Height;
        fighter_dest.w = Width;
        fighter_dest.h = Height;

		sprintf(damage, "-%d", get_damage(eAttack));

		switch(n) {
		case 0:
		case 1:
		case 2:
		case 3:	
            fighter_dest.x = X;
            fighter_dest.y = Y - Height;
            fighter_dest.w = Width;
            fighter_dest.h = Height;

            SDL_BlitSurface(Surf, &fighter_src, dest_surf, &fighter_dest);
			break;
		case 4:
			if (Left)
                fighter_dest.x = X - 20;
			else
                fighter_dest.x = X + 20;

            SDL_BlitSurface(Surf, &fighter_src, dest_surf, &fighter_dest);

            color.r = 255;
            color.g = 255;
            color.b = 0;
            SDL_BlitText(damage, dest_surf, X+Width/2, Y - Height, Font, color);
			break;
		case 5:
            fighter_dest.x = X;
            SDL_BlitSurface(Surf, &fighter_src, dest_surf, &fighter_dest);
			
            color.r = 255;
            color.g = 255;
            color.b = 150;
            SDL_BlitText(damage, dest_surf, X+Width/2, Y - Height -20, Font, color);
			break;
		}
	}

}
