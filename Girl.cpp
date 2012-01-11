//girl.cpp

#include <math.h>
#include <stdio.h>
#include "Girl.h"
#include "assist.h"




//************************初始化地图数据****************************************
	
short Tile_aqing[10][15] = {//阿青家地图数据
	{ 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8},
	{ 5,65,12,12,12,12,12,12,12,12,12,12,12,63, 9},
	{ 5,64,14,14,14,14,14,14,14,14,14,14,14,62, 9},
	{ 5,10,10,10,10,10,10,14,14,10,10,10,10,10, 9},
	{ 4,11,11,11,11,11,11, 0, 0,11,11,11,11,11, 4},
	{ 4,15,15,15,15,15,15, 0, 0,15,15,15,15,15, 4},
	{ 4,15,15,15,15,15,15, 0, 0,15,15,15,15,15, 4},
	{ 4,15,15,15,15,15,15, 0, 0,15,15,15,15,15, 4},
	{ 2, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 3},
	{15,15,15,15,15,15,15, 0, 0,15,15,15,15,15,15}
	};
short Trap_aqing[10][15] = {//阿青家地图上的陷阱
	{0},//1
	{0},//2
	{0},//3
	{0},//4
	{0},//5
	{0},//6
	{0},//7
	{0},//8
	{0},//9
	{ 0, 0, 0, 0, 0, 0, 0,11}
	};
short Block_aqing[10][15] = {	//阿青家的阻挡布局
	{1,1,1,1,1,1, 1,1,1,1,1, 1,1,1,1},
	{1,1,1,1,1,1, 1,1,1,1,1, 1,1,1,1},
	{1,1,0,0,0,0, 0,0,0,0,0, 0,0,1,1},
	{1,1,1,1,1,1, 1,0,0,1,1, 1,1,1,1},
	{1,1,1,1,1,1, 1,0,0,1,1, 1,1,1,1},
	{1,0,0,0,0,0, 0,0,0,0,0, 0,0,0,1},
	{1,0,0,0,0,0, 0,0,0,0,0, 0,0,0,1},
	{1,0,0,0,0,0, 0,0,0,0,0, 0,0,0,1},
	{1,1,1,1,1,1, 1,0,0,1,1, 1,1,1,1},
	{0,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0}
	};


short Tile_shaoxing[10][15] = {	//越国都城地图
	{17,17,18,24,20,20,20,20,25,17,17,17,18,19,19},
	{17,18,19,30,37,22,22,38,27,17,17,18,24,20,20},
	{21,21,28,20,20,20,20,20,20,29,21,21,21,14,14},
	{35,34,36,26,40,26,26,39,26,33,33,32,33,14,14},
	{14,14,14,26,37,22,22,38,26,33,33,31,33,11,11},
	{10,10,10,26,37,23,23,38,26,12,12,31,12,11,11},
	{16,16,16,16,16,16,16,16,16,16,16,16,16,16,16},
	{16,16,16,16,16,16,16,16,16,16,16,16,16,16,16},
	{16,16,16,16,16,16,16,16,16,16,16,16,16,16,16},
	{16,16,16,16,16,16,16,16,16,16,16,16,16,16,16}
	};
short Trap_shaoxing[10][15] = {	//越国都城地图陷阱
	{0},//1
	{0},//2
	{0},//3
	{0},//4
	{0},//5
	{0},//6
	{12,102,0, 0, 0, 100, 100, 0, 0, 203, 0, 101, 0,   0,0},//7
	{0, 0,  0, 0, 0, 0,   0,   0, 0, 203, 0, 0,   202, 0,0},//8
	{0, 0,  0, 0, 0, 0,   0,   0, 0, 203, 0, 0,   202, 0,10},//9
	{0, 0,  0, 0, 0, 0,   0,   0, 0, 203, 0, 0,   202, 0,0}//10
	};
short Block_shaoxing[10][15] = {	//越国都城阻挡布局
	{1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,1},
	{1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,1},
	{1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,1},
	{1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,1},
	{1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,1},
	{1,1,1,1, 1,1,1,1,1, 1,1,1,1,1,1},
	{0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0},
	{0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0},
	{0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0},
	{0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0}
	};

short Tile_citydoor[10][15] = {	//越国城门地图
	{11,11,26,26,41,43,47,44,42,26,26,11,11,11,11},//1
	{11,11,26,26,15,45,47,46,15,26,26,11,11,11,11},//2
	{11,11,26,26,43,47,47,47,44,26,26,11,11,11,11},//3
	{11,11,26,26,45,47,47,47,46,26,26,11,11,11,11},//4*
	{15,48,49,15,54,16,16,16,55,15,15,15,15,15,15},//5
	{48,50,50,49,54,16,16,16,16,16,16,16,16,16,16},//6*
	{50,53,50,51,54,16,16,16,16,16,16,16,16,16,16},//7*
	{50,50,52,49,54,16,16,16,16,16,16,16,16,16,16},//8*
	{50,50,50,51,54,16,16,16,55,15,15,15,15,15,15},//9
	{50,50,50,49,54,16,16,16,15,15,15,15,15,15,15}//10*
	};
short Trap_citydoor[10][15] = {	//越国城门陷阱
	{0},//1
	{0},//2
	{ 0, 0, 0, 0, 0,0,14,0},//3
	{0},//4
	{0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0},//6
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,11},//7
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0},//8
	{0},
	{ 0, 0, 0, 0, 0,0,13,0, 0, 0, 0, 0, 0, 0, 0}
	};
short Block_citydoor[10][15] = {	//越国城门阻挡布局
	{1,1,1,1, 1,1,0, 1,1,1,1, 1,1,1,1},
	{1,1,1,1, 1,0,0, 0,1,1,1, 1,1,1,1},
	{1,1,1,1, 1,0,0, 0,1,1,1, 1,1,1,1},
	{1,1,1,1, 0,0,0, 0,0,1,1, 1,1,1,1},
	{0,1,1,0, 0,0,0, 0,0,0,0, 0,0,0,0},
	{1,1,1,1, 0,0,0, 0,0,0,0, 0,0,0,0},
	{1,1,1,1, 0,0,0, 0,0,0,0, 0,0,0,0},
	{1,1,1,1, 0,0,0, 0,0,0,0, 0,0,0,0},
	{1,1,1,1, 0,0,0, 0,0,0,0, 0,0,0,0},
	{1,1,1,1, 0,0,0, 0,0,0,0, 0,0,0,0}
	};

short Tile_fanli[10][15] = {	//范蠡家地图
	{ 6, 7, 7, 7, 7, 7,15,15,15,15,56,20,20,20,57},//1
	{ 5,65,60,60,60,60,16,16,16,16,15,33,32,33,15},//2
	{ 5,64,14,14,14,14,16,16,16,16,15,33,31,33,15},//3
	{ 5,14,14,14,14, 9,58,58,58,16,15,12,31,12,15},//4
	{ 5,10,10,10,10, 9,58,58,58,16,15,15,15,15,15},//5
	{ 5,63,12,12,12, 9,58,58,58,16,16,16,16,16,16},//6*
	{ 5,62,14,14,14,61,58,58,58,16,16,16,16,16,16},//7*
	{ 5,14,14,14,14,14,16,16,16,16,15,15,15,15,15},//8
	{ 5,10,10,10,10,10,15,15,15,15,15,15,15,15,15},//9
	{59,11,11,11,11,11,15,15,15,15,15,15,15,15,15}
	};
short Trap_fanli[10][15] = {	//范蠡家地图陷阱
	{0},//1
	{0},//2
	{0},//3
	{0},//4
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 103, 0, 0},//5
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12},
	{0},
	{0},
	{0}
	};
short Block_fanli[10][15] = {	//范蠡家阻挡布局
	{1,1,1,1,1,1, 0,0,0,0, 1,1,1,1,1},
	{1,1,1,1,1,1, 0,0,0,0, 0,1,1,1,0},
	{1,1,0,0,0,0, 0,0,0,0, 0,1,1,1,0},
	{1,0,0,0,0,1, 1,1,1,0, 0,1,1,1,0},
	{1,1,1,1,1,1, 1,1,1,0, 0,0,0,0,0},
	{1,1,1,1,1,1, 1,1,1,0, 0,0,0,0,0},
	{1,1,0,0,0,1, 1,1,1,0, 0,0,0,0,0},
	{1,0,0,0,0,0, 0,0,0,0, 0,0,0,0,0},
	{1,1,1,1,1,1, 0,0,0,0, 0,0,0,0,0},
	{1,1,1,1,1,1, 0,0,0,0, 0,0,0,0,0}
	};

short Tile_outside[10][15] = {	//郊外地图数据
		{50,50,50,51,67,47,47,69,76,50,50,50,50,50,50},
		{50,50,50,15,66,47,47,47,69,78,79,79,79,79,79},
		{50,50,50,49,15,67,47,47,47,47,47,47,47,47,47},
		{52,50,50,50,72,68,47,47,47,47,47,47,47,47,47},
		{50,50,50,50,71,68,47,47,47,73,74,74,74,74,74},
		{50,52,50,50,71,45,47,47,47,44,75,50,50,50,50},
		{53,50,53,50,70,67,47,47,47,46,76,50,50,50,50},
		{50,50,50,50,49,66,47,47,47,47,44,77,53,50,50},
		{50,52,50,50,50,49,47,47,47,47,46,77,50,50,50},
		{50,50,50,53,50,51,47,47,47,47,47,50,50,52,50}
	};
short Trap_outside[10][15] = { //郊外地图陷阱
		{0},
		{ 0, 0, 0, 0, 0,0,0,0},
		{ 0, 0, 0, 0, 0, 200,200,200, 0, 0, 0, 0, 0, 0,0},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,15},
		{0,0,0,0, 205,205,205,205,205,205},
		{0},
		{0},
		{0},
		{0},
		{ 0, 0, 0, 0, 0, 0,0,12,0,0,0, 0, 0, 0, 0}
	};
short Block_outside[10][15] = {	//郊外地图阻挡布局
		{1,1,1,1, 0,0,0,0,1, 1,1,1,1,1,1},
		{1,1,1,0, 0,0,0,0,0, 1,1,1,1,1,1},
		{1,1,1,1, 0,0,0,0,0, 0,0,0,0,0,0},
		{1,1,1,1, 1,0,0,0,0, 0,0,0,0,0,0},
		{1,1,1,1, 1,0,0,0,0, 0,0,0,0,0,0},
		{1,1,1,1, 1,0,0,0,0, 0,1,1,1,1,1},
		{1,1,1,1, 1,0,0,0,0, 0,1,1,1,1,1},
		{1,1,1,1, 1,0,0,0,0, 0,0,1,1,1,1},
		{1,1,1,1, 1,1,0,0,0, 0,0,1,1,1,1},
		{1,1,1,1, 1,1,0,0,0, 0,0,1,1,1,1}
	};

short Tile_wuguo[10][15] = {	//吴国城门地图数据
	{17,17,17,17,17,13,20,20,20,20,25,17,17,17,17},
	{17,17,17,17,17,17,23,22,22,23,17,17,17,17,17},
	{17,17,17,13,20,20,20,20,20,20,20,20,25,17,17},
	{11,17,11,17,11,22,11,22,11,22,11,23,11,17,11},
	{11,11,11,11,11,11,26,41,42,26,11,11,11,11,11},
	{11,11,11,11,11,11,26,45,46,26,11,11,11,11,11},
	{11,11,11,11,11,11,26,47,47,26,11,11,11,11,11},
	{72,15,15,15,15,15,43,47,47,44,15,15,15,15,15},
	{71,15,15,15,15,15,45,47,47,46,15,15,15,15,15},
	{70,15,15,15,15,43,47,47,47,47,44,15,48,49,15}
};
short Trap_wuguo[10][15] = { //吴国城门地图陷阱
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0,0,0,0,0, 0,0,207,17},
	{0,0,0,0,0, 0,0,207,207},
	{0},
	{0,0,0,0,0, 0,0,201,201,201, 0,0,0,0,0}
};
short Block_wuguo[10][15] = {	//吴国地图阻挡布局
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,0,0,1, 1,1,1,1,1},
	{1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
	{1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
	{1,0,0,0,0, 0,0,0,0,0, 0,0,1,1,0}
};

short Tile_caoyuan[10][15] = {	//草原和宫殿的地图数据
	{	0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13,	14	},
	{	15,	16,	17,	18,	19,	20,	21,	22,	23,	24,	25,	26,	27,	28,	29	},
	{	30,	31,	32,	33,	34,	35,	36,	37,	38,	39,	40,	41,	42,	43,	44	},
	{	45,	46,	47,	48,	49,	50,	51,	52,	53,	54,	55,	56,	57,	58,	59	},
	{	60,	61,	62,	63,	64,	65,	66,	67,	68,	69,	70,	71,	72,	73,	74	},
	{	75,	76,	77,	78,	79,	80,	81,	82,	83,	84,	85,	86,	87,	88,	89	},
	{	90,	91,	92,	93,	94,	95,	96,	97,	98,	99,	100,101,102,103,104	},
	{	105,106,107,108,109,110,111,112,113,114,115,116,117,118,119	},
	{	120,121,122,123,124,125,126,127,128,129,130,131,132,133,134	},
	{	135,136,137,138,139,140,141,142,143,144,145,146,147,148,149	}
};
short Trap_caoyuan[10][15] = { //草原的地图陷阱
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{206,206,206,206,206,206,206,206,206,206,206,206,206,206,206},
	{0},
	{0},
	{0,0,0,0,0, 0,0,14,0,0, 0,0,0,0,0}
};
short Block_caoyuan[10][15] = {	//草原地图阻挡布局
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1},
	{0},
	{0},
	{0},
	{0},
	{0}
};

short Trap_gongdian[10][15] = { //宫殿的地图陷阱
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{300,300,300,300,300,300,300,300,300,300,300,300,300,300,300},
	{0,0,0,0,0, 0,0,16,0,0, 0,0,0,0,0}
};
short Block_gongdian[10][15] = {	//宫殿地图阻挡布局
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,0,0,1,1, 0,0,1,1,1},
	{0,0,1},
	{0},
	{0},
	{0}
};

