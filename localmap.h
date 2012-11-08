#include "entity.h"
#include <ncurses.h>
const int maxx=20; //controls the size of the local map
const int maxy=20;
class localmap
{
	public:
      localmap();
      void initialize();
      void print_map();
      void inspect();
      entity get_point(int x,int y);
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
void localmap::initialize()
{
	refx=0;
	refy=0;
	int i=0;
	int j=0;
	winmaxx=80;
	winmaxy=40;

	local_win = newwin(winmaxy, winmaxx, 0, 0);
	while (i<maxx){
		j=0;
		while (j<maxy){
			if ((j==3)&&(i==3)){
			map[i][j]=entity('s');}
			else{map[i][j]=entity(',');}
			j+=1;
		}
		i+=1;
	}
	wrefresh(local_win);
}
entity localmap::get_point(int x,int y){ 
	return map[x][y];
}
void localmap::print_map()
{
	int i=0;
	int j=0;
	while (i<winmaxx){ //window size x
		j=0;
		while (j<winmaxy){ //window size y
			if ((i+refx<maxx)&&(i+refx>0)&&(j+refy<maxy)&&(j+refy>0)){
				wmove(local_win,j,i);
				waddch(local_win,map[i+refx][j+refy].get_val());
			}else{
				wmove(local_win,j,i);
				waddch(local_win,' ');
			}
			j+=1;
		}
		i+=1;
	}
	wrefresh(local_win);
}
void localmap::inspect(){
		viewx=0;
		viewy=0;
		char c;
		while (c!='q'){
			c=wgetch(local_win);
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
			print_map();
			//touchwin(stdscr);
			wrefresh(local_win);
			wmove(local_win,viewy,viewx);
		}
}
