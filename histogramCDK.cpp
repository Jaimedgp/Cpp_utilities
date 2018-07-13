/* $Id: histogram_ex.c,v 1.12 2016/12/04 15:22:16 tom Exp $ */

#include <cdk.h>

#ifdef HAVE_XCURSES
char *XCursesProgramName = "histogram_ex";
#endif

#if !defined (HAVE_SLEEP) && defined (_WIN32)	/* Mingw */
#define sleep(x) _sleep(x*1000)
#endif

int main (int argc, char **argv)
{
   /* *INDENT-EQLS* */
   CDKSCREEN *cdkscreen         = 0;
   CDKHISTOGRAM *treble         = 0;
   CDKHISTOGRAM *Other         = 0;
   const char *trebleTitle      = "<C></5>Treble<!5>";

   CDK_PARAMS params;
   boolean Box;

   CDKparseParams (argc, argv, &params, CDK_CLI_PARAMS);
   Box = CDKparamValue (&params, 'N', FALSE);

   cdkscreen = initCDKScreen (NULL);

   /* Start CDK Color. */
   initCDKColor ();

   treble = newCDKHistogram (cdkscreen,
			     CDKparamValue (&params, 'X', 8), // position of leftup corner X
			     CDKparamValue (&params, 'Y', 1), // position of left corner Y
			     CDKparamValue (&params, 'H', 20), // height of the column
			     CDKparamValue (&params, 'W', 10), // width of the column
			     VERTICAL, "0",
			     Box,
			     CDKparamValue (&params, 'T', FALSE));
   if (treble == 0)
   {
      /* Exit CDK. */
      destroyCDKScreen (cdkscreen);
      endCDK ();

      printf ("Cannot make treble histogram. Is the window big enough??\n");
      //ExitProgram (EXIT_FAILURE);
   }

   Other = newCDKHistogram (cdkscreen,
			     CDKparamValue (&params, 'X', 20), // position of leftup corner X
			     CDKparamValue (&params, 'Y', 1), // position of left corner Y
			     CDKparamValue (&params, 'H', 20), // height of the column
			     CDKparamValue (&params, 'W', 10), // width of the column
			     VERTICAL, "0.6",
			     Box,
			     CDKparamValue (&params, 'T', FALSE));
   if (Other == 0)
   {
      /* Exit CDK. */
      destroyCDKScreen (cdkscreen);
      endCDK ();

      printf ("Cannot make treble histogram. Is the window big enough??\n");
      //ExitProgram (EXIT_FAILURE);
   }


#define BAR(a,b,c) A_BOLD, a, b, c, ' '|A_REVERSE|COLOR_PAIR(3), Box

   /* Set the histogram values. */
   setCDKHistogram (treble, vNONE, CENTER, BAR (0, 10, 7));
   setCDKHistogramLLChar(treble, 'A'|A_REVERSE);
   refreshCDKScreen (cdkscreen);
   sleep (4);

   
   setCDKHistogram (Other, vNONE, CENTER, BAR (0, 10, 4));
   refreshCDKScreen (cdkscreen);
   sleep (4);
   /* Set the histogram values. */
   //setCDKHistogram (treble, vPERCENT, CENTER, BAR (0, 10, 9));
   //refreshCDKScreen (cdkscreen);
   //sleep (4);

   /* Set the histogram values. */
   //setCDKHistogram (treble, vPERCENT, CENTER, BAR (0, 10, 10));
   //refreshCDKScreen (cdkscreen);
   //sleep (4);

   /* Set the histogram values. */
   //setCDKHistogram (treble, vPERCENT, CENTER, BAR (0, 10, 3));
   //refreshCDKScreen (cdkscreen);
   //sleep (4);

   /* Set the histogram values. */
   //setCDKHistogram (treble, vPERCENT, CENTER, BAR (0, 10, 3));
   //refreshCDKScreen (cdkscreen);
   //sleep (4);

   /* Set the histogram values. */
   //setCDKHistogram (treble, vPERCENT, CENTER, BAR (0, 10, 10));
   //refreshCDKScreen (cdkscreen);
   //sleep (4);

   /* Clean up. */
   destroyCDKHistogram (treble);
   destroyCDKScreen (cdkscreen);
   endCDK ();
   //ExitProgram (EXIT_SUCCESS);
}
