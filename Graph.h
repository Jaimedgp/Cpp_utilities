/**
 *
 */

#ifndef Graph_h
#define Graph_h
#include <cdk.h>


class Graph {
	public:
		Graph(WINDOW* cursesWin, int *Vlues); // Constructor
		
		

	private:
        int *values;

		CDKSCREEN *cdkscreen;
};

#endif
