/*
 * Print nxn idendity matrix (input n from keyboard)
 */
#include <stdio.h>

int main()
{
    // row=i, column=j
    int i,j;
    // size of idendity matrix
    int n;

    // get input from keyboard
    printf("Enter the size of nxn matrix: ");
    scanf("%d", &n);

    // print the result
    printf("Output Identity Matrix: \n");
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            if( i== j)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }


    return 0;
}
