//
// Created by Piermarco Barbè on 2019-02-22.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int c;

    while((c = getchar()) != EOF){
//        printf("%d\n", c);


        if(c == 32){
            printf("\n");
            continue;
        }

        if(c == 10){
            printf("\n\n");
            continue;
        }

        if(c == 97 || c == 101 || c == 105 || c == 111 || c == 117){
            printf("%cs%c", c, c);
        } else {
            printf("%c", c);
        }

    }
}