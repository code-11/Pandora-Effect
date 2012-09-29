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
};
                  
char *opt_choices[] = {
        						"Difficulty   1_2_3",
                        "Sound        On_Off",
};     
             
char *help_choices[] = {
        						"You cry for help...",
                        "but no one can hear you.",
};  

char *load_choices[] = {
								"Load Game 1 ____ No game saved",
								"Load Game 2 ____ No game saved",
								"Load Game 3 ____ No game saved",
};

char *title1="    ____                  __                       ______________          __ ";
char *title2="   / __ \\____ _____  ____/ /___  _________ _      / ____/ __/ __/__  _____/ /_";
char *title3="  / /_/ / __ `/ __ \\/ __  / __ \\/ ___/ __ `/_____/ __/ / /_/ /_/ _ \\/ ___/ __/";
char *title4=" / ____/ /_/ / / / / /_/ / /_/ / /  / /_/ /_____/ /___/ __/ __/  __/ /__/ /_  ";
char *title5="/_/    \\__,_/_/ /_/\\__,_/\\____/_/   \\__,_/     /_____/_/ /_/  \\___/\\___/\\__/  ";



void load_menu()
{
	ITEM **my_items;
	int c;			
	int d;	
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;
	WINDOW *load_win;
	load_win = newwin(5, 31, ((LINES/2)-2), ((COLS/3)-1));

	//box(local_win, 0 , 0);
	wrefresh(load_win);
	refresh();

	n_choices = ARRAY_SIZE(load_choices);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(i = 0; i < n_choices; ++i)
		     my_items[i] = new_item(load_choices[i],"");//, choices[i]);
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	set_menu_win(my_menu, load_win);
	set_menu_mark(my_menu, " ");
	//set_menu_sub(my_menu, derwin(local_win, 6, 10, (LINES/2), COLS/3));
	keypad(load_win, TRUE);

	post_menu(my_menu);
	wrefresh(load_win);
	while(true)
	{
		c = wgetch(load_win);
		//c=getch();
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
				if (blargh[0]=='B'){c=='q';}
				break;			
		}
		if (c=='q'){
			free_menu(my_menu);
			wclear(load_win);
			wrefresh(load_win);
			wclear(load_win);
			refresh();
			break;
		}
	}
	
}

void opt_menu()
{
	ITEM **my_items;
	int c;			
	int d;	
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;
	WINDOW *opt_win;
	opt_win = newwin(5, 31, ((LINES/2)-2), ((COLS/3)+4));

	//box(local_win, 0 , 0);
	wrefresh(opt_win);
	refresh();

	n_choices = ARRAY_SIZE(opt_choices);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(i = 0; i < n_choices; ++i)
		     my_items[i] = new_item(opt_choices[i],"");//, choices[i]);
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	set_menu_win(my_menu, opt_win);
	set_menu_mark(my_menu, " ");
	//set_menu_sub(my_menu, derwin(local_win, 6, 10, (LINES/2), COLS/3));
	keypad(opt_win, TRUE);

	post_menu(my_menu);
	wrefresh(opt_win);
	while(true)
	{
		c = wgetch(opt_win);
		//c=getch();
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
				if (blargh[0]=='B'){c=='q';}
				break;			
		}
		if (c=='q'){
			free_menu(my_menu);
			wclear(opt_win);
			wrefresh(opt_win);
			wclear(opt_win);
			refresh();
			break;
		}
	}
	
}

void help_menu()
{
	ITEM **my_items;
	int c;			
	int d;	
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;
	WINDOW *help_win;
	help_win = newwin(5, 31, ((LINES/2)-2), ((COLS/3)-6));

	//box(local_win, 0 , 0);
	wrefresh(help_win);
	refresh();

	n_choices = ARRAY_SIZE(help_choices);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(i = 0; i < n_choices; ++i)
		     my_items[i] = new_item(help_choices[i],"");//, choices[i]);
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	set_menu_win(my_menu, help_win);
	set_menu_mark(my_menu, " ");
	//set_menu_sub(my_menu, derwin(local_win, 6, 10, (LINES/2), COLS/3));
	keypad(help_win, TRUE);

	post_menu(my_menu);
	wrefresh(help_win);
	while(true)
	{
		c = wgetch(help_win);
		//c=getch();
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
				if (blargh[0]=='B'){c=='q';}//ack
				break;			
		}
		if (c=='q'){
			free_menu(my_menu);
			wclear(help_win);
			wrefresh(help_win);
			wclear(help_win);
			refresh();
			break;
		}
	}
	
}

void main_menu()
{
	ITEM **my_items;
	int c;			
	int d;	
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;
	WINDOW *local_win;
	local_win = newwin(5, 31, ((LINES/2)-2), ((COLS/3)+6));

	//box(local_win, 0 , 0);
	wrefresh(local_win);	

	n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(i = 0; i < n_choices; ++i)
		     my_items[i] = new_item(choices[i],"");//, choices[i]);
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu((ITEM **)my_items);
	set_menu_win(my_menu, local_win);
	set_menu_mark(my_menu, " ");
	//set_menu_sub(my_menu, derwin(local_win, 6, 10, (LINES/2), COLS/3));
	keypad(local_win, TRUE);

	post_menu(my_menu);
	wrefresh(local_win);
	while(true)
	{
		c = wgetch(local_win);
		//c=getch();
 		switch(c)
		 {	case KEY_DOWN:
			     menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;	
			case 'a':
				mvprintw(LINES-3,0,"                ");
				const char *blargh=item_name(current_item(my_menu));
				switch(blargh[0])
				{
				//keypad(stdscr, TRUE);
					case 'S'://tart New Game":
						//d=getch();
						mvprintw(LINES-3,0,"Started New Game");
						break;
					case 'L'://oad Game":
						mvprintw(LINES-3,0,"Loaded Game");
						load_menu();
						break;
					case 'O'://ptions":
						mvprintw(LINES-3,0,"Selected Options");
						opt_menu();
						break;
					case 'H'://elp":
						mvprintw(LINES-3,0,"Selected Help");
						help_menu();
						break;
					case 'E'://xit":
						mvprintw(LINES-3,0,"Exiting");
						c='q';
					//free_item(my_items[0]);
				}
				wrefresh(local_win);
				free_menu(my_menu);
				//wendwin(local_win);
				refresh();
				break;			
		}
		if (c=='q'){
			break;
		}
	}
}	

int main()
{		
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
	mvprintw(((LINES/2)+6), ((COLS/2)-7), "q for Back/Exit");
	mvprintw(((LINES/2)+5), ((COLS/2)-7), "a to Select");
	refresh();
	
	main_menu();

	/*free_item(my_items[0]);
	free_item(my_items[1]);*/
	endwin();
}

