#include "mnBr.h"
#include <ncurses.h>
#include <string.h>

char *choices[] = {"Start",
"Pause",
"Fit",
"View Raw Data",
"Configure",
"Quit",
};

Menu::Menu(WINDOW *menuWindow) {

	menuWin = menuWindow;


	n_choices = sizeof(choices) / sizeof(char *);
	highlight = 1;
	choice = 0;

	buildMenu();

}

void Menu::buildMenu() {

	int x, y, xSize, ySize;
	getmaxyx(menuWin, ySize, xSize);

	int yInterval = (ySize-6)/7;
	y = yInterval;

	for (int i = 0; i < n_choices; ++i) {

		x = (xSize-strlen(choices[i]))/2;

		if (highlight == i + 1) {

			wattron(menuWin, A_REVERSE);
			mvwprintw(menuWin, y, x, "%s", choices[i]);
			wattroff(menuWin, A_REVERSE);
		} else {

			mvwprintw(menuWin, y, x, "%s", choices[i]);
		}

		y += yInterval;
	}
	
	wrefresh(menuWin);
}

bool Menu::choiseOne() {

	int c = wgetch(menuWin);
    switch(c) {
       	case KEY_UP:
       		if(highlight == 1) {
           		highlight = n_choices;
       		} else {
           		--highlight;
       			break;
       		}
       	case KEY_DOWN:
       		if (highlight == n_choices) {
           		highlight = 1;
       		} else {
           		++highlight;
       			break;
       		}
       	case 10:
       		choice = highlight;
       		break;
       	default:
       		mvwprintw(menuWin ,24, 1, "Caracter presionado = %3d Ojala se imprima como '%c'", c, c);
       		wrefresh(menuWin);
       		break;
    }

    buildMenu();
}