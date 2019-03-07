//
// Created by Piermarco Barbè on 2019-02-22.
//


#include <stdio.h>
#include <stdlib.h>

int main(){
    int ch;
    int s = 0;
    while((ch=getchar()) != -1){
        printf("%c (%d)\n", ch, ch);
        s += ch;
        printf("Sum is %d\n", s);
    }
}