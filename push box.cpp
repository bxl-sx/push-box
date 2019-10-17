#include<iostream>
#include<conio.h>
#include <windows.h>

using namespace std;
void Game_Menu();
void Game_description();
int DrawMap();
void Move();
int finish();
void setmap(int n);
void color(int m);
bool flag = true;
int pass = 1;
#define R 10
#define C 10
int map[R][C] = {0};
//�ؿ�1 
int map1[R][C] = {
{ 0,0,1,1,1,0,0,0 },
{ 0,0,1,3,1,0,0,0 },
{ 0,0,1,0,1,1,1,1 },
{ 1,1,1,0,0,4,3,1 },
{ 1,3,4,4,0,1,1,1 },
{ 1,1,1,5,4,1,0,0 },
{ 0,0,0,1,3,1,0,0 },
{ 0,0,0,1,1,1,0,0 }
};
//��ͼ 2���ؿ�2��
int map2[R][C]={
{1,1,1,1,1,0,0,0,0,0},
{1,5,0,0,1,0,0,0,0,0},
{1,0,4,4,1,0,1,1,1,0},
{1,0,4,0,1,0,1,3,1,0},
{1,1,1,0,1,1,1,3,1,0},
{0,1,1,0,0,0,0,3,1,0},
{0,1,0,0,0,1,0,0,1,0},
{0,1,0,0,0,1,1,1,1,0},
{0,1,1,1,1,1,0,0,0,0}
};
//��ͼ 3���ؿ�3��
int map3[R][C]={
{ 0,0,0,1,1,1,1,1,1,1 },
{ 0,0,1,1,0,0,1,0,5,1 },
{ 0,0,1,0,0,0,1,0,0,1 },
{ 0,0,1,4,0,4,0,4,0,1 },
{ 0,0,1,0,4,1,1,0,0,1 },
{ 1,1,1,0,4,0,1,0,1,1 },
{ 1,3,3,3,3,3,0,0,1,0 },
{ 1,1,1,1,1,1,1,1,1,0 },
};
void Game_Menu(){
	system("cls");
	cout << "*******************" << endl;
	cout << "      ������       " << endl;
	cout << "    ��s��S��ʼ     " << endl;
	cout << "    ��q��Q�˳�     " << endl;
	cout << "*******************" << endl;
	_getch();
};
void Game_description(){
	//system("cls");
	cout << "*****************************\n";
	cout << "     ����������������ƶ�    \n";
	cout << " �������ӵ���Ŀ�ĵ���Ϸʤ��  \n";
	cout << "*****************************\n";
};
int DrawMap(){
	cout << "��" << pass << "��\n";
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			switch(map[i][j]){
				case 0:
					color(0x7);
					cout << "  ";  //�յء����?���??��
    				break;
   				case 1:
    				color(8);
    				cout << "��";//ǽ��
    				break;
   				case 3:
    				color(0xE);
    				cout << "��";//Ŀ�ĵ�
    				break;
   				case 4:
    				color(4);
    				cout << "��";//���� 
    				break;
   				case 5:
    				color(3);
    				cout << "��"; //��
    				break;
   				case 7:     //4+3   ���ӵ���Ŀ�ĵ�
    				color(6);   
    				cout << "��";
    				break;
   				case 8:     //5+3  ����Ŀ�ĵ��غ�
    				color(3);
    				cout << "��";
    				break;
   				default:
    				break;
   			}
		}
		cout << '\n';
	}
	return 0;
};
void Move(){
	int x = 0, y = 0;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(map[i][j] == 5 || map [i] [j] == 8){
				x = i;
				y = j;
				break;
			}
		}
	}
	cout << "��ǰλ��:(" << x << ',' << y << ")\n";
	int ch = _getch();
	switch(ch){
		case 'w':
		case 'W':
		case 72:
			if(map[x - 1][y] == 0 || map[x - 1][y] == 3){
				map[x][y] -= 5;
				map[x - 1][y] += 5;
			}
			else if(map[x - 1][y] == 4 || map[x - 1][y] == 7){
				if(map[x - 2][y] == 0 || map[x - 2][y] == 3){
					map[x][y] -= 5;
					map[x - 1][y] += 1;
					map[x - 2][y] += 4;
				}
			}
			break;
		
		case 's':
		case 'S':
		case 80:
			if(map[x + 1][y] == 0 || map[x + 1][y] == 3){
				map[x][y] -= 5;
				map[x + 1][y] += 5;
			}
			else if(map[x + 1][y] == 4 || map[x + 1][y] == 7){
				if(map[x + 2][y] == 0 || map[x + 2][y] == 3){
					map[x][y] -= 5;
					map[x + 1][y] += 1;
					map[x + 2][y] += 4;
				}
			}
			break;
		
		case 'a':
		case 'A':
		case 75:
			if(map[x][y - 1] == 0 || map[x][y - 1] == 3){
				map[x][y] -= 5;
				map[x][y - 1] += 5;
			}
			else if(map[x][y - 1] == 4 || map[x][y - 1] == 7){
				if(map[x][y - 2] == 0 || map[x][y - 2] == 3){
					map[x][y] -= 5;
					map[x][y - 1] += 1;
					map[x][y - 2] += 4;
				}
			}
			break;
		
		case 'd':
		case 'D':
		case 77:
			if(map[x][y + 1] == 0 || map[x][y + 1] == 3){
				map[x][y] -= 5;
				map[x][y + 1] += 5;
			}
			else if(map[x][y + 1] == 4 || map[x][y + 1] == 7){
				if(map[x][y + 2] == 0 || map[x][y + 2] == 3){
					map[x][y] -= 5;
					map[x][y + 1] += 1;
					map[x][y + 2] += 4;
				}
			}
			break;
		case 'q':
		case 'Q':
			flag = false;
		default:
			break;	
	}
};
int finish(){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(map[i][j] == 4)return 0;
		}
	}
	return 1;
};
void setmap(int n){
	switch(n){
		case 1:
			memcpy(map, map1, sizeof(map1));
			break;
		case 2:
			memcpy(map, map2, sizeof(map2));
			break;
		case 3:
			memcpy(map, map3, sizeof(map3));
			break;
	}
};
void color(int m){
	HANDLE consolehend;
	consolehend = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehend, m); 
};
int main(){
	Game_Menu();
	char ch = getch();
	setmap(pass);
	
	if(ch == 'q' || ch == 'Q'){
		return 0;
	}
	while(flag){
		system("cls");
		Game_description();
		DrawMap();
		//while(flag){
			Move();
			//Sleep(100);
			if(finish()){
				system("cls");
				DrawMap();
				cout << " ��ϲ���ɹ����أ�\n";
				system("pause");
				pass++;
				setmap(pass);
				
			}
		
	}
	return 0; 
}

