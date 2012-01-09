#ifndef FIGHTER_H_
#define FIGHTER_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

class Fighter
{
private:
	short ID;
	short Index;
	short Width;
	short Height;
	short Left;
	SDL_Surface *Surf;
    TTF_Font *Font;
public:
	char Name[32];
	short X;
	short Y;
	short bAttack;
	short Attack;
	short Defend;
	short HP;	//最大HP
	short cHP;	//当前的HP
	char SndPath[32]; //打斗的声音
	Fighter *F;	//指向Fighter的指针，用于敌人链表

public:
	Fighter();
	~Fighter();
	void init_fighter(short id, short i, const char * name, short hp, 
		short att, short def, short x, short y, short w, short h, 
		short l, short a, SDL_Surface *surf, const char * path,
        TTF_Font *font);
	void draw_self(short n, SDL_Surface *dest_surf, int ex, int ey, short eAttack);
	short can_defend(short damage);
	short get_damage(short eAttack);
	void set_hp( short hp);
	float get_hp_percent();

};

#endif
