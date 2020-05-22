#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cartas.h"
#include "interface.h"



int length;
int *jugador, *jugador_temp;

int main (){

  length = upload_cards("cartas.txt");
  jugador_temp = show_hand(length);




  return 0;
}
