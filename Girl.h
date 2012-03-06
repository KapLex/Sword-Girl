#ifndef __GIRLH__
#define __GIRLH__

#include "Role.h"
#include "Map.h"
#include "Record.h"
#include "Dialog.h"
#include "Fighter.h"
#include "Menu.h"




#define CK RGB(0,0,0)	//定义关键色
#define speed 20	//定义角色移动速度
#define FRAME_TIME 120	//定义一帧的毫秒数

//游戏运行状态的宏定义
#define GAME_LOAD_	0	//游戏数据装载
#define GAME_TITLE_	1	//游戏开始画面
#define MAIN_MOVE_	2	//由玩家控制主角
#define READ_RECORD_	3	//读取纪录
#define GAME_EXIT_	4	//正在退出游戏
#define SYSTEM_MENU_	5	//游戏过程中调出系统菜单
#define WRITE_RECORD_	6	//存写纪录
#define GAME_MESSAGE_	7	//系统消息
#define FIGHT_START_	8	//战斗开始
#define FIGHTING_	9	//战斗进行
#define FIGHT_END_	10	//战斗结束
#define AUTO_PLAY_	11	//自动剧情
#define TREAT_NPC_	12	//处理NPC事件
#define BEFORE_SELECT_	13	//弹出等待玩家选择答案的页面
#define WAIT_SELECT_	14	//等待玩家做出选择
#define	SELECT_YES_		15	//玩家做出是的选择
#define SELECT_NO_		16	//玩家做出否的选择
#define CHECK_STATE_	17	//查看状态
#define CHECK_ABOUT_	18	//查看作品信息


//**********************变量声明**************************************

short bActive;
short game_running;

int SCR_X;	//窗口在屏幕上的位置
int SCR_Y;
//RECT OldWindow;	//用于处理窗口移动事件，记录移动前窗口位置




//页面
SDL_Surface *screen;
SDL_Surface *hero;
SDL_Surface *XiShi;
SDL_Surface *FanLi;
SDL_Surface *sheep;
SDL_Surface *other_yue;//7 越国杂项页面
SDL_Surface *item;
SDL_Surface *fight;
SDL_Surface *menu;
SDL_Surface *dlg;
SDL_Surface *info;
SDL_Surface *state;
SDL_Surface *map_tile1;
SDL_Surface *map_tile2;
SDL_Surface *map_tile3;

// fonts
TTF_Font *menu_font;
TTF_Font *about_font;
TTF_Font *message_font;
TTF_Font *dlg_font;

//colors
SDL_Color menu_color;
SDL_Color about_color;
SDL_Color message_color;
SDL_Color dlg_color;


//地图
Map Map_aqing;	//1
Map Map_shaoxing;	//2
Map Map_citydoor;	//3
Map Map_fanli;	//4
Map Map_Wuguo;	//5
Map Map_caoyuan;	//6
Map Map_Gongdian;	//7
Map Map_outside;	//8
Map Map_Xiangfang;	//9

//角色
Role Aqing;		//1 主角阿青
Role QingBed;	//2 阿青的床
Role AqingMa;	//3	阿青妈
Role Sheep1;	//4
Role Sheep2;	//5 两只绵羊
Role ZhangDaye;	//6 爱唠叨的张大爷
Role LiDashu;	//7	卖菜的李大叔
Role CaiTan;	//8 李大叔的菜摊
Role Wujianshi1;//9	
Role Wujianshi2;//10 两名在绍兴城撒野的吴国剑士
Role YueWeibing1;	//11
Role YueWeibing2;	//12 城门的卫兵甲和卫兵乙
Role Puren;		//13 仆人
Role Fanli;		//14 范蠡
Role box_fanli;	//15 范蠡家的宝箱
Role WuWeibing1;//16 
Role WuWeibing2;//17 吴国的卫兵甲和卫兵乙
Role Xishi;		//18 美人西施
Role Yehaizi;	//19 草原上的野孩子
Role box_caoyuan;	//20 草原上宝箱
Role Jianke;	//21 范府厢房中的神秘剑客
Role box_jianke;	//22 剑客的宝箱
Role Wushi;		//23 绍兴城中的武师
Role Feitu;		//24 郊外的匪徒
Role Shangping;	//25 悍匪商平
Role Shiwei;	//26 西施的侍卫

//战斗角色
Fighter fAqing;		//1 战斗的阿青
Fighter fWushi1;	//2
Fighter fWushi2;	//3 战斗的两名吴国剑士
Fighter fYehaizi;	//4 战斗的野孩子
Fighter fJianke;	//5 战斗的神秘剑客
Fighter fWushi;		//6 战斗的武师
Fighter fFeitu;		//7 战斗的匪徒
Fighter fShangping; //8 悍匪商平
Fighter fShiwei;	//9 西施的侍卫

