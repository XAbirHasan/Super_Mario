#define _CRT_SECURE_NO_WARNINGS

# include "igraphics.h"


void use_for_calling_animtion();

void move_forward();
void move_backward();
void win_mario();
void movement(unsigned char key);
void back_ground();
void game_ground();
void jump_move();
void size();
void obstacle();

void land_mark();
void land_mark_fall();

void fall_down();
void fall_down_no_land();

void fall_check();

void coin_movement();
void coin_collect();

void enemy();
void kill_enemy();
void dead();
void enemy_Move();
void timer();


bool mario_dead;


int mposx, mposy;																																																															// forward.....0-8																																																										// move back.......	9-17																																																						// jump f........	18-28...																																																																// jump back.....29 -39

char mario[40][30] = { "char\\move forward\\1.bmp", "char\\move forward\\2.bmp", "char\\move forward\\3.bmp", "char\\move forward\\4.bmp", "char\\move forward\\5.bmp", "char\\move forward\\6.bmp", "char\\move forward\\7.bmp", "char\\move forward\\8.bmp", "char\\move forward\\9.bmp", "char\\move backward\\1.bmp", "char\\move backward\\2.bmp", "char\\move backward\\3.bmp", "char\\move backward\\4.bmp", "char\\move backward\\5.bmp", "char\\move backward\\6.bmp", "char\\move backward\\7.bmp", "char\\move backward\\8.bmp", "char\\move backward\\9.bmp", "char\\jump f\\1.bmp", "char\\jump f\\2.bmp", "char\\jump f\\3.bmp", "char\\jump f\\4.bmp", "char\\jump f\\5.bmp", "char\\jump f\\6.bmp", "char\\jump f\\7.bmp", "char\\jump f\\8.bmp", "char\\jump f\\9.bmp", "char\\jump f\\10.bmp", "char\\jump f\\11.bmp", "char\\jump b\\1.bmp", "char\\jump b\\2.bmp", "char\\jump b\\3.bmp", "char\\jump b\\4.bmp", "char\\jump b\\5.bmp", "char\\jump b\\6.bmp", "char\\jump b\\7.bmp", "char\\jump b\\8.bmp", "char\\jump b\\9.bmp", "char\\jump b\\10.bmp", "char\\jump b\\11.bmp" };
int index_forward, index_backward = 9;
int jump_index_f = 18, jump_index_b = 29; // NOT NEEDED......NOW.......
int move_index;

char mario_jump[4][30] = { "char\\jump forward\\1.bmp", "char\\jump forward\\2.bmp", "char\\jump backward\\1.bmp", "char\\jump backward\\2.bmp" };
int jump_index;

bool jump, jump_up, jump_down;
double jump_dx, jump_dy;


char win[40][30] = { "char\\win\\1.bmp", "char\\win\\2.bmp", "char\\win\\3.bmp", "char\\win\\4.bmp", "char\\win\\5.bmp", "char\\win\\6.bmp", "char\\win\\7.bmp", "char\\win\\8.bmp", "char\\win\\9.bmp", "char\\win\\10.bmp", "char\\win\\11.bmp", "char\\win\\12.bmp", "char\\win\\13.bmp", "char\\win\\14.bmp", "char\\win\\15.bmp", "char\\win\\16.bmp", "char\\win\\17.bmp", "char\\win\\18.bmp", "char\\win\\19.bmp", "char\\win\\20.bmp", "char\\win\\21.bmp", "char\\win\\22.bmp", "char\\win\\23.bmp", "char\\win\\24.bmp", "char\\win\\25.bmp", "char\\win\\26.bmp", "char\\win\\27.bmp", "char\\win\\28.bmp", "char\\win\\29.bmp", "char\\win\\30.bmp", "char\\win\\31.bmp", "char\\win\\32.bmp", "char\\win\\33.bmp", "char\\win\\34.bmp", "char\\win\\35.bmp", "char\\win\\36.bmp", "char\\win\\37.bmp", "char\\win\\38.bmp", "char\\win\\39.bmp", "char\\win\\40.bmp" };
int win_index;

double mario_dx, mario_dy = 35;

char background[10][20] = { "background\\1.bmp", "background\\2.bmp", "background\\3.bmp", "background\\4.bmp", "background\\5.bmp", "background\\6.bmp", "background\\7.bmp", "background\\8.bmp", "background\\9.bmp", "background\\10.bmp", };
int index = -1;

int stand;

char mario_fall[2][30] = { "char\\jump forward\\2.bmp", "char\\jump backward\\2.bmp" };
bool can_fall, now_fall;
double fall_dx, fall_dy;
int fall_index;

char mario_fall_no_land[2][30] = { "char\\jump forward\\2.bmp", "char\\jump backward\\2.bmp" };
bool now_fall_no_land;
double fall_no_land_dx, fall_no_land_dy;
int fall_no_land_index;

char coin_pic[4][30] = { "coin\\1.bmp", "coin\\2.bmp", "coin\\3.bmp", "coin\\4.bmp" };
int coin_index;

char enemy_1_pic[2][30] = { "char\\enemy\\1.bmp", "char\\enemy\\2.bmp" };
int enemy_1_index;

char enemy_2_pic[4][30] = { "char\\enemy 2 f\\1.bmp", "char\\enemy 2 f\\2.bmp", "char\\enemy 2 b\\1.bmp", "char\\enemy 2 b\\2.bmp" };
int enemy_2_index;

char mario_die_pic_f[19][30] = { "char\\die f\\1.bmp", "char\\die f\\2.bmp", "char\\die f\\3.bmp", "char\\die f\\4.bmp", "char\\die f\\5.bmp", "char\\die f\\6.bmp", "char\\die f\\7.bmp", "char\\die f\\8.bmp", "char\\die f\\9.bmp", "char\\die f\\10.bmp", "char\\die f\\11.bmp", "char\\die f\\12.bmp", "char\\die f\\13.bmp", "char\\die f\\14.bmp", "char\\die f\\15.bmp", "char\\die f\\16.bmp", "char\\die f\\17.bmp", "char\\die f\\18.bmp", "char\\die f\\19.bmp" };
int die_index_f;

char mario_die_pic_b[19][30] = { "char\\die b\\1.bmp", "char\\die b\\2.bmp", "char\\die b\\3.bmp", "char\\die b\\4.bmp", "char\\die b\\5.bmp", "char\\die b\\6.bmp", "char\\die b\\7.bmp", "char\\die b\\8.bmp", "char\\die b\\9.bmp", "char\\die b\\10.bmp", "char\\die b\\11.bmp", "char\\die b\\12.bmp", "char\\die b\\13.bmp", "char\\die b\\14.bmp", "char\\die b\\15.bmp", "char\\die b\\16.bmp", "char\\die b\\17.bmp", "char\\die b\\18.bmp", "char\\die b\\19.bmp" };
int die_index_b;

double dx[10];

bool move_right, move_left, game_win, move_anywhere_right, move_anywhere_left;

struct object
{
	double Lx, Rx;
	double Ly, Ry;

	double H_lx, H_rx;
	double H_ly, H_ry;

	double Mx, My;
	double D_mx, D_my;

}mario_size;

struct coin_object
{
	double dx, dy;

}coin[41];

int coin_show[40];

struct enemy_object
{
	double dx, dy;

}enemy_1[10];
int show_enemy_1[10];

struct enemy_object2
{
	double dx, dy;

}enemy_2[3];
int show_enemy_2[3];

int menu;
double menu_dx = 654, menu_dy = 174, m_width = 364, m_height = 77;
double red, green, blue;

char Score[10], Time[10], Life[10];
int score_int, time_int=300, life_int=3;

bool game_over;


