//
// Created by Piermarco Barbè on 2019-03-07.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readFile.h"
#include "arrayListString.h"
#include "stringsUtils.h"
#include "floatList.h"
#include <math.h>
#include "Vector2d.h"


struct Vector2d * newEmptyVector2d(){
    struct Vector2d * r = malloc(sizeof(struct Vector2d));

    r->x = 0;
    r->y = 0;
    r->next = NULL;

    return r;
}

struct Vector2d * newVector2d(float x, float y){
    struct Vector2d * r = newEmptyVector2d();

    r->x = x;
    r->y = y;
    r->next = NULL;

    return r;
}

void printVector2d(Vector2d * v){
    printf("[%f - %f]\n", v->x, v->y);
}

struct Vector2d * createVector2dList(char * fileName){

    if(fileName == NULL){
        printf("No filename provided.\n");
        return NULL;
    }

    struct arrayListString * points = readFile(fileName);


    points = arrayListStringRemoveIfMatching("", points);

    struct Vector2d * head = newEmptyVector2d();
    struct Vector2d * last = head;
    struct Vector2d * prev = last;

    while(points != NULL){

        char * line = points->value;

        line++;

        int firstSpace = getCharFromString(line, ' ');

        char * firstValue = getSubstring(line, 1, firstSpace);

        last->x = atof(firstValue);

        int lastPar = getCharFromString(line+firstSpace+3, ']');

        char * secondValue = getSubstring(line+firstSpace+3, 1, lastPar -1);

        last->y = atof(secondValue);

        points = points->next;

        last->next = newEmptyVector2d();

        prev = last;

        last = last->next;

    }


    prev->next = NULL;


    return head;

}


float getVectorLength(Vector2d * v){
    if(v == NULL){
        printf("Error: vector is not defined.\n");
        return -1;
    }

    return sqrt(pow(v->x, 2) + pow(v->y, 2));

}

float getVectorsDistance(struct Vector2d * v, struct Vector2d * w) {
    if (v == NULL) {
        printf("Error: vector v is not defined.\n");
        return -1;

    }

    if (w == NULL) {
        printf("Error: vector w is not defined.\n");
        return -1;
    }

    float d = sqrt(pow(v->x - w->x, 2) +
                   pow(v->y - w->y, 2)
    );
//    printf("Distance: %f\n" , d);
    return d;
}

void printVector2dList(struct Vector2d * v){
    while(v != NULL){
        printVector2d(v);
        v = v->next;
    }
}

float vector2dMaxDistance(struct Vector2d * v){
    float max = 0;
    float last = 0;

    int i=0, j=0;

    struct Vector2d * w = v;
    struct Vector2d * head = v;

    while(v != NULL){
        while(w != NULL){
//            printf("%d-%d\n", i, j);
            last = getVectorsDistance(v, w);
            if (max < last){
                max = last;
//                printf("Record:%f\n", max);
            }

            w = w->next;
            j++;

        }

        v = v->next;
        i++;
        w = v;
        j = i;

    }


    return max;

}

struct floatList * vector2dApplyVector2d(float (function_ptr)(struct Vector2d *), struct Vector2d * head){

    struct floatList * last = newEmptyFloatList();
    struct floatList * prev = last;
    struct floatList * r = last;

    while(head != NULL){
        printf("%f\n", (*function_ptr)(head));
        last->value = (*function_ptr)(head);
        head = head->next;
        last->next = newEmptyFloatList();
        prev = last;
        last = last->next;
    }

    prev->next = NULL;

    return r;
}
