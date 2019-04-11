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

int arrayListStringSize(struct arrayListString * a){
    int r = 1;

//    if(a->value == 0) return 0;

    while(a->next != 0){
        r++;
        a = a->next;
    }
    return r;
}

struct arrayListString * newArrayListStringItemVoid(){
    struct arrayListString * _new = malloc(sizeof(struct arrayListString));
    _new->value = 0;
    _new->next = 0;
    return _new;
}

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
        if(strlen(a->value) >= 50){
            printf("'%s...', \n", getSubstringIntInt(a->value, 1, 50));
        } else {
            printf("'%s', \n", a->value);
        }
    } else {
        if(strlen(a->value) >= 50){
            printf("'%s...' \n", getSubstringIntInt(a->value, 1, 50));
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

    struct arrayListString * last = newArrayListStringItemVoid();
    struct arrayListString * ret = last;


    while(a != NULL) {

        if (strstr(a->value, t)) {
            arrayListStringItemPush(last, a->value);
        }
//        else {
//            printf("%s not matching with %s\n", a->value, t);
//        }
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

int arrayListStringItemPush(arrayListString * a, char * s){

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

    if(a->value == NULL){
        a->value = malloc(strlen(s)+1);
        strcpy(a->value, s);
        a->value[strlen(s)+1] = 0;
        return k;
    }

    struct arrayListString * prev;

    while(a->next != NULL){

//        printf("a: ");
//        printArrayListStringItem(a);
        prev = a;
        a = a->next;
        k++;

    }
    k++;

//    printf("Last is %llu\n", a->id);


    struct arrayListString * n = newArrayListStringItemString(s);
//    printf("HERE\n");

//    printf("New obj: \n");

//    printArrayListStringItem(n);

    a->next = n;
    n->next = NULL;
//    printf("%d\n", k);
    return k;
}


struct arrayListString * arrayListStringItemGet(struct arrayListString * a, int pos){

    if(pos <= 0)
        return 0;

    int k = 1;
    while(k <= pos && a != NULL){
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
    while(k <= pos && a != NULL){
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
    struct arrayListString * result;

    while(a->next != NULL){
//        printf("%s\n", a->value);
        prev = a;
        a = a->next;
    }

    result = prev->next;
    prev->next = NULL;

    if(result == 0){
        return prev;
    }

    return result;

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

struct arrayListString * arrayListStringSplit(struct arrayListString * a, char * sep){
    struct arrayListString * res = newArrayListStringItemVoid();
    char * s;
    int c = 1;
    int l = 1;

    while(a != 0){
        s = a->value;

        if(getSubstringCharP(s, sep) == 0){
            arrayListStringItemPush(res, s);
            a = a->next;
            continue;
        }

//        printf("%s\n", s);
        s = getSubstringCharP(s, sep);


        while(s){

            l = c;
            c = s - a->value;

            printf("GSII: %d\n", getSubstringIntInt(a->value, l, c) > 0);

            printf("Subs = '%s'\n", getSubstringIntInt(a->value, l, c));


            arrayListStringItemPush(res, appendChar(getSubstringIntInt(a->value, l, c), '\0'));
            s++;
            printf("%s\n", s);

            printf("GSCP: %s -> %s\n", s, getSubstringCharP(s, sep));

            if(getSubstringCharP(s, sep) != 0){
                s = getSubstringCharP(s, sep);
            } else {
                arrayListStringItemPush(res, s);
                s = 0;
            }


            c+=strlen(sep)+1;
        }

//        l = c;
//        c = strlen(a->value);
//        printf("Subs = '%s'\n", getSubstringIntInt(a->value, l, c));
//        arrayListStringItemPush(res, appendChar(getSubstringIntInt(a->value, l, c), '\0'));



        c = 1;
        l = 1;


        a = a->next;
    }
//    res = a;

//    printArrayListString(res);

    return res;


}