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
        printf("Error: end < begin.");
        return NULL;
    }

    if(s == NULL){
        printf("Error: input string is NULL.");
        return NULL;
    }

    if(strlen(s) < end){
        printf("Error: end greater than strlen(s) : %d > %d.\n", end, strlen(s));
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