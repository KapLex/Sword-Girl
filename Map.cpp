//#include "girl.h"
//#include <ddraw.h>
#include "Map.h"
#include "assist.h"


Map::Map()
{
	short Temp[10][15]={
		{0},{0},{0},{0},{0},
		{0},{0},{0},{0},{0}};
	init_map(0, "",Temp,Temp,Temp,NULL,0, NULL, NULL);
}

Map::~Map()
{
	Npc = NULL;
	Surf = NULL;
}

void Map::init_map (int id, const char name[],short tile[10][15],
				   short trap[10][15],short block[10][15],
				   SDL_Surface *surf, int n,
                   TTF_Font *font, SDL_Color *color)
{
	ID = id;
	strcpy(Name,name);
	for (int i = 0; i<10;i++)
	{
		for(int j=0; j<15; j++)
		{
			Tile[i][j] = tile[i][j];
			Trap[i][j] = trap[i][j];
			Block[i][j] = block[i][j];
		}
	}
    Surf = surf;
	count_in_row = n;
	NpcNum = 0;
	Npc = NULL;
	for(int k=0; k<15; k++)
		Npcs[k] = 0;
    Font =font;
    Color = color;
}

void Map::draw_map_only(SDL_Surface *dest_surf)	//只画地图，用于战斗背景
{
	int i, j;
	int TileNum;
    SDL_Rect map_src, map_dest;

	for(i=0;i<10;i++)
	{
		for(j=0;j<15;j++)
		{
			TileNum = Tile[i][j];			
			map_src.x = (TileNum % count_in_row)*32;
			map_src.y = (TileNum/count_in_row)*32;			
			map_src.w = 32;
			map_src.h = 32;

#ifdef PSP
            map_dest.x = j*32;
            map_dest.y = i*27;
			map_dest.w = 32;
			map_dest.h = 27;
#else
            map_dest.x = j*32;
            map_dest.y = i*32;
			map_dest.w = 32;
			map_dest.h = 32;
#endif

            SDL_BlitSurface(Surf, &map_src, dest_surf, &map_dest);
		}
	}
}

void Map::draw_map (SDL_Surface * dest_surf, 
				   Role & player, SDL_Surface *assist_surf)
{
	static int flash = 1;
	int i, j;
	int TileNum;
    SDL_Rect map_src, map_dest, assist_src;

	//画地图元素
	for(i=0;i<10;i++)
	{
		for(j=0;j<15;j++)
		{
			TileNum = Tile[i][j];
			map_src.x = (TileNum % count_in_row)*32;
			map_src.y = (TileNum/count_in_row)*32;
			map_src.w = 32;
			map_src.h = 32;

#ifdef PSP
            map_dest.x = j*32;
            map_dest.y = i*27;
			map_dest.w = 32;
			map_dest.h = 27;
#else
            map_dest.x = j*32;
            map_dest.y = i*32;
			map_dest.w = 32;
			map_dest.h = 32;
#endif

            SDL_BlitSurface(Surf, &map_src, dest_surf, &map_dest);
						
			//画场景切换点
			if (Trap[i][j]&& Trap[i][j]<100)
			{
				//SetRect(&Rect_map_dest, j*32, i*32, (j+1)*32, (i+1)*32);
				if (flash > 0) {
                    assist_src.x = 1;
				}
				else {
                    assist_src.x = 36;
				}
                assist_src.y = 176;
                assist_src.w = 35;
                assist_src.h = 35;

                SDL_BlitSurface(assist_surf, &assist_src, dest_surf, &map_dest);
			}

		}
	}
	
	//画Npc
	if (Npc) {
		Role *temp;
		temp = Npc;
		while(temp && (temp->Y < player.Y)) {
			temp->draw_self(dest_surf);
			temp = temp->R;
		}
		player.draw_self(dest_surf);
		while (temp) {
			temp->draw_self(dest_surf);
			temp = temp->R;
		}
	}
	else {
		player.draw_self(dest_surf);
	}
	
    if (!TTF_WasInit()){
        printf("Truetype font engine has not been initialized!\n");
        exit(1);
    }
    SDL_BlitText(Name, dest_surf, SCR_W/2-8, 8, Font, *Color);

	//更新Flash
	flash = -flash;
}