void iDraw()
{
	iClear();
	if (menu == 0)
	{
		iShowBMP(0, 0, "home\\home.bmp");

		iSetColor(red, green, blue);
		iRectangle(menu_dx, menu_dy, m_width, m_height);
		iRectangle(menu_dx - .5, menu_dy - .5, m_width + 1, m_height + 1);
		iRectangle(menu_dx - 1, menu_dy - 1, m_width + 2, m_height + 2);
		iRectangle(menu_dx - 1.5, menu_dy - 1.5, m_width + 3, m_height + 3);
		iRectangle(menu_dx - 2, menu_dy - 2, m_width + 4, m_height + 4);
		iRectangle(menu_dx - 2.5, menu_dy - 2.5, m_width + 5, m_height + 5);
		iRectangle(menu_dx - 3, menu_dy - 3, m_width + 6, m_height + 6);
	}
	else if (menu == 1)
	{
		iShowBMP(0, 0, "home\\instruction.bmp");

		iSetColor(red, green, blue);
		iRectangle(menu_dx, menu_dy, m_width, m_height);
		iRectangle(menu_dx - .5, menu_dy - .5, m_width + 1, m_height + 1);
		iRectangle(menu_dx - 1, menu_dy - 1, m_width + 2, m_height + 2);
		iRectangle(menu_dx - 1.5, menu_dy - 1.5, m_width + 3, m_height + 3);
		iRectangle(menu_dx - 2, menu_dy - 2, m_width + 4, m_height + 4);
		iRectangle(menu_dx - 2.5, menu_dy - 2.5, m_width + 5, m_height + 5);
		iRectangle(menu_dx - 3, menu_dy - 3, m_width + 6, m_height + 6);
	}
	else if (game_over == 1)
	{
		iShowBMP(0, 0, "home\\gameOver.bmp");
	}
	else if (menu == 2 && game_over == 0)
	{
		game_ground();
		size();
		land_mark();
		land_mark_fall();
		coin_collect();
		kill_enemy();
	}
	
	
}

