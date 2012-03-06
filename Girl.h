#ifndef __GIRLH__
#define __GIRLH__

#include "Role.h"
#include "Map.h"
#include "Record.h"
#include "Dialog.h"
#include "Fighter.h"
#include "Menu.h"




#define CK RGB(0,0,0)	//����ؼ�ɫ
#define speed 20	//�����ɫ�ƶ��ٶ�
#define FRAME_TIME 120	//����һ֡�ĺ�����

//��Ϸ����״̬�ĺ궨��
#define GAME_LOAD_	0	//��Ϸ����װ��
#define GAME_TITLE_	1	//��Ϸ��ʼ����
#define MAIN_MOVE_	2	//����ҿ�������
#define READ_RECORD_	3	//��ȡ��¼
#define GAME_EXIT_	4	//�����˳���Ϸ
#define SYSTEM_MENU_	5	//��Ϸ�����е���ϵͳ�˵�
#define WRITE_RECORD_	6	//��д��¼
#define GAME_MESSAGE_	7	//ϵͳ��Ϣ
#define FIGHT_START_	8	//ս����ʼ
#define FIGHTING_	9	//ս������
#define FIGHT_END_	10	//ս������
#define AUTO_PLAY_	11	//�Զ�����
#define TREAT_NPC_	12	//����NPC�¼�
#define BEFORE_SELECT_	13	//�����ȴ����ѡ��𰸵�ҳ��
#define WAIT_SELECT_	14	//�ȴ��������ѡ��
#define	SELECT_YES_		15	//��������ǵ�ѡ��
#define SELECT_NO_		16	//����������ѡ��
#define CHECK_STATE_	17	//�鿴״̬
#define CHECK_ABOUT_	18	//�鿴��Ʒ��Ϣ


//**********************��������**************************************

short bActive;
short game_running;

int SCR_X;	//��������Ļ�ϵ�λ��
int SCR_Y;
//RECT OldWindow;	//���ڴ������ƶ��¼�����¼�ƶ�ǰ����λ��




//ҳ��
SDL_Surface *screen;
SDL_Surface *hero;
SDL_Surface *XiShi;
SDL_Surface *FanLi;
SDL_Surface *sheep;
SDL_Surface *other_yue;//7 Խ������ҳ��
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


//��ͼ
Map Map_aqing;	//1
Map Map_shaoxing;	//2
Map Map_citydoor;	//3
Map Map_fanli;	//4
Map Map_Wuguo;	//5
Map Map_caoyuan;	//6
Map Map_Gongdian;	//7
Map Map_outside;	//8
Map Map_Xiangfang;	//9

//��ɫ
Role Aqing;		//1 ���ǰ���
Role QingBed;	//2 ����Ĵ�
Role AqingMa;	//3	������
Role Sheep1;	//4
Role Sheep2;	//5 ��ֻ����
Role ZhangDaye;	//6 ����߶���Ŵ�ү
Role LiDashu;	//7	���˵������
Role CaiTan;	//8 �����Ĳ�̯
Role Wujianshi1;//9	
Role Wujianshi2;//10 ���������˳���Ұ�������ʿ
Role YueWeibing1;	//11
Role YueWeibing2;	//12 ���ŵ������׺�������
Role Puren;		//13 ����
Role Fanli;		//14 ���
Role box_fanli;	//15 ���ҵı���
Role WuWeibing1;//16 
Role WuWeibing2;//17 ����������׺�������
Role Xishi;		//18 ������ʩ
Role Yehaizi;	//19 ��ԭ�ϵ�Ұ����
Role box_caoyuan;	//20 ��ԭ�ϱ���
Role Jianke;	//21 �����᷿�е����ؽ���
Role box_jianke;	//22 ���͵ı���
Role Wushi;		//23 ���˳��е���ʦ
Role Feitu;		//24 ����ķ�ͽ
Role Shangping;	//25 ������ƽ
Role Shiwei;	//26 ��ʩ������

//ս����ɫ
Fighter fAqing;		//1 ս���İ���
Fighter fWushi1;	//2
Fighter fWushi2;	//3 ս�������������ʿ
Fighter fYehaizi;	//4 ս����Ұ����
Fighter fJianke;	//5 ս�������ؽ���
Fighter fWushi;		//6 ս������ʦ
Fighter fFeitu;		//7 ս���ķ�ͽ
Fighter fShangping; //8 ������ƽ
Fighter fShiwei;	//9 ��ʩ������

//�˵�����
Menu StartMenu[4];	//��ʼ�˵�
Menu SystemMenu[4];	//ϵͳ�˵�
Menu SelectMenu[2];	//ѡ��˵�
Record GameRecord[3];	//��¼�˵�

