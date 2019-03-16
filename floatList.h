//
// Created by Piermarco Barbè on 2019-03-15.
//

#ifndef SYSTEMSPROGRAMMING_FLOATLIST_H
#define SYSTEMSPROGRAMMING_FLOATLIST_H

#include <float.h>
#include <limits.h>


typedef struct floatList {
    float value;
    struct floatList * next;
} floatList;

struct floatList * newEmptyFloatList();
struct floatList * newFloatList(float f);
void printFloatList(struct floatList * f);
float getMaxFromFloatList(struct floatList * f);
float getMinFromFloatList(struct floatList * f);

#endif //SYSTEMSPROGRAMMING_FLOATLIST_H
