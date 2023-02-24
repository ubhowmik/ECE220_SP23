#include <stdio.h>
#include <string.h>
void string_copy(char src[], char des[]);
int main(){

    char src[10];
    
    string_copy(src, "ABC");
    printf("%s\n", src);
   
    strcpy(src, "ABCDE");// from string.h
    printf("%s\n", src);
	
	return 0;
}

void string_copy(char src[], char des[]){

    int i = 0 ;
    while(des[i] != '\0'){
        src[i] = des[i];
        i++;
    }
    src[i] = '\0';
}