short Tile_xiangfang[10][15] = {	//范蠡府厢房的地图数据
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{65,65,11,11,11,11,65,65,65,11,11,11,11,11,65},
	{64,64,14,14,14,14,64,64,64,14,14,14,14,14,64},
	{14,14,14,14,14,14,14,14,14,14,14,14,14,14,14},
	{14,14,14,14,14,14,14,14,14,14,14,14,14,14,63},
	{14,14,14,14,14,14,14,14,14,14,14,14,14,14,62},
	{14,14,14,14,14,14,14,14,14,14,14,14,14,14,14},
	{10,10,10,10,10,10,14,14,10,10,10,10,10,10,10},
	{33,33,33,33,33,33,14,14,33,33,33,33,33,33,33},
	{60,60,60,60,60,60,14,14,60,60,60,60,60,60,60}
};

short Block_xiangfang[10][15] = { //范蠡府厢房的阻挡布局
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1},
	{1,1,0,0,0, 0,1,1,1,0, 0,0,0,0,1},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0},
	{1,1,1,1,1, 1,0,0,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,0,0,1,1, 1,1,1,1,1},
	{1,1,1,1,1, 1,0,0,1,1, 1,1,1,1,1}
};
short Trap_xiangfang[10][15] = { //范蠡府厢房的陷阱分布
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0},
	{0,0,0,0,0,0,0,13}
};

//*********************************************************************


//****************************应用程序函数******************************* 

//程序入口函数
int main(int argc, char ** argv)
{
    int windowed = 0;
    if(argc >1){
        if( strcmp(argv[1], "-h") == 0){
            printf("This is a chinese RPG for Linux. Version: 0.9\n");
            printf("The program runs in fullscreen by default;\n");
            printf("You can run it in a window by adding an option: -w\n");
            printf("Have Fun!!!\n");
            return 0;
        }
        if( strcmp(argv[1], "-w") == 0)
            windowed = 1;
    }

    SDL_Event event;
	//SCR_X = 100;	//定义绘图窗口在屏幕中位置
	//SCR_Y = 100;

    InitSDL( windowed );
    OpenFonts();

	//bActive = TRUE;
	Flag = GAME_LOAD_;	//设置游戏进度 
	InitGame();	//游戏初始化

    while(game_running){

        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                game_running = 0;
        }

		MainLoop();
        SDL_Flip(screen);
        SDL_Delay(80);
    }


    CloseFonts();
    FreeSDL();

}
	

/*
	case WM_MOVE:	//窗口移动时更新SCR_X和SCR_Y的值
		RECT r;
		GetWindowRect(hWnd,&r);
		SCR_X += r.left - OldWindow.left;
		SCR_Y += r.top - OldWindow.top;
		OldWindow = r;
		break;
*/

	

