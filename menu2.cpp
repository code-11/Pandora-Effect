#include <curses.h>
#include <menu.h>
#include <stdio.h>
#include <stdlib.h>

char *choices[] = {
        						"Start New Game",
                        "Load Game",
                        "Options",
                        "Help",
                        "Exit",
                  };
int first_menu(choices)
{
	move(0,0)
	int x=0;
	for (int i=0;i<sizeof(choices);i+=1)
	{
		move(x,0);
		x+=1;
	}
	return 0;
}

