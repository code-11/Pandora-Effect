#include <ncurses.h>
#include <stdio.h>
class Source
{
	public:
      Source(int X, int Y, char Type, int Decay_rate);//nondefault constructor
		int eval();
		char type;
		int decay_rate;
		int x;
		int y;
};
int Source::eval()
{

	int evalx= x-decay_rate; 
	int evaly= y+decay_rate;
	while(evalx<x+decay_rate)
	{
		evaly=y+decay_rate;
		while(evaly>y-decay_rate)
		{
			evaly-=1;
			move(evaly,evalx);
			addch(type);
		}
		evalx+=1;
	}	 
	return 1;
}
Source::Source(int X,int Y,char Type, int Decay_rate)
{
    x=X;
    y=Y;
    type=Type;
    decay_rate=Decay_rate;
}
int main(int argc, char *argv[])
{
	initscr();	
	start_color();
	noecho();

	
	Source bob=Source(3,3,'M',3);
	Source matt=Source(6,2,'D',2);
	Source hilda=Source(10,5,'H',1);
	
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	
	attron(COLOR_PAIR(1));
	bob.eval();
	attroff(COLOR_PAIR(1));
	
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	
	attron(COLOR_PAIR(2));
	matt.eval();
	attroff(COLOR_PAIR(2));
	
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	
	attron(COLOR_PAIR(3));
	hilda.eval();
	attroff(COLOR_PAIR(3));
	
	wrefresh(stdscr);
	getch();
	endwin();
}