void game_ground()
{
	iShowBMP(0, 0, background[index]);
	_itoa(score_int, Score, 10);
	_itoa(time_int, Time, 10);
	_itoa(life_int, Life, 10);
	
	iSetColor(255, 255, 255);

	iText(90, 540, "Score :", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(180, 540, Score, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(490, 540, "Time :", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(580, 540, Time, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(940, 540, "Life :", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1030, 540, Life, GLUT_BITMAP_TIMES_ROMAN_24);
	
	for (int i = 0; i < 40; i++)
	{
		if (coin_show[i] == 1 && (coin[i].dx != 0 || coin[i].dy != 0))
		{
			iShowBMP2(coin[i].dx, coin[i].dy, coin_pic[coin_index], 255);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (show_enemy_1[i] == 1 && (enemy_1[i].dx != 0 && enemy_1[i].dy != 0))
		{
			iShowBMP2(enemy_1[i].dx, enemy_1[i].dy, enemy_1_pic[enemy_1_index], 255);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (show_enemy_2[i] == 1 && (enemy_2[i].dx != 0 && enemy_2[i].dy != 0))
		{
			iShowBMP2(enemy_2[i].dx, enemy_2[i].dy, enemy_2_pic[enemy_2_index], 0);
		}
	}
	
	

	if (game_win == 1)
	{
		iShowBMP2(815, 35, win[win_index], 0);
	}
	else if (mario_dead == 1)
	{
		if (move_right == 1)
		{
			iShowBMP2(mario_dx - 10, mario_dy, mario_die_pic_f[die_index_f], 0);
		}
		else if (move_left == 1)
		{
			iShowBMP2(mario_dx + 10, mario_dy, mario_die_pic_b[die_index_b], 0);
		}
		
	}
	else
	{
		if (jump == 1)
		{
			iShowBMP2(mario_dx + jump_dx, mario_dy + jump_dy, mario_jump[jump_index], 0);
		}
		else if (now_fall == 1)
		{
			iShowBMP2(mario_dx + fall_dx, mario_dy + fall_dy, mario_fall[fall_index], 0);
		}
		else if (now_fall_no_land == 1)
		{ 
			iShowBMP2(mario_dx + fall_no_land_dx, mario_dy + fall_no_land_dy, mario_fall_no_land[fall_no_land_index], 0);
		}
		else
		{
			iShowBMP2(mario_dx, mario_dy, mario[move_index], 0);
			stand++;
			if (stand > 60)
			{
				stand = 0;
				if (move_right == 1)
				{
					move_index = 0;
				}
				else if (move_left == 1)
				{
					move_index = 9;
				}

			}
		}
	}
}



void iMouseMove(int mx, int my)
{
	//place your codes here

}



void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && menu == 0)
	{
		if (mx > 645 && mx < 1018)
		{
			if (my>174 && my < 251)
			{
				menu = 1;
				menu_dx = 511;
				menu_dy = 61;
				m_width = 146;
				m_height = 39;
			}
			else if (my>48 && my < 124)
			{
				exit(0);
			}
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && menu == 1)
	{
		if (mx > 511 && mx < 675)
		{
			if (my > 61 && my < 100)
			{
				menu = 2;
				index = 0;
				back_ground();
			}
		
		}
	}

	printf("mx= %d...... my= %d\n", mx, my);
	
}

/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	mposx = mx;
	mposy = my;

	if (menu == 0)
	{
		if (mx > 645 && mx < 1018)
		{
			if (my>174 && my < 251)
			{
				menu_dx = 654;
				menu_dy = 174;
				red = 26;
				green = 237;
				blue = 237;
			}
			else if (my>48 && my < 124)
			{
				menu_dx = 654;
				menu_dy = 48;
				red = 26;
				green = 237;
				blue = 237;
			}
			else
			{
				red = 237;
				green = 43;
				blue = 26;
			}
		}
		else
		{
			red = 237;
			green = 43;
			blue = 26;
		}
	}
	if (menu == 1)
	{
		if (mx > 511 && mx < 675)
		{
			if (my > 61 && my < 100)
			{
				menu_dx = 511;
				menu_dy = 61;
				red = 26;
				green = 237;
				blue = 237;
			}
		}
		else
		{
			red = 237;
			green = 43;
			blue = 26;
		}
	}

	//printf("mx= %d...... my= %d\n", mx, my);

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	size();
	land_mark();
	land_mark_fall();
	if (key == ' ' && jump == 0 && now_fall_no_land == 0 && now_fall == 0 && mario_dead == 0)
	{
		jump = 1;
		jump_up = 1;
	}
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{
	size();
	obstacle();
	land_mark();
	land_mark_fall();
	if (now_fall == 0){
		fall_check();
		
	}
	if (mario_dead == 0)
	{
		movement(key);
	}
	
	
	
	//printf("jump = %d \t jump_down = %d\n", jump, jump_down);
	//printf("back = %d   pixel : %.2f  \nObject_R : %.2f   object l : %.2f\nObject_Ry : %.2f   object ly : %.2f\n", back_index, pixel_dx, mario_size.Rx, mario_size.Lx, mario_size.Ry, mario_size.Ly);
}

void size()       /// here size is position of mario............
{
	mario_size.Lx = mario_dx + jump_dx + 31;
	mario_size.Rx = mario_dx + jump_dx + 72;
	mario_size.H_lx = mario_dx + jump_dx + 31;
	mario_size.H_rx = mario_dx + jump_dx + 72;
	mario_size.Mx = mario_dx + jump_dx + 51;
	mario_size.D_mx = mario_dx + jump_dx + 51;
	
	if (now_fall == 1)
	{
		mario_size.Ly = mario_dy + fall_dy;
		mario_size.Ry = mario_dy + fall_dy;
		mario_size.H_ly = mario_dy + fall_dy + 68;
		mario_size.H_ry = mario_dy + fall_dy + 68;
		mario_size.My = mario_dy + fall_dy + 55;
		mario_size.D_my = mario_dy + fall_dy;
	}
	else
	{
		mario_size.Ly = mario_dy + jump_dy;
		mario_size.Ry = mario_dy + jump_dy;
		mario_size.H_ly = mario_dy + jump_dy + 68;
		mario_size.H_ry = mario_dy + jump_dy + 68;
		mario_size.My = mario_dy + jump_dy + 55;
		mario_size.D_my = mario_dy + jump_dy;
	}
	
}

void movement(unsigned char key)
{
	if (move_anywhere_right == 1)
	{
		if (key == GLUT_KEY_RIGHT)
		{
			move_anywhere_left = 1;
			move_right = 1;
			move_left = 0;
			move_index = index_forward;
			fall_index = 0;

			if (jump_up == 1)
			{
				jump_index = 0;
			}
			else if (jump == 0)
			{
				jump_index = 0;
			}
			else if (jump_down == 1)
			{
				jump_index = 1;
			}

			mario_dx += 5;
			if (mario_dx > 502 && index == 9)
			{
				game_win = 1;
				mario_dx = 800;
			}
			if (mario_dx >= 1200)
			{
				mario_dx = 0;
				index++;
				back_ground();
				
			}

		}
	}
	if (move_anywhere_left == 1)
	{
		if (key == GLUT_KEY_LEFT)
		{
			move_anywhere_right = 1;
			move_left = 1;
			move_right = 0;
			move_index = index_backward;
			fall_index = 1;

			if (jump_up == 1)
			{
				jump_index = 2;
			}
			else if (jump == 0)
			{
				jump_index = 2;
			}
			else if (jump_down == 1)
			{
				jump_index = 3;
			}

			mario_dx -= 5;
			if (mario_dx < 0)
			{
				mario_dx = 0;
			}
		}
	}
}

void obstacle()
{


	if (index == 1)  // 1st satge
	{
		if (move_right == 1)
		{
			if ((mario_size.Rx > 903 && mario_size.Rx < 954) && (mario_size.Ry> 164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 1002 && mario_size.Rx < 1056) && (mario_size.Ry> 164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 1102 && mario_size.Rx < 1153) && (mario_size.Ry> 164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
		}
		if (move_left == 1)
		{
			if ((mario_size.Lx > 903 && mario_size.Lx < 954) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 1002 && mario_size.Lx < 1056) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 1102 && mario_size.Lx < 1153) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
		}
	}

	if (index == 2)  // 2nd satge...........
	{ 
		if (move_right == 1)
		{
			if ((mario_size.Rx > 100 && mario_size.Rx < 200) && (mario_size.Ry>30 && mario_size.Ry < 122))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 608 && mario_size.Rx < 698) && (mario_size.Ry>30 && mario_size.Ry < 164))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 1007 && mario_size.Rx < 1100) && (mario_size.Ry>30 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
		}
		if (move_left == 1)
		{
			if ((mario_size.Lx > 100 && mario_size.Lx < 200) && (mario_size.Ly>30 && mario_size.Ly < 122))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 608 && mario_size.Lx < 698) && (mario_size.Ly>30 && mario_size.Ly < 164))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 1007 && mario_size.Lx < 1100) && (mario_size.Ly>30 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
		}
	}

	else if (index == 3)         /// Stage 3.............
	{
		if (move_right == 1)
		{
			if ((mario_size.Rx > 354 && mario_size.Rx < 452) && (mario_size.Ry>30 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else
			{
				move_anywhere_right = 1;
			}
		}
		if (move_left == 1)
		{
			if ((mario_size.Lx > 354 && mario_size.Lx < 452) && (mario_size.Ly>30 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else
			{
				move_anywhere_left = 1;
			}
		}
	}

	else if (index == 4)
	{
		if (move_right == 1)
		{
			if ((mario_size.Rx > 147 && mario_size.Rx < 198) && (mario_size.Ry>164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 251 && mario_size.Rx < 300) && (mario_size.Ry>164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 298 && mario_size.Rx < 700) && (mario_size.Ry>331 && mario_size.Ry < 374))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 848 && mario_size.Rx < 1002) && (mario_size.Ry>331 && mario_size.Ry < 374))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 998 && mario_size.Rx < 1052) && (mario_size.Ry>164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
		}
		if (move_left == 1)
		{
			if ((mario_size.Lx > 147 && mario_size.Lx < 198) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 251 && mario_size.Lx < 300) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 298 && mario_size.Lx < 700) && (mario_size.Ly>331 && mario_size.Ly < 374))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 848 && mario_size.Lx < 1002) && (mario_size.Ly>331 && mario_size.Ly < 374))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 998 && mario_size.Lx < 1052) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
		}
	}
	else if (index == 5)          // stage 5............
	{
		if (move_right == 1)
		{
			if ((mario_size.Rx > 97 && mario_size.Rx < 200) && (mario_size.Ry> 164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 998 && mario_size.Rx < 1051) && (mario_size.Ry> 164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 1147) && (mario_size.Ry> 311 && mario_size.Ry < 374))                //..................................................................>>>>>>>>>>>>>>>>>>
			{
				move_anywhere_right = 0;
			}
		}
		if (move_left == 1)
		{
			if ((mario_size.Lx > 97 && mario_size.Lx < 200) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 998 && mario_size.Lx < 1051) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 1147) && (mario_size.Ly>331 && mario_size.Ly < 374))                 //..............................................................>>>>>>>>>>>>>>>>>>
			{
				move_anywhere_left = 0;
			}
		}
	}

	else if (index == 6)
	{
		if (move_right == 1)
		{
			if (( mario_size.Rx < 100) && (mario_size.Ry > 331 && mario_size.Ry < 374))             //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<...........................................
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 297 && mario_size.Rx < 351) && (mario_size.Ry > 331 && mario_size.Ry < 374))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 345 && mario_size.Rx < 450) && (mario_size.Ry>164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 449 && mario_size.Rx < 501) && (mario_size.Ry > 331 && mario_size.Ry < 374))
			{
				move_anywhere_right = 0;
			}
			


			else if ((mario_size.Rx > 598 && mario_size.Rx < 647) && (mario_size.Ry>30 && mario_size.Ry < 82))                                  //////////////////
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 647 && mario_size.Rx < 699) && (mario_size.Ry>30 && mario_size.Ry < 122))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 699 && mario_size.Rx < 749) && (mario_size.Ry>30 && mario_size.Ry < 164))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 749 && mario_size.Rx < 800) && (mario_size.Ry>30 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}


			else if ((mario_size.Rx > 898 && mario_size.Rx < 948) && (mario_size.Ry>30 && mario_size.Ry < 206))               //////
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 948 && mario_size.Rx < 999) && (mario_size.Ry>30 && mario_size.Ry < 164))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 999 && mario_size.Rx < 1049) && (mario_size.Ry>30 && mario_size.Ry < 122))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 1049 && mario_size.Rx < 1100) && (mario_size.Ry>30 && mario_size.Ry < 82))
			{
				move_anywhere_right = 0;
			}
			else
			{
				move_anywhere_right = 1;
			}
		}
		if (move_left == 1)
		{
			if (( mario_size.Lx < 100) && (mario_size.Ly>331 && mario_size.Ly < 374))                 //<<<<<<<<<<<<<<<<<<<<<<<<<..........................................................
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 297 && mario_size.Lx < 351) && (mario_size.Ly>331 && mario_size.Ly < 374))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 345 && mario_size.Lx < 450) && (mario_size.Ly>164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 449 && mario_size.Lx < 501 ) && (mario_size.Ly>331 && mario_size.Ly < 374))
			{
				move_anywhere_left = 0;
			}


			if ((mario_size.Lx > 598 && mario_size.Lx < 647) && (mario_size.Ly>30 && mario_size.Ly < 82))                        ////////
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 647 && mario_size.Lx < 699) && (mario_size.Ly>30 && mario_size.Ly < 122))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 699 && mario_size.Lx < 749) && (mario_size.Ly>30 && mario_size.Ly < 164))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 749 && mario_size.Lx < 800) && (mario_size.Ly>30 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}



			else if ((mario_size.Lx > 898 && mario_size.Lx < 948) && (mario_size.Ly>30 && mario_size.Ly < 206))                        ///////
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 948 && mario_size.Lx < 999) && (mario_size.Ly>30 && mario_size.Ly < 164))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 999 && mario_size.Lx < 1049) && (mario_size.Ly>30 && mario_size.Ly < 122))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 1049 && mario_size.Lx < 1100) && (mario_size.Ly>30 && mario_size.Ly < 82))
			{
				move_anywhere_left = 0;
			}
			else
			{
				move_anywhere_left = 1;
			}
		}
	}
	else if (index == 7)
	{
		if (move_right == 1)
		{
			if ((mario_size.Rx > 100 && mario_size.Rx < 149) && (mario_size.Ry>30 && mario_size.Ry < 82))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 149 && mario_size.Rx < 199) && (mario_size.Ry>30 && mario_size.Ry < 122))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 199 && mario_size.Rx < 249) && (mario_size.Ry> 30 && mario_size.Ry < 164))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 249 && mario_size.Rx < 350) && (mario_size.Ry>30 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}


			else if ((mario_size.Rx > 449 && mario_size.Rx < 499) && (mario_size.Ry>30 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 499 && mario_size.Rx < 549) && (mario_size.Ry>30 && mario_size.Ry < 164))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 549 && mario_size.Rx < 599) && (mario_size.Ry> 30 && mario_size.Ry < 122))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 599 && mario_size.Rx < 649) && (mario_size.Ry>30 && mario_size.Ry < 82))
			{
				move_anywhere_right = 0;
			}


			else if ((mario_size.Rx > 853 && mario_size.Rx < 948) && (mario_size.Ry > 30 && mario_size.Ry < 122))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 1099 && mario_size.Rx < 1200) && (mario_size.Ry>164 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}


		}
		if (move_left == 1)
		{
			if ((mario_size.Lx > 100 && mario_size.Lx < 149) && (mario_size.Ly>30 && mario_size.Ly < 82))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 149 && mario_size.Lx < 199) && (mario_size.Ly>30 && mario_size.Ly < 122))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 199 && mario_size.Lx < 249) && (mario_size.Ly>30 && mario_size.Ly < 164))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 249 && mario_size.Lx < 350) && (mario_size.Ly>30 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}


			else if ((mario_size.Lx > 449 && mario_size.Lx < 499) && (mario_size.Ly>30 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 499 && mario_size.Lx < 549) && (mario_size.Ly>30 && mario_size.Ly < 164))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 549 && mario_size.Lx < 599) && (mario_size.Ly>30 && mario_size.Ly < 122))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 599 && mario_size.Lx < 649) && (mario_size.Ly>30 && mario_size.Ly < 82))
			{
				move_anywhere_left = 0;
			}



			else if ((mario_size.Lx > 853 && mario_size.Lx < 948) && (mario_size.Ly>30 && mario_size.Ly < 122))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 1099 && mario_size.Lx < 1198) && (mario_size.Ly> 164 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}

		}
	}


	else if (index == 8)
	{
		if (move_right == 1)
		{
			if ((mario_size.Rx > 49 && mario_size.Rx < 101) && (mario_size.Ry>163 && mario_size.Ry < 205))
			{
				move_anywhere_right = 0;
			}



			else if ((mario_size.Rx > 450 && mario_size.Rx < 550) && (mario_size.Ry>30 && mario_size.Ry < 122))
			{
				move_anywhere_right = 0;
			}



			else if ((mario_size.Rx > 550 && mario_size.Rx < 600) && (mario_size.Ry> 30 && mario_size.Ry < 82))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 600 && mario_size.Rx < 650) && (mario_size.Ry>30 && mario_size.Ry < 122))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 650 && mario_size.Rx < 700) && (mario_size.Ry>30 && mario_size.Ry < 164))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 700 && mario_size.Rx < 750) && (mario_size.Ry>30 && mario_size.Ry < 206))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 750 && mario_size.Rx < 800) && (mario_size.Ry> 30 && mario_size.Ry < 249))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 800 && mario_size.Rx < 850) && (mario_size.Ry>30 && mario_size.Ry < 290))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 850 && mario_size.Rx < 900) && (mario_size.Ry > 30 && mario_size.Ry < 332))
			{
				move_anywhere_right = 0;
			}
			else if ((mario_size.Rx > 900 && mario_size.Rx < 1000) && (mario_size.Ry>164 && mario_size.Ry < 375))
			{
				move_anywhere_right = 0;
			}


		}
		if (move_left == 1)
		{
			if ((mario_size.Lx > 49 && mario_size.Lx < 101) && (mario_size.Ly> 163 && mario_size.Ly < 205))
			{
				move_anywhere_left = 0;
			}


			else if ((mario_size.Lx > 450 && mario_size.Lx < 550) && (mario_size.Ly>30 && mario_size.Ly <122))
			{
				move_anywhere_left = 0;
			}




			else if ((mario_size.Lx > 550 && mario_size.Lx < 600) && (mario_size.Ly>30 && mario_size.Ly < 80))
			{
				move_anywhere_left = 0;
			}



			else if ((mario_size.Lx > 600 && mario_size.Lx < 650) && (mario_size.Ly>30 && mario_size.Ly < 122))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 650 && mario_size.Lx < 700) && (mario_size.Ly>30 && mario_size.Ly < 164))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 700 && mario_size.Lx < 750) && (mario_size.Ly>30 && mario_size.Ly < 206))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 750 && mario_size.Lx < 800) && (mario_size.Ly>30 && mario_size.Ly < 249))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 800 && mario_size.Lx < 850) && (mario_size.Ly>30 && mario_size.Ly < 290))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 850 && mario_size.Lx < 900) && (mario_size.Ly>30 && mario_size.Ly < 332))
			{
				move_anywhere_left = 0;
			}
			else if ((mario_size.Lx > 900 && mario_size.Lx < 1000) && (mario_size.Ly>30 && mario_size.Ly < 375))
			{
				move_anywhere_left = 0;
			}
		}
	}

	else if (index == 9)         /// Stage 9.............
	{
		if (move_right == 1)
		{
			if ((mario_size.Rx > 200 && mario_size.Rx < 250) && (mario_size.Ry>30 && mario_size.Ry < 82))
			{
				move_anywhere_right = 0;
			}
		}
		if (move_left == 1)
		{
			if ((mario_size.Lx > 200 && mario_size.Lx < 250) && (mario_size.Ly>30 && mario_size.Ly < 82))
			{
				move_anywhere_left = 0;
			}
	
		}
	}
}


