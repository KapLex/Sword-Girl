#ifndef __MAPH__
#define __MAPH__

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Role.h"


#ifdef PSP
    #define SCR_W 480
    #define SCR_H 270
#else
    #define SCR_W 480
    #define SCR_H 320
#endif


//BOOL flash;

//地图类声明
class Map
{
public:
	int ID;
	char Name[32];
	short Tile[10][15];
	short Trap[10][15];
	short Block[10][15];
	int count_in_row;

//TO DO PSP  
#ifdef PSP
#else  
#endif	

  SDL_Surface * Surf;	


	int NpcNum;
	int Npcs[15];
	Role *Npc;
    TTF_Font *Font;
    SDL_Color *Color;

public:
	Map();
	~Map();
	void init_map(int id, const char name[],short tile[10][15],
				 short trap[][15], short block[][15],
                 SDL_Surface *surf, int n,
                 TTF_Font *font, SDL_Color *color);
	void draw_map(SDL_Surface *dest_surf, Role& player,
            SDL_Surface *assist_surf);
	void draw_map_only(SDL_Surface *dest_surf);
	void add_npc(Role *, int x, int y);
	void add_npc_id(int id);
	void del_npc_id(int id);
	void del_npc(Role *);
	void del_all_npc();
	void del_trap(int x, int y);
	void add_trap(int grid_x, int grid_y, int trap_num);
	void del_trap_by_num(short num);
	short if_block(int xCurrent,int yCurrent);
	short check_trap(int xCurrent,int yCurrent);
	short npc_in_map(Role *);
};




#endif
