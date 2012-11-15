#include "localmap.h"
#include <stdio.h>
int main()
{
	initscr();
	noecho();
	start_color();
	init_color(COLOR_BLACK,0,0,0);
	init_color(COLOR_RED,1000,0,0);

	localmap some_map=localmap();
	some_map.initialize();

	entity ralph=some_map.get_point(5,5);
	ralph.set_val('W');
	some_map.set_point(5,5,ralph);

	entity bob=some_map.get_point(50,25);
	bob.set_val('T');
	some_map.set_point(50,25,bob);

	entity max=some_map.get_point(60,5);
	max.set_val('K');
	some_map.set_point(60,5,max);



	entity greg=some_map.get_point(30,70);
	greg.set_val('L');

	unit greg_unit=unit('+');
	greg.set_unit(greg_unit);

	some_map.set_point(30,70,greg);



	some_map.print_map();
	some_map.inspect();
	endwin();
}
