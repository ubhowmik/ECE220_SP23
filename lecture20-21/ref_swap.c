#include <stdio.h>

void swap(int *a, int *b){
int temp = *a;
 *a = *b;
*b = temp;
}

int main()
{
 int val1, val2;
val1 = 10, val2 = 20;


printf("%d %d\n", val1,val2);

swap(val1, val2);

printf("%d %d\n", val1,val2);

return 0;

}