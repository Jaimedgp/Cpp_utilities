#include "hstgram.h"

int main (int argc, char **argv) {
	
	Histogram h(argc, argv) ;

	for (int i=0; i<10; ++i) {
		h.drawValues(i);
	}

	h.destroyHistrograms();

	return 0;
}