//初始化directdraw函数
void InitSDL( int win )
{
    Uint32 colorkey;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    atexit(SDL_Quit);

    if (win == 0)
        screen = SDL_SetVideoMode(SCR_W, SCR_H, 16, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
    else
        screen = SDL_SetVideoMode(SCR_W, SCR_H, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);

    if (screen == NULL) {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        exit(1);
    }

    // How to set the icon
    SDL_WM_SetCaption("越女剑Linux版", "sword");

    SDL_ShowCursor(0); //hide mouse pointer

    SDL_EnableKeyRepeat(0, 30); //disable key repeat


	//3 创建菜单页面
    CreateBmpSurface(&menu, "pic/menu.bmp");

    //create dialog background
    CreateBmpSurface(&dlg, "pic/dlg.bmp");
    CreateBmpSurface(&info, "pic/info.bmp");

	//4 创建状态页面
    CreateBmpSurface(&state, "pic/state.bmp");
    colorkey = SDL_MapRGB(state->format, 0, 0, 0);
    SDL_SetColorKey(state, SDL_SRCCOLORKEY, colorkey);
	
	//5 创建精灵页面
    CreateBmpSurface(&hero, "pic/aqing.bmp");
    colorkey = SDL_MapRGB(hero->format, 0, 0, 0);
    SDL_SetColorKey(hero, SDL_SRCCOLORKEY, colorkey);

	//6 范蠡
    CreateBmpSurface(&FanLi, "pic/fanli.bmp");
    colorkey = SDL_MapRGB(FanLi->format, 0, 0, 0);
    SDL_SetColorKey(FanLi, SDL_SRCCOLORKEY, colorkey);

	//7 西施
    CreateBmpSurface(&XiShi, "pic/xishi.bmp");
    colorkey = SDL_MapRGB(XiShi->format, 0, 0, 0);
    SDL_SetColorKey(XiShi, SDL_SRCCOLORKEY, colorkey);

	//8 创建绵羊页面
    CreateBmpSurface(&sheep, "pic/sheep.bmp");
    colorkey = SDL_MapRGB(sheep->format, 0, 0, 0);
    SDL_SetColorKey(sheep, SDL_SRCCOLORKEY, colorkey);

	//9 创建越国杂项页面
    CreateBmpSurface(&other_yue, "pic/other.bmp");
    colorkey = SDL_MapRGB(other_yue->format, 0, 0, 0);
    SDL_SetColorKey(other_yue, SDL_SRCCOLORKEY, colorkey);

	//10 创建物体页面
    CreateBmpSurface(&item, "pic/item.bmp");
    colorkey = SDL_MapRGB(item->format, 0, 0, 0);
    SDL_SetColorKey(item, SDL_SRCCOLORKEY, colorkey);

	//11 创建战斗页面
    CreateBmpSurface(&fight, "pic/fight.bmp");
    colorkey = SDL_MapRGB(fight->format, 0, 0, 0);
    SDL_SetColorKey(fight, SDL_SRCCOLORKEY, colorkey);

	//12 创建地图元素页面1
    CreateBmpSurface(&map_tile1, "pic/maptile.bmp");

	//13 创建地图元素页面2
    CreateBmpSurface(&map_tile2, "pic/grass.bmp");

	//14 创建地图元素页面2
    CreateBmpSurface(&map_tile3, "pic/palace.bmp");
}


//释放页面和directdraw对象
void FreeSDL()
{
    SDL_FreeSurface(hero);
    SDL_FreeSurface(XiShi);
    SDL_FreeSurface(FanLi);
    SDL_FreeSurface(sheep);
    SDL_FreeSurface(other_yue);
    SDL_FreeSurface(item);
    SDL_FreeSurface(fight);
    SDL_FreeSurface(menu);
    SDL_FreeSurface(dlg);
    SDL_FreeSurface(info);
    SDL_FreeSurface(state);
    SDL_FreeSurface(map_tile1);
    SDL_FreeSurface(map_tile2);
    SDL_FreeSurface(map_tile3);
	
}

void OpenFonts()
{
    if (-1 == TTF_Init()){
        printf("TTF engine init failed!\n");
        exit(1);
    }

    menu_font = TTF_OpenFont("font.ttf", 16);
    if (!menu_font){
        printf("Unable open font.ttf!\n");
        exit(1);
    }
    menu_color.r = 220;
    menu_color.g = 220;
    menu_color.b = 255;

    about_font = TTF_OpenFont("font.ttf", 12);
    if (!about_font){
        printf("Unable open font.ttf!\n");
        exit(1);
    }
    about_color.r = 0;
    about_color.g = 255;
    about_color.b = 255;

    message_font = TTF_OpenFont("font.ttf", 20);
    if (!message_font){
        printf("Unable open font.ttf!\n");
        exit(1);
    }
    message_color.r = 255;
    message_color.g = 0;
    message_color.b = 0;

    dlg_font = TTF_OpenFont("font.ttf", 15);
    if (!dlg_font){
        printf("Unable open font.ttf!\n");
        exit(1);
    }
    dlg_color.r = 255;
    dlg_color.g = 255;
    dlg_color.b = 0;
}

void CloseFonts()
{
    TTF_CloseFont(menu_font);
    menu_font = NULL;
    TTF_CloseFont(about_font);
    about_font = NULL;
    TTF_CloseFont(message_font);
    message_font = NULL;
    TTF_CloseFont(dlg_font);
    dlg_font = NULL;

    TTF_Quit();
}
//****************************************************************************


//***********************和游戏状态绑定的函数******************************

//游戏主循环
void MainLoop()
{
	//如果不到一帧的时间，则不进行绘图操作
//	new_time = GetTickCount();
//	if (new_time - old_time < FRAME_TIME)
//		return;
	
//	old_time = new_time;
	
	switch(Flag)
	{
	case GAME_TITLE_:	//1
		GameTitle();
		break;
	case MAIN_MOVE_:	//2
		MainMove();
		break;
	case SYSTEM_MENU_:	//3
		System_Menu();
		break;
	case READ_RECORD_:	//4
		Load();
		break;
	case WRITE_RECORD_:	//5
		Store();
		break;
	case GAME_MESSAGE_:	//6
		GameMessage();
		break;
	case FIGHT_START_:	//7
		StartFight();
		break;
	case FIGHTING_:		//8
		Fighting();
		break;
	case FIGHT_END_:	//9
		FightEnd();
		break;
	case AUTO_PLAY_:	//10
		AutoPlay();
		break;
	case TREAT_NPC_:	//11
		TreatNpc();
		break;
	case BEFORE_SELECT_://12
		BeforeSelect();
		break;
	case WAIT_SELECT_:	//13
		WaitSelect();
		break;
	case SELECT_YES_:	//14
		SelectYes();
		break;
	case SELECT_NO_:	//15
		SelectNo();
		break;
	case CHECK_STATE_:	//16
		CheckState();
		break;
	case CHECK_ABOUT_:	//17
		CheckAbout();
		break;
	default:
		GameExit();
	}
	
}

//游戏初始化
void InitGame()
{
	//显示初始化界面
    SDL_BlitText("游戏正在初始化。。。", screen, 100, SCR_H/2,
            message_font, message_color);

	InitData();	//初始化游戏数据
	
	DrawTitle();

    game_running = 1;

	Flag = GAME_TITLE_;		//推进游戏进度
}


//主角在地图走动的函数
void MainMove()
{
	RefreshCanvas();//先显示后计算

    Uint8 *keys = SDL_GetKeyState(NULL);

    if (keys[SDLK_ESCAPE]) {
		DrawSystemMenu();
		Flag = SYSTEM_MENU_;
		return;
	}

    if (keys[SDLK_SPACE]) {
		current_npc_id = FindNpc();
		if(current_npc_id) {
			Flag = TREAT_NPC_;
		}
		else {
			TrapNum = current_map->check_trap(Aqing.X, Aqing.Y);
			if (TrapNum>=100 && TrapNum < 200)
				QueryMessage(TrapNum);
		}
		return;
	}

	//计算玩家所在的格子
	int grid_x, grid_y; 

#ifdef PSP
	grid_x = Aqing.X/32;
	grid_y = Aqing.Y/27;
#else
	grid_x = Aqing.X>>5;
	grid_y = Aqing.Y>>5;
#endif

    if (keys[SDLK_DOWN]) {
		Aqing.Dir = 0;
		Aqing.Step = Aqing.Step +1;
		if(Aqing.Step > 2)
		Aqing.Step = 1;
		Aqing.Y += speed;
		if(CrushCheck()) {
			Aqing.Y -= speed;
		}
		if(current_map->if_block(Aqing.X, Aqing.Y))

#ifdef PSP
			Aqing.Y = (grid_y+1)*27-10;
#else
			Aqing.Y = (grid_y+1)*32-10;
#endif

	}
	else if(keys[SDLK_RIGHT])	//按下方向键右
	{
		Aqing.Dir = 2;
		Aqing.Step = Aqing.Step +1;
		if(Aqing.Step > 2)
			Aqing.Step = 1;
		Aqing.X += speed;

		if(CrushCheck())
			Aqing.X -= speed;

		if(current_map->if_block (Aqing.X, Aqing.Y))
			Aqing.X = (grid_x+1)*32-Aqing.Width/2;
	}

	else if(keys[SDLK_LEFT])	//按下方向键左
	{
		Aqing.Dir = 1;
		Aqing.Step = Aqing.Step +1;
		if(Aqing.Step > 2)
			Aqing.Step = 1;
		Aqing.X -= speed;

		if(CrushCheck())
			Aqing.X += speed;
		if(current_map->if_block (Aqing.X, Aqing.Y))
			Aqing.X = grid_x*32+Aqing.Width/2;
	}
	else if(keys[SDLK_UP])	//按下方向键上
	{
		Aqing.Dir = 3;
		Aqing.Step = Aqing.Step +1;
		if(Aqing.Step > 2)
			Aqing.Step = 1;
		Aqing.Y -= speed;

		if(CrushCheck())
			Aqing.Y += speed;
		if(current_map->if_block (Aqing.X, Aqing.Y))

#ifdef PSP
			Aqing.Y = grid_y*27;
#else
			Aqing.Y = grid_y*32;
#endif
	}
	else {
		if(Aqing.Step)
			Aqing.Step = 0;
	}

	BorderCheck(&Aqing.X ,&Aqing.Y );
	TrapNum = current_map->check_trap(Aqing.X, Aqing.Y);
	if (TrapNum>= 10 &&TrapNum < 100)
	{
		SceneChange();
	}
	else if (TrapNum >=200 && TrapNum <400)
	{
		Flag = AUTO_PLAY_;
	}
}

//开始战斗函数
void StartFight()
{
    Uint8 *keys = SDL_GetKeyState(NULL);
	if(keys[SDLK_SPACE]||keys[SDLK_RETURN]) {
		if (common_diag.is_over()) {
			fAqing.Y = current_enemy->Y;
			if(fAqing.bAttack == current_enemy->bAttack )
				fAqing.bAttack = !current_enemy->bAttack;

			frame_fight =0;
			fight_frame_num = 0;
			round_num = 1;
			Flag = FIGHTING_;
		}
		else {			
			common_diag.show(screen);
		}
	}
}

//战斗中
void Fighting()
{
	char temp[300];
	UpdateFight();
	fight_frame_num++;//总的战斗帧数增加
	frame_fight++;

	//更新回合数
	if(fight_frame_num%12 == 0)
	{
		round_num++;
	}

	//处理神秘剑客的特殊事件
	if ((!defeat_jianke) && (current_enemy == &fJianke)&& (round_num >= 11))
	{
		common_diag.set_text("神秘剑客：停！@神秘剑客：已经十个回合了！恭喜你！你赢了！@阿青：外面那个女孩一直说你帅，我觉得今天你才真的帅！");
		common_diag.show(screen);
		Flag = FIGHT_END_;
		return;
	}
	
	if (frame_fight >= 6) {
		if(fAqing.bAttack) {
			if (!(current_enemy->can_defend(fAqing.Attack ))) {
				play_sound("voc\\Victory.wav");
				if (current_enemy->Attack <= fAqing.Defend)
				{
					fAqing.HP += 1;
					fAqing.Attack += 1;
					fAqing.Defend += 1;
					sprintf( temp, "你战胜了%s！@最大战斗力提升1 ，攻击力提升1 ，防御力提升1 ！", current_enemy->Name);
				}
				else {
					fAqing.HP += current_enemy->HP /10;
					fAqing.Attack += current_enemy->Attack /10;
					fAqing.Defend += current_enemy->Defend /10;
					sprintf( temp, "你战胜了%s！@最大战斗力提升 %d ，攻击力提升 %d ，防御力提升 %d ！", 
						current_enemy->Name, current_enemy->HP /10, current_enemy->Attack /10, current_enemy->Defend /10);
				}
				common_diag.set_text(temp);
				common_diag.show(screen);
				Flag = FIGHT_END_;
			}
		}
		else {
			if(!(fAqing.can_defend(current_enemy->Attack))) {
				play_sound("voc\\Fail.wav");
				sprintf(temp, "你输给了%s！", current_enemy->Name );
				common_diag.set_text(temp);
				common_diag.show(screen);
				////FlipPage();
				Flag = FIGHT_END_;
			}
		}
		frame_fight =0;
		fAqing.bAttack = ! fAqing.bAttack;
		current_enemy->bAttack = !current_enemy->bAttack;
	}
}

//战斗结束
void FightEnd()
{
	current_enemy->cHP = current_enemy->HP;
	
    Uint8 *keys = SDL_GetKeyState(NULL);
	if(keys[SDLK_SPACE]||keys[SDLK_RETURN]) {
		if (common_diag.is_over()) {
			if (fAqing.cHP == 0)	//如果阿青失败
			{
				if(current_enemy == &fJianke)
				{
					RefreshCanvas();
					if(round_num<=4 && !defeat_jianke)
					{
						common_diag.set_text("神秘剑客：你还差很多，可以找城门处的武师切磋一下，也可以去郊外历练一下。@神秘剑客：先回家休息一下吧。");
					}
					else if(round_num<=8 && !defeat_jianke)
					{
						common_diag.set_text("神秘剑客：不错，有进步了，可以去郊外的草原上去练功了！@神秘剑客：先回家休息一下吧。");
					}
					else if (round_num <= 10 && !defeat_jianke)
					{
						if(!ask_to_caoyuan)
						{
							common_diag.set_text("神秘剑客：进步很快，继续努力吧！@神秘剑客：我会叫我的徒儿在草原上等你，如果你打赢他，他会将我送你的东西转交给你！@神秘剑客：先回家休息一下吧。");
							ask_to_caoyuan = 1;	
							Map_caoyuan.del_all_npc();
							Map_caoyuan.add_npc(&Yehaizi, Yehaizi.X, Yehaizi.Y);
							Map_caoyuan.add_npc(&box_caoyuan,box_caoyuan.X, box_caoyuan.Y);
						}
						else
						{
							common_diag.set_text("马上就可以赢我了！继续努力啊！@神秘剑客：先回家休息一下吧。");
						}
					}
					else
					{
						common_diag.set_text("神秘剑客：小姑娘，不要骄傲，还要努力！@阿青：喂，不要动手动脚的啦！");
					}
					common_diag.show(screen);
					//FlipPage();
					Flag = GAME_MESSAGE_;
					return;
				}
				if (current_enemy == &fFeitu )	//如果输给匪徒
				{
					//ClrScr();					
					common_diag.set_text("匪徒：小……姑娘，既然你……你输了，那就别怪我了，来……来，我帮你宽……衣！哈……哈！@阿青：呜……，想不到我竟被这样的人……@…… ……@你现在很虚弱，还是在床上休息一下吧！");
					common_diag.show( screen);
					//FlipPage();
					GotoMap(&Map_aqing);
				

					Aqing.set_location(2,0,SCR_W-90,80);
					
					Flag =GAME_MESSAGE_;
					return;
				}
				if(current_enemy == &fShangping)	//如果输给商平
				{
					//ClrScr();					
					common_diag.set_text("商平：哈哈！小姑娘，知道我的厉害了吧？来，让你看看，我还有更厉害的！@阿青：呜……，不要那么粗暴啦！@…… ……@你现在很虚弱，还是在床上休息一下吧！");
					common_diag.show( screen);
					//FlipPage();
					GotoMap(&Map_aqing);
					

					Aqing.set_location(2,0,SCR_W-90,80);
					Flag =GAME_MESSAGE_;
					return;
				}
				if(current_enemy == &fYehaizi)
				{
					//ClrScr();
					common_diag.set_text("野孩子：还要努力呀！@阿青：我下次会赢的！@……@你现在很虚弱，在床上休息一下再出去吧！");
					common_diag.show( screen);
					//FlipPage();
					GotoMap(&Map_aqing);
					

					Aqing.set_location(2,0,SCR_W-90,80);
					Flag =GAME_MESSAGE_;
					return;
				}
				GotoMap(&Map_aqing);
				

				Aqing.set_location(2,0,SCR_W-90,80);
				RefreshCanvas();
				common_diag.set_text("阿青：觉得好虚弱，在床上休息一下吧。");
				common_diag.show(screen);
				//FlipPage();
				Flag = GAME_MESSAGE_;
			}
			else
			{
				if(current_enemy->F)
				{
					char temp[100];
					current_enemy = current_enemy->F ;
					sprintf(temp, "你与%s发生战斗！", current_enemy->Name );
					common_diag.set_text(temp);
					common_diag.show(screen);
					//FlipPage();
					Flag = FIGHT_START_;
				}
				else	//战斗结束并且胜利
				{
					if (current_enemy == &fWushi2) //如果战胜了吴国武士
					{
						Map_shaoxing.del_npc(&Wujianshi1 );
						Map_shaoxing.del_npc(&Wujianshi2 );
						

						Map_shaoxing.add_npc(&Fanli, 30, 220);
						Aqing.set_location(1, 0, 180, 220);
						
						RefreshCanvas();
						TrapNum = 210;
						Flag = AUTO_PLAY_; 
					}
					else if(current_enemy == &fFeitu)	//如果战胜了匪徒
					{
						common_diag.set_text("阿青：哼，跟本姑娘学学，本领高了再出来做坏事！");
						common_diag.show(screen);
						//FlipPage();
						if(!defeat_feitu)
						{
							defeat_feitu = 1;
						}
						Flag = GAME_MESSAGE_;
					}
					else if(current_enemy == &fShangping)
					{
						common_diag.set_text("阿青：我对你讲哦，做坏人难，做有名的坏人更难，不是靠吹牛就可以的！@商平：……");
						common_diag.show(screen);
						//FlipPage();
						if(!defeat_shangping)
						{
							defeat_shangping = 1;
						}
						Flag = GAME_MESSAGE_;
					}
					else if(current_enemy == &fYehaizi)
					{
						if(!defeat_yehaizi)
						{
							defeat_yehaizi = 1;
							common_diag.set_text("野孩子：你赢了！宝箱里的东西你拿去吧！");
							common_diag.show(screen);
							//FlipPage();
							

							Yehaizi.set_location(1,3, 350,150);
							Flag = GAME_MESSAGE_;
						}
						else
						{
							RefreshCanvas();
							Flag = MAIN_MOVE_;
						}
					}
					else if(current_enemy == &fJianke)
					{
						if(!defeat_jianke)
						{
							defeat_jianke = 1;
							RefreshCanvas();
							TrapNum = 220;
							Flag = AUTO_PLAY_;
						}
						else if(! really_defeat_jianke)
						{
							really_defeat_jianke = 1;
							
							//������Ҫ�޸� 
							Jianke.X += 30;
							Jianke.Y -= 20;
							common_diag.set_text("神秘剑客：真为你感到高兴！你可以拿走宝箱中的剑了，真的很适合你的。");
							common_diag.show(screen);
							//FlipPage();
							Flag = GAME_MESSAGE_;
						}
						else
						{
							RefreshCanvas();
							Flag = MAIN_MOVE_;
						}
					}
					else if(current_enemy == &fShiwei)
					{
						if(!defeat_shiwei)
						{
							defeat_shiwei = 1;
							Map_Wuguo.del_trap_by_num(209);
							common_diag.set_text("吴吉庆：想不到我一生纵横，今天栽在一个小姑娘手里，你可以过去了！");
							common_diag.show(screen);
							//FlipPage();
							Flag = GAME_MESSAGE_;
						}
						else
						{
							RefreshCanvas();
							Flag = MAIN_MOVE_;
						}
					}
					else
					{
						RefreshCanvas();
						Flag = MAIN_MOVE_;
					}	
					
				}
			}
		
		}
		else
		{			
			common_diag.show(screen);
			//FlipPage();
		}
		
	}

}

//系统消息显示中
void GameMessage()
{
    Uint8 *keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_SPACE])
	{
		//PressKey(VK_SPACE);
		if (common_diag.is_over())
		{
			if(TrapNum == 210)
			{
				Fanli.Dir = 1;
				RefreshCanvas();
				TrapNum = 211;
				Flag = AUTO_PLAY_;
				return;
			}
			if(TrapNum == 220)
			{
				DrawPic("pic/landscape.bmp");
				TrapNum = 221;
				Flag = AUTO_PLAY_;
				return;
			}
			if(TrapNum == 221)
			{
				//ClrScr();
				//FlipPage();
				TrapNum = 222;
				Flag = AUTO_PLAY_;
				return;
			}

			if(TrapNum == 300) //如果是阿青来到吴王宫的剧情
			{
				RefreshCanvas();
				TrapNum = 301;
				Flag = AUTO_PLAY_;
				return;
			}
			if(TrapNum == 301) //如果是范蠡出现的剧情
			{
				RefreshCanvas();
				TrapNum = 302;
				Flag = AUTO_PLAY_;
				return;
			}
			if(TrapNum == 302)	//如果是西施出现的剧情
			{
				Aqing.Dir = 0;
				RefreshCanvas();
				TrapNum = 303;
				Flag = AUTO_PLAY_;
				return;
			}
//			if(TrapNum == 303)	//如果是阿青离去的剧情
//			{
//				DrawEnd();
				//FlipPage();
//				Flag = GAME_TITLE_;
//				return;
//			}
		
			RefreshCanvas();
			Flag = MAIN_MOVE_;
		}
		else
		{			
			common_diag.show(screen);
			//FlipPage();
		}

	}
}

//自动剧情
void AutoPlay()
{
	char temp[500];
	short result;

	switch(TrapNum)
	{
	case 200:	//从越国到吴国
	//������Ҫ�޸� ��int dir, int step, int x, int y�� 
		Aqing.set_location(3,0,240,SCR_H-40);
		GotoMap(&Map_Wuguo);
		//ClrScr();
		common_diag.set_text("经过四五天的长途跋涉，小太妹阿青终于来到了吴国都城前。");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 201:	//从吴国到越国
	

		Aqing.set_location(0,0, 200,100);
		GotoMap(&Map_outside);
		//ClrScr();
		common_diag.set_text("经过四五天的长途跋涉，小太妹阿青终于回到了越国都城郊外。");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 202:	//第一次来到赵大爷身边
		Aqing.Dir = 3;
		RefreshCanvas();
		common_diag.set_text("张大爷：该死的吴国剑士，又来我们国家示威了，杀了我们十多名剑士。唉……我看主要是他们的剑好，不然我们剑士的剑怎么会被他们砍断呢？如果有一位高明的剑客传授我们国家的剑士剑法，或许能扳回这个劣势……@阿青：……");
		common_diag.show(screen);
		//FlipPage();
		//去除陷阱
		current_map->del_trap_by_num(202);
		Flag = GAME_MESSAGE_;
		break;
	case 203:
		Aqing.Dir = 1;
		Aqing.Step = 0;
		RefreshCanvas();
		current_enemy = &fWushi1;
		current_enemy->F = &fWushi2;
		sprintf(temp, "李大叔：大爷，小人做小本生意的，您不能拿这么多水果不给钱，求您多少给一点。@吴国剑士甲：去你妈的，在越国还没哪个敢管我，你还敢跟老子要钱！@吴国剑士乙：大哥，不出手教训他一下不知道我们吴国人的厉害！@吴国剑士甲：对，揍他！@阿青：住手！@你与%s开始战斗！", current_enemy->Name );
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		current_map->del_trap_by_num(203);
		Flag = FIGHT_START_;
		break;
	case 210:
		result = Fanli.move_to(4,6);
		if(result)
		{
			RefreshCanvas();
			Flag = AUTO_PLAY_;
		}
		else
		{
			RefreshCanvas();
			common_diag.set_text("范蠡：好剑法！好剑法！我们国家有这样的人才，何愁不能壮大？@范蠡：小姑娘，你刚才用的剑法是谁教你的？@阿青：剑法？什么剑法？@范蠡：……  ……@范蠡：……，小姑娘，愿意到我家做客吗？@阿青：老头家中可有什么好玩的？@范蠡：好玩的东西简直数不清！@阿青：好，那我去！@范蠡：好，那老头我先行一步，姑娘随后赶来吧，寒舍就在城南！");
			common_diag.show(screen);
			//FlipPage();
			asked_by_fanli = 1;
			Flag = GAME_MESSAGE_;
		}
		break;
	case 211:
		result = Fanli.move_to(1,6);
		if(result)
		{
			RefreshCanvas();
			Flag = AUTO_PLAY_;
		}
		else
		{
			Map_shaoxing.del_npc(&Fanli );
			RefreshCanvas();
			

			Fanli.set_location(2,0,80,95);
			Flag = MAIN_MOVE_;
		}
		break;

	case 205:
		current_map->add_npc(&Feitu, Feitu.X,Feitu.Y);
		current_map->del_trap_by_num(205);
		current_enemy = &fFeitu;
		Aqing.Dir =2;
		RefreshCanvas();
		sprintf(temp,"匪徒：站……站住！打……打……打劫！@匪徒：哦？小……小妞不错呀，我……先劫……劫个色！@阿青：你找死！@你与%s发生战斗！", current_enemy->Name);
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		Flag = FIGHT_START_;
		break;

	case 206:	//第一次见张平的剧情
		current_map->del_trap_by_num(206);
		current_enemy = &fShangping;
		sprintf(temp, "商平：哈哈哈，小丫头，你知道我是谁吗？@阿青：不知道，我为什么要知道？@商平：气死我了！我就是商平，“天见商平，寸草不生；人见商平，吓得不行”的商平！@阿青：这地方草最多了，怎么叫寸草不生？我见了你，也没有吓得不行呀，哈哈！@商平：气死我了！给你点厉害瞧瞧！@你与%s发生战斗！", current_enemy->Name);
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		Flag = FIGHT_START_;
		break;
	case 207:	
		WuWeibing1.X += 30;
		WuWeibing2.X -= 30;
		Aqing.Y = 280;
		RefreshCanvas();
		common_diag.set_text("吴国卫兵：后面就是吴王宫，你不能再往里走了。");
		common_diag.show(screen);
		//FlipPage();
		WuWeibing1.X -=30;
		WuWeibing2.X += 30;
		Flag = GAME_MESSAGE_;
		break;

	case 220:
		DrawPic("pic/troop.bmp");
		common_diag.set_text("阿青胜利了！@神秘剑客也兑现了他的诺言，向越国优秀的剑士传授了一些剑道的要领。@这些要领很快普及了越国的军营，越国的作战实力大幅度提高了！@一年后，即公元482年，越国趁吴国大军北征之机向吴国发动了进攻，大获全胜，攻占了姑苏。");
		common_diag.show(screen );
		//FlipPage();
		Map_fanli.del_npc(&Fanli );
		Map_Wuguo.del_trap_by_num(207);
		Map_Wuguo.add_trap(7,7,209);
		Map_Wuguo.add_trap(8,7,209);
		Map_Wuguo.del_all_npc();
		Map_Wuguo.add_npc(&Shiwei, Shiwei.X, Shiwei.Y);
		GotoMap( &Map_aqing);
		fAqing.cHP = fAqing.HP;
		Aqing.set_location(0,0,240,190);
		Flag = GAME_MESSAGE_;
		break;
	case 221:
		common_diag.set_text("在这一年时间里，范蠡也信守诺言，每天都有一些时间和阿青在一起。@阿青觉得虽然这个老头打架不是自己的对手，但他睿智的谈吐总让自己莫名地愉快。@阿青已经不再揪范蠡的胡子玩，但她越来越喜欢和范蠡在一起，听他讲道理，陪他看草原上的日落。");
		common_diag.show(screen );
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 222:
		common_diag.set_text("但是越国攻占姑苏后，已经有几天找不到范蠡了……");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;

	case 209:
		common_diag.set_text("吴吉庆：小姑娘，既然你要强行通过，别怪我不客气了！@你与西施的侍卫吴吉庆发生战斗！");
		common_diag.show(screen);
		//FlipPage();
		current_enemy = &fShiwei;
		Flag = FIGHT_START_;
		break;

	case 300:	//阿青来到吴王宫
		Map_Gongdian.del_trap_by_num(300);
		common_diag.set_text("阿青：范蠡，范蠡！你在哪里？@阿青：范蠡，你出来吧！@……  ……@范蠡：我在这里！");
		common_diag.show(screen);
		//FlipPage();
		Map_Gongdian.add_npc(&Fanli, 50, 220);
		Flag = GAME_MESSAGE_;
		break;
	case 301:	//范蠡出现
		result = Fanli.move_to(7,6);
		if(result)
		{
			RefreshCanvas();
			Flag = AUTO_PLAY_;
		}
		else
		{
			Fanli.Dir = 0;
			RefreshCanvas();
			common_diag.set_text("阿青：老头你躲在这里做什么？@范蠡：……姑苏城百废待兴，我在这里办公。@阿青：呵呵，我在这里陪你吧。顺便在这城里玩玩。@范蠡：……@西施：丞相，谁找你呀？");
			common_diag.show(screen);
			//FlipPage();
			Map_Gongdian.add_npc(&Xishi, 50,220);
			Flag = GAME_MESSAGE_;
		}
		break;

	case 302:	//西施出现
		result = Xishi.move_to(6,6);
		if(result)
		{
			RefreshCanvas();
			Flag = AUTO_PLAY_;
		}
		else
		{
			Xishi.Dir = 0;
			RefreshCanvas();
			common_diag.set_text("阿青：喂，你是谁呀？和老头这么亲密？！@西施：我是夷光。@范蠡：……@阿青：我明白老头你为什么不回去了。……@西施：……@范蠡：……@阿青：她太美了，真的太美了……");
			common_diag.show(screen);
			//FlipPage();
			Flag = GAME_MESSAGE_;
		}
		break;

	case 303:	//阿青离开
		result = Aqing.move_to(7,9);
		if(result)
		{
			RefreshCanvas();
			Flag = AUTO_PLAY_;
		}
		else
		{
			common_diag.set_text("阿青离去了，没有人知道她去了哪里。@她终于生平第一次体验到了伤心的滋味。@让我们一起来鄙视范蠡这个欺骗少女之心的老头吧！@亲爱的朋友们，游戏到此就告一段落了。如果你还没过瘾，继续在各个场景中转一下吧。@让我们一起为Linux 游戏做些贡献吧，这对Linux 的进一步普及很重要。");
			common_diag.show(screen);
			//FlipPage();
			Flag = GAME_MESSAGE_;
		}
		break;
		
		
	default:
		Flag = MAIN_MOVE_;
		
	}

}

