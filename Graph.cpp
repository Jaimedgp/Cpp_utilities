/**
 *
 * HISTOGRAMS SCRIPT
 * 
 * @author Jaimedgp
 * @version 1.0
 */

#include <cdk.h>
#include "Graph.h"

Graph::Graph (WINDOW* cursesWin, int *Vlues) {

   cdkscreen = initCDKScreen (cursesWin); // init cdk screen in ncurses window
   values = Vlues;

   const char *title            = 0;
   const char *xtitle           = 0;
   const char *ytitle           = 0;
   const char *graphChars       = 0;

   title  = "<C>Test Graph";
   xtitle = "<C>X AXIS TITLE";
   ytitle = "<C>Y AXIS TITLE";
   graphChars = "0123456789";

   CDKGRAPH *graph = newCDKGraph (cdkscreen,
                      CENTER,
                      CENTER,
                      10,
                     20,
                     title, xtitle, ytitle);

   //setCDKGraph (graph, values, 20, graphChars, FALSE, vPLOT);

   refreshCDKScreen (cdkscreen);
} 
