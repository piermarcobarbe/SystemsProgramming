//
// Created by Piermarco Barbè on 2019-03-06.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stringsUtils.h"


char * appendChar(char * s, char c){
//    printf("%lu\n", strlen(s)+1);
    char * r = malloc(strlen(s)+1);
//    printf("s:%s", s);
//    printf("r:'%s'", r);
    strcpy(r, s);

//    printf("r:'%s'", r);

    r[strlen(s)] = c;
//    printf("r:'%s'", r);
    r[strlen(s)+1] = '\0';
//    printf("r:'%s'", r);
    return r;
}

char * getSusbstringCharP(char * s, char * in){

//    printf("%s - %s\n", s, in);

    int i_s = 0;
    int i_in = 0;

    while(i_s <= strlen(s)){
//        printf("[%lu]%s\n", strlen(s+i_s), s+i_s);

        while(*(s + i_s) == *(in + i_in) && i_in < strlen(in) && i_s < strlen(s)){

//            printf("[%d]'%c'|[%d]'%c'\n", i_s, *(s + i_s),i_in, *(in + i_in));



            i_s++;
            i_in++;

        }

        if(i_in == strlen(in)){
//            printf("R:%s\n", s + i_s);
            return s + i_s - i_in;
        } else {
            i_in = 0;
        }



        i_s++;

    }

    return NULL;

}


char * getSubstringCharPCharP(char * s, char * begin, char * end){


    char * start = getSusbstringCharP(s, begin);


    if(start == NULL){
        printf("Could not find '%s' in '%s'\n", begin, s);
        return NULL;
    }

    char * finish = getSusbstringCharP(start, end);

    if(finish == NULL){
        printf("Could not find '%s' in '%s'\n", end, start);
        return NULL;
    }
//    printf("start:%s\nfinish:%s\n", start, finish);

    int count = 0;
    char * m = start;

    while(start != finish){
        count++;
        start++;
    }

    start = m;
//    printf("diff:%d\n", count);

    count += strlen(end);

    char * r = malloc(count+1);

    strncpy(r, start, count);

    r[count+1] = '\0';
//    printf("%s\n", r);

    return r;

}

char * replaceString(char * s, char * out, char * in){

//    printf("out: %lu - '%s'\n", strlen(out), out);
//    printf("in: %lu - '%s'\n", strlen(in), in);

    if(strlen(out) == 0){
        printf("Empty out parameter.\n");
        return s;
    }



    int occurrences = 0;
    char * nextOccurrence = getSusbstringCharP(s, out);

//    printf("nextOccurrence:%s\n", nextOccurrence);
    while(nextOccurrence != NULL){
        occurrences++;
        nextOccurrence = getSusbstringCharP(nextOccurrence+strlen(out), out);
    }



//    printf("Found %d occurrences.\nCalculating output size...", occurrences);

    int retSize = strlen(s);


//    printf("strlen(s): %d\n", retSize);

    int occurrencesDiff = strlen(in) - strlen(out);

    if(occurrences > 0){
        int delta = occurrencesDiff * occurrences;
        retSize += delta;
    }
//    retSize++;

//    printf(" %d bytes.\n", retSize);

    char * r = malloc(retSize);

    nextOccurrence = getSusbstringCharP(s, out);

    int i_s = 0;
    int i_r = 0;
    int i_in = 0;

    while(nextOccurrence != NULL){
        while((s+i_s) != nextOccurrence){

//            printf("%s\n", r);
            r[i_r] = s[i_s];
            i_s++;
            i_r++;

        }

//        printf("(before)R:%s\nFound point:'%s'\n", r, s+i_s);

        while(*(in + i_in) != 0){
            r[i_r] = in[i_in];
//            printf("r:%s\n", r);
            i_in++;
            i_r++;
        }

        i_in = 0;
//        printf("(after)R:%s\n\n", r);

        i_s += strlen(out);
        nextOccurrence = getSusbstringCharP(nextOccurrence+strlen(out), out);
    }

//    printf("r2: '%s'\n", r);

    while((*(s + i_s) != 0)){
        r[i_r] = s[i_s];
//        printf("R:'%s'\n", r);
        i_s++;
        i_r++;
    }

    *(r+i_r) = '\0';


    return r;
}

char * replaceChar(char * s, char out, char in){
    char * r = malloc(strlen(s));
    int count = 0;

    for(int i = 0; i < strlen(s); i++){
        if(s[i] == out){
            r[count] = in;
        } else {
            r[count] = s[i];
        }
        count ++;
    }

    return r;
}

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

    for(int i = 0; i <= strlen(s); i++){
//        printf("r:%s\n", r);
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


char * getSubstringIntInt(char * s, int begin, int end){

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

//        printf("%s\n", r);

        strcpy(s, r);

        return 0;
}

int replaceStringInPlace(char * s, char * r){

    if(strlen(r) > strlen(s)){
        printf("replaceStringInPlace: Could not copy %lu bytes in %lu bytes.\n", strlen(r), strlen(s));
        return -1;
    }

    int i = 0;

    printf("Before: '%s'", s);

    while(s[i] != 0){
        printf("%d\n", s[i]);
        s[i] = 0;
        i++;
    }

    i = 0;

    while(r[i] != 0){
        s[i] = r[i];
        printf("Copied '%c'", s[i]);
        i++;
    }

    printf("After: '%s'\n", s);
    return i;

}

int removeCharInPlace(char * s, char c){

    if(s == NULL){
        printf("replaceCharInPlace: input string is null.\n");
        return -1;
    }

    if(!(c)){
        printf("replaceCharInPlace: input char is null.\n");
        return -2;
    }

    int i = 0;
    int j = 0;
    int occurrences = 0;
    while(s[i] != 0){
        if(s[i] == c){
            printf("%c\n", s[i]);
            occurrences++;
            j = i;
            while(s[j] != 0){
                s[j] = s[j+1];
                j++;
            }
        }
        i++;
    }

    return occurrences;
}