//处理NPC事件
void TreatNpc()
{
	switch(current_npc_id)
	{
	case 2://范蠡
        if(defeat_shiwei)
            common_diag.set_text("范蠡：小姑娘，希望你幸福！");
        else if(get_key) {
			common_diag.set_text("范蠡：小姑娘，宝箱钥匙也给你了，条件也答应你了，答应我的事也努力做到呀。@阿青：恩，我会的。");
		}
		else if (see_jianke) {
			get_key = 1;
			common_diag.set_text("范蠡：呵呵，小姑娘，看到了什么好玩的？@阿青：好啊，老头儿，你利用我啊？@范蠡：小姑娘何出此言？@阿青：那个剑客那么厉害！你让我跟他拼命呀！@范蠡：呵呵，小姑娘是答应和他比试了？@阿青：喂，老头儿，那个家伙是不是真的那么厉害，还是他吓唬我？@范蠡：确实非常厉害，但我看以姑娘的身手，和他走十个回合还不成问题。@阿青：真的？@范蠡：老头儿我很少看错人。@阿青：呵呵。那我答应了有什么好处？@范蠡：西边房间里有口宝箱，箱里有口宝剑，我看很适合姑娘，姑娘如果喜欢就拿去用吧。这是宝箱的钥匙。@阿青得到宝箱钥匙！@阿青：老头很大方呀，哈。……不过呢，如果我和那个家伙交手胜了，你还要答应我一个条件。@范蠡：啊？还有条件呀？@阿青：那当然，如果我赢了，就是帮了老头你的大忙，也是帮了我们国家一个大忙。@范蠡：姑娘深明大义，好，请讲出那个条件吧。@阿青：好，我觉得老头你的胡子很好玩。如果我赢了，老头每天让我玩玩胡子吧，直到我不想玩了为止。@范蠡：……@范蠡…………@范蠡：好吧，我答应姑娘。@阿青：说话算数啊！哈哈。@范蠡：当然。");
			
		}
		else if (asked_to_house)
		{
			common_diag.set_text("范蠡：去看过了吗？找到什么好玩的没有？@阿青：还没呢。");
		}
		else if (asked_by_fanli)
		{
			asked_to_house = 1;
			common_diag.set_text("范蠡：小姑娘，你来了。@阿青：是呀，来找好玩的东西啦。你这花花草草的还挺漂亮的，改天把我家的羊牵过来放放。@范蠡：呵呵……。@阿青：老头儿，还有什么好玩的？@范蠡：等我想想。@阿青：呵呵，我知道了，你的胡子最好玩，来，让我揪揪……@范蠡：有了！我家东厢房里有好玩的东西，我吩咐仆人让你进去，你自己去看吧。");
		}
		else
		{
			common_diag.set_text("范蠡：……");
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	
	case 4:	//野孩子
		if(defeat_yehaizi)
		{
			common_diag.set_text("野孩子：怎么？要和我比试武功吗？@要和野孩子切磋吗？");
			common_diag.show(screen);
			//FlipPage();
			Flag = BEFORE_SELECT_;
		}
		else if( see_yehaizi)
		{
			common_diag.set_text("野孩子：你又来了，来吧，打倒我！@战斗开始！");
			common_diag.show(screen);
			//FlipPage();
			current_enemy = &fYehaizi;
			Flag = FIGHT_START_;
		}
		else if(ask_to_caoyuan)
		{
			common_diag.set_text("野孩子：你来了！师父已经和我讲清楚了，师父要我送你的东西就在我身后的箱子里，来吧，赢了我之后自己开箱拿吧！");
			common_diag.show(screen);
			//FlipPage();
			see_yehaizi = 1;
			current_enemy = &fYehaizi;
			Flag = FIGHT_START_;
		}
		else
		{
			common_diag.set_text("野孩子：你是叫阿青吧？师父和我讲过你，他有件东西要我转交给你，那东西就在我身后的箱子里，来吧，赢了我之后自己开箱拿吧！");
			common_diag.show(screen);
			//FlipPage();
			see_yehaizi = 1;
			current_enemy = &fYehaizi;
			Flag = FIGHT_START_;
		}
		
		break;
	case 5: //神秘剑客
		if(really_defeat_jianke)
		{
			common_diag.set_text("神秘剑客：姑娘真是天下第一贱！还要和在下比试吗?");
			common_diag.show(screen);
			//FlipPage();
			Flag = BEFORE_SELECT_;
		}
		else if(ask_where_fanli)
		{
			common_diag.set_text("神秘剑客：姑娘，你的资质非常难得，要好好利用，攀登贱道高峰。要切磋剑术吗？");
			common_diag.show(screen);
			//FlipPage();
			Flag = BEFORE_SELECT_;
		}
		else if(defeat_jianke)
		{
			ask_where_fanli = 1;
			common_diag.set_text("神秘剑客：范大夫在吴王宫里。你如果想去找他，可能会有人阻止你见他，而且是个极厉害的对手。@阿青：你怎么知道？@神秘剑客：不告诉你，这个世界要保留一点神秘感，才可爱。@阿青：晕！@神秘剑客：不过，我可以送给你一件真正的宝贝，就在我身后的箱子里。前提是你要打赢我。@阿青：是什么宝贝？@神秘剑客：是把剑，一把至阴至柔的剑，只有在你这样的贱女人手里，才能发挥真正的威力！@阿青：呵呵，想要。");
			common_diag.show(screen);
			//FlipPage();
			Flag = GAME_MESSAGE_;
		}
		else if(get_key)
		{
			common_diag.set_text("神秘剑客：姑娘，答应了范大夫的请求，便请努力。现在要和我比试吗？");
			common_diag.show(screen);
			//FlipPage();
			Flag = BEFORE_SELECT_;
		}
		else if (see_jianke)
		{
			common_diag.set_text("神秘剑客：姑娘肯答应范大夫的请求吗？@阿青：还没和他问清楚。");
			common_diag.show(screen);
			//FlipPage();
			Flag = GAME_MESSAGE_;
		}
		else
		{
			see_jianke = 1;
			common_diag.set_text("神秘剑客：你是来和我比试的吗？@阿青：比试？为什么？@神秘剑客：范大夫没和你说吗？如果有人能和我交手十个回合而不败，我就答应他的请求。@阿青：请求，什么请求？@神秘剑客：是这样，我是范大夫府上的食客。范大夫请求我指点越国武士的剑术，但是师父传我的剑术不可外传，我又不好拒绝范大夫，就告诉他，如果有人能和我交手十个回合而不败，我就答应指点一些剑术要领给越国武士。@阿青：有多少人来和你比试过了？@神秘剑客：从我允诺到现在，有一年时间了，不下五十人来过。@阿青：他们都没能和你交手十个回合？@神秘剑客：是。@阿青：哇……。死老头，利用我，我去找他问清楚。");
			common_diag.show(screen);
			//FlipPage();
			Flag = GAME_MESSAGE_;
		}
		break;
	case 10: //阿青妈
		if(fAqing.get_hp_percent() < 0.5)
		{
			common_diag.set_text("阿青的娘：倒霉的孩子，又和人打架了吧？精神这么差，去床上休息一下吧！");
		}
		else
		{
			common_diag.set_text("阿青的娘：阿青，这么大个姑娘了，别总闲逛，有时间去城外放放羊！@阿青：院子里不是很多草吗？让它们吃不就行了？@阿青的娘：败家的孩子，咱家什么都没有，就有一点草，还不节省点？@阿青：……");
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 11:	//张大爷
		if(defeat_jianke)
		{
			common_diag.set_text("张大爷：姑娘，没想到你年纪这么小就成我们国家的大功臣了！@阿青：当然，比你这老头强多了！");
		}
		else
		{
			common_diag.set_text("张大爷：和人战斗要消耗很多体力，像别的游戏中那样在战斗中吃药其实根本不顶用，最有效的恢复体力的方式就是回家睡觉了。呵呵……@阿青：早就知道了，哼！");
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 12:	//李大叔
		if(defeat_jianke)
		{
			common_diag.set_text("李大叔：吴王宫里的夷光妃子是天下第一美人，……一想就要流口水……@阿青：有我美吗？@李大叔：……我没话说了。");
		}
		else
		{
			common_diag.set_text("李大叔：新鲜的蔬菜水果！快来看快来买呀！@阿青：能不能尝个苹果？@李大叔：不行！");
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 13:	//越国武士1
		if(defeat_feitu)
		{
			common_diag.set_text("越国武士甲：姑娘，外面的劫匪都怕你了，小小年纪这么厉害呀！@阿青：知道本姑娘厉害就好，眼睛还敢在我身上瞟来瞟去的？");
		}
		else
		{
			common_diag.set_text("越国武士甲：越国去吴国的路上常有悍匪劫财劫色，小姑娘出去玩可不要跑远了！@阿青：不要你管！");			
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 14:	//越国武士2
		if (defeat_jianke)
		{
			common_diag.set_text("越国武士乙：吴国的剑士不会再来了，唉，可怜我英雄无用武之地了。@阿青：陪本姑娘练练？@越国武士乙：……今天不行，肚子不舒服。");
		}
		else
		{
			common_diag.set_text("越国武士乙：每次和吴国剑士比武，都没人推荐我上，不然我早就打得他们哭爹喊娘了！@阿青：吹牛大王！");			
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 15:	//仆人晓月
		if(defeat_jianke)
		{
			common_diag.set_text("仆人晓月：我家主人去吴国了。里面那个男人就开始不规矩，对我动手动脚的，不过我心里满高兴的。");
		}
		else if (see_jianke)
		{
			common_diag.set_text("仆人晓月：里面那个男人好帅的，我每天给他送饭，不知不觉地爱上他了，每天夜里我都好想他。能守在他的屋外也是一种幸福！@阿青：你个花痴！");
		}
		else if (asked_to_house)
		{
			Puren.set_location(0,6,360,130);
			common_diag.set_text("仆人晓月：主人和我说过了，允许你到厢房里去找“好玩”的东西。");
		}
		else
		{
			common_diag.set_text("仆人晓月：你好，我是这里的仆人晓月。");
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;

	case 16:	//绍兴城武师
		common_diag.set_text("我看小姑娘也是武林中人，在下爱武成痴，最爱与人切磋，请姑娘不吝赐教！@要与此人过招吗？");
		common_diag.show(screen);
		//FlipPage();
		Flag = BEFORE_SELECT_;
		break;

	case 101://吴国卫兵1
		common_diag.set_text("吴国卫兵甲：漂亮的小妞，等大爷下班后去陪大爷喝茶吧，哈哈！@阿青：去找你妈陪吧！");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 102: //吴国卫兵2
		common_diag.set_text("吴国卫兵乙：小妞，你是越国的吧！别在这转悠，否则别怪我们兄弟对你不客气，嘿嘿！@阿青：看你们谁敢，我手中的剑刺瞎你们双眼！@吴国卫兵乙：（真是凶啊，还是家里的老婆比较温柔……）");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 112:	//郊外的匪徒
		if(defeat_feitu)
		{
			common_diag.set_text("匪徒：姑……姑娘，有……有什么吩咐……吗？@是否要他陪练武功？");
			common_diag.show(screen);
			//FlipPage();
			Flag = BEFORE_SELECT_;
		}
		else
		{
			common_diag.set_text("匪徒：小……小妞，是不是还想……来……来一次啊？@阿青：呸，本姑娘是来找你报仇的！");
			common_diag.show(screen);
			//FlipPage();
			current_enemy = &fFeitu;
			Flag = FIGHT_START_;
		}
		break;
	case 113:
		if(defeat_shangping)
		{
			common_diag.set_text("商平：……@是否要他陪练武功？");
			common_diag.show(screen);
			//FlipPage();
			Flag = BEFORE_SELECT_;
		}
		else
		{
			common_diag.set_text("商平：嘿嘿，小妞，再让你见识一下我的厉害！@阿青：哼，跟你拼了！");
			common_diag.show(screen);
			////FlipPage();
			current_enemy = &fShangping;
			Flag = FIGHT_START_;
		}
		break;
	case 114:	//侍卫吴吉庆
		if(defeat_shiwei)
		{
			common_diag.set_text("吴吉庆：打不过你我也无话可说，你要过就过去吧。@吴吉庆：什么？陪你练功？我才没那么傻，让我挨揍，你得经验值呀！");
			common_diag.show(screen);
			//FlipPage();
			Flag = GAME_MESSAGE_;
		}
		else
		{
			common_diag.set_text("吴吉庆：我是夷光妃子的贴身侍卫，有我在这里，谁都别想通过，除非打赢我！你要试试看吗？");
			common_diag.show(screen);
			//FlipPage();
			Flag = BEFORE_SELECT_;
		}
		break;

	case 200:
	case 201:	//绵羊
		common_diag.set_text("绵羊：咩……");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 301:	//范蠡的宝箱
		play_sound("voc\\OpenBox.wav");
		if (box_fanli.Step == 1)
		{
			common_diag.set_text("宝箱已经被打开过了！");
		}
		else if (get_key)
		{
			box_fanli.Step = 1;
			fAqing.Attack += 10;
			common_diag.set_text("你打开范蠡的宝箱，得到了宝剑【非常贱】，攻击力上升10！");
		}
		else
		{
			common_diag.set_text("你没有钥匙，打不开宝箱！");
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;

	case 302: //宝箱
		play_sound("voc\\OpenBox.wav");
		if(box_caoyuan.Step == 1)
		{
			common_diag.set_text("宝箱已经被打开过了！");
		}
		else if(defeat_yehaizi)
		{
			common_diag.set_text("你得到了神秘剑客送你的内功心法【浩然正气】！@你领悟了上面的心法，攻击力和防御力都提升 20 ！");
			fAqing.Attack += 20;
			fAqing.Defend += 20;
			box_caoyuan.Step = 1;
		}
		else if(see_yehaizi)
		{
			common_diag.set_text("野孩子：在打赢我之前，请不要动那里面的东西！");
		}
		else
		{
			common_diag.set_text("野孩子：你是谁？请不要乱动别人的东西！");
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 303:
		fAqing.set_hp(fAqing.HP );
		common_diag.set_text("你在你的小床上睡到第二天早晨！@你的体力恢复了！");
		//ClrScr();
		common_diag.show(screen);
		//FlipPage();
		play_sound("voc\\Refresh.wav");
		Flag = GAME_MESSAGE_;
		break;
	case 304:	//剑客的宝箱
		play_sound("voc\\OpenBox.wav");
		if(box_jianke.Step == 1)
		{
			common_diag.set_text("宝箱已经被打开过了！");
		}
		else if(really_defeat_jianke)
		{
			box_jianke.Step = 1;
			RefreshCanvas();
			common_diag.set_text("你得到了真正适合你的武器【越女贱】，你得攻击力上升80 ，最大战斗力上升160！");
			fAqing.HP += 160;
			fAqing.Attack += 80;
		}
		else
		{
			common_diag.set_text("神秘剑客：请不要随便拿我的东西！");
		}
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	default:
		Flag = MAIN_MOVE_;
	}
}

//游戏篇头
void GameTitle()
{	
	
    Uint8 *keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_ESCAPE])	//如果按下ESC
	{
		//PressKey(VK_ESCAPE);
		Flag = GAME_EXIT_;
		return;
	}

	//如果敲回车或空格，执行菜单功能
	if( keys[SDLK_SPACE] )	
	{
		//PressKey(VK_SPACE);
		play_sound("voc\\PushButton.wav");
		if (StartMenu[0].Sel )
		{
			RefreshCanvas();
			Flag = MAIN_MOVE_;	 
		}
		else if (StartMenu[1].Sel)
		{
			DrawRecord();
			//FlipPage();
			Flag = READ_RECORD_;
		}
		else if (StartMenu[2].Sel)
		{
			ShowAbout();
			//FlipPage();
			Flag = CHECK_ABOUT_;
		}
		else
		{
			Flag = GAME_EXIT_;
		}
		return;
	}

	//得到被选中的菜单的索引
	short selected;
	for(int i = 0; i < 4; i++)
	{
		if (StartMenu[i].Sel)
		{
			selected = i;
			break;
		}
	}


	if(keys[SDLK_DOWN])
	{
		//PressKey(VK_DOWN);
		play_sound("voc\\ChangeButton.wav");
		StartMenu[selected].Sel  = 0;
		selected++;
		if (selected >= 4)
			selected = selected%4;
		StartMenu[selected].Sel = 1;
		DrawTitle();
		//FlipPage();
	}
	else if(keys[SDLK_UP])
	{
		//PressKey(VK_UP);
		play_sound("voc\\ChangeButton.wav");
		StartMenu[selected].Sel = 0;
		selected--;
		if(selected <0)
			selected = 3;
		StartMenu[selected].Sel = 1;
		DrawTitle();
		//FlipPage();
	}
}

//游戏退出
void GameExit()
{
    DrawEnd();
	current_map = NULL;
	current_enemy = NULL;

    static short counter = 6;
    if(counter == 0)
        game_running = 0;
    counter --;
}

//游戏过程中调出系统菜单
void System_Menu()
{
    Uint8 *keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_ESCAPE])	//如果按下ESC
	{
		//PressKey(VK_ESCAPE);
		RefreshCanvas();
		Flag = MAIN_MOVE_;
		return;
	}

	if(keys[SDLK_SPACE])	//按下空格或回车
	{
		//PressKey(VK_SPACE);
		play_sound("voc\\PushButton.wav");
		if(SystemMenu[0].Sel )
		{
			DrawStateDetail();
			//FlipPage();
			Flag = CHECK_STATE_;
		}
		else if(SystemMenu[1].Sel )
		{
			DrawRecord();
			//FlipPage();
			Flag = WRITE_RECORD_;
		}
		
		else if(SystemMenu[2].Sel )
		{
			DrawRecord();
			//FlipPage();
			Flag = READ_RECORD_;			
		}
		
		else if(SystemMenu[3].Sel )
		{
			Flag = GAME_EXIT_;
		}
		return;
	}

	//得到被选中的菜单的索引
	short selected;
	for(int i = 0; i < 4; i++)
	{
		if (SystemMenu[i].Sel)
		{
			selected = i;
			break;
		}
	}
	
	if(keys[SDLK_DOWN])
	{
		//PressKey(VK_DOWN);
		play_sound("voc\\ChangeButton.wav");
		SystemMenu[selected].Sel = 0;
		selected++;
		if (selected >= 4)
		selected = selected%4;
		SystemMenu[selected].Sel = 1;
		DrawSystemMenu();
		//FlipPage();
	}
	else if(keys[SDLK_UP])
	{
		//PressKey(VK_UP);
		play_sound("voc\\ChangeButton.wav");
		SystemMenu[selected].Sel = 0;
		selected--;
		if (selected < 0)
		selected = 3;
		SystemMenu[selected].Sel = 1;
		DrawSystemMenu();
		//FlipPage();
	}
	
}

//读取进度函数
void Load()
{
    Uint8 *keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_ESCAPE])
	{
		//PressKey(VK_ESCAPE);
		RefreshCanvas();
		DrawSystemMenu();
		//FlipPage();
		Flag = SYSTEM_MENU_;
		return;
	}

	//得到被选中的菜单的索引
	short selected;
	for(int i = 0; i < 3; i++)
	{
		if (GameRecord[i].Selected)
		{
			selected = i;
			break;
		}
	}

	if(	keys[SDLK_SPACE])
	{
		//PressKey(VK_SPACE);
		play_sound("voc\\PushButton.wav");
        SDL_BlitText("请稍侯。。。", screen, 200, 150, message_font, message_color);
		
		if(LoadData(GameRecord[selected].Location ))
		{
			RefreshCanvas();
			DrawSystemMenu();
			Flag = SYSTEM_MENU_;
		}
		else
		{
			GetMapbyID(Aqing.MapID);
			RelayoutNpc();
			RefreshCanvas();
			Flag = MAIN_MOVE_;
		}
		return;
	}


	
	if(keys[SDLK_DOWN])
	{
		//PressKey(VK_DOWN);
		play_sound("voc\\ChangeButton.wav");
		GameRecord[selected].Selected  = 0;
		selected++;
		if (selected >= 3)
			selected = selected%3;
		GameRecord[selected].Selected  = 1;
		DrawRecord();
		//FlipPage();
	}
	else if(keys[SDLK_UP])
	{
		//PressKey(VK_UP);
		play_sound("voc\\ChangeButton.wav");
		GameRecord[selected].Selected  = 0;
		selected--;
		if(selected <0)
			selected = 2;
		GameRecord[selected].Selected  = 1;
		DrawRecord();
		//FlipPage();
	}
}

//存储进度函数
void Store()
{
    Uint8 *keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_ESCAPE])
	{
		//PressKey(VK_ESCAPE);
		RefreshCanvas();
		DrawSystemMenu();
		Flag = SYSTEM_MENU_;
		return;
	}

	//得到被选中的菜单的索引
	short selected;
	for(int i = 0; i < 3; i++)
	{
		if (GameRecord[i].Selected)
		{
			selected = i;
			break;
		}
	}

	if(	keys[SDLK_SPACE])
	{
		//PressKey(VK_SPACE);
		play_sound("voc\\PushButton.wav");
        SDL_BlitText("请稍侯。。。", screen, 200, 150, message_font, message_color);
		
		if(StoreData(GameRecord[selected].Location))
		{
			RefreshCanvas();
			DrawSystemMenu();
			Flag = SYSTEM_MENU_;
		}
		else
		{
			RefreshCanvas();
			common_diag.set_text("存档成功！");
			common_diag.show(screen);
			Flag = GAME_MESSAGE_;
		}
		return;
	}

	if(keys[SDLK_DOWN])
	{
		//PressKey(VK_DOWN);
		play_sound("voc\\ChangeButton.wav");
		GameRecord[selected].Selected  = 0;
		selected++;
		if (selected >= 3)
			selected = selected % 3;
		GameRecord[selected].Selected  = 1;
		DrawRecord();
		//FlipPage();
	}
	else if(keys[SDLK_UP])
	{
		//PressKey(VK_UP);
		play_sound("voc\\ChangeButton.wav");
		GameRecord[selected].Selected  = 0;
		selected--;
		if(selected <0)
			selected = 2;
		GameRecord[selected].Selected  = 1;
		DrawRecord();
		//FlipPage();
	}
	
}

void BeforeSelect()
{	
    Uint8 *keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_SPACE]||keys[SDLK_RETURN])
	{
		if (common_diag.is_over())
		{
			DrawSelectMenu();
			//FlipPage();
			Flag = WAIT_SELECT_;
		}
		else
		{			
			common_diag.show(screen);
			//FlipPage();
		}
	
	}
}