void Map::add_npc_id(int id)
{
	for(int i=0; i<15; i++) {
		if (Npcs[i] == id)
			return;
	}
	
	for(int i=0; i<15; i++) {
		if (Npcs[i] == 0) {
			Npcs[i] = id;
			return;
		}
	}
}

void Map::del_npc_id(int id)
{
	for(int i=0; i<15; i++) {
		if (Npcs[i] == id)
			Npcs[i] =0;			
	}
}

//往地图中加入NPC
void Map::add_npc(Role * rAdded, int x, int y)
{
	if (NpcNum >= 15) {
        printf("Too many npc in this map!\n");
		return;
	}

	if (npc_in_map(rAdded))
		return;

	rAdded->X = x;
	rAdded->Y = y;
		
	if (!NpcNum) {
		Npc = rAdded;
		rAdded->R = NULL;
		NpcNum++;
		add_npc_id(rAdded->ID);
	}
	else {
		Role * temp = NULL;
		Role *temp1 = NULL;

	    //如果插入的NPC在已有NPC的后方，则排在链表头
		if (rAdded->Y < Npc->Y ) {
			temp = Npc;
			Npc = rAdded;
			rAdded->R = temp;
			NpcNum++;
			add_npc_id(rAdded->ID );
			temp = NULL;
		}
		else {	//将Npc插在队列中间
			temp = Npc;
			while (temp->R) {
				temp1 = temp->R;
				if (rAdded->Y < temp1->Y) {
					temp->R = rAdded;
					rAdded->R = temp1;
					NpcNum++;
					add_npc_id(rAdded->ID );
					temp = NULL;
					temp1 = NULL;
					return;
				}
				temp = temp1;
				temp1 = temp1->R; 
			}
			temp->R = rAdded; //如果不能插在中间就放在尾部
			rAdded->R = NULL;
			NpcNum++;
			add_npc_id(rAdded->ID );
			temp = NULL;
			temp1 = NULL;
		}
	}
}

void Map::del_npc(Role * rDel)	//删除地图中的npc
{
	if (Npc == NULL) {
		return;
	}
	if (Npc == rDel) {
		del_npc_id(rDel->ID );
		Npc = rDel->R;
		NpcNum--;
	}
	else {
		Role *temp = Npc;
		while(temp) {
			if (temp->R == rDel) {
				del_npc_id(rDel->ID );
				temp->R = rDel->R;
				NpcNum--;
				temp = NULL;
				return;
			}
			temp = temp->R;
		}
	}
}

void Map::del_all_npc()
{
	Npc =NULL;
	NpcNum = 0;
	for(int i = 0; i < 15; i++) {
		Npcs[i] = 0;
	}
}

short Map::npc_in_map(Role * r)
{
	Role * temp = Npc;
	while(temp) {
		if(temp == r) {
			temp = NULL;
			return 1;
		}
		temp = temp->R;
	}
	return 0;
}

void Map::del_trap(int x, int y)
{
	int i, j;
	i = y >>5;
	j = x >>5;
	Trap[i][j] = 0;
}

void Map::add_trap(int grid_x, int grid_y, int trap_num)
{
	if(grid_x > 14 || grid_x < 0 || grid_y >9 || grid_y < 0)
		return;
	Trap[grid_y][grid_x] = trap_num;
}

void Map::del_trap_by_num(short num)
{
	for(short i =0; i<10; i++)
	{
		for(short j=0; j< 15; j++)
		{
			if (Trap[i][j] == num)
			{
				Trap[i][j] = 0;
			}
		}
	}
}

short Map::if_block (int xCurrent,int yCurrent)
{
	int i,j;

#ifdef PSP
	i = yCurrent/27;
	j = xCurrent/32;
#else
	i = yCurrent>>5;
	j = xCurrent>>5;	
#endif	
	
	return Block[i][j];
}

short Map::check_trap (int xCurrent,int yCurrent)
{
	int i,j;
	
#ifdef PSP
	i = yCurrent/27;
	j = xCurrent/32;
#else
	i = yCurrent>>5;
	j = xCurrent>>5;	
#endif	

	return  Trap[i][j];

}
