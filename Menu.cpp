#include "mnBr.h"
#include <ncurses.h>
#include <string.h>

Menu::Menu(WINDOW *menuWindow) {

	menuWin = menuWindow;

	choices[] = {"Start",
  				 "Pause",
			     "Fit",
				 "View Raw Data",
				 "Configure",
				 "Quit"};

	int n_choices = sizeof(choices) / sizeof(char *);
	int highlight = 1;
	int choice = 0;
	int c;


}

void Menu::buildMenu() {

	int x, y, xSize, ySize;
	getmaxyx(menuWin, ySize, xSize);

	for (int i = 0; i < n_choices; ++i) {

		x = (xSize-strlen(choices[i]))/2

		if (highlight == i+1) {

			wattron(menuWin, A_REVERSE);
			mvwprintw(menuWin, y, x, "%s", choices[i]);
			wattroff(menuWin, A_REVERSE);
		} else {

			mvwprintw(menuBar, y, x, "%s", choices[i]);
		}
	}
}