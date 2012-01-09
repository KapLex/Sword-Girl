#include "Role.h"
//#include "girl.h"

Role::Role()
{
	ID = 0;
	strcpy(Name,"");
	Height = 0;
	Width = 0;
	X = 0;
	Y = 0;
	Dir = 0;
	Step = 0;
	Surf = NULL;
	MapID = 10;
	EnemyID = 0;
    R = NULL;
}

Role::~Role()
{
	R = NULL;
	Surf = NULL;
}

void Role::set_location(int dir, int step, int x, int y)
{
	Dir = dir;
	Step = step;
	X = x;
	Y = y;
}

void Role::role_set (short id, const char *name,int h,int w,int x,int y,
					int dir,int step, SDL_Surface * surf,
					int map_id, short enemy_id)
{
	ID = id;
	strcpy(Name,name);
	Height = h;
	Width = w;
	X = x;
	Y = y;
	Dir = dir;
	Step = step;
	Surf = surf;
	MapID = map_id;
	EnemyID = enemy_id;
	R = NULL;
}


void Role::draw_self(SDL_Surface * dest_surf)
{
    SDL_Rect role_src, role_dest;
	role_src.x = Step*Width;
	role_src.y = Dir*Height;
	role_src.w = Width;
	role_src.h = Height;
    role_dest.x = X - (Width/2);
    role_dest.y = Y - ((7*Height)>>3);
    role_dest.w = Width;
    role_dest.h = Height;
    SDL_BlitSurface(Surf, &role_src, dest_surf, &role_dest);
}

/* 当移动完成时返回0 */
int Role::move_to(int grid_x, int grid_y)
{
	int xGrid = X >>5;
	int yGrid = Y >>5;

	if(xGrid < grid_x)
	{
		Dir = 2;
		Step++;
		if (Step >2)
			Step = 1;
		X += 16;
		return 1;
	}

	if(xGrid > grid_x)
	{
		Dir = 1;
		Step++;
		if (Step >2)
			Step = 1;
		X -= 16;
		return 1;
	}

	if(yGrid < grid_y)
	{
		Dir = 0;
		Step++;
		if (Step >2)
			Step = 1;
		Y += 16;
		return 1;
	}

	if(yGrid > grid_y)
	{
		Dir = 3;
		Step++;
		if (Step >2)
			Step = 1;
		Y -= 16;
		return 1;
	}
	
	Step = 0;
	return 0;
}
