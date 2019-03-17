//

#include "arrayListString.h"
#include "stringsUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>



//
// Created by Piermarco Barbè on 2019-02-26.



void printArrayListStringItemVerbose(struct arrayListString * a){
    if(a == NULL){
        printf("No arrayListString object provided.\n");
        return;
    }



    if(a->next != NULL){
        printf("[%lld] => '%s' | next => [%lld]\n", a->id, a->value, a->next->id);
    } else {
        printf("[%lld] => '%s' | next => [NULL]\n", a->id, a->value);
    }

}

void printArrayListStringItem(struct arrayListString * a){
    if(a == NULL){
        printf("No arrayListString object provided.\n");
        return;
    }



    if(a->next != NULL){
        if(strlen(a->value) >= 20){
            printf("'%s...', \n", getSubstringIntInt(a->value, 1, 20));
        } else {
            printf("'%s', \n", a->value);
        }
    } else {
        if(strlen(a->value) >= 20){
            printf("'%s...' \n", getSubstringIntInt(a->value, 1, 20));
        } else {
            printf("'%s' \n", a->value);
        }
    }

}


struct arrayListString * newArrayListStringItemInt(int maxStringLength){

//    srand(time(NULL));
//    printf("newArrayListStringItemInt %d\n", maxStringLength);


    struct arrayListString * r = malloc(sizeof(struct arrayListString));

    r->value = malloc(maxStringLength);
    r->next = 0;
    r->id = rand();


//    printf("Creating: ");
//    printArrayListStringItem(r);


    return r;


}

struct arrayListString * newArrayListStringItemString(char * s){

//    printf("newArrayListStringItemString: '%s'\n", s);

    struct arrayListString * r = newArrayListStringItemInt(strlen(s)+1);
    strcpy(r->value, s);

    return r;

}

void printArrayListStringVerbose(struct arrayListString * a){

    printf("\n\n");

    if(a == NULL){
        printf("No arrayListString provided.\n");
    }


    while(a != NULL){
        printArrayListStringItemVerbose(a);
        a = a->next;
    }

    printf("\n\n");


}

void printArrayListString(struct arrayListString * a){

    printf("\n\n");

    if(a == NULL){
        printf("No arrayListString provided.\n");
    }

    printf("[\n");

    while(a != NULL){
        printArrayListStringItem(a);
        a = a->next;
    }
    printf("\n]\n");

    printf("\n\n");


}

struct arrayListString * arrayListStringMatch(struct arrayListString * a, char * t){

    struct arrayListString * last = malloc(sizeof(struct arrayListString));
    struct arrayListString * ret = last;

    int maxStringLen = 0;
    int stringNumber = 0;

    while(a->value != NULL){

        if (strlen(a->value) > maxStringLen){
            maxStringLen = strlen(a->value)+1;
        }
        stringNumber ++;



        a = a->next;
    }


    last = newArrayListString(stringNumber, maxStringLen);

    while(a->value != NULL) {

        if (strstr(a->value, t)) {
            arrayListStringItemPush(a->value, last);
        }
        a = a->next;
    }


    return ret;

}

struct arrayListString * newArrayListString(int size, int maxStringLen){


    struct arrayListString * last = newArrayListStringItemInt(maxStringLen);
    struct arrayListString * head = last;
    struct arrayListString * lN;
    int k = 1;

    while(k < size){
        lN = newArrayListStringItemInt(maxStringLen);

        last->next = lN;

//        printf("%llu -> %llu\n", last->id, lN->id);
        last = last->next;

        k++;
    }
    last->next = NULL;

//    printf("Last is ");
//    printArrayListStringItem(last);

//    free(last);


    return head;


}

int arrayListStringItemPush(char * s, arrayListString * a){

//    printf("Pushing.\n");

    if(a == NULL){
        printf("No arrayListString provided.\n");
        return -1;
    }

    if(s == NULL){
        printf("No String provided.\n");
        return -2;
    }

    int k = 1;

    struct arrayListString * prev;

    while(a->next != NULL){

//        printf("a: ");
//        printArrayListStringItem(a);
        prev = a;
        a = a->next;
        k++;

    }

//    printf("Last is %llu\n", a->id);


    struct arrayListString * n = newArrayListStringItemString(s);
//    printf("HERE\n");

//    printf("New obj: \n");

//    printArrayListStringItem(n);

    a->next = n;
    n->next = NULL;
    return k-1;
}


struct arrayListString * arrayListStringItemGet(struct arrayListString * a, int pos){
    int k = 1;
    while(k < pos && a != NULL){
        a = a->next;
        k++;
    }


    if(a == NULL){
        printf("arrayListStringItemGet: OutOfBounds.\n");
        return NULL;
    }


    return a;

}
struct arrayListString * arrayListStringItemSet(struct arrayListString * a, int pos, char * s) {
    int k = 1;
    while(k < pos && a != NULL){
        a = a->next;
        k++;
    }


    if(a == NULL){
        printf("arrayListStringItemSet: OutOfBounds.\n");
        return NULL;
    }

    free(a->value);

    a->value = malloc(strlen(s)+1);

    strcpy(a->value, s);

    return a;


}

struct arrayListString * arrayListStringItemPop(struct arrayListString * a){
    struct arrayListString * prev;
    while(a->next != NULL){
        prev = a;
        a = a->next;
    }

    struct arrayListString * r = prev->next;
    prev->next = NULL;

    return r;

}

struct arrayListString * arrayListStringApplyCharP(char * (*function_ptr)(char *), struct arrayListString * a){

    struct arrayListString * r = a;

    while(a != NULL){

        a->value = (*function_ptr)(a->value);
        a = a->next;
    }


    return r;
}

struct arrayListString * arrayListStringApplyCharPChar(char * (*function_ptr)(char *, char), struct arrayListString * a, char charForApply){

    struct arrayListString * r = a;

    while(a != NULL){

        a->value = (*function_ptr)(a->value, charForApply);
        a = a->next;
    }


    return r;
}


struct arrayListString * arrayListStringRemoveIfMatching(char * s, struct arrayListString * a) {
    struct arrayListString * head = NULL;
    struct arrayListString * last= NULL;
//    head->next = NULL;

    while (a != NULL) {

//        printf("Checking [%llu] '%s'\n", a->id, a->value);

        if (strcmp(a->value, s) != 0) {

            if (head == NULL && last == NULL) {
                head = a;
                last = a;
            } else {
                last->next = a;
                last = last->next;
            }

        } else {
//            printf("Removing [%llu]'%s' matching with '%s'\n", a->id, a->value, s);
        }

        a = a->next;


    }

    last->next = NULL;

    return head;
}