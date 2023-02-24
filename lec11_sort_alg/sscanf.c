#include <stdio.h>

#define SIZE_BUF 20
int main(){
char buf[SIZE_BUF]="12 34 abc";
int rc;
int num1, num2;
char str[10];
rc = sscanf(buf,"%d%d%s", &num1, &num2, str);
    printf("var1: %d\n", num1);
    printf("vars2: %d\n", num2);
    printf("des: %s\n", str);
    printf("rc: %d\n", rc);
return 0;
}







//use fgets
