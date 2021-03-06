#include <stdio.h>
#include <array>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <ncurses.h>
#include <utility>
#include "source.h"
//g++ map3.cpp -Wall -pedantic -lncurses -std=c++0x
//export TERM=xterm-256color
using namespace std;

typedef unordered_map<char,int> Point;

pair<char,int> find_high(Point point){
	pair <char,int> high ('~',1);  //makes pair which it thinks its high value
	for(auto& cur_pair: point){    //iterates through all the pairs in an unordered map
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
			Point empty={{'~',1}}; //instantiates an undordered map with a pair already inside. {{ }}
			matrix[i][i2]=empty;
		}
	}
}

void print_map(Point chrome)
{
	pair <char,int> highest ('~',1);
	int i=0;
	int i2=0;
	Point cur_point;
	for(i=0;i<sizex;i+=1){
		for(i2=0;i2<sizey;i2+=1){
			cur_point=matrix[i][i2];
			highest=find_high(cur_point);        // finds highest value in unordered map 
			int color_num=chrome[highest.first]; // gets color number for that highest value
			
			attron(COLOR_PAIR(color_num));  //turns on attributes (an ncurses function) makes characters have color
			move(i2,i);                     //moves the cursor
			addch(highest.first);           //adds the character to the screen
			attroff(COLOR_PAIR(color_num)); //turns attribute off
			//wrefresh(stdscr);
			//getch();
		}
	}
}
void view_tiles(){   //allows navigation with a.w.s.d keys also displays position and source streangth on map
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
{	//ncurses functions
	init_color(num, r, g, b);
	init_pair (num, COLOR_BLACK, num);//init_pair(pairnumber, foreground, background)  each pair has a certain number, like color number
	return num;
}

void randomize(char types[],int t_size)
{
	srand(time(NULL));
	int r_x; //random x coordinate max
	int r_y; //random y cordinate max
	char r_t; //random type from array 
	int r_str; //random strength max plus 1
	int r_d; //random decay rate from 1 to 2
	int i=0;
	int r_num; //random type index
	const int num_source=(sizex*sizey)/10;
	//char c;
	Source sources[num_source]; //list of sources may be used to save map in the future.
	
	while (i<num_source){
		//c=getch();
		//if (c=='q'){break;}
		r_x=rand()%sizex;
		r_y=rand()%sizey;
		r_num=rand()%t_size;
		r_num-=1;
		r_t=types[r_num];
		r_str=rand()%7+2;
		r_d=rand()%2+1;
		sources[i]=Source(r_x,r_y,r_t,r_d,r_str);
		sources[i].eval();
		move(LINES-1,1);
		refresh();
		print_map(chrome);

		i+=1;
		}
	
}

int main()
{	//ncurses functions:
	initscr();	   //starts ncurses mode (reroutes input and output from the terminal)
	start_color();    //instantiates 8 color macros and allows those 8 colors on the screen
	noecho();        //doesn't allow player to write onto screen
	init_color(COLOR_BLACK,0,0,0);//makes the background actually black, non of this semi-black grey bussiness
	
	//our definded color functions
	chrome['^']=make_color(9,500,500,0);    //mountains
	chrome['.']=make_color(10,0,1000,0);   //hills
	chrome['~']=make_color(11,0,0,1000);    //water
	chrome['_']=make_color(12,300,300,300); //gravel
	chrome[',']=make_color(13,1000,1000,0); //dirt
	chrome['|']=make_color(14,100,600,100); //trees
	chrome['f']=make_color(15,40,400,160);
	
	fill_points(); //makes unordered maps not null/ makes evry point water with value of one/ goodbye segmentation faults
	//Say hi to our different sources, they are friendly:	
	char types[]={'^','|','.',',','_','f'};
	int typesc=sizeof(types);
	randomize(types,typesc);
	print_map(chrome);  //prints map to the screen

	wrefresh(stdscr);   //refreshes screen- writes everything we do to screen and does tricky efficiency calculation
	
	view_tiles();      //allows navigation on screen
	
	endwin();          //closes when q is entered
	return 0;
}
