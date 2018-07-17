#ifndef mnBr_h
#define mnBr_h
#include <ncurses.h>
#include <string.h>

class Menu {
	public:
		Menu (WINDOW *);
		~Menu();

		void buildMenu();

	private:
		WINDOW *menuWin;
		
		int highlight;
		char *choices[];

};

#endif