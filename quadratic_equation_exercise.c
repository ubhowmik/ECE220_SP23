#include <stdio.h>
#include <math.h>   // needed for sqrt
int main(){
    float a,b,c;    // coefficients
    float D;        // determinant
    float x1,x2;    // solution(s)
    // get equation coefficients
    printf("Enter a,b,c: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Solving equation %f*x^2 + %f*x+ %f=0\n", a,b,c);
    // Your Code Here. . .
    

    else{
        printf("No real roots \n");
    }
    return 0;
}
