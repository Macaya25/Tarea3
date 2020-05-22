#include "interface.h"
#include "cartas.h"

int* show_hand(int length){
  int *nums = (int*)malloc(10*sizeof(int));
  srand((unsigned) time(&t));
  for(int i = 0 ; i < 10 ; i++ ) {
    rep = 0;
    while (rep == 0) {
      temp = rand() % (length);
      for(int i = 0; i<10;i++){
        if(nums[i] == temp)  temp = rand() % (length);
        if(temp == 0)  temp = rand() % (length);
        else rep = 1;
      }
    }
    nums[i] = temp;
  }
  for(int i = 0 ; i < 10 ; i++ ) {
    printf("%d - %-13s [%d/Vida] [%d/ATQ]\n", i, Cartas[nums[i]].name,Cartas[nums[i]].Hp,Cartas[nums[i]].Dmg);
  }
  return nums;
}
