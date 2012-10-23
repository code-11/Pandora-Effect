#include <stdio.h>
#include <array>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <ncurses.h>
#include <utility>
#include <typeinfo>
#include "source.h"

#include <sstream>
#include <cstring>
//g++ map3.cpp -Wall -pedantic -lncurses -std=c++0x
//export TERM=xterm-256color
using namespace std;

typedef unordered_map<char,int> Point;

pair<char,int> find_high(Point point){
	pair <char,int> high ('~',0);
	for(auto& cur_pair: point){
		if (cur_pair.second>high.second){
			high=cur_pair;
		}
	}
	return high;
}

void fill_points()
{
	int i=0;
	int i2=0;
	for (i=0;i<sizex;i+=1){
		for(i2=0;i2<sizey;i2+=1){
			Point empty={{'~',0}};
			matrix[i][i2]=empty;
		}
	}
}

void print_map(Point chrome)
{
	pair <char,int> highest ('~',0);
	int i=0;
	int i2=0;
	Point cur_point;
	for(i=0;i<sizex;i+=1){
		for(i2=0;i2<sizey;i2+=1){
			cur_point=matrix[i][i2];
			/*highest=make_pair('~',0);
			for(auto& cur_pair: cur_point){
				if (cur_pair.second>highest.second){
					highest=cur_pair;
				}
			}*/
			highest=find_high(cur_point);
			int color_num=chrome[highest.first];
			
			attron(COLOR_PAIR(color_num));
			move(i2,i);
			addch(highest.first);
			attroff(COLOR_PAIR(color_num));
			//wrefresh(stdscr);
			//getch();
		}
	}
}
void view_tiles(){
	int viewx=10;
	int viewy=10;
	//int cur_color;
	char c;
	pair <char,int> high;
	Point cur_point;
	keypad(stdscr,TRUE);
	cbreak();
	while (true){
		c=getch();
		move(LINES-1,1);
		addstr("                                ");
		move(LINES-2,1);
		addstr("                                ");
		if (c=='q'){break;}
		if (c=='w'){viewy-=1;}
		if (c=='a'){viewx-=1;}
		if (c=='s'){viewy+=1;}
		if (c=='d'){viewx+=1;}
		
		if (viewx<0){viewx=0;}
		if (viewy<0){viewy=0;}
		if (viewx>sizex-1){viewx=sizex-1;}
		if (viewy>sizey-1){viewy=sizey-1;}
		
		cur_point=matrix[viewx][viewy];
		move(LINES-2,1);
		printw("Position is x:%i y:%i",viewx,viewy);
		move(LINES-1,1);
		addstr("Terrain is: ");
		for(auto& cur_pair: cur_point){
			//if (cur_pair.second!=NULL){
				addch(cur_pair.first);
				addch(':');
				printw("%i",cur_pair.second);
				addch(' ');
				
			//}
		}
		//Has some output problems 
		//Not sure if its actually outputting what we want
		move(viewy,viewx);
		refresh();

	}
}
int make_color(int num,int r, int g, int b)
{
	init_color(num, r, g, b);
	init_pair (num, num, COLOR_BLACK);
	return num;
}

void randomize()
{
	srand(time(NULL));
	int rand_x;
	int rand_y;
	while (getch()!='q'){
		rand_x=rand()%sizex;
		rand_y=rand()%sizey;
		move(LINES-1,1);
		printw("x:%i y:%i",rand_x,rand_y);
		addstr("                                ");
	}
	
}

int main()
{
	initscr();	
	start_color();
	noecho();
	init_color(COLOR_BLACK,0,0,0);
	
	chrome['^']=make_color(9,500,500,0);
	chrome['.']=make_color(10,0,1000,0);
	chrome['~']=make_color(11,0,0,1000);
	chrome['-']=make_color(12,300,300,300);
	chrome['`']=make_color(13,1000,1000,0);
	chrome['|']=make_color(14,100,600,100);
	
	Source bob=Source(7,18,'`',2,6);
	Source max=Source(11,14,'.',3,9);
	Source ralph=Source (9,14,'-',2,10);
	Source philip=Source(13,15,'^',2,8);
	Source ben=Source(6,10,'|',1,3);
	
	fill_points();
	bob.eval();
	max.eval();
	ralph.eval();
	philip.eval();
	ben.eval();
	print_map(chrome);
	//randomize();
	wrefresh(stdscr);
	
	view_tiles();
	
	endwin();
	return 0;
}
