#ifndef __RECORDH__
#define __RECORDH__

#include <SDL/SDL.h>
#include "Role.h"

class Record
{
public:
	int X;
	int Y;
	int W;
	int H;
	char Name[32];
	char Location[32];
	int Selected;   //0: unselected; other: selected
    SDL_Surface * Surf;
    TTF_Font * Font;
    SDL_Color * Color;

public:
	~Record();
	void set_record(int x, int y, int w, int h,
					const char name[], const char location[],
					int selected, SDL_Surface * surf,
                    TTF_Font *font, SDL_Color *color);
	void draw_record(SDL_Surface * dest_surf);

    /* 成功返回0，失败返回非0 */
	int load_game(Role& r);
	int store_game(Role& r);

};

#endif
