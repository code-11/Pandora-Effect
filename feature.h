class feature
{
	private:
		int maxx;
		int maxy;
		int x;
		int y;
		char** form;
	public:
		feature(){}
		feature(int X,int Y,int Maxx,int Maxy, char** Form){
			x=X;
			y=Y;
			maxx=Maxx;
			maxy=Maxy;
			form=Form;
		}
		int get_maxx(){return maxx;}
		int get_maxy(){return maxy;}
		char** get_form(){return form;}
		void set_form(char** Form){form=Form;}
		void set_x(int X){x=X;}
		void set_y(int Y){y=Y;}

};