//ȫ����Ϸ����
Dialog common_diag;	//������Ϣ��
int current_npc_id;	//��ǰ��Npc��id
Map * current_map;	//��ǰ�ĵ�ͼָ��
Fighter * current_enemy;	//��ǰ�ĵ���ָ��
short TrapNum; //��Ҳ��е�������
long old_time, new_time; //���ڼ���֡ʱ��ı���
short frame_fight;	//ս��ʱ��֡����
int fight_frame_num;	//ս������֡��
short round_num;	//�غ���
short Flag;//��Ϸ����״̬��־

//�����־����
short asked_by_fanli;	//1 ���������ı�־
short asked_to_house;	//2 ���Ҫȥ�᷿�Һ���Ķ���
short see_jianke;		//3 �Ƿ�������ؽ���
short get_key;			//4 �õ���󻱦���Կ��
short defeat_feitu;		//5 �Ƿ����˷�ͽ
short defeat_shangping;	//6 �Ƿ�������ƽ
short ask_to_caoyuan;	//7 ���ؽ��ͽ���ȥ��ԭ
short see_yehaizi;		//8 �Ƿ����Ұ����
short defeat_yehaizi;    //9 �Ƿ��Ѵ��Ұ����
short defeat_jianke;	    //10 �Ƿ��ѵֵ����ؽ��ͣ������غ�
short ask_where_fanli;	//11 �Ƿ��Ѿ��ʹ����Ķ���
short really_defeat_jianke;	//12 �Ƿ�����������ؽ���
short defeat_shiwei;		//13 ��ܷ������



//**************************��������**********************************

//Ӧ�ó�����
void InitSDL( int windowed );
void FreeSDL();
void OpenFonts();
void CloseFonts();

//����Ϸ״̬��Ӧ�ĺ���
void MainLoop();	//0 ��Ϸ��ѭ��
void InitGame();	//1 ��Ϸ��ʼ��
void MainMove();	//2 �����ڵ�ͼ�߶��ĺ���
void StartFight();	//3 ��ʼս��
void Fighting();	//4	ս����
void FightEnd();	//5 ս������
void TreatNpc();	//6 ����Npc�¼�
void GameTitle();	//7
void GameExit();	//8 ��Ϸ�˳�
void System_Menu();	//9 ��Ϸ�����е���ϵͳ�˵�
void GameMessage();	//10 ��Ϸ��������ʾ��Ϣ
void AutoPlay();	//11 �Զ�����
void Load();	//12 װ�ص���
void Store();	//13 �洢����	
void BeforeSelect();	//14 �������ѡ��Ĳ˵�
void WaitSelect();	//15 �ȴ����ѡ��
void SelectYes();	//16 ��������ǵ�ѡ��
void SelectNo();	//17 ����������ѡ��
void CheckState();	//18 �鿴���״̬
void CheckAbout();	//19 �鿴��Ʒ��Ϣ

//������Ϸ���溯��
void DrawState();		//1 �����ǵ�״̬
void DrawStateDetail();	//2 ��ʾ��ϸ״̬��Ϣ
void DrawStartMenu();	//3 ����ʼ�˵�
void DrawSystemMenu();	//4 ��ϵͳ�˵�
void DrawSelectMenu();	//5 ��ѡ��˵�
void DrawRecord();		//6 ����¼
void RefreshCanvas();	//7 ���·�ս������
void UpdateFight();		//8 ����ս������
void DrawRoundNum();	//9 ��ս���غ���
//void ClrScr();			//10 ����
void DrawPic(const char *);	//11 ����Ļ����ʾͼƬ
void ShowAbout();		//12 ��ʾ��Ʒ����Ϣ	
void FlipPage();		//13 ������ҳ������ݴ��͵���ҳ��
void DrawTitle();		//14 ������ҳ���ϻ�Ƭͷ
void DrawEnd();			//15 ��Ƭβ

//��Ϸ��������
void BorderCheck(int *x,int *y);	//1 �߽���
short CrushCheck();					//2 ��ײ���
void SceneChange();					//3 �����л�����
void QueryMessage(short);			//4 ��Ӧ������ض��ص㰴�¿ո��¼�
short FindNpc();					//5 Ѱ�������Ե�Npc,����Npc��ID
void GetMapbyID(int);				//6 ͨ����ͼID���ı�current_map
Role * GetNpcbyID(int);				//7 �õ�npc��ָ��
void RelayoutNpc();					//8 �л���ͼʱ�����¼���NPC
void GotoMap(Map *);				//9 �����ߵ��µĵ�ͼ
//void PressKey(DWORD key);			//10�ȴ������ɿ�
void play_sound(const char *);			//11 ��������

//������Ϸ���ݺ���
void InitData();					//1 ��ʼ������
short LoadData(char *);				//2 ��ȡ����
short StoreData(char *);				//3 �洢����



#endif
