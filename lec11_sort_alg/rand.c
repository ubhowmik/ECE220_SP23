/* C program to generate random number 
*******use a seed value********
This program will create different sequence 
of random numbers on every run for differnt
seed values
*/  

#include<stdio.h>
#include<stdlib.h>

int main()
{
int i;
// a=10; b=5
int seed;
printf("Enter any integer as seed value: ");
scanf("%d",&seed);

srand(seed);

for (i=0;i<5; i++)
printf(" %d ", (rand()%(10-5+1))+5);

return 0;
}



//printf(" %d ", (rand()%(10-5+1))+5);

/*
int seed;
printf("Enter any integer as seed value: ");
scanf("%d",&seed);
srand(seed);
*/