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
char *title1="    ____                  __                       ______________          __ ";
char *title2="   / __ \\____ _____  ____/ /___  _________ _      / ____/ __/ __/__  _____/ /_";
char *title3="  / /_/ / __ `/ __ \\/ __  / __ \\/ ___/ __ `/_____/ __/ / /_/ /_/ _ \\/ ___/ __/";
char *title4=" / ____/ /_/ / / / / /_/ / /_/ / /  / /_/ /_____/ /___/ __/ __/  __/ /__/ /_  ";
char *title5="/_/    \\__,_/_/ /_/\\__,_/\\____/_/   \\__,_/     /_____/_/ /_/  \\___/\\___/\\__/  ";

int main()
{	ITEM **my_items;
	int c;				
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;	
	
	WINDOW *local_win;
	
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	
	attron(COLOR_PAIR(1));
	mvprintw((LINES/2)-10,(COLS/3)-25,"%s",title1);
	mvprintw((LINES/2)-9,(COLS/3)-25,"%s",title2);
	mvprintw((LINES/2)-8,(COLS/3)-25,"%s",title3);
	mvprintw((LINES/2)-7,(COLS/3)-25,"%s",title4);
	mvprintw((LINES/2)-6,(COLS/3)-25,"%s",title5);
	attroff(COLOR_PAIR(1));

	//getch();
	mvprintw(((LINES/2)+5), ((COLS/2)-7), "q to Exit");
	refresh();
	
	local_win = newwin(5, 15, ((LINES/2)-2), ((COLS/3)+8));
	
	//box(local_win, 0 , 0);
	wrefresh(local_win);	
	
	n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(i = 0; i < n_choices; ++i)
	        my_items[i] = new_item(choices[i],"");//, choices[i]);
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	set_menu_win(my_menu, local_win);
	keypad(local_win, TRUE);
	
	post_menu(my_menu);
	wrefresh(local_win);
	while(true)
	{
		c = wgetch(local_win);
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
	free_item(my_items[0]);
	free_item(my_items[1]);
	free_menu(my_menu);
	endwin();
}