void WaitSelect()
{
    Uint8 *keys = SDL_GetKeyState(NULL);
	//如果敲回车或空格，执行菜单功能
	if( keys[SDLK_SPACE] )	
	{
		//PressKey(VK_SPACE);
		play_sound("voc\\PushButton.wav");
		if (SelectMenu[0].Sel )
		{
			Flag = SELECT_YES_;	 
		}
		else if (SelectMenu[1].Sel)
		{
			Flag = SELECT_NO_;
		}
		return;
	}
	
	
	if(keys[SDLK_DOWN]||keys[SDLK_UP])
	{
		//PressKey(VK_DOWN);
		//PressKey(VK_UP);
		play_sound("voc\\ChangeButton.wav");
		SelectMenu[0].Sel = !SelectMenu[0].Sel;
		SelectMenu[1].Sel = !SelectMenu[1].Sel;
		DrawSelectMenu();
		//FlipPage();
	}
	
}

void SelectYes()
{
	RefreshCanvas();
	char temp[200];
	if (current_npc_id == 5)
	{
		current_enemy = &fJianke;
		sprintf(temp, "阿青：好，我试一下。@你与%s发生了战斗！", current_enemy->Name);
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		Flag = FIGHT_START_;
	}
	else if(current_npc_id == 16)
	{
		current_enemy = &fWushi;
		sprintf(temp, "阿青：好，就让你见识一下本姑娘的厉害！@你与%s发生了战斗！", current_enemy->Name);
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		Flag = FIGHT_START_;
	}
	else if(current_npc_id == 112)
	{
		current_enemy = &fFeitu;
		sprintf(temp, "阿青：手下败将，陪姑娘练练手！@匪徒：姑……姑娘，今天能……不能休……休息？@阿青：废话少说，来！@你与%s发生战斗！", current_enemy->Name);
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		Flag = FIGHT_START_;
	}
	else if(current_npc_id == 113)
	{
		current_enemy = &fShangping;
		sprintf(temp, "阿青：商大坏人，陪姑娘练练手罢！@商平：练就练，谁怕谁？哪一天你栽到我手上，让你好看！@阿青：哈哈，开始吧！@你与%s发生战斗！", current_enemy->Name);
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		Flag = FIGHT_START_;
	}
	else if(current_npc_id == 4)
	{
		current_enemy = &fYehaizi;
		sprintf(temp, "阿青：恩，请多指教！你与%s发生战斗！", current_enemy->Name);
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		Flag = FIGHT_START_;
	}
	else if(current_npc_id == 114)
	{
		current_enemy = &fShiwei;
		sprintf(temp, "阿青：当然，别以为你长得帅我就不打你！@你与%s发生战斗！", current_enemy->Name);
		common_diag.set_text(temp);
		common_diag.show(screen);
		//FlipPage();
		Flag = FIGHT_START_;
	}
	else
	{
		Flag = MAIN_MOVE_;
	}
}

void SelectNo()
{
	RefreshCanvas();
	if (current_npc_id == 5)
	{
		common_diag.set_text("阿青：现在不想。@神秘剑客：好吧。如果觉得体力不好，就回家到床上休息一下再来吧。");
	}
	else if(current_npc_id == 16)
	{
		common_diag.set_text("阿青：走开，本姑娘今天心情不好！");
	}
	else if(current_npc_id == 112)
	{
		common_diag.set_text("阿青：姑娘今天心情好，先饶你这次！@匪徒：谢……谢姑……姑娘！");
	}
	else if(current_npc_id == 113)
	{
		common_diag.set_text("阿青：算了，没兴致跟你玩了！@商平：哼！");
	}
	else if(current_npc_id == 4)
	{
		common_diag.set_text("阿青：今天不想。");
	}
	else if(current_npc_id == 114)
	{
		common_diag.set_text("阿青：每个月总有这么几天，动作不方便，下次再试吧。");
	}
	else
	{
		common_diag.set_text("……");
	}
	common_diag.show(screen);
	//FlipPage();
	Flag = GAME_MESSAGE_;
}

//查看详细状态信息
void CheckState()
{
    Uint8 *keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_SPACE])
	{
		//PressKey(VK_SPACE);
		RefreshCanvas();
		DrawSystemMenu();
		//FlipPage();
		Flag = SYSTEM_MENU_;
	}
}

//查看作品信息
void CheckAbout()
{
    Uint8 *keys = SDL_GetKeyState(NULL);
	if(keys[SDLK_SPACE])
	{
		//PressKey(VK_SPACE);
		DrawTitle();
		//FlipPage();
		Flag = GAME_TITLE_;
	}

}

//****************************************************************************

//*************************更新游戏画面函数**********************************

//换页
//void //FlipPage()
//{
//	lpDDPrimary->BltFast(SCR_X, SCR_Y, screen, NULL, DDBLTFAST_WAIT);
//}

//清屏
//void ClrScr()
//{
//	DDBLTFX fx;
//	fx.dwSize = sizeof(fx);
//	fx.dwFillColor = RGB(0,0,0);
//	screen->Blt (NULL,NULL,NULL,DDBLT_WAIT|DDBLT_COLORFILL,&fx);
//}

//更新非战斗画面
void RefreshCanvas()
{
	current_map->draw_map(screen, Aqing, item);
	DrawState();
	//FlipPage();
}

//更新战斗画面
void UpdateFight()
{
	current_map->draw_map_only(screen);
	if (!fAqing.bAttack)
	{
		fAqing.draw_self(frame_fight, screen, current_enemy->X, current_enemy->Y,current_enemy->Attack );
		current_enemy->draw_self(frame_fight, screen, fAqing.X, fAqing.Y ,fAqing.Attack);
	}
	else
	{
		current_enemy->draw_self(frame_fight, screen, fAqing.X, fAqing.Y ,fAqing.Attack);
		fAqing.draw_self(frame_fight, screen, current_enemy->X, current_enemy->Y,current_enemy->Attack );
	}
	DrawState();
	DrawRoundNum();
	//FlipPage();
	if (frame_fight == 3)
	{
		if (fAqing.bAttack)
		{
			play_sound(fAqing.SndPath);
		}
		else
		{
			play_sound(current_enemy->SndPath);
		}
	}
}

//画开始菜单
void DrawStartMenu()
{
	StartMenu[0].draw_menu (screen);
	StartMenu[1].draw_menu (screen);
	StartMenu[2].draw_menu (screen);
	StartMenu[3].draw_menu (screen);
}

//画系统菜单
void DrawSystemMenu()
{
	SystemMenu[0].draw_menu (screen);
	SystemMenu[1].draw_menu (screen);
	SystemMenu[2].draw_menu (screen);
	SystemMenu[3].draw_menu (screen);
}

void DrawSelectMenu()
{
	SelectMenu[0].draw_menu(screen);
	SelectMenu[1].draw_menu(screen);
}

//画纪录
void DrawRecord()
{
	GameRecord[0].draw_record (screen);
	GameRecord[1].draw_record (screen);
	GameRecord[2].draw_record (screen);
}

//画片头
void DrawTitle()
{
    DrawPic("pic/title.bmp");
	DrawStartMenu();
}

//画片尾
void DrawEnd()
{
    SDL_Surface *end = SDL_LoadBMP("pic/end.bmp");
    SDL_BlitSurface(end, NULL, screen, NULL);
    SDL_FreeSurface(end);
	//DrawStartMenu();
}

//画状态面板
void DrawState()
{
    SDL_Rect rect_src, rect_dest;
    rect_src.x = 0;
    rect_src.y = 0;
    rect_src.w = 160;
    rect_src.h = 30;

    rect_dest.x = SCR_W -160;
    rect_dest.y = 0;
    rect_dest.w = 160;
    rect_dest.h = 30;

    SDL_BlitSurface(state, &rect_src, screen, &rect_dest);

	
	int width = (int)((fAqing.get_hp_percent()*100));
	if (width)
	{
        rect_src.x = 0;
        rect_src.y = 31;
        rect_src.w = width;
        rect_src.h = 10;
        rect_dest.x = SCR_W-7-width;
        rect_dest.y = 9;
        rect_dest.w = width;
        rect_dest.h = 10;
        SDL_BlitSurface(state, &rect_src, screen, &rect_dest);
	}
	

	char temp[20];
	sprintf( temp, "%d/%d", fAqing.cHP, fAqing.HP);
    SDL_BlitText(temp, screen, SCR_W-70, 7, about_font, about_color);
}

//显示详细状态信息
void DrawStateDetail()
{
    SDL_Rect rect_src, rect_dest;
    rect_src.x = 0;
    rect_src.y = 0;
    rect_src.w = 300;
    rect_src.h = 200;
    rect_dest.x = 120;
    rect_dest.y = 40;
    rect_dest.w = 300;
    rect_dest.h = 200;
    SDL_BlitSurface(info, &rect_src, screen, &rect_dest);

	char temp[50];
    SDL_BlitText("详细状态信息：", screen, 160, 70, menu_font, menu_color);
	sprintf(temp, "姓名：%s ", Aqing.Name);
    SDL_BlitText(temp, screen, 160, 100, menu_font, menu_color);
	sprintf(temp, "战斗力：%d / %d ", fAqing.cHP, fAqing.HP );
    SDL_BlitText(temp, screen, 160, 120, menu_font, menu_color);
	sprintf(temp, "攻击力：%d ", fAqing.Attack);
    SDL_BlitText(temp, screen, 160, 140, menu_font, menu_color);
	sprintf(temp, "防御力：%d ", fAqing.Defend);
    SDL_BlitText(temp, screen, 160, 160, menu_font, menu_color);
}

//显示作品信息
void ShowAbout()
{
    SDL_Rect rect_src, rect_dest;
    rect_src.x = 0;
    rect_src.y = 0;
    rect_src.w = 300;
    rect_src.h = 300;

    rect_dest.x = 80;
    rect_dest.y = 5;
    rect_dest.w = 300;
    rect_dest.h = 300;

    SDL_BlitSurface(info, &rect_src, screen, &rect_dest);
	
    SDL_BlitText("作品信息", screen, 115, 40, menu_font, about_color);
    SDL_BlitText("作品名称：越女剑 for Linux", screen, 115, 65, about_font, about_color);
    SDL_BlitText("版    本：1.0", screen, 115, 80, about_font, about_color);
    SDL_BlitText("功能按键：方向键，空格键和ESC键", screen, 115, 95, about_font, about_color);
    SDL_BlitText("资源来源：地图元素由自己绘制", screen, 115, 110, about_font, about_color);
    SDL_BlitText("          其它图片和声音源于网络", screen, 115, 125, about_font, about_color);
    SDL_BlitText("          对这些资源的作者表示感谢！", screen, 115, 140, about_font, about_color);
    SDL_BlitText("剧    情：金庸先生《越女剑》", screen, 115, 155, about_font, about_color);
    SDL_BlitText("          情节已被本人无恶意地篡改", screen, 115, 170, about_font, about_color);
    SDL_BlitText("          希望金先生不要见怪。", screen, 115, 185, about_font, about_color);
    SDL_BlitText("作    者：吴吉庆 (jiqingwu@gmail.com)", screen, 115, 200, about_font, about_color);
    SDL_BlitText("完成时间：2009年10月9日", screen, 115, 215, about_font, about_color);
}

//画当前的回合数
void DrawRoundNum()
{
	char temp[30];
	sprintf( temp, "当前回合数：%d", round_num);
    SDL_BlitText(temp, screen, 0, 0, message_font, message_color);
}

//在屏幕上显示图片
void DrawPic(const char * path)
{
    SDL_Surface *temp = SDL_LoadBMP(path);
    if (!temp){
        printf("Unable to load bitmap.\n");
        exit(0);
    }
    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = temp->w;
    dest.h = temp->h;
    SDL_BlitSurface(temp, NULL, screen, &dest);
    SDL_FreeSurface(temp);
}

//********************************************************************************


//****************************游戏辅助函数***************************************

