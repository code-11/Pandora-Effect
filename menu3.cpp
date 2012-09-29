#include <curses.h>
#include <menu.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

char *choices[] = {
        						"Start New Game",
                        "Load Game",
                        "Options",
                        "Help",
                        "Exit",
                  };

int main()
{	ITEM **my_items;
	int c;				
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;
	
	
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(i = 0; i < n_choices; ++i)
	        my_items[i] = new_item(choices[i],"");//, choices[i]);
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	mvprintw(LINES - 2, 0, "F1 to Exit");
	post_menu(my_menu);
	refresh();
	while(true)
	{
		c = getch();
 		switch(c)
	    {	case KEY_DOWN:
		        menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;	
			case 'a':
				//mvprintw(LINES-3, 0, "Item selected is : %s", item_name(current_item(my_menu)));
				const char *blargh=item_name(current_item(my_menu));
				//mvprintw(LINES-3,0,"Item selected is : %s",blargh);
				switch(blargh[0])
				{
					case 'S'://tart New Game":
						mvprintw(LINES-3,0,"Started New Game");
						break;
					case 'L'://oad Game":
						mvprintw(LINES-3,0,"Loaded Game");
						break;
					case 'O'://ptions":
						mvprintw(LINES-3,0,"Selected Options");
						break;
					case 'H'://elp":
						mvprintw(LINES-3,0,"Selected Help");
						break;
					case 'E'://xit":
						mvprintw(LINES-3,0,"Exiting");
						c='q';
				}
				break;			
		}
		if (c=='q'){
			break;
		}
	}	
	getch();
	free_item(my_items[0]);
	free_item(my_items[1]);
	free_menu(my_menu);
	endwin();
}

