#include "localmap.h"
#include <stdio.h>
int main()
{
	initscr();
	noecho();
	localmap some_map=localmap();
	some_map.initialize();
	some_map.print_map();
	some_map.inspect();
	endwin();
}
