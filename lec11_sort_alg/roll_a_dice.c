#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>

void roll_a_dice1(int* one, int* two, int* three);
void roll_a_dice2(int array[]); 

int main(){
srand(time(0));
int rnd_number[3];

    // update rnd_number as 3 integers
roll_a_dice1(&rnd_number[0], &rnd_number[1], &rnd_number[2]);
printf("%d %d %d\n", rnd_number[0], rnd_number[1], rnd_number[2]);
    // update rnd_number as array
roll_a_dice2(rnd_number);
printf("%d %d %d\n", rnd_number[0], rnd_number[1], rnd_number[2]);
return 0;
}

void roll_a_dice1(int* one, int* two, int* three){
*one = (rand () % 6) + 1;
*two = (rand () % 6) + 1;
*three = (rand () % 6) + 1;
}

void roll_a_dice2(int array[]) {
//void roll_a_dice2(int *array)
//void roll_a_dice2(int array[3])
array[0] = (rand () % 6) + 1;
array[1] = (rand () % 6) + 1;
array[2] = (rand () % 6) + 1;
}