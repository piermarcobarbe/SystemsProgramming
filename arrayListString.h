//
// Created by Piermarco Barbè on 2019-02-26.
//

#ifndef SYSTEMSPROGRAMMING_ARRAYLIST_H
#define SYSTEMSPROGRAMMING_ARRAYLIST_H

/*
 * arrayListString.value : char * : The string hold by the List cell
 * arrayListString.next : arrayListString * : The next item
 * */

typedef struct arrayListString {
    long long int id;
    char * value;
    struct arrayListString * next;
} arrayListString;


int arrayListStringSize(struct arrayListString * a);
struct arrayListString * newArrayListStringItemVoid();
int arrayListStringItemPush(arrayListString * a, char * s);
void printArrayListString(struct arrayListString * a);

void printArrayListStringVerbose(struct arrayListString * a);

void printArrayListStringItem(struct arrayListString * a);
void printArrayListStringItemVerbose(struct arrayListString * a);

struct arrayListString * arrayListStringMatch(struct arrayListString * a, char * t);
struct arrayListString * newArrayListString(int size, int maxStringLen);
struct arrayListString * newArrayListStringItemInt(int i);
struct arrayListString * newArrayListStringItemString(char * s);
struct arrayListString * arrayListStringItemGet(struct arrayListString * a, int pos);
struct arrayListString * arrayListStringItemSet(struct arrayListString * a, int pos, char * s);
struct arrayListString * arrayListStringItemPop(struct arrayListString * a);

struct arrayListString * arrayListStringApplyCharP(char * (*function_ptr)(char *), struct arrayListString * a);
struct arrayListString * arrayListStringApplyCharPChar(char * (*function_ptr)(char *, char), struct arrayListString * a, char charForApply);

struct arrayListString * arrayListStringRemoveIfMatching(char * s, struct arrayListString * a);

struct arrayListString * arrayListStringSplit(struct arrayListString * a, char * sep);

#endif //SYSTEMSPROGRAMMING_ARRAYLIST_H