//菜单对象
Menu StartMenu[4];	//开始菜单
Menu SystemMenu[4];	//系统菜单
Menu SelectMenu[2];	//选择菜单
Record GameRecord[3];	//纪录菜单

//全局游戏变量
Dialog common_diag;	//公用消息框
int current_npc_id;	//当前的Npc的id
Map * current_map;	//当前的地图指针
Fighter * current_enemy;	//当前的敌人指针
short TrapNum; //玩家踩中的陷阱编号
long old_time, new_time; //用于计算帧时间的变量
short frame_fight;	//战斗时的帧计数
int fight_frame_num;	//战斗的总帧数
short round_num;	//回合数
short Flag;//游戏运行状态标志

//剧情标志变量
short asked_by_fanli;	//1 被范蠡邀请的标志
short asked_to_house;	//2 范蠡要去厢房找好玩的东西
short see_jianke;		//3 是否见过神秘剑客
short get_key;			//4 得到范蠡宝箱的钥匙
short defeat_feitu;		//5 是否打败了匪徒
short defeat_shangping;	//6 是否打败了商平
short ask_to_caoyuan;	//7 神秘剑客叫你去草原
short see_yehaizi;		//8 是否见过野孩子
short defeat_yehaizi;    //9 是否已打败野孩子
short defeat_jianke;	    //10 是否已抵挡神秘剑客１０个回合
short ask_where_fanli;	//11 是否已经问过范蠡的动向
short really_defeat_jianke;	//12 是否真正打败神秘剑客
short defeat_shiwei;		//13 打败范蠡侍卫



//**************************函数声明**********************************

//应用程序函数
void InitSDL( int windowed );
void FreeSDL();
void OpenFonts();
void CloseFonts();

//和游戏状态对应的函数
void MainLoop();	//0 游戏主循环
void InitGame();	//1 游戏初始化
void MainMove();	//2 主角在地图走动的函数
void StartFight();	//3 开始战斗
void Fighting();	//4	战斗中
void FightEnd();	//5 战斗结束
void TreatNpc();	//6 处理Npc事件
void GameTitle();	//7
void GameExit();	//8 游戏退出
void System_Menu();	//9 游戏过程中调出系统菜单
void GameMessage();	//10 游戏过程中显示消息
void AutoPlay();	//11 自动剧情
void Load();	//12 装载档案
void Store();	//13 存储档案	
void BeforeSelect();	//14 弹出玩家选择的菜单
void WaitSelect();	//15 等待玩家选择
void SelectYes();	//16 玩家做出是的选择
void SelectNo();	//17 玩家做出否的选择
void CheckState();	//18 查看玩家状态
void CheckAbout();	//19 查看作品信息

//更新游戏画面函数
void DrawState();		//1 画主角的状态
void DrawStateDetail();	//2 显示详细状态信息
void DrawStartMenu();	//3 画开始菜单
void DrawSystemMenu();	//4 画系统菜单
void DrawSelectMenu();	//5 画选择菜单
void DrawRecord();		//6 画纪录
void RefreshCanvas();	//7 更新非战斗画面
void UpdateFight();		//8 更新战斗画面
void DrawRoundNum();	//9 画战斗回合数
//void ClrScr();			//10 清屏
void DrawPic(const char *);	//11 在屏幕上显示图片
void ShowAbout();		//12 显示作品的信息	
void FlipPage();		//13 将离屏页面的内容传送到主页面
void DrawTitle();		//14 在离屏页面上画片头
void DrawEnd();			//15 画片尾

//游戏辅助函数
void BorderCheck(int *x,int *y);	//1 边界检测
short CrushCheck();					//2 碰撞检测
void SceneChange();					//3 场景切换函数
void QueryMessage(short);			//4 响应玩家在特定地点按下空格事件
short FindNpc();					//5 寻找玩家面对的Npc,返回Npc的ID
void GetMapbyID(int);				//6 通过地图ID，改变current_map
Role * GetNpcbyID(int);				//7 得到npc的指针
void RelayoutNpc();					//8 切换地图时，重新加载NPC
void GotoMap(Map *);				//9 主角走到新的地图
//void PressKey(DWORD key);			//10等待按键松开
void play_sound(const char *);			//11 播放声音

//操作游戏数据函数
void InitData();					//1 初始化数据
short LoadData(char *);				//2 读取数据
short StoreData(char *);				//3 存储数据



#endif
