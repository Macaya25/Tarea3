#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cartas.h"
#include "interface.h"

int length, ready;
int *jugador_temp;
int *randoms;

int damage(card c, int dado){
	int atq=c.Dmg;
	int d=atq*dado;
	return d;
}

int duelo(int* cartasJ, int r, int g, int j, int roll_gm, int roll_player) {
	int dGm=damage(Cartas[randoms[g]], roll_gm);
	int dJ=damage(Cartas[randoms[j]], roll_player);
	show_match(r, Cartas[randoms[g]], Cartas[randoms[j]], roll_gm, roll_player);
  // printf("DGM: %d vs %d HPPlayer\n", dGm, Cartas[randoms[j]].Hp);
  printf("El %s enemigo ataca con %d puntos de daño\n", Cartas[randoms[g]].name, dGm);
  // printf("DJ: %d vs %d HPGM\n", dJ, Cartas[randoms[g]].Hp);
  printf("Tu %s ataca al %s enemigo con %d puntos de daño\n", Cartas[randoms[j]].name, Cartas[randoms[g]].name, dJ);
	if (dGm > Cartas[randoms[j]].Hp && dJ < Cartas[randoms[g]].Hp) {
    printf("El duelo lo gano el Duel Master\n");
    return 1;
  }
	else if (dJ > Cartas[randoms[g]].Hp && dGm<Cartas[randoms[cartasJ[j]]].Hp) {
    printf("El duelo lo gano el jugador\n"); //despues que corregirlo para q salga el nombre del jugador
    return 2;
  }
	else {
    printf("el duelo fue un empate\n");
    return 0;
  }
}


int main () {
  //Cartas es variable global


  length = upload_cards("cartas.txt");//cantidad de cartas
  randoms = r_nums(length);//int array q serian las 15 cartas al azar
  show_hand(randoms);//muestra las 10 cartas al azar para el jugador

  int* cartasJ = cartas_jugador();
  // for(int i = 0; i<5; i++) {
  //   printf("Carta %d = %d\n", i, cartasJ[i]);
  // }

  valor_dados* L = malloc(sizeof(valor_dados));
  valor_dados *actual = L;
  int SD_result, match_result;
  char str[10];

  //Llenar lista ligada
  int derrotas_j = 0;
  int derrotas_gm = 0;
  for (int i = 0; i < 10; i++){
    if (derrotas_j == 5) {
      printf("Gano GM\n");
      break;
    }
    if (derrotas_gm == 5) {
      printf("Gano Jugador\n");
      break;
    }
    printf("Presione enter para arrojar los dados: ");
    fgets(str, 10, stdin);
    printf("\n");
    actual -> roll_player = roll_dice();
    actual -> roll_gm = roll_dice();
    actual -> next = malloc(sizeof(valor_dados));
    printf("Roll Jugador: %d\n", actual -> roll_player);
    printf("Roll Game Mr: %d\n", actual -> roll_gm);
    printf("Derrotas J: %d\nDerrotas GM: %d\n", derrotas_j, derrotas_gm);

    SD_result = roll_count(L);
    if (SD_result == 1) break;
    else if (SD_result == 2) break;
    // show_match(i+1, Cartas[randoms[11+i]], Cartas[cartasJ[i]], actual -> roll_gm, actual -> roll_player);

    match_result = duelo(cartasJ, i+1, 10+derrotas_gm, cartasJ[derrotas_j], actual -> roll_gm, actual -> roll_player);
    if (match_result == 1) {
      derrotas_j++;
    }
    else if (match_result == 2)  {
      derrotas_gm++;
    }
    else {
      derrotas_j++;
      derrotas_gm++;
    }
    //Insertar una forma para verificar si ya no quedan cartas
    actual = actual -> next;
  }




  //Liberar lista ligada
  actual = L;
  valor_dados *before;
  while(actual->next != NULL){
    before = actual;
    actual = actual -> next;
    free(before);
  }




  // //Verificar si llevan 15 (Muerte Subita)
  // int suma_jugador(int* Player_dice){
  //   return suma;
  // }
  // int suma_gm(int* Gm_dice){
  //   return suma
  // }

  // //Se determina un ganador
  // void combate(card Jugador, card gm, roll_player, roll_player, derrotas de los 2) {
  // derrotas++;
  // }
  //Preguntar si volver a jugar


  free(randoms);
  free(Cartas);
  return 0;
}
