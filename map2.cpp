#include <stdio.h>
#include <list>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <ncurses.h>
#include <utility>
using namespace std;
typedef list<list< unordered_map<char,int> > > Grid;
typedef list< unordered_map<char,int> > Line;
typedef unordered_map<char,int> Point;

list<list< unordered_map<char,int> > > matrix;
/*
void print_map(Grid mat){
	pair <char,int> highest;
	pair <char,int> current_pair;
	for (Grid::iterator itr=mat.begin(); itr!=mat.end(); ++itr){
		Line current_line= *itr;	
		for (Line::iterator itr2=current_line.begin(); itr2!=current_line.end(); ++itr2){
			Point current_point= *itr2;
			if(!current_point.empty()){
				highest=make_pair(current_point.begin().first,current_point.begin().second);
				for (Point::iterator itr3=current_point.begin();itr3!=current_point.end();++itr3){
					current_pair= *itr3;
					if (current_pair.second>highest.second){
						highest=current_pair;
					}
				}
				move(itr2,itr);
				addch(highest.first);
			}
		}
	}
}
*/
Point get(Line arr,int pos)
{
	Line::iterator itr=arr.begin();
	advance(itr,pos);
	return *itr;
}
Point get2(Grid mat,int pos1, int pos2)
{
	Grid::iterator itr=mat.begin();
	advance(itr,pos1);
	Line arr=*itr;
	return get(arr, pos2);
}

class Source
{
	public:
      Source(int X, int Y, char Type, int Decay_rate, int str);//nondefault constructor
		//int eval(Grid);
		int eval();
		int distance(int x0,int y0,int x1,int y1);
		char type;
	private:
		int decay_rate;
		int x;
		int y;
		int str;
};
Source::Source(int X,int Y,char Type, int Decay_rate,int Str)
{
    x=X;
    y=Y;
    type=Type;
    decay_rate=Decay_rate;
    str=Str;
}
/*
Source::setX(int X)
{
	x=X;
}
Source::getX()
{
	return x;
}
Source max=Source(1,1,'l',6,6);
max.setX(9);
printf("%i",max.getX());
cout<<max.getX();
*/

int Source::distance(int x0,int y0,int x1,int y1)
{
	int dx=(x1-x0);
	int dy=(y1-y0);
	double temp=sqrt((dx*dx)+(dy*dy));
	return round(temp);
}
int Source::eval()
//int Source::eval(Grid matrix)
{

	int size=str/decay_rate;
	
	int up_boundx=x-size;
	int up_boundy=y-size;
	int low_boundx=x+size;
	int low_boundy=y+size;
	
	int evalx=up_boundx;
	int evaly;
	int dis;
	while(evalx<low_boundx){
		evaly=up_boundy;
		while(evaly<low_boundy){
			dis=distance(evalx,evaly,x,y);
			//dis=abs(evalx-x)+abs(evaly-y)
			if (dis<size)
			{
				//Point map=get2(matrix,evalx,evaly);
				//map.insert(make_pair<char,int>(type,(size-dis)*decay_rate));
				move(evaly,evalx);
				addch(type);
			}
			evaly+=1;
		}
		evalx+=1;
	}
	return 1;
}

int main()
{
	initscr();	
	start_color();
	noecho();
	
	Source bob=Source(10,10,'o',3,27);
	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	bob.eval();
	//bob.eval(matrix);
	//print_map(matrix);
	attroff(COLOR_PAIR(1));
	
	wrefresh(stdscr);
	getch();
	endwin();
	return 0;
}
