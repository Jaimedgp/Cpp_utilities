#include <ncurses.h>
#include "hstgram.h"
#include "mnBr.h"

int main (int argc, char **argv) {

	WINDOW *plotAll, *plotSelect, *menuBar;

	noecho();
	initscr();			
	cbreak();

	refresh();

	plotAll = newwin(LINES, 2*COLS/3, 0, 0);
	box(plotAll, 0, 0);
	wrefresh(plotAll);

	plotSelect = newwin(LINES, COLS/3, 0, 2*COLS/3);
	box(plotSelect, 0, 0);
	wrefresh(plotSelect);
	keypad(plotSelect, TRUE);			

	Menu mn(plotSelect);
	
	Histogram h(argc, argv, plotAll) ;

	for (int i=0; i<10; ++i) {
		h.drawValues(i);
	}

	mn.choiseOne();

	getch();

	return 0;
}
