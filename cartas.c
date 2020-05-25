#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cartas.h"

//Funcion para crear una lista del struct carta (card)
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

  return f;
}

void show_match(int round, card gm,  card Player, int roll_gm, int roll_player) {
  printf("╔═══════════════════════════════════════════════════╗\n");
  printf("║%22s%5s %d%22s║\n"," ","Round", round, " ");
  printf("╚═══════════════════════════════════════════════════╝\n");
  printf("Game Master\n");
  printf("╔════╦═══════════════╗ ╔═══╗   ╔════╦═══════════════╗\n");
  printf("║ %02d ║ %-13s ║ ║ %d ║   ║ %02d ║ %-13s ║\n", gm.Hp, gm.name, roll_gm, Player.Hp, Player.name);
  printf("╠════╩═══════════════╣ ╚═══╝   ╠════╩═══════════════╣\n");
  for(int i = 0; i<11; i++) printf("║%20s║%9s║%20s║\n", " ", " ", " ");
  printf("║%15s╔════╣   ╔═══╗ ║%15s╔════╣\n", " ", " ");
  printf("║ %13s ║ %02d ║   ║ %d ║ ║ %13s ║ %02d ║\n", " ", gm.Dmg, roll_player, " ", Player.Dmg);
  printf("╚═══════════════╩════╝   ╚═══╝ ╚═══════════════╩════╝\n");
  printf("%54s", "Player\n");


}

int* cartas_jugador(){
  // char cartasJ[11]; //11 porque son 5 cortas, 5 comas y 1 nullcaracter
  char *cartasJ = (char*)malloc(11);
  printf("Por favor, escoja sus cartas\n");
  scanf("%s", cartasJ );
  int* cElegidas = (int*) malloc(5*sizeof(int));
  char *nc = strtok(cartasJ, ",");
  int i = 0;
  while (nc != NULL) {
    cElegidas[i]=atoi(nc);
    nc=strtok(NULL, ",");
    i++;
    }
  return cElegidas;
}

int roll_count(valor_dados* L){
  int sum_player = 0;
  int sum_gm = 0;
  valor_dados *actual = L;
  while (actual-> next != NULL) {
    sum_player += actual -> roll_player;
    sum_gm += actual -> roll_gm;
    actual = actual -> next;
  }
  if (sum_player == 15){
    printf("Has ganado por muerte subita\n");
    return 1;
  } else if (sum_gm == 15){
    printf("Ha ganado el Game Master por muerte subita\n");
    return 2;
  }
  return 0;
}
