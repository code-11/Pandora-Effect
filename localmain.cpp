#include "localmap.h"
#include <stdio.h>
int main()
{
	initscr();
	noecho();
	localmap some_map=localmap();
	some_map.initialize();
	//some_map.get_point(5,5).set_val('W');
	//addch(some_map.get_point(5,5).get_val());
	//getch();
	some_map.print_map();
	some_map.inspect();
	endwin();
}
