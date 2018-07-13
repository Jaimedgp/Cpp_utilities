#include <ncurses.h>
#include <string.h>

char *choices[] = {
  "RUN",
  "SAVE",
  "EXIT",
};
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menuBar, int highlight);


int main(int argc, char *argv[]) {
	
	WINDOW *plotAll, *plotSelect, *menuBar;
	int highlight = 1;
 	int choice = 0;
	int c;

	noecho();
	initscr();			
	cbreak();			

	refresh();

	plotAll = newwin(LINES-2, 2*COLS/3, 2, COLS/3);
	box(plotAll, 0, 0);
	wrefresh(plotAll);

	plotSelect = newwin(LINES-2, COLS/3, 2, 0);
	box(plotSelect, 0, 0);
	wrefresh(plotSelect);

	menuBar = newwin(3, COLS, 0, 0);
	wrefresh(menuBar);
	keypad(menuBar, TRUE);

	print_menu(menuBar, highlight);
  	while(1) {
  		 c = wgetch(menuBar);
      	switch(c) {
        	case KEY_LEFT:
        		if(highlight == 1)
            		highlight = n_choices;
        		else
            		--highlight;
        			break;
        	case KEY_RIGHT:
          		if(highlight == n_choices)
            		highlight = 1;
        		else
            		++highlight;
          			break;
        	case 10:
          		choice = highlight;
          		break;
        	default:
          		mvwprintw(plotSelect ,24, 1, "Caracter presionado = %3d Ojala se imprima como '%c'", c, c);
          		wrefresh(plotSelect);
          		break;
        }
      
    	print_menu(menuBar, highlight);
      	
      	if(choice != 0) break; /* El usuario eligio salir del bucle infinito */
  	
    }

    initscr();
	getch();
		
	endwin();			/* End curses mode		  */
	return 0;
}


void print_menu(WINDOW *menuBar, int highlight) {
 
	int x, y, i;

	x = 2;
	y = 0;
	mvwprintw(menuBar, y, x, "|    ");
	x = 7;
	//box(menuBar, 0, 0);
	for(i = 0; i < n_choices; ++i) {
		if(highlight == i + 1) { /* Resalta lo opcion actual */
        	wattron(menuBar, A_REVERSE);
          	mvwprintw(menuBar, y, x, "%s", choices[i]);
          	wattroff(menuBar, A_REVERSE);
        } else {
        	mvwprintw(menuBar, y, x, "%s", choices[i]);
        }

      	x =x+strlen(choices[i]);
      	mvwprintw(menuBar, y, x, "    |    ");
      	x = x+9;
    }

	 wrefresh(menuBar);
}
