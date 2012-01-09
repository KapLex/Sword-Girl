
#include <SDL/SDL_ttf.h>
#include "assist.h"
#include "Record.h"
#include "Role.h"
#include "Map.h"
#include "stdio.h"

Record::~Record()
{
	Surf = NULL;
}

void Record::set_record (int x,int y,int w,int h, const char name[],
						const char location[], int selected,
						SDL_Surface * surf, TTF_Font *font,
                        SDL_Color * color)
{
	X = x;
	Y = y;
	W = w;
	H = h;
	strcpy(Name,name);
	strcpy(Location,location);
	Selected = selected;
	Surf = surf;
    Font = font;
    Color = color;
}

void Record::draw_record(SDL_Surface * dest_surf)
{
    SDL_Rect record_src, record_dest;
    record_src.x = 0;
    record_src.w = W;
    record_src.h = H;
	if(Selected)
        record_src.y = H;
	else
        record_src.y = 0;

    record_dest.x = X;
    record_dest.y = Y;
    record_dest.w = W;
    record_dest.h = H;
    SDL_BlitSurface(Surf, &record_src, dest_surf, &record_dest);

    if (!TTF_WasInit()){
        printf("Truetype font engine has not been initialized!\n");
        exit(1);
    }
    SDL_BlitText(Name, dest_surf, X+10, Y + 5, Font, *Color);
}

int Record::store_game (Role& r)
{
	FILE *fp;
	fp = fopen(Location,"wb");
	if(fp == NULL)
	{
        printf("Store game failed!\n");
		return 1;
	}
	fwrite(&r.X, sizeof(int), 1, fp);
	fwrite(&r.Y, sizeof(int), 1, fp);
	fwrite(&r.Dir, sizeof(int), 1, fp);
	fwrite(&r.Step, sizeof(int), 1, fp);
	fwrite(&r.MapID, sizeof(int), 1, fp);
	
	fclose(fp);
	return 0;
}

int Record::load_game (Role & r)
{
	FILE *fp;
	fp = fopen(Location,"rb");
	if(fp == NULL)
	{
        printf("Load game failed, why?\n");
		return 1;
	}
	fread(&r.X, sizeof(int),1,fp);
	fread(&r.Y, sizeof(int),1,fp);
	fread(&r.Dir, sizeof(int),1,fp);
	fread(&r.Step, sizeof(int),1,fp);
	fread(&r.MapID, sizeof(int),1,fp);
	fclose(fp);
	return 0;
}

