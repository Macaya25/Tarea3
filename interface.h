#include <stdlib.h>
#include <stdio.h>
#include <time.h>

time_t t;
int rep;
int temp;

void show_hand();
int* game_master_hand(int);
int* random_cards(int);
int* r_nums(int length);
int roll_dice();