//通过id得到NPC的地址
Role * GetNpcbyID(int id)
{
	switch(id)
	{
	case 1:	//1
		return &Aqing;
	case 2:	//2
		return &Fanli;
	case 3:	//3
		return &Xishi;
	case 4:	//4
		return &Yehaizi;
	case 5:	//5
		return &Jianke;
	case 10:	//6
		return &AqingMa;
	case 11:	//7
		return &ZhangDaye;
	case 12:	//8
		return &LiDashu;
	case 13:	//9
		return &YueWeibing1;
	case 14:	//10
		return &YueWeibing2;
	case 15:	//11
		return &Puren;
	case 16:	//12
		return &Wushi;
	case 101:	//13
		return &WuWeibing1;
	case 102:	//14
		return &WuWeibing2;
	case 110:	//15
		return &Wujianshi1 ;
	case 111:	//16
		return &Wujianshi2;
	case 200:	//17
		return &Sheep1;
	case 201:	//18
		return &Sheep2 ;
	case 300:	//19
		return &CaiTan;
	case 301:	//20
		return &box_fanli;
	case 302:	//21
		return &box_caoyuan;
	case 303:	//22
		return &QingBed;
	case 304:	//23
		return &box_jianke;
	case 112:	//24
		return &Feitu;
	case 113:	//25
		return &Shangping;
	case 114:	//26
		return &Shiwei;
	default:
		return 0;
	}
}

//通过主角的MapID恢复当前地图
void GetMapbyID(int id)
{
	switch(id)
	{
	case 10:
		current_map = &Map_aqing;
		break;
	case 11:
		current_map = &Map_shaoxing;
		break;
	case 12:
		current_map = &Map_citydoor;
		break;
	case 13:
		current_map = &Map_fanli;
		break;
	case 14:
		current_map = &Map_outside;
		break;
	case 15:
		current_map = &Map_caoyuan;
		break;
	case 16:
		current_map = &Map_Wuguo;
		break;
	case 17:
		current_map = &Map_Gongdian;
		break;
	case 18:
		current_map = &Map_Xiangfang;
		break;
	default:
		current_map = &Map_aqing;
	}
}

//新地图载入时，重新安排上面的NPC
void RelayoutNpc()
{
	Role * temp = NULL;
	current_map->Npc = NULL;
	current_map->NpcNum = 0;
	for(int i=0; i<15; i++)
	{
		if (current_map->Npcs[i])
		{
			temp = GetNpcbyID(current_map->Npcs[i]);
			//BorderCheck(&temp->X, &temp->Y);
			current_map->add_npc(temp, temp->X, temp->Y );
		}
	}
}

//主角走到新地图
void GotoMap(Map *m)
{
	Aqing.MapID = m->ID; 
	current_map = m;
	RelayoutNpc();
}

//场景切换函数
void SceneChange( )
{
	switch(TrapNum)
	{
	case 10:	//从绍兴街上到阿青家中
		Aqing.set_location(3,0,SCR_W/2,SCR_H-45);
		GotoMap(&Map_aqing);
		break;
		
	case 11:	
 		if(Aqing.MapID == 10)	//从阿青家到绍兴街上
		{
			Aqing.set_location(1,0,SCR_W-40, SCR_H-60);
		}
		else	//从绍兴城门到绍兴街上
		{
			Aqing.set_location(2,0,40, SCR_H-60);
		}
		GotoMap(&Map_shaoxing);
		break;
	case 12:
		
		if(Aqing.MapID == 11)	//从绍兴街到绍兴城门
		{
			Aqing.set_location(1,0, SCR_W-40, SCR_H-100);
		}
		else if(Aqing.MapID == 13)	//从范蠡家到绍兴城门
		{
			Aqing.set_location(3,0,192,SCR_H-40);			
		}
		else	//从郊外到绍兴城门
		{
			Aqing.set_location(0,0,192,100);	
		}
		GotoMap(&Map_citydoor);
		break;
	case 13:
		if(Aqing.MapID == 12)	//从绍兴城门到范蠡府上
		{
			Aqing.set_location(1,0,SCR_W-45,180);			
		}
		else	//从厢房到范蠡府院
		{
			Aqing.set_location(0,0,400,140);
		}
		GotoMap(&Map_fanli);
		break;
	case 14:
		if(Aqing.MapID == 12)	//从绍兴城门到郊外
		{
			Aqing.set_location(3,0, 220, SCR_H-40);
		}
		else if(Aqing.MapID == 15)	//从草原到郊外
		{
			Aqing.set_location(1,0,SCR_W-40, 100);		
		}
		GotoMap(&Map_outside);
		break;
	case 15:	//从越过郊外到草原
		Aqing.set_location(3,0,240,SCR_H-40);
		GotoMap(&Map_caoyuan);
		break;
	case 16:	//从吴王宫到吴国城门
		Aqing.set_location(0,0, 260,230);
		GotoMap(&Map_Wuguo);
		break;
	case 17:	//从吴国城门到吴王宫
		Aqing.set_location(3,0,240,SCR_H-40);
		GotoMap(&Map_Gongdian);
		break;

	default:
		return;
	}
}

//按下键后松开函数
//void PressKey(DWORD key)
//{
//	while(GetAsyncKeyState(key))
//	{
//	}
//}

//播放声音
void play_sound(const char * path)
{
	//PlaySound(NULL, rpg_app, SND_PURGE);
	//PlaySound(path, rpg_app, SND_ASYNC|SND_NOWAIT);
}

//响应在行走过程中敲空格的事件
void QueryMessage(short n)
{
	
	switch(n)
	{
	case 100:
		common_diag.set_text( "店主由于沉溺于编程，此店暂停营业，正在出租中！");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 101:
		common_diag.set_text("这个屋子的主人搬走了，据说因为受了旁边店主的鼓动，隐居去编程了！");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 102:
		common_diag.set_text("无赖掌柜：本店早就没货了，我懒得很，小妞，长得满标致的，做我老婆来拯救我吧！@阿青：你去死吧！");
		common_diag.show(screen);
		//FlipPage();
		Flag = GAME_MESSAGE_;
		break;
	case 103:
		play_sound("voc\\OpenBox.wav");
		current_map = &Map_Xiangfang;
		Aqing.MapID = Map_Xiangfang.ID;
		Aqing.set_location(3,0,240,280);
		Flag = MAIN_MOVE_;
		break;
	}
	
}

//边界检测函数
void BorderCheck(int *x,int *y)
{
	if(*x-Aqing.Width/2 < 0)
		*x = Aqing.Width/2 + 1;
	if((*x+Aqing.Width/2) > SCR_W)
		*x = SCR_W-Aqing.Width/2 -1;
	if((*y-((Aqing.Height)>>3)*7)<0)
		*y = ((Aqing.Height)>>3) *7 + 1;
	if(*y+((Aqing.Height)>>3)>SCR_H)
		*y = SCR_H - ((Aqing.Height)>>3) -1;
}

short CrushCheck()	//碰撞检测
{
	
	Role * temp = current_map->Npc;
	while(temp)
	{
		if (abs(Aqing.X - temp->X )< 20 && abs(Aqing.Y - temp->Y )<20)
		{
			temp = NULL;
			return 1;
		}
		temp = temp->R;
	}
	temp = NULL;
	return 0;

}

short FindNpc()	//寻找玩家面对的npc
{

	Role *temp = current_map->Npc;
	short id = 0;
	while(temp)
	{
		switch(Aqing.Dir)
		{
		case 0:
			if(abs(Aqing.X - temp->X)<15 &&(temp->Y- Aqing.Y)<50 && (temp->Y- Aqing.Y)>0)
			{
				id = temp->ID ;	
				temp = NULL;
				return id;
			}
			break;
		case 1:
			if((Aqing.X - temp->X )>0 && (Aqing.X - temp->X )<50 && abs(Aqing.Y - temp->Y)<15)
			{
				id = temp->ID ;
				temp = NULL;
				return id;
			}
			break;
		case 2:
			if((temp->X - Aqing.X )>0 && (temp->X - Aqing.X )<50 && abs(Aqing.Y - temp->Y)<15)
			{
				id = temp->ID ;
				temp = NULL;
				return id;
			}
			break;
		case 3:
			if(abs(Aqing.X - temp->X)<15 &&(Aqing.Y - temp->Y)<50 && (Aqing.Y - temp->Y)>0)
			{
				id = temp->ID ;	
				temp = NULL;
				return id;
			}
			break;
		}
		temp = temp->R;
	}

	return id;
}


//*******************************************************************



//*****************************游戏数据函数*******************************************

//初始化游戏数据
void InitData()
{
		//初始化菜单
	StartMenu[0].set_menu ("新建游戏",(SCR_W/2)-31,SCR_H-105,
						  70,25,1,menu, menu_font, &menu_color);
	StartMenu[1].set_menu ("读    档",(SCR_W/2)-31,SCR_H-80,
						  70,25,0,menu, menu_font, &menu_color);
	StartMenu[2].set_menu ("作品信息",(SCR_W/2)-31,SCR_H-55,
						  70,25,0,menu, menu_font, &menu_color);
	StartMenu[3].set_menu ("退    出",(SCR_W/2)-31,SCR_H-30,
						  70,25,0,menu, menu_font, &menu_color);
	SystemMenu[0].set_menu ("状 态",10,10,50,25,1,menu, menu_font, &menu_color);
	SystemMenu[1].set_menu ("存 档",10,35,50,25,0,menu, menu_font, &menu_color);
	SystemMenu[2].set_menu ("读 档",10,60,50,25,0,menu, menu_font, &menu_color);
	SystemMenu[3].set_menu ("退 出",10,85,50,25,0,menu, menu_font, &menu_color);
	SelectMenu[0].set_menu("是",365,260,40,25,1,menu, menu_font, &menu_color);
	SelectMenu[1].set_menu("否",365,286,40,25,0,menu, menu_font, &menu_color);

	//初始化对话框
	common_diag.set_dlg(dlg, dlg_font, &dlg_color);

	//初始化存档

#ifdef PSP
	GameRecord[0].set_record (160,190,90,25,"存档一",
		"save/1.sav",1,menu, menu_font, &menu_color);
	GameRecord[1].set_record (160,215,90,25,"存档二",
		"save/2.sav",0,menu, menu_font, &menu_color);
	GameRecord[2].set_record (160,240,90,25,"存档三",
		"save/3.sav",0,menu, menu_font, &menu_color);
#else
	GameRecord[0].set_record (160,220,90,25,"存档一",
		"save/1.sav",1,menu, menu_font, &menu_color);
	GameRecord[1].set_record (160,245,90,25,"存档二",
		"save/2.sav",0,menu, menu_font, &menu_color);
	GameRecord[2].set_record (160,270,90,25,"存档三",
		"save/3.sav",0,menu, menu_font, &menu_color);
#endif


	//初始化地图	
	Map_aqing.init_map (10,"阿青家",Tile_aqing,Trap_aqing, Block_aqing,map_tile1, 4, message_font, &message_color);	//1
	Map_shaoxing.init_map (11,"绍兴城",Tile_shaoxing,Trap_shaoxing, Block_shaoxing, map_tile1, 4, message_font, &message_color);	//2
	Map_citydoor.init_map (12,"绍兴城门",Tile_citydoor,Trap_citydoor, Block_citydoor,map_tile1, 4, message_font, &message_color);	//3
	Map_fanli.init_map (13,"范蠡府上",Tile_fanli,Trap_fanli, Block_fanli,map_tile1, 4, message_font, &message_color);	//4
	Map_outside.init_map (14,"郊  外",Tile_outside,Trap_outside, Block_outside,map_tile1, 4, message_font, &message_color);	//5
	Map_Wuguo.init_map(16, "吴国城门", Tile_wuguo,Trap_wuguo, Block_wuguo, map_tile1, 4, message_font, &message_color);	//6
	Map_caoyuan.init_map(15, "放牧草原", Tile_caoyuan, Trap_caoyuan, Block_caoyuan, map_tile2, 15, message_font, &message_color);	//7
	Map_Gongdian.init_map(17, "吴王宫", Tile_caoyuan, Trap_gongdian, Block_gongdian, map_tile3, 15, message_font, &message_color);	//8
	Map_Xiangfang.init_map(18, "范蠡府东厢房", Tile_xiangfang, Trap_xiangfang,Block_xiangfang,map_tile1,4, message_font, &message_color);	//9
/*
void Role::role_set (short id, const char *name,int h,int w,int x,int y,
					int dir,int step, SDL_Surface * surf,
					int map_id, short enemy_id)
*/					
	//初始化角色
	Aqing.role_set (1,"阿青",90,55,250,150,0,0,hero,10, 0);	//1
	QingBed.role_set(303, "阿青的小床", 35, 35, 430,80,4,0, item, 10, 0);	//2
	AqingMa.role_set(10,"阿青的娘", 95,60, 100, 95, 0, 3, other_yue,10,0);	//3
	Sheep1.role_set(200,"绵羊1", 48,48, 400,210, 3,0, sheep, 10,0);	//4
	Sheep2.role_set(201,"绵羊2", 48,48, 380,220, 0,0, sheep, 10, 0);	//5
	ZhangDaye.role_set(11,"张大爷", 95, 60, 400, 240, 0, 2, other_yue, 11, 0);//6
	LiDashu.role_set(12,"李大叔", 95,60, 150,307, 1, 2, other_yue, 11, 0);	//7
	Puren.role_set(15, "仆人晓月", 95,60, 400,130, 0,6, other_yue, 13, 0);	//8
	CaiTan.role_set(300,"李大叔的菜摊", 95, 120, 100, 305, 1, 0, other_yue, 11, 0);	//9
	Wujianshi1.role_set(110, "吴国剑士甲", 95,60, 150, 270, 1, 4, other_yue, 11, 110);	//10
	Wujianshi2.role_set(111, "吴国剑士乙", 95,60, 100, 240, 1, 5,other_yue, 11, 111);	//11
	YueWeibing1.role_set(13,"越国卫兵1", 95,60, 105,150, 0, 0, other_yue, 12, 0);	//12
	YueWeibing2.role_set(14,"越国卫兵2", 95,60, 305,150, 0, 1, other_yue, 12, 0);	//13
	WuWeibing1.role_set(101,"吴国卫兵1", 95, 60, 200, 240,0, 4, other_yue, 16, 0);	//14
	WuWeibing2.role_set(102,"吴国卫兵2", 95,60, 310, 240, 0,5, other_yue, 16, 0);	//15
	box_fanli.role_set(301,"范大夫的宝箱", 35,35, 150,200, 0,0, item, 13, 0);	//16
	Fanli.role_set(2,"范蠡大夫", 80,40, 100, 100, 2,0, FanLi, 13, 0);	//17
	Xishi.role_set(3,"西施", 85, 50, 220,220, 0,0, XiShi, 17, 0);	//18
	Yehaizi.role_set(4,"草原上的野孩子",95,60, 380, 180, 1, 3, other_yue,15,4 );	//19
	box_caoyuan.role_set(302,"草原上的宝箱", 35,35, 400, 160, 2,0, item, 15, 0);	//20
	Jianke.role_set(5, "神秘剑客", 95,60, 120,150, 1,6,other_yue,18,5);	//21
	box_jianke.role_set(304, "剑客的宝箱", 35,35,110,110, 1,0, item,18,0);	//22
	Wushi.role_set(16, "武师", 95,60, 400,200, 2,0, other_yue, 12,16);	//23
	Feitu.role_set(112, "匪徒", 95,60, 330,150, 2,2, other_yue, 14,112);	//24
	Shangping.role_set(113, "悍匪商平", 95,60, 270,190, 2,1,other_yue, 15,113);	//25
	Shiwei.role_set(114, "吴吉庆", 95,60, 225,225,2,3, other_yue,16, 114);	//26

	//初始化战斗角色
	fAqing.init_fighter(1, 0, "阿青",100, 20,15, 250,235, 60,85, 0,1, fight, "voc\\Aqing.wav", message_font);	//1
	fWushi1.init_fighter(110, 1, "吴国剑士甲", 90, 20,5, 120,220, 60,85, 1, 0,fight, "voc\\Wujianshi.wav", message_font);	//2
	fWushi2.init_fighter(111, 1, "吴国剑士乙", 100, 20,10, 120,240, 70,100, 1,0,fight, "voc\\Wujianshi.wav", message_font);	//3
	fYehaizi.init_fighter(4, 3, "草原上的野孩子", 465,125,100, 100,250,60,85,1,0,fight, "voc\\Yehaizi.wav", message_font);	//4
	fJianke.init_fighter(5, 4,"神秘剑客",1100, 160,150, 120,210, 60,85, 1,0,fight, "voc\\Jianke.wav", message_font);	//5
	fWushi.init_fighter(16, 5,"绍兴武师", 120, 30, 18, 140,230, 60,85, 1,0,fight, "voc\\Wushi.wav", message_font);	//6
	fFeitu.init_fighter(112,2, "口痴的匪徒", 200, 42,40, 140,140, 60,85, 1,0, fight, "voc\\Feitu.wav", message_font);//7
	fShangping.init_fighter(113, 2, "悍匪商平", 300, 75,50, 140, 220, 60,85, 1,0, fight, "voc\\Feitu.wav", message_font);	//8
	fShiwei.init_fighter(114, 6, "西施的侍卫吴吉庆", 1200, 225, 250, 140,255, 60,85, 1,0, fight, "voc\\Jianke.wav", message_font);

	//地图中加入Npc
	Map_aqing.add_npc(&AqingMa, AqingMa.X, AqingMa.Y);	
	Map_aqing.add_npc(&QingBed, QingBed.X, QingBed.Y);	
	Map_aqing.add_npc(&Sheep1, Sheep1.X, Sheep1.Y );	
	Map_aqing.add_npc(&Sheep2, Sheep2.X, Sheep2.Y );	
	Map_shaoxing.add_npc(&ZhangDaye, ZhangDaye.X, ZhangDaye.Y );	
	Map_shaoxing.add_npc(&LiDashu, LiDashu.X, LiDashu.Y);	
	Map_shaoxing.add_npc(&CaiTan, CaiTan.X, CaiTan.Y);
	Map_shaoxing.add_npc(&Wujianshi1, Wujianshi1.X, Wujianshi1.Y);
	Map_shaoxing.add_npc(&Wujianshi2, Wujianshi2.X, Wujianshi2.Y);
	Map_citydoor.add_npc(&YueWeibing1, YueWeibing1.X, YueWeibing1.Y);
	Map_citydoor.add_npc(&YueWeibing2, YueWeibing2.X, YueWeibing2.Y);
	Map_citydoor.add_npc(&Wushi, Wushi.X, Wushi.Y);
	Map_fanli.add_npc(&box_fanli, box_fanli.X, box_fanli.Y);
	Map_fanli.add_npc(&Fanli, Fanli.X, Fanli.Y);
	Map_fanli.add_npc(&Puren, Puren.X, Puren.Y);
	Map_Wuguo.add_npc(&WuWeibing1, WuWeibing1.X, WuWeibing1.Y );
	Map_Wuguo.add_npc(&WuWeibing2, WuWeibing2.X, WuWeibing2.Y);
	Map_Xiangfang.add_npc(&Jianke, Jianke.X, Jianke.Y);
	Map_Xiangfang.add_npc(&box_jianke,box_jianke.X,box_jianke.Y);
	Map_caoyuan.add_npc(&Shangping, Shangping.X, Shangping.Y);

	
	//初始化全局游戏变量
	current_map = &Map_aqing;
	current_enemy = NULL;
	current_npc_id = 0;

	//初始化剧情标志变量
	asked_by_fanli = 0;			//1
	asked_to_house = 0;			//2
	see_jianke = 0;				//3
	get_key = 0;				//4
	defeat_feitu = 0;			//6
	defeat_shangping = 0;		//6
	ask_to_caoyuan = 0;			//7
	see_yehaizi = 0;			//8
	defeat_yehaizi = 0;			//9 是否已打败野孩子
	defeat_jianke = 0;			//10是否已抵挡神秘剑客１０个回合
	ask_where_fanli = 0;		//11
	really_defeat_jianke = 0;	//12 是否真正打败神秘剑客
	defeat_shiwei = 0;			//13 打败范蠡侍卫

}

