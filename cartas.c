#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cartas.h"


int upload_cards(char* archivo){
  FILE* Cards;
  int val;
  Cards = fopen(archivo, "r");
  char t[30];
  int f = 1;
  Cartas  = (card*) malloc(50 * sizeof(card));
  while(fgets(t, 30, Cards) != NULL){
    char *token = strtok(t, " ");
    int i = 0;
    while(token != NULL) {
      if (i == 0) {
        if (f==0) printf("%s", token);
        strcpy(Cartas[f].name, token);
      }
      if (i == 1) {
        val = atoi(token);
        Cartas[f].Hp = val;
      }
      if (i == 2) {
        val = atoi(token);
        Cartas[f].Dmg = val;
      }
      token = strtok(NULL, " ");
      i++;
    }
    f++;
  }
  fclose(Cards);
  free(Cartas);
  return f;
}