void land_mark()
{
	
	if (index == 1)  // 1st satge
	{
		
		if (((mario_size.Rx - 3 > 903 && mario_size.Rx < 954) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 903 && mario_size.Lx < 954) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 > 1002 && mario_size.Rx < 1056) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 1002 && mario_size.Lx < 1056) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 > 1102 && mario_size.Rx < 1153) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 1102 && mario_size.Lx < 1153) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		
	}

	else if (index == 2)  // 2nd satge...........
	{
		if (((mario_size.Rx -3 > 100 && mario_size.Rx < 200) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 100 && mario_size.Lx < 200) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
			jump = 0;
			mario_dy = 122;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx -3> 608 && mario_size.Rx < 698) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 608 && mario_size.Lx < 698) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
			jump = 0;
			mario_dy = 164;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx -3> 1007 && mario_size.Rx < 1100) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 1007 && mario_size.Lx < 1100) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
	}
	

	else if (index == 3 )         /// Stage 3.............
	{
		if(((mario_size.Rx - 3 > 354 && mario_size.Rx - 3 < 452) && (mario_size.Ry  >203 && mario_size.Ry  < 209)) || ((mario_size.Lx  > 354 && mario_size.Lx  < 452) && (mario_size.Ly >203 && mario_size.Ly  < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}		
	}
	
	else if (index == 4)       // stage 4...........
	{
		if (((mario_size.Rx - 3 > 147 && mario_size.Rx < 198) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 147 && mario_size.Lx < 198) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 > 251 && mario_size.Rx < 300) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 251 && mario_size.Lx < 300) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 > 298 && mario_size.Rx < 700) && (mario_size.Ry>371 && mario_size.Ry < 377)) || ((mario_size.Lx > 298 && mario_size.Lx < 700) && (mario_size.Ly>371 && mario_size.Ly < 377)))
		{
			jump = 0;
			mario_dy = 374;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 > 848 && mario_size.Rx < 1002) && (mario_size.Ry>371 && mario_size.Ry < 377)) || ((mario_size.Lx > 848 && mario_size.Lx < 1002) && (mario_size.Ly>371 && mario_size.Ly < 377)))
		{
			jump = 0;
			mario_dy = 374;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 998 && mario_size.Rx < 1052) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 998 && mario_size.Lx < 1052) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
	}
	else if (index == 5)          // stage 5............
	{
		if (((mario_size.Rx - 3> 97 && mario_size.Rx < 200) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 97 && mario_size.Lx < 200) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 > 998 && mario_size.Rx < 1051) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 998 && mario_size.Lx < 1051) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 1147) && (mario_size.Ry> 371 && mario_size.Ry < 377)) || ((mario_size.Lx > 1147) && (mario_size.Ly>371 && mario_size.Ly < 377)))                //..................................................................>>>>>>>>>>>>>>>>>>
		{
			jump = 0;
			mario_dy = 374;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
	}

	else if (index == 6)    // stage 6..........
	{
		if (((mario_size.Rx - 3 < 100) && (mario_size.Ry > 371 && mario_size.Ry < 377)) || ((mario_size.Lx < 100) && (mario_size.Ly>371 && mario_size.Ly < 377)))           //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<...........................................
		{
			jump = 0;
			mario_dy = 374;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 > 297 && mario_size.Rx < 351) && (mario_size.Ry > 371 && mario_size.Ry < 377)) || ((mario_size.Lx > 297 && mario_size.Lx < 351) && (mario_size.Ly>371 && mario_size.Ly < 377)))
		{
			jump = 0;
			mario_dy = 374;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 345 && mario_size.Rx < 450) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 345 && mario_size.Lx < 450) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 >449 && mario_size.Rx < 501) && (mario_size.Ry > 371 && mario_size.Ry < 377)) || ((mario_size.Lx > 449 && mario_size.Lx < 501) && (mario_size.Ly>371 && mario_size.Ly < 377)))
		{
			jump = 0;
			mario_dy = 374;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}



		else if (((mario_size.Rx - 3 >598 && mario_size.Rx < 647) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 598 && mario_size.Lx < 647) && (mario_size.Ly>79 && mario_size.Ly < 85)))                                  //////////////////
		{
			jump = 0;
			mario_dy = 82;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 647 && mario_size.Rx < 699) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 647 && mario_size.Lx < 699) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
			jump = 0;
			mario_dy = 122;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 699 && mario_size.Rx < 749) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 699 && mario_size.Lx < 749) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
			jump = 0;
			mario_dy = 164;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 749 && mario_size.Rx < 800) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 749 && mario_size.Lx < 800) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}


		else if (((mario_size.Rx - 3> 898 && mario_size.Rx < 948) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 898 && mario_size.Lx < 948) && (mario_size.Ly>203 && mario_size.Ly < 209)))              //////
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 948 && mario_size.Rx < 999) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 948 && mario_size.Lx < 999) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
			jump = 0;
			mario_dy = 164;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3 > 999 && mario_size.Rx < 1049) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 999 && mario_size.Lx < 1049) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
			jump = 0;
			mario_dy = 122;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 1049 && mario_size.Rx < 1100) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 1049 && mario_size.Lx < 1100) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
			jump = 0;
			mario_dy = 82;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
	}

	else if (index == 7)   // stage 7.........
	{
		if (((mario_size.Rx - 3 > 100 && mario_size.Rx < 149) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 100 && mario_size.Lx < 149) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
			jump = 0;
			mario_dy = 82;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 149 && mario_size.Rx < 199) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 149 && mario_size.Lx < 199) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
			jump = 0;
			mario_dy = 122;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 199 && mario_size.Rx < 249) && (mario_size.Ry> 161 && mario_size.Ry < 167)) || ((mario_size.Lx > 199 && mario_size.Lx < 249) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
			jump = 0;
			mario_dy = 164;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 249 && mario_size.Rx < 350) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 249 && mario_size.Lx < 350) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}


		else if (((mario_size.Rx - 3 > 449 && mario_size.Rx < 499) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 449 && mario_size.Lx < 499) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 499 && mario_size.Rx < 549) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 499 && mario_size.Lx < 549) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
			jump = 0;
			mario_dy = 164;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 549 && mario_size.Rx < 599) && (mario_size.Ry> 119 && mario_size.Ry < 125)) || ((mario_size.Lx > 549 && mario_size.Lx < 599) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
			jump = 0;
			mario_dy = 122;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 599 && mario_size.Rx < 649) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 599 && mario_size.Lx < 649) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
			jump = 0;
			mario_dy = 82;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}


		else if (((mario_size.Rx - 3> 853 && mario_size.Rx < 948) && (mario_size.Ry > 119 && mario_size.Ry < 125)) || ((mario_size.Lx > 853 && mario_size.Lx < 948) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
			jump = 0;
			mario_dy = 122;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 1099 && mario_size.Rx < 1200) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 1099 && mario_size.Lx < 1198) && (mario_size.Ly> 203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
	}


	else if (index == 8)
	{
		if (((mario_size.Rx - 3> 49 && mario_size.Rx < 101) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 49 && mario_size.Lx < 101) && (mario_size.Ly> 203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}



		else if (((mario_size.Rx - 3> 450 && mario_size.Rx < 550) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 450 && mario_size.Lx < 550) && (mario_size.Ly>119 && mario_size.Ly <125)))
		{
			jump = 0;
			mario_dy = 122;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}



		else if (((mario_size.Rx - 3> 550 && mario_size.Rx < 600) && (mario_size.Ry> 79 && mario_size.Ry < 85)) || ((mario_size.Lx > 550 && mario_size.Lx < 600) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
			jump = 0;
			mario_dy = 82;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 600 && mario_size.Rx < 650) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 600 && mario_size.Lx < 650) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
			jump = 0;
			mario_dy = 122;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 650 && mario_size.Rx < 700) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 650 && mario_size.Lx < 700) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
			jump = 0;
			mario_dy = 164;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 700 && mario_size.Rx < 750) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 700 && mario_size.Lx < 750) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
			jump = 0;
			mario_dy = 206;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 750 && mario_size.Rx < 800) && (mario_size.Ry> 246 && mario_size.Ry < 252)) || ((mario_size.Lx > 750 && mario_size.Lx < 800) && (mario_size.Ly>246 && mario_size.Ly < 252)))
		{
			jump = 0;
			mario_dy = 249;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 800 && mario_size.Rx < 850) && (mario_size.Ry>287 && mario_size.Ry < 293)) || ((mario_size.Lx > 800 && mario_size.Lx < 850) && (mario_size.Ly>287 && mario_size.Ly < 293)))
		{
			jump = 0;
			mario_dy = 290;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 850 && mario_size.Rx < 900) && (mario_size.Ry > 329 && mario_size.Ry < 335)) || ((mario_size.Lx > 850 && mario_size.Lx < 900) && (mario_size.Ly>329 && mario_size.Ly < 335)))
		{
			jump = 0;
			mario_dy = 322;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
		else if (((mario_size.Rx - 3> 900 && mario_size.Rx < 1000) && (mario_size.Ry>372 && mario_size.Ry < 378)) || ((mario_size.Lx > 900 && mario_size.Lx < 1000) && (mario_size.Ly>372 && mario_size.Ly < 378)))
		{
			jump = 0;
			mario_dy = 375;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
	}

	else if (index == 9)         /// Stage 9.............
	{
		if (((mario_size.Rx - 3> 200 && mario_size.Rx < 250) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 200 && mario_size.Lx < 250) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
			jump = 0;
			mario_dy = 82;
			jump_dy = 0;
			can_fall = 1;
			now_fall = 0;
		}
	}
}




