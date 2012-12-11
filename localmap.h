#include "entity.h"
#include <ncurses.h>
#include <unordered_map>
const int maxx=100; //controls the size of the local map
const int maxy=100;
class localmap
{
	public:
      localmap();
      void initialize(unordered_map<char,int> biomes);
      void print_map(unordered_map<char,int> biomes);//get rid of this arguement later
      void inspect(unordered_map<char,int> biomes);
      entity get_point(int x,int y);
      void set_point(int x,int y, entity e);
	private:
		entity map[maxx][maxy];
		int refx;
		int refy;
		int viewx;
		int viewy;
		int winmaxx;
		int winmaxy;
		int winminx;
		int winminy;
		WINDOW *local_win;
};
localmap::localmap(){}
void localmap::initialize(unordered_map<char,int> biomes)  //makes world
{
	refx=0;
	refy=0;
	int i=0;
	int j=0;
	winmaxx=80;
	winmaxy=30;

	local_win = newwin(winmaxy, winmaxx, 0, 0);
	while (i<maxx){
		j=0;
		while (j<maxy){
			map[i][j]=entity(',');
			j+=1;
		}
		i+=1;
	}
	wrefresh(local_win);
}
entity localmap::get_point(int x,int y){ 
	return map[x][y];
}
void localmap::set_point(int x, int y,entity e){
	map[x][y]=e;
}
void localmap::print_map(unordered_map<char,int> biomes)//get rid of this argument later
{
	init_pair(1,COLOR_RED,COLOR_BLACK);
	int i=0;
	int j=0;
	
	//Just here for testing, take away later
	pair <char,int> high ('~',1);  //makes pair which it thinks its high value
	for(auto& cur_pair: biomes){    //iterates through all the pairs in an unordered map
		if (cur_pair.second>high.second){
			high=cur_pair;
		}
	}
	int color_num=chrome[high.first];


	while (i<winmaxx){ //window size x
		j=0;
		while (j<winmaxy){ //window size y
			if ((i+refx<maxx)&&(i+refx>0)&&(j+refy<maxy)&&(j+refy>0)){
				wmove(local_win,j,i);
				char temp_val=map[i+refx][j+refy].get_val();
				if (temp_val!=','){
					wattron(local_win,COLOR_PAIR(color_num));
					waddch(local_win,temp_val);
					wattroff(local_win,COLOR_PAIR(color_num));
				}else{
					wattron(local_win,COLOR_PAIR(color_num));
					waddch(local_win,',');
					wattroff(local_win,COLOR_PAIR(color_num));
				}
			}else{
				wmove(local_win,j,i);
				wattron(local_win,COLOR_PAIR(color_num));
				waddch(local_win,ACS_DIAMOND);
				wattroff(local_win,COLOR_PAIR(color_num));
			}
			j+=1;
		}
		i+=1;
	}
	wrefresh(local_win);
}
void localmap::inspect(unordered_map<char,int> biomes){
		viewx=0;
		viewy=0;
		char c;
		while (c!='q'){
			c=wgetch(local_win);
			move(LINES-1,1);	
			addstr("                                                                          ");
			if (c=='w'){viewy-=1;}
			if (c=='a'){viewx-=1;}
			if (c=='s'){viewy+=1;}
			if (c=='d'){viewx+=1;}
			if (c=='W'){viewy-=5;}
			if (c=='A'){viewx-=5;}
			if (c=='S'){viewy+=5;}
			if (c=='D'){viewx+=5;}
			
			if (viewx<0){
				viewx=0;
				refx-=1;
				if (c=='A'){refx-=3;}
			}
			if (viewy<0){
				viewy=0;
				refy-=1;
				if (c=='W'){refy-=3;}
			}
			if (viewx>winmaxx-1){
				viewx=winmaxx-1;
				refx+=1;
				if (c=='D'){refx+=3;}
			}
			if (viewy>winmaxy-1){
				viewy=winmaxy-1;
				refy+=1;
				if (c=='S'){refy+=3;}
			}
			if (refx<0){
				refx=0;
			}
			if (refy<0){
				refy=0;
			}
			if (refy+winmaxy>maxy+1){
				refy=maxy-winmaxy+1;
			}
			if (refx+winmaxx>maxx+1){
				refx=maxx-winmaxx+1;
			}


			print_map(biomes);
			//touchwin(stdscr);
			wrefresh(local_win);
			move(LINES-1,1);
			printw("refx:%i refy:%i viewx:%i viewy:%i",refx,refy,viewx+refx,viewy+refy);
			refresh();
			wmove(local_win,viewy,viewx);
		}
		wclear(local_win);
		wrefresh(local_win);
		delwin(local_win);
}
