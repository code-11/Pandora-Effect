#include "entity.h"
#include <ncurses.h>
const int maxx=20;
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
};
localmap::localmap(){}
void localmap::initialize()
{
	refx=4;
	refy=0;
	int i=0;
	int j=0;
	while (i<maxx){
		j=0;
		while (j<maxy){
			map[i][j]=entity(',');
			j+=1;
		}
		i+=1;
	}
}
entity localmap::get_point(int x,int y){
	return map[x][y];
}
void localmap::print_map()
{
	int i=0;
	int j=0;
	while (i<maxx){
		j=0;
		while (j<maxy){
			if ((j+refy<maxy)&&(i+refx<maxx)){
				move(j+refy,i+refx);
				addch(map[i+refx][j+refy].get_val());
			}else{
				move(j+refy,i+refx);
				addch('#');
			}
			j+=1;
		}
		i+=1;
	}
	refresh();
}
void localmap::inspect(){
		viewx=0;
		viewy=0;
		char c;
		while (c!='q'){
			c=getch();
			move(LINES-1,1);
			addstr("                                                  ");
			if (c=='w'){refy-=1;}
			if (c=='a'){refx-=1;}
			if (c=='s'){refy+=1;}
			if (c=='d'){refx+=1;}
			
			move(LINES-1,1);
			if (viewx<0){
				viewx=0;
				refx-=1;
				//printw("refx: %i",refx);
			}
			if (viewy<0){
				viewy=0;
				addstr("bump b");
			}
			if (viewx>maxx-1){
				viewx=maxx-1;
				addstr("bump c");
			}
			if (viewy>maxy-1){
				viewy=maxy-1;
				addstr("bump d");
			}
			print_map();
			refresh();
			move(viewy,viewx);
		}
}
