//role.h
//01 以后在定义类的时候应该注意，类的数据成员尽量声明为私有。
//01 外部只能通过类的接口函数才能访问类的数据成员。
#ifndef __ROLEH__
#define __ROLEH__

#include <SDL/SDL.h>
//#include "map.h"

class Role
{
public:
	char Name[32];
	//int Life;
	//int Energy;
	short ID;
	int Height;
	int Width;
	int X;	//相对坐标
	int Y;	
	int Dir;
	int Step;
    SDL_Surface * Surf;
	int MapID;
	short EnemyID;
	Role * R;

public:
	Role();
	~Role();
	void set_location(int dir, int step, int x, int y);
	void role_set(short id, const char *name, int h, int w, 
            int x,int y, int dir, int step,
            SDL_Surface * surf,int map_id, short enemy_id);
	void draw_self(SDL_Surface * dest_surf);
	int move_to(int grid_x, int grid_y);

	void role_set_PSP(short id, const char *name, int h, int w, 
            int x,int y, int dir, int step,
            SDL_Surface * surf,int map_id, short enemy_id);
};

#endif
