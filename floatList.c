//
// Created by Piermarco Barbè on 2019-03-07.
//

#include "floatList.h"
#include <stdio.h>
#include <stdlib.h>

struct floatList * newEmptyFloatList(){
    struct floatList * r = malloc(sizeof(struct floatList));
    return r;
}

struct floatList * newFloatList(float f){
    struct floatList * r = newEmptyFloatList();
    r->value = f;
    return r;
}

void printFloatList(struct floatList * f){
    while(f != NULL){
        printf("%f\n", f->value);
        f = f->next;
    }
}

float getMaxFromFloatList(struct floatList * f){
    float max = FLT_MIN;
    while(f != NULL){
        if(f->value > max){
            max = f->value;
        }

        f = f->next;
    }
    return max;
}
float getMinFromFloatList(struct floatList * f){
    float min = FLT_MAX;
    while(f != NULL){
        if(f->value < min){
            min = f->value;
        }

        f = f->next;
    }
    return min;
}