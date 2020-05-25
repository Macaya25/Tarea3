#include "interface.h"
#include "cartas.h"

//Funcion para mostrar en consola las 10 cartas disponibles para el jugador
void show_hand(int* nums) {
  for(int i = 0 ; i < 10 ; i++ ) {
    if(nums[i] == 0) printf("a ");
    printf("%d - %-13s [%02d/Vida] [%02d/ATQ]\n", i, Cartas[nums[i]].name,Cartas[nums[i]].Hp,Cartas[nums[i]].Dmg);
  }
}

//Esta funcion la saque de internet
//No creo que sea tan importante saber hacerla desde 0
int* r_nums(int length) {
  int *array = malloc(15*sizeof(int));
  int x;
  int i = 0;
  srand(time(NULL));
  while(i < 16){
      int r = 0;
      while (r == 0) {
        r =rand() % length;
        for (x = 0; x < i; x++) {
            if(array[x]==r){
                break;
            }
            if(r==0) break;
        }
        if(x==i){
            array[i++]=r;
        }
    }
  }
  return array;
}

//Tirar un dado
int roll_dice() {
  int roll = 0;
  while (roll == 0) {
    roll = rand() % 7;
  }
  return roll;
}
