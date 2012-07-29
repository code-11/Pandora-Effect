#include <ncurses.h>
#include "character.h"
#include <string>
#include <sstream>
#include <cstring>
//TODO: Make character use strings
//TODO: We will pick gender from a list
//TODO: Create basic attribute of characters
int main(int argc, char *argv[])
{	initscr();			/* Start curses mode 		*/
	start_color();			/* Start color 			*/
	assume_default_colors(COLOR_GREEN,COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_GREEN); //Makes a new color pair red text on green background 
	noecho(); //cancel output to the screen when using getch
	keypad(stdscr, TRUE); //allows input of key like F2 or ENTER

	box(stdscr,0,0); //puts a box around the window
	attron(COLOR_PAIR(1)); //starts color attribute
	move(1,1);
	wrefresh(stdscr);
	printw("IT WORKS CHLOE !!!\n"); //print to window 
	attroff(COLOR_PAIR(1)); //ends it

	char key; //makes a new string, key
	move(2,1);
	printw("Input name: \n");
	std::string buffer= " ";
	move(3,1);
	while(key!="KEY_ENTER")
	{
		key=getch();
		if(key=="KEY_ENTER")
		{
			break;
		}
		buffer+=key;

		char *b=new char[0];
		b[0]=key;		
	
		printw(b);
		wrefresh(stdscr);
	}
	character player=character(buffer);
	std::string moniker= player.getName();
	attron(A_BOLD); //starts bold attribute

	std::stringstream newstream;
	newstream << "Your name is: "<< moniker ;
	std::string newerstring= newstream.str();

	//Creating a character array
	char *a=new char[newerstring.size()+1];
	//makes the newerstring.size th element zero	
	//a[newerstring.size()]=0;
	//copies newerstring to character array a
	memcpy(a,newerstring.c_str(),newerstring.size());
	//move cursor to 5,5
	
	move(5,5);
	printw(a);
	wrefresh(stdscr);
	
        //key=getch(); //assign keyboard input of one character to key
	attroff(A_BOLD);
	getch();


	endwin();
}
	
