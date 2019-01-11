#include <panel.h>

//#include "Graph.h"

WINDOW *my_wins[3];
  PANEL  *my_panels[3];
  int lines = 10, cols = 40, y = 2, x = 4, i;

void drawPanel() {

  my_wins[2] = newwin(LINES-10, COLS-10, 5, 5);
  box(my_wins[2], 0, 0);
  my_panels[2] = new_panel(my_wins[2]);   /* agregar 1, orden: stdscr-0-1   */

  int values[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

    /* Actualizar en orden de apilamiento. El 2nd panel estara en la cima     */
  update_panels();

  /* Mostrar en la pantalla */
  doupdate();

  getch();

  hide_panel(my_panels[2]);

  del_panel(my_panels[2]);
    /* Actualizar en orden de apilamiento. El 2nd panel estara en la cima     */
  update_panels();

  /* Mostrar en la pantalla */
  doupdate();

  //Graph muonDcysHis = Graph(my_wins[2], values);

  //wrefresh(my_wins[1]);


}

int main()
{ 

  initscr();
  cbreak();
  noecho();
  refresh();

  /* Creacion de ventanas para los paneles */
  my_wins[0] = newwin(LINES, COLS/2, 0, 0);
  my_panels[0] = new_panel(my_wins[0]);
  

  /*
   * Creacion de bordes alrededor de las ventanas para ver el efecto
   * de los paneles
   */
  box(my_wins[0], 0, 0);

  /* Unir un panel a cada ventana */      /* ordenar de abajo hacia arriba  */
  //my_panels[0] = new_panel(my_wins[0]);   /* agregar 0, orden: stdscr-0     */
  

  mvwprintw(my_wins[0], LINES/2, COLS/4,"Estamos en el Panel %d", 0);
  wrefresh(my_wins[0]);

  

   /* Creacion de ventanas para los paneles */
  my_wins[1] = newwin(LINES, COLS/2, 0, COLS/2);
  my_panels[1] = new_panel(my_wins[1]);
  

  /*
   * Creacion de bordes alrededor de las ventanas para ver el efecto
   * de los paneles
   */
  box(my_wins[1], 0, 0);

  /* Unir un panel a cada ventana */      /* ordenar de abajo hacia arriba  */
  //my_panels[0] = new_panel(my_wins[0]);   /* agregar 0, orden: stdscr-0     */
  

  mvwprintw(my_wins[1], LINES/2, COLS/4,"Estamos en el Panel %d", 1);
  wrefresh(my_wins[1]);


  /* Actualizar en orden de apilamiento. El 2nd panel estara en la cima     */
  //update_panels();

  /* Mostrar en la pantalla */
  //doupdate();

  getch();

  drawPanel();

  

  wrefresh(my_wins[0]);

  getch();
  endwin();
}