void land_mark_fall()
{ 
	if (index == 3)         /// Stage 3.............
	{
		if (((mario_size.Rx - 3> 951 && mario_size.Rx < 1053) && (mario_size.Ry>32 && mario_size.Ry < 38)) && ((mario_size.Lx > 951 && mario_size.Lx < 1053) && (mario_size.Ly> 32 && mario_size.Ly < 38)))
		{
			jump = 0;
			mario_dy = 0;
			fall_no_land_dy = 35;
			now_fall_no_land = 1;
		}
	}
	else if (index == 4)         /// Stage 3.............
	{
		if (((mario_size.Rx - 3> 600 && mario_size.Rx < 748) && (mario_size.Ry>32 && mario_size.Ry < 38)) && ((mario_size.Lx > 600 && mario_size.Lx < 748) && (mario_size.Ly> 32 && mario_size.Ly < 38)))
		{
			jump = 0;
			mario_dy = 0;
			fall_no_land_dy = 35;
			now_fall_no_land = 1;
		}
	}
	else if (index == 7)         /// Stage 3.............
	{
		if (((mario_size.Rx - 3> 350 && mario_size.Rx < 449) && (mario_size.Ry>32 && mario_size.Ry < 38)) && ((mario_size.Lx > 350 && mario_size.Lx < 449) && (mario_size.Ly> 32 && mario_size.Ly < 38)))
		{
			jump = 0;
			mario_dy = 0;
			fall_no_land_dy = 35;
			now_fall_no_land = 1;
		}
	}
}