//读取游戏数据
short LoadData( char * path)
{
	FILE *fp;

	//打开文件
	fp = fopen(path,"rb");
	if(fp == NULL)
	{
        printf("load failed!\n");
		return 1;
	}

	//读取玩家数据
	fread(&Aqing.X, sizeof(int),1,fp);
	fread(&Aqing.Y, sizeof(int),1,fp);
	fread(&Aqing.Dir, sizeof(int),1,fp);
	fread(&Aqing.Step, sizeof(int),1,fp);
	fread(&Aqing.MapID, sizeof(int),1,fp);
	fread(&fAqing.HP, sizeof(short), 1, fp);
	fread(&fAqing.cHP, sizeof(short), 1, fp);
	fread(&fAqing.Attack, sizeof(short), 1,fp);
	fread(&fAqing.Defend, sizeof(short), 1, fp);

	//读取其它NPC数据
	fread(&Puren.X, sizeof(int), 1, fp);
	fread(&Puren.Y, sizeof(int), 1, fp);
	fread(&Jianke.X, sizeof(int), 1, fp);
	fread(&Jianke.Y, sizeof(int), 1, fp);
	fread(&Yehaizi.X, sizeof(int), 1, fp);
	fread(&Yehaizi.Y, sizeof(int), 1, fp);
	fread(&box_fanli.Step, sizeof(int), 1, fp);
	fread(&box_jianke.Step, sizeof(int), 1, fp);
	fread(&box_caoyuan.Step, sizeof(int), 1, fp);

	//读取地图陷阱数据
	int i,j;
	for(i = 0; i< 10; i++)
	{
		for(j =0; j< 15; j++)
		{
			fread(&Map_shaoxing.Trap[i][j], sizeof(short), 1, fp);
			fread(&Map_outside.Trap[i][j], sizeof(short), 1, fp);
			fread(&Map_Wuguo.Trap[i][j], sizeof(short), 1, fp);
			fread(&Map_Gongdian.Trap[i][j], sizeof(short), 1, fp);
			fread(&Map_caoyuan.Trap[i][j], sizeof(short), 1, fp);
		}
	}

	//读取地图NPC数据
	for(i =0; i< 15; i++)
	{
		fread(&Map_aqing.Npcs[i], sizeof(int), 1, fp);		//1
		fread(&Map_shaoxing.Npcs[i], sizeof(int), 1, fp);	//2
		fread(&Map_citydoor.Npcs[i], sizeof(int), 1, fp);	//3
		fread(&Map_fanli.Npcs[i], sizeof(int), 1, fp);		//4
		fread(&Map_outside.Npcs[i], sizeof(int), 1, fp);	//5
		fread(&Map_caoyuan.Npcs[i], sizeof(int), 1, fp);	//6
		fread(&Map_Wuguo.Npcs[i], sizeof(int), 1, fp);		//7
		fread(&Map_Gongdian.Npcs[i], sizeof(int), 1, fp);	//8
		fread(&Map_Xiangfang.Npcs[i], sizeof(int), 1, fp);	//9
	}

	//读取剧情标志数据
	fread(&asked_by_fanli, sizeof(short), 1, fp);	//1
	fread(&asked_to_house, sizeof(short), 1, fp);	//2
	fread(&see_jianke, sizeof(short), 1, fp);	//3
	fread(&get_key, sizeof(short), 1, fp);		//4
	fread(&defeat_feitu, sizeof(short), 1, fp);	//5
	fread(&defeat_shangping, sizeof(short), 1, fp);	//6
	fread(&ask_to_caoyuan, sizeof(short), 1, fp);	//7
	fread(&see_yehaizi, sizeof(short), 1, fp);		//8
	fread(&defeat_yehaizi, sizeof(short), 1, fp);	//9
	fread(&defeat_jianke, sizeof(short), 1, fp);		//10
	fread(&ask_where_fanli, sizeof(short), 1, fp);		//11
	fread(&really_defeat_jianke, sizeof(short), 1, fp);	//12
	fread(&defeat_shiwei, sizeof(short), 1, fp);	//13

	fclose(fp);
	return 0;
	
}

//存储游戏数据
short StoreData(char * path)
{
	FILE *fp;

	//打开文件
	fp = fopen(path,"wb");
	if(fp == NULL)
	{
        printf("store failed!\n");
		return 1;
	}

	//存储玩家数据
	fwrite(&Aqing.X, sizeof(int), 1, fp);
	fwrite(&Aqing.Y, sizeof(int), 1, fp);
	fwrite(&Aqing.Dir, sizeof(int), 1, fp);
	fwrite(&Aqing.Step, sizeof(int), 1, fp);
	fwrite(&Aqing.MapID, sizeof(int), 1, fp);
	fwrite(&fAqing.HP, sizeof(short), 1, fp);
	fwrite(&fAqing.cHP, sizeof(short), 1, fp);
	fwrite(&fAqing.Attack, sizeof(short), 1,fp);
	fwrite(&fAqing.Defend, sizeof(short), 1, fp);

	//存储其它NPC数据
	fwrite(&Puren.X, sizeof(int), 1, fp);
	fwrite(&Puren.Y, sizeof(int), 1, fp);
	fwrite(&Jianke.X, sizeof(int), 1, fp);
	fwrite(&Jianke.Y, sizeof(int), 1, fp);
	fwrite(&Yehaizi.X, sizeof(int), 1, fp);
	fwrite(&Yehaizi.Y, sizeof(int), 1, fp);
	fwrite(&box_fanli.Step, sizeof(int), 1, fp);
	fwrite(&box_jianke.Step, sizeof(int), 1, fp);
	fwrite(&box_caoyuan.Step, sizeof(int), 1, fp);

	//存储地图陷阱数据
	int i,j;
	for(i = 0; i< 10; i++)
	{
		for(j =0; j< 15; j++)
		{
			fwrite(&Map_shaoxing.Trap[i][j], sizeof(short), 1, fp);
			fwrite(&Map_outside.Trap[i][j], sizeof(short), 1, fp);
			fwrite(&Map_Wuguo.Trap[i][j], sizeof(short), 1, fp);
			fwrite(&Map_Gongdian.Trap[i][j], sizeof(short), 1, fp);
			fwrite(&Map_caoyuan.Trap[i][j], sizeof(short), 1, fp);
		}
	}

	//存储地图NPC数据
	for(i =0; i< 15; i++)
	{
		fwrite(&Map_aqing.Npcs[i], sizeof(int), 1, fp);		//1
		fwrite(&Map_shaoxing.Npcs[i], sizeof(int), 1, fp);	//2
		fwrite(&Map_citydoor.Npcs[i], sizeof(int), 1, fp);	//3
		fwrite(&Map_fanli.Npcs[i], sizeof(int), 1, fp);		//4
		fwrite(&Map_outside.Npcs[i], sizeof(int), 1, fp);	//5
		fwrite(&Map_caoyuan.Npcs[i], sizeof(int), 1, fp);	//6
		fwrite(&Map_Wuguo.Npcs[i], sizeof(int), 1, fp);		//7
		fwrite(&Map_Gongdian.Npcs[i], sizeof(int), 1, fp);	//8
		fwrite(&Map_Xiangfang.Npcs[i], sizeof(int), 1, fp);	//9
	}

	//存储剧情标志数据
	fwrite(&asked_by_fanli, sizeof(short), 1, fp);	//1
	fwrite(&asked_to_house, sizeof(short), 1, fp);	//2
	fwrite(&see_jianke, sizeof(short), 1, fp);	//3
	fwrite(&get_key, sizeof(short), 1, fp);		//4
	fwrite(&defeat_feitu, sizeof(short), 1, fp);	//5
	fwrite(&defeat_shangping, sizeof(short), 1, fp);	//6
	fwrite(&ask_to_caoyuan, sizeof(short), 1, fp);	//7
	fwrite(&see_yehaizi, sizeof(short), 1, fp);		//8
	fwrite(&defeat_yehaizi, sizeof(short), 1, fp);	//9
	fwrite(&defeat_jianke, sizeof(short), 1, fp);		//10
	fwrite(&ask_where_fanli, sizeof(short), 1, fp);		//11
	fwrite(&really_defeat_jianke, sizeof(short), 1, fp);	//12
	fwrite(&defeat_shiwei, sizeof(short), 1, fp);	//13
		
	
	//关闭文件
	fclose(fp);
	return 0;
}

