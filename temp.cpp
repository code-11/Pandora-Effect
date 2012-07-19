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
	init_pair(1, COLOR_RED, COLOR_GREEN); //Makes a new color pair red text on green background 
	noecho(); //cancel output to the screen when using getch
	keypad(stdscr, TRUE); //allows input of key like F2 or ENTER

	box(stdscr,0,0); //puts a box around the window
	attron(COLOR_PAIR(1)); //starts color attribute
	printw("IT WORKS CHLOE !!!\n"); //print to window 
	attroff(COLOR_PAIR(1)); //ends it

	char key; //makes a new string, key
	printw("Input name: \n");
	std::string buffer= " ";
	while(key!= 'q')
	{
		key=getch();
		buffer+=key;
	}
	
        //key=getch(); //assign keyboard input of one character to key
	character player=character(buffer);
	std::string moniker= player.getName();
	attron(A_BOLD); //starts bold attribute

	std::stringstream newstream;
	newstream << "Your name is: "<< moniker ;
	std::string newerstring= newstream.str();
	
	char *a=new char[newerstring.size()+1];
	a[newerstring.size()]=0;
	memcpy(a,newerstring.c_str(),newerstring.size());

	mvprintw(2,2,a);     //prints to screen
	attroff(A_BOLD);


	endwin();
}
	
