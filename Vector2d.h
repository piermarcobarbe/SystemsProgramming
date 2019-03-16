//
// Created by Piermarco Barbè on 2019-03-07.
//

#include "floatList.h"

#ifndef SYSTEMSPROGRAMMING_2DVECTOR_H

#define SYSTEMSPROGRAMMING_2DVECTOR_H

typedef struct Vector2d{
    float x;
    float y;
    struct Vector2d * next;
} Vector2d;

float getVectorLength(struct Vector2d * v);
float getVectorsDistance(struct Vector2d * v, struct Vector2d * w);
struct Vector2d * newVector2d(float x, float y);
void printVector2d(struct Vector2d * v);
struct Vector2d * createVector2dList(char * fileName);
struct Vector2d * newEmptyVector2d();
void printVector2dList(struct Vector2d * v);
float vector2dMaxDistance(struct Vector2d * v);
struct floatList * vector2dApplyVector2d(float (function_ptr)(struct Vector2d *), struct Vector2d * head);

#endif //SYSTEMSPROGRAMMING_2DVECTOR_H