void fall_check()
{
	if (index == 1)  // 1st satge
	{

		if (((mario_size.Rx - 3 > 903 && mario_size.Rx < 954) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 903 && mario_size.Lx < 954) && (mario_size.Ly>203 && mario_size.Ly < 209))){
		}
		else if (((mario_size.Rx - 3 > 1002 && mario_size.Rx < 1056) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 1002 && mario_size.Lx < 1056) && (mario_size.Ly>203 && mario_size.Ly < 209))){
		}
		else if (((mario_size.Rx - 3 > 1102 && mario_size.Rx < 1153) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 1102 && mario_size.Lx < 1153) && (mario_size.Ly>203 && mario_size.Ly < 209))){
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}

	}
	
	else if (index == 2)
	{
		if (((mario_size.Rx - 3 > 100 && mario_size.Rx < 200) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 100 && mario_size.Lx < 200) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
		}
		else if (((mario_size.Rx - 3> 608 && mario_size.Rx < 698) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 608 && mario_size.Lx < 698) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
		}
		else if (((mario_size.Rx - 3> 1007 && mario_size.Rx < 1100) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 1007 && mario_size.Lx < 1100) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}

	}
	
	else if (index == 3)         /// Stage 3.............
	{
		if (((mario_size.Rx - 3 > 354 && mario_size.Rx - 3 < 452) && (mario_size.Ry  >203 && mario_size.Ry  < 209)) || ((mario_size.Lx  > 354 && mario_size.Lx  < 452) && (mario_size.Ly >203 && mario_size.Ly  < 209)))
		{
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}
	}
	
	else if (index == 4)       // stage 4...........
	{
		if (((mario_size.Rx - 3 > 147 && mario_size.Rx < 198) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 147 && mario_size.Lx < 198) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else if (((mario_size.Rx - 3 > 251 && mario_size.Rx < 300) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 251 && mario_size.Lx < 300) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else if (((mario_size.Rx - 3 > 298 && mario_size.Rx < 700) && (mario_size.Ry>371 && mario_size.Ry < 377)) || ((mario_size.Lx > 298 && mario_size.Lx < 700) && (mario_size.Ly>371 && mario_size.Ly < 377)))
		{
		}
		else if (((mario_size.Rx - 3 > 848 && mario_size.Rx < 1002) && (mario_size.Ry>371 && mario_size.Ry < 377)) || ((mario_size.Lx > 848 && mario_size.Lx < 1002) && (mario_size.Ly>371 && mario_size.Ly < 377)))
		{
		}
		else if (((mario_size.Rx - 3> 998 && mario_size.Rx < 1052) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 998 && mario_size.Lx < 1052) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}
	}


	else if (index == 5)          // stage 5............
	{
		if (((mario_size.Rx - 3> 97 && mario_size.Rx < 200) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 97 && mario_size.Lx < 200) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else if (((mario_size.Rx - 3 > 998 && mario_size.Rx < 1051) && (mario_size.Ry> 203 && mario_size.Ry < 209)) || ((mario_size.Lx > 998 && mario_size.Lx < 1051) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else if (((mario_size.Rx - 3> 1147) && (mario_size.Ry> 371 && mario_size.Ry < 377)) || ((mario_size.Lx > 1147) && (mario_size.Ly>371 && mario_size.Ly < 377)))                //..................................................................>>>>>>>>>>>>>>>>>>
		{
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}
	}

	else if (index == 6)    // stage 6..........
	{
		if (((mario_size.Rx - 3 < 100) && (mario_size.Ry > 371 && mario_size.Ry < 377)) || ((mario_size.Lx < 100) && (mario_size.Ly>371 && mario_size.Ly < 377)))           //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<...........................................
		{
		}
		else if (((mario_size.Rx - 3 > 297 && mario_size.Rx < 351) && (mario_size.Ry > 371 && mario_size.Ry < 377)) || ((mario_size.Lx > 297 && mario_size.Lx < 351) && (mario_size.Ly>371 && mario_size.Ly < 377)))
		{
		}
		else if (((mario_size.Rx - 3> 345 && mario_size.Rx < 450) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 345 && mario_size.Lx < 450) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else if (((mario_size.Rx - 3 >449 && mario_size.Rx < 501) && (mario_size.Ry > 371 && mario_size.Ry < 377)) || ((mario_size.Lx > 449 && mario_size.Lx < 501) && (mario_size.Ly>371 && mario_size.Ly < 377)))
		{
		}



		else if (((mario_size.Rx - 3 >598 && mario_size.Rx < 647) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 598 && mario_size.Lx < 647) && (mario_size.Ly>79 && mario_size.Ly < 85)))                                  //////////////////
		{
		}
		else if (((mario_size.Rx - 3> 647 && mario_size.Rx < 699) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 647 && mario_size.Lx < 699) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
		}
		else if (((mario_size.Rx - 3> 699 && mario_size.Rx < 749) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 699 && mario_size.Lx < 749) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
		}
		else if (((mario_size.Rx - 3> 749 && mario_size.Rx < 800) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 749 && mario_size.Lx < 800) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}


		else if (((mario_size.Rx - 3> 898 && mario_size.Rx < 948) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 898 && mario_size.Lx < 948) && (mario_size.Ly>203 && mario_size.Ly < 209)))              //////
		{
		}
		else if (((mario_size.Rx - 3> 948 && mario_size.Rx < 999) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 948 && mario_size.Lx < 999) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
		}
		else if (((mario_size.Rx - 3 > 999 && mario_size.Rx < 1049) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 999 && mario_size.Lx < 1049) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
		}
		else if (((mario_size.Rx - 3> 1049 && mario_size.Rx < 1100) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 1049 && mario_size.Lx < 1100) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}
	}

	else if (index == 7)
	{
		if (((mario_size.Rx - 3 > 100 && mario_size.Rx < 149) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 100 && mario_size.Lx < 149) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
		}
		else if (((mario_size.Rx - 3> 149 && mario_size.Rx < 199) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 149 && mario_size.Lx < 199) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
		}
		else if (((mario_size.Rx - 3> 199 && mario_size.Rx < 249) && (mario_size.Ry> 161 && mario_size.Ry < 167)) || ((mario_size.Lx > 199 && mario_size.Lx < 249) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
		}
		else if (((mario_size.Rx - 3> 249 && mario_size.Rx < 350) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 249 && mario_size.Lx < 350) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}


		else if (((mario_size.Rx - 3 > 449 && mario_size.Rx < 499) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 449 && mario_size.Lx < 499) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else if (((mario_size.Rx - 3> 499 && mario_size.Rx < 549) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 499 && mario_size.Lx < 549) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
		}
		else if (((mario_size.Rx - 3> 549 && mario_size.Rx < 599) && (mario_size.Ry> 119 && mario_size.Ry < 125)) || ((mario_size.Lx > 549 && mario_size.Lx < 599) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
		}
		else if (((mario_size.Rx - 3> 599 && mario_size.Rx < 649) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 599 && mario_size.Lx < 649) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
		}


		else if (((mario_size.Rx - 3> 853 && mario_size.Rx < 948) && (mario_size.Ry > 119 && mario_size.Ry < 125)) || ((mario_size.Lx > 853 && mario_size.Lx < 948) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
		}
		else if (((mario_size.Rx - 3> 1099 && mario_size.Rx < 1200) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 1099 && mario_size.Lx < 1198) && (mario_size.Ly> 203 && mario_size.Ly < 209)))
		{
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}
	}


	else if (index == 8)     // satge 8............
	{
		if (((mario_size.Rx - 3> 49 && mario_size.Rx < 101) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 49 && mario_size.Lx < 101) && (mario_size.Ly> 203 && mario_size.Ly < 209)))
		{
		}



		else if (((mario_size.Rx - 3> 450 && mario_size.Rx < 550) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 450 && mario_size.Lx < 550) && (mario_size.Ly>119 && mario_size.Ly <125)))
		{
		}



		else if (((mario_size.Rx - 3> 550 && mario_size.Rx < 600) && (mario_size.Ry> 79 && mario_size.Ry < 85)) || ((mario_size.Lx > 550 && mario_size.Lx < 600) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
		}
		else if (((mario_size.Rx - 3> 600 && mario_size.Rx < 650) && (mario_size.Ry>119 && mario_size.Ry < 125)) || ((mario_size.Lx > 600 && mario_size.Lx < 650) && (mario_size.Ly>119 && mario_size.Ly < 125)))
		{
		}
		else if (((mario_size.Rx - 3> 650 && mario_size.Rx < 700) && (mario_size.Ry>161 && mario_size.Ry < 167)) || ((mario_size.Lx > 650 && mario_size.Lx < 700) && (mario_size.Ly>161 && mario_size.Ly < 167)))
		{
		}
		else if (((mario_size.Rx - 3> 700 && mario_size.Rx < 750) && (mario_size.Ry>203 && mario_size.Ry < 209)) || ((mario_size.Lx > 700 && mario_size.Lx < 750) && (mario_size.Ly>203 && mario_size.Ly < 209)))
		{
		}
		else if (((mario_size.Rx - 3> 750 && mario_size.Rx < 800) && (mario_size.Ry> 246 && mario_size.Ry < 252)) || ((mario_size.Lx > 750 && mario_size.Lx < 800) && (mario_size.Ly>246 && mario_size.Ly < 252)))
		{
		}
		else if (((mario_size.Rx - 3> 800 && mario_size.Rx < 850) && (mario_size.Ry>287 && mario_size.Ry < 293)) || ((mario_size.Lx > 800 && mario_size.Lx < 850) && (mario_size.Ly>287 && mario_size.Ly < 293)))
		{
		}
		else if (((mario_size.Rx - 3> 850 && mario_size.Rx < 900) && (mario_size.Ry > 329 && mario_size.Ry < 335)) || ((mario_size.Lx > 850 && mario_size.Lx < 900) && (mario_size.Ly>329 && mario_size.Ly < 335)))
		{
		}
		else if (((mario_size.Rx - 3> 900 && mario_size.Rx < 1000) && (mario_size.Ry>372 && mario_size.Ry < 378)) || ((mario_size.Lx > 900 && mario_size.Lx < 1000) && (mario_size.Ly>372 && mario_size.Ly < 378)))
		{
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}
	}

	else if (index == 9)         /// Stage 9.............
	{
		if (((mario_size.Rx - 3> 200 && mario_size.Rx < 250) && (mario_size.Ry>79 && mario_size.Ry < 85)) || ((mario_size.Lx > 200 && mario_size.Lx < 250) && (mario_size.Ly>79 && mario_size.Ly < 85)))
		{
		}
		else
		{
			if (can_fall == 1 && jump == 0)
			{
				now_fall = 1;
				fall_dy = mario_dy - 35;
				mario_dy = 35;
			}
		}
	}
	
}


void coin_collect()                                    ////........................... coin 
{
	   
	for (int i = 0; i<40; i++)
	{
		if (((mario_size.Rx - 3 > coin[i].dx + 2 && mario_size.Rx < coin[i].dx + 33) && (mario_size.Ry > coin[i].dy && mario_size.Ry < coin[i].dy + 35)) || ((mario_size.Lx > coin[i].dx + 2 && mario_size.Lx < coin[i].dx + 33) && (mario_size.Ly>coin[i].dy && mario_size.Ly < coin[i].dy + 35)) || ((mario_size.H_rx > coin[i].dx + 2 && mario_size.H_rx < coin[i].dx + 33) && (mario_size.H_ry > coin[i].dy && mario_size.H_ry < coin[i].dy + 35)) || ((mario_size.H_lx > coin[i].dx + 2 && mario_size.H_lx < coin[i].dx + 33) && (mario_size.H_ly>coin[i].dy && mario_size.H_ly < coin[i].dy + 35)) || ((mario_size.Mx > coin[i].dx + 2 && mario_size.Mx < coin[i].dx + 33) && (mario_size.My > coin[i].dy && mario_size.My < coin[i].dy + 35)))
		{
			if (coin_show[i] == 1)
			{
				score_int += 10;
			}
			coin_show[i] = 0;
		}
	}

}

void kill_enemy()
{
	for (int i = 0; i < 10; i++)
	{
		if (jump_down == 1 || now_fall == 1)
		{
			if (((mario_size.Rx - 3 > enemy_1[i].dx + 2 && mario_size.Rx < enemy_1[i].dx + 48) && (mario_size.Ry > enemy_1[i].dy && mario_size.Ry < enemy_1[i].dy + 40)) || ((mario_size.Lx > enemy_1[i].dx + 2 && mario_size.Lx < enemy_1[i].dx + 48) && (mario_size.Ly>enemy_1[i].dy && mario_size.Ly < enemy_1[i].dy + 40)) || ((mario_size.D_mx > enemy_1[i].dx + 2 && mario_size.D_mx < enemy_1[i].dx + 48) && (mario_size.D_my > enemy_1[i].dy && mario_size.D_my < enemy_1[i].dy + 40)))
			{
				if (show_enemy_1[i] == 1)
				{
					score_int += 100;
				}
				show_enemy_1[i] = 0;
			}
		}
		else
		{
			if (show_enemy_1[i] == 1 && enemy_1[i].dx != 0 && enemy_1[i].dx !=0)
			{

				if (move_right == 1)
				{
					if (((mario_size.Rx - 3 > enemy_1[i].dx + 2 && mario_size.Rx < enemy_1[i].dx + 48) && (mario_size.Ry > enemy_1[i].dy - 2 && mario_size.Ry < enemy_1[i].dy + 40)) || ((mario_size.Lx - 3 > enemy_1[i].dx + 2 && mario_size.Lx < enemy_1[i].dx + 48) && (mario_size.Ly>enemy_1[i].dy - 2 && mario_size.Ly < enemy_1[i].dy + 40)))
					{
						mario_dead = 1;
					}
				}
				else if (move_left == 1)
				{
					if (((mario_size.Rx - 3 > enemy_1[i].dx + 2 && mario_size.Rx < enemy_1[i].dx + 48) && (mario_size.Ry > enemy_1[i].dy - 2 && mario_size.Ry < enemy_1[i].dy + 40)) || ((mario_size.Lx - 3 > enemy_1[i].dx + 2 && mario_size.Lx < enemy_1[i].dx + 48) && (mario_size.Ly>enemy_1[i].dy - 2 && mario_size.Ly < enemy_1[i].dy + 40)))
					{
						mario_dead = 1;
					}
				}
			}
		}
	}
}

void back_ground()
{
	
	if(index == 0)
	{
		coin[0].dx = 250;
		coin[0].dy = 250;

		coin[1].dx = 500;
		coin[1].dy = 200;

		coin[2].dx = 750;
		coin[2].dy = 200;

		enemy_1[0].dx = 1200;
		enemy_1[0].dy = 35;

	}
	else if (index == 1)
	{
		coin_show[0] = 0;
		coin_show[1] = 0;
		coin_show[2] = 0;

		show_enemy_1[0] = 0;
		
		coin[3].dx = 200;
		coin[3].dy = 200;

		coin[4].dx = 400;
		coin[4].dy = 200;

		coin[5].dx = 1004;
		coin[5].dy = 370;

		coin[6].dx = 960;
		coin[6].dy = 168;

		coin[7].dx = 650;
		coin[7].dy = 370;

		coin[8].dx = 1060;
		coin[8].dy = 168;

		enemy_1[1].dx = 1200;
		enemy_1[1].dy = 35;

		
	}
	else if (index == 2)
	{
		coin_show[3] = 0;
		coin_show[4] = 0;
		coin_show[5] = 0;
		coin_show[6] = 0;
		coin_show[7] = 0;
		coin_show[8] = 0;
		show_enemy_1[1] = 0;
		
		coin[9].dx = 130;
		coin[9].dy = 280;

		coin[10].dx = 628;
		coin[10].dy = 375;

		coin[11].dx = 1040;
		coin[11].dy = 450;

		enemy_1[2].dx = 400;
		enemy_1[2].dy = 35;
		dx[2] = 5;
		enemy_1[3].dx = 800;
		enemy_1[3].dy = 35;
		dx[3] = 5;

	}
	else if (index == 3)
	{
		coin_show[9] = 0;
		coin_show[10] = 0;
		coin_show[11] = 0;
		show_enemy_1[2] = 0; 
		show_enemy_1[3] = 0;
		
		coin[12].dx = 130;
		coin[12].dy = 200;

		coin[13].dx = 600;
		coin[13].dy = 300;

		coin[14].dx = 380;
		coin[14].dy = 410;


		coin[15].dx = 930;
		coin[15].dy = 180;

		coin[16].dx = 1040;
		coin[16].dy = 180;

		enemy_1[4].dx = 700;
		enemy_1[4].dy = 35;
		dx[4] = 5;


	}
	else if (index == 4)
	{
		coin_show[12] = 0;
		coin_show[13] = 0;
		coin_show[14] = 0;
		coin_show[15] = 0;
		coin_show[16] = 0;
		
		show_enemy_1[4] = 0;
		
		coin[17].dx = 207;
		coin[17].dy = 170;

		coin[18].dx = 380;
		coin[18].dy = 410;

		coin[19].dx = 480;
		coin[19].dy = 410;


		coin[20].dx = 580;
		coin[20].dy = 410;

		coin[21].dx = 907;
		coin[21].dy = 410;

		coin[22].dx = 656;
		coin[22].dy = 220;

		enemy_1[5].dx = 800;
		enemy_1[5].dy = 35;
		dx[5] = 5;

	}
	else if (index == 5)
	{
		coin_show[17] = 0;
		coin_show[18] = 0;
		coin_show[19] = 0;
		coin_show[20] = 0;
		coin_show[21] = 0;
		coin_show[22] = 0;

		show_enemy_1[5] = 0;
		
		coin[23].dx = 135;
		coin[23].dy = 330;

		coin[24].dx = 380;
		coin[24].dy = 250;

		coin[25].dx = 580;
		coin[25].dy = 170;

		coin[26].dx = 910;
		coin[26].dy = 410;

		enemy_1[6].dx = 1200;
		enemy_1[6].dy = 35;
	}
	else if (index == 6)
	{
		coin_show[23] = 0;
		coin_show[24] = 0;
		coin_show[25] = 0;
		coin_show[26] = 0;
	
		show_enemy_1[6] = 0;

		coin[27].dx = 40;
		coin[27].dy = 440;

		coin[28].dx = 306;
		coin[28].dy = 440;


		coin[29].dx = 458;
		coin[29].dy = 440;

		coin[30].dx = 840;
		coin[30].dy = 420;

		coin[31].dx = 550;
		coin[31].dy = 250;

		enemy_1[7].dx = 800;
		enemy_1[7].dy = 35;
		dx[7] = 5;
	
	}
	else if (index == 7)
	{
		coin_show[27] = 0;
		coin_show[28] = 0;
		coin_show[29] = 0;
		coin_show[30] = 0;
		coin_show[31] = 0;

		show_enemy_1[7] = 0;

		coin[32].dx = 97;
		coin[32].dy = 294;

		coin[33].dx = 384;
		coin[33].dy = 357;

		coin[34].dx = 881;
		coin[34].dy = 250;

		coin[35].dx = 1136;
		coin[35].dy = 365;

		enemy_1[8].dx = 700;
		enemy_1[8].dy = 35;
		dx[8] = 5;

	}
	else if (index == 8)
	{
		coin_show[32] = 0;
		coin_show[33] = 0;
		coin_show[34] = 0;
		coin_show[35] = 0;

		show_enemy_1[8] = 0;
		
		coin[36].dx = 65;
		coin[36].dy = 325;

		coin[37].dx = 183;
		coin[37].dy = 120;

		coin[38].dx = 471;
		coin[38].dy = 274;

		coin[39].dx = 946;
		coin[39].dy = 476;

		enemy_1[9].dx = 200;
		enemy_1[9].dy = 35;
		dx[9] = 5;

	}
	else if (index == 9)
	{
		coin_show[36] = 0;
		coin_show[37] = 0;
		coin_show[38] = 0;
		coin_show[39] = 0;
		show_enemy_1[9] = 0;
	}
}

void move_forward()
{
	if (move_right == 1)
	{
		index_forward++;
		if (index_forward >= 8)
		{
			index_forward = 1;
		}
		
	}
	
}

void move_backward()
{
	if (move_left == 1)
	{
		index_backward++;
		if (index_backward >= 17)
		{
			index_backward = 10;
		}
		
	}
}

void win_mario()
{
	if (game_win == 1)
	{
		win_index++;
		if (win_index > 39)
		{
			win_index = 32;
		}
	}
}


void jump_move()
{
	if (move_anywhere_right == 1)
	{
		if (jump == 1)
		{
			if (jump_up == 1)
			{
				jump_dy += 5;
				if (jump_dy >= 200)
				{
					jump_up = 0;
					jump_down = 1;
					if (move_right == 1)
					{
						jump_index = 1;
					}
					else if (move_left == 1)
					{
						jump_index = 3;
					}

				}
			}
			if (jump_down == 1)
			{
				jump_dy -= 5;
				if (jump_dy <= 0)
				{
					land_mark();
					jump_dy = 0;
					jump_down = 0;
					jump = 0;
					jump_index = 0;
					fall_check();
					if (move_right == 1)
					{
						jump_index = 0;
					}
					else if (move_left == 1)
					{
						jump_index = 2;
					}
				}
			}
		}
	}
}
void fall_down()
{
	if (now_fall == 1)
	{
		fall_dy -= 5;
		if (fall_dy <= 0)
		{
			fall_dy = 0;
			can_fall = 0;
			now_fall = 0;
			
			if (move_right == 1)
			{
				fall_index = 0;
			}
			else if (move_left == 1)
			{
				fall_index = 1;
			}
		}
	}
}
void fall_down_no_land()
{
	if (now_fall_no_land == 1)
	{
		fall_no_land_dy -= 5;
		if (fall_no_land_dy <= -40)
		{
			fall_no_land_dy = 0;
			now_fall_no_land = 0;
			mario_dy = 35;
			mario_dx = 0;
			if (move_right == 1)
			{
				fall_no_land_index = 0;
			}
			else if (move_left == 1)
			{
				fall_no_land_index = 1;
			}
		}
	}
}

void coin_movement()
{
	coin_index++;
	if (coin_index >=3)
	{
		coin_index = 0;
	}
	
}

void enemy()
{
	enemy_1_index++;
	if (enemy_1_index >= 2)
	{
		enemy_1_index = 0;
	}
	enemy_2_index++;
	if (enemy_2_index >= 2)
	{
		enemy_2_index = 0;
	}
}

void dead()
{
	if (mario_dead == 1)
	{
		if (move_right == 1)
		{
			die_index_f++;
			if (die_index_f >= 19)
			{
				die_index_f = 0;
				mario_dead = 0;
				mario_dx = 0;
				life_int--;
				if (life_int == 0)
				{
					game_over = 1;
				}
			}

		}
		else if (move_left == 1)
		{
			die_index_b++;
			if (die_index_b >= 19)
			{
				die_index_b = 0;
				mario_dead = 0;
				mario_dx = 0;
				life_int--;
				if (life_int == 0)
				{
					game_over = 1;
				}
			}
		}
	}
	
}

void use_for_calling_animtion()
{
	move_backward();
	move_forward();
	enemy_Move();
}

void enemy_Move()
{
	if (index == 0)
	{
		enemy_1[0].dx -= 5;
		if (enemy_1[0].dx <= -50)
		{
			enemy_1[0].dx = -50;
		}
	}
	else if (index == 1)
	{
		enemy_1[1].dx -= 5;
		if (enemy_1[0].dx <= -50)
		{
			enemy_1[0].dx = -50;
		}
	}
	else if (index == 2)
	{
		enemy_1[2].dx += dx[2];
		if (enemy_1[2].dx < 200 || enemy_1[2].dx > 560)
		{
			dx[2] = dx[2] * -1;
		}

		enemy_1[3].dx -= dx[3];
		if (enemy_1[3].dx < 700 || enemy_1[3].dx > 960)
		{
			dx[3] = dx[3] * -1;
		}
		 
	}
	else if (index == 3)
	{
		enemy_1[4].dx -= dx[4];
		if (enemy_1[4].dx < 450 || enemy_1[4].dx > 890)
		{
			dx[4] = dx[4] * -1;
		}
	}
	else if (index == 4)
	{
		enemy_1[5].dx -= dx[5];
		if (enemy_1[5].dx < 750 || enemy_1[5].dx > 1090)
		{
			dx[5] = dx[5] * -1;
		}
	}
	else if (index == 5)
	{
		enemy_1[6].dx -= 5;
		if (enemy_1[6].dx <= -50)
		{
			enemy_1[6].dx = -50;
		}
	}
	else if (index == 6)
	{
		enemy_1[7].dx -= dx[7];
		if (enemy_1[7].dx < 800 || enemy_1[7].dx > 850)
		{
			dx[7] = dx[7] * -1;
		}
	}
	else if (index == 7)
	{
		enemy_1[8].dx -= dx[8];
		if (enemy_1[8].dx < 652 || enemy_1[8].dx > 805)
		{
			dx[8] = dx[8] * -1;
		}
	}
	else if (index == 8)
	{
		enemy_1[9].dx -= dx[9];
		if (enemy_1[9].dx < 10 || enemy_1[9].dx > 405)
		{
			dx[9] = dx[9] * -1;
		}
	}
}

void timer()
{
	if (menu == 2)
	{
		time_int--;
		if (time_int == 0)
		{
			game_over = 1;
		}
	}
}

int main()
{
	iSetTimer(80, use_for_calling_animtion);
	iSetTimer(200, win_mario);
	iSetTimer(40, jump_move);
	iSetTimer(40, fall_down);
	iSetTimer(40, fall_down_no_land);
	iSetTimer(150, coin_movement);
	iSetTimer(150, enemy);
	iSetTimer(150, dead);
	iSetTimer(1000, timer);
	move_anywhere_right = move_anywhere_left = 1;

	int i;
	for (i = 0; i < 40; i++)
	{
		coin_show[i] = 1;
	}
	for (i = 0; i < 10; i++)
	{
		show_enemy_1[i] = 1;
	}

	iInitialize(1200, 600, "super mario");  // ..............dont change this or you will in trouble which you cant even imagine.......................

	return 0;
}