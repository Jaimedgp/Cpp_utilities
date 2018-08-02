#include <panel.h>

#include "Histograms.h"

WINDOW *my_wins[2];
  PANEL  *my_panels[2];
  int lines = 10, cols = 40, y = 2, x = 4, i;

void drawPanel() {

  my_wins[1] = newwin(LINES-10, COLS-10, 5, 5);
  box(my_wins[1], 0, 0);
  my_panels[1] = new_panel(my_wins[1]);   /* agregar 1, orden: stdscr-0-1   */

  Histograms muonDcysHis = Histograms(my_wins[1], 10, 20);

  muonDcysHis.drawIncrement(5);

  //wrefresh(my_wins[1]);


}

int main()
{ 

  initscr();
  cbreak();
  noecho();

  /* Creacion de ventanas para los paneles */
  my_wins[0] = newwin(LINES, COLS, 0, 0);
  

  /*
   * Creacion de bordes alrededor de las ventanas para ver el efecto
   * de los paneles
   */
  box(my_wins[0], 0, 0);

  /* Unir un panel a cada ventana */      /* ordenar de abajo hacia arriba  */
  my_panels[0] = new_panel(my_wins[0]);   /* agregar 0, orden: stdscr-0     */
  

  mvwprintw(my_wins[0], lines/2, 5,"Estamos en el Panel %d", 0);
  wrefresh(my_wins[0]);
  


  /* Actualizar en orden de apilamiento. El 2nd panel estara en la cima     */
  update_panels();

  /* Mostrar en la pantalla */
  doupdate();

  getch();

  drawPanel();

  getch();

  del_panel(my_panels[1]);
    /* Actualizar en orden de apilamiento. El 2nd panel estara en la cima     */
  update_panels();

  /* Mostrar en la pantalla */
  doupdate();

  getch();
  endwin();
}