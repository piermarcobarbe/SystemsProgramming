//
// Created by Piermarco Barbè on 2019-02-22.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(){
    int ch;

    while((ch = getchar()) != EOF){

        if(ch == 10) continue;

        ch += 3;
        ch = ch % CHAR_MAX;

        printf("%c", ch);
    }
}
