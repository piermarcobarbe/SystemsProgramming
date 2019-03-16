//
// Created by Piermarco Barbè on 2019-03-06.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char * flipLine(char * s){

    char * r = malloc(strlen(s)+1);

//    printf("%d.\n", strlen(s));

    for(int i = strlen(s)-1; i >=0; i--){
//        printf("[%d] %c",i, s[i]);
        r[strlen(s) - 1 - i] = s[i];
    }

    r[strlen(s)] = 0;

//    printf("\n");
//
//    printf("s:%s\n", s);
//    printf("r:%s\n", r);

    return r;
}


char * removeChar(char * s, char c){

    char * r = malloc(strlen(s));
    int count = 0;

    for(int i = 0; i < strlen(s); i++){
        if(s[i] != c){
            r[count] = s[i];
            count ++;
        }
    }

    return r;
}

char * removeFirstChar(char * s, char c){

    char * r = malloc(strlen(s));
    int count = 0;
    int skip = 0;

    for(int i = 0; i < strlen(s); i++){

        if(skip == 0){
            if(s[i] != c){
                r[count] = s[i];
                count ++;
            } else {
                skip = 1;
            }
        } else {
            r[count] = s[i];
            count ++;
        }
    }

    return r;

}


char * getSubstring(char * s, int begin, int end){

//    printf("%s - %d - %d\n", s, begin, end);

    if(end < begin){
        printf("Error: end < begin: %d < %d.\n", end, begin);

        return NULL;
    }

    if(s == NULL){
        printf("Error: input string is NULL.\n");
        return NULL;
    }

    if(strlen(s) < end){
        printf("Error: end greater than strlen(s) : %d > %lu.\n", end, strlen(s));
        return NULL;
    }


    if(begin <= 0){
        printf("Error: begin must be positive, it was %d.\n", begin);
        return NULL;
    }

    char * r = malloc(end-begin+2);

    memcpy(r, s+begin-1, end-begin+1);

//    printf("Returning %s\n", r);

    r[end-begin+2] = '\0';

    return r;


}


int getCharFromString(char * s, char c){

    for(int i = 0; i < strlen(s); i++){

//        printf("Comparing %c with %c\n", *(s+i), c);
        if(*(s+i) == c){
            return i;
        }
    }
    return -1;

}


int deleteDigits(char * s){

    char * r = malloc(strlen(s));
    int s_i = 0;
    int r_i = 0;

//    printf("%s\n", s);
        while(*(s+s_i) != 0){
//            printf("%c\n", *(s+s_i));
            switch (*(s+s_i)){
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
                    s_i++;
                    break;
                default:
                    *(r+r_i) = *(s+s_i);
                    s_i++;
                    r_i++;

            }
        }
        *(r+r_i) = '\0';

        printf("%s\n", r);

        strcpy(s, r);

        return 0;
}