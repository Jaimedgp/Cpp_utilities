//

#ifndef hstgrm_h
#define hstgrm_h
#define BAR(a,b,c) A_BOLD, a, b, c, ' '|A_REVERSE|COLOR_PAIR(3), false
#include <cdk.h>

class Histogram {
	public:
		Histogram(int , char **, WINDOW*); // Constructor
		~Histogram(); // destructor

		void drawValues(int);
	private:
		CDKSCREEN *cdkscreen;
   		CDKHISTOGRAM *eachHistograms[10];

   		int events[10];

};

#endif