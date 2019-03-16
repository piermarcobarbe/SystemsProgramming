//
// Created by Piermarco Barbè on 2019-03-15.
//
#include <stdio.h>
int redact_digits(char * s){
//    int isDigitRed = 0;
    while((*s) != 0){

        switch (*s){
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
//                if(isDigitRed == 1){
//                    printf("%c", *s);
//                } else {
//                    printf("#%c", *s);
//                    isDigitRed = 1;
//                }
                printf("#");
                s++;
                break;
            default:
                printf("%c", *s);
                s++;
//                isDigitRed = 0;

        }


    }
    printf("\n");
    return 0;
}

int main(int argc, char * argv[]){
    redact_digits(argv[1]);
}