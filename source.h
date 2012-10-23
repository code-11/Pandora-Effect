#include <unordered_map>
using namespace std;

const int sizex=48;
const int sizey=24;

typedef unordered_map<char,int> Point;
Point matrix[sizex][sizey];
Point chrome; 

class Source
{
	public:
      Source(int X, int Y, char Type, int Decay_rate, int str);//nondefault constructor
		int eval();
		//int eval();
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

int Source::distance(int x0,int y0,int x1,int y1)
{
	int dx=(x1-x0);
	int dy=(y1-y0);
	double temp=sqrt((dx*dx)+(dy*dy));
	return round(temp);
}
//int Source::eval()
int Source::eval() //inserts pairs into points in our matrix
{
	int src_size=str/decay_rate;
	int startx=x-src_size;
	int starty=y-src_size;
	int endx=x+src_size;
	int endy=y+src_size;
	
	if (startx<0){startx=0;}
	if (starty<0){starty=0;}
	
	if (endx>sizex-1){endx=sizex-1;}
	if (endy>sizey-1){endy=sizey-1;}
	
	int evalx=startx;
	int evaly;
	int dis;
	pair <char,int> to_insert;

	
	while(evalx<=endx){
		evaly=starty;
		while(evaly<=endy){
			dis=distance(evalx,evaly,x,y);
			//dis=abs(evalx-x)+abs(evaly-y)
			if (dis<src_size)
			{
				to_insert=make_pair(type,((src_size-dis)*decay_rate)); 
				matrix[evalx][evaly].insert(to_insert);
			}
			evaly+=1;
		}
		evalx+=1;
	}
	return 1;
}
