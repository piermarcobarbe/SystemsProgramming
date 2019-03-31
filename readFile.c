//
// Created by Piermarco Barbè on 2019-02-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"
#include "arrayListString.h"
#include "stringsUtils.h"

long int getFileLength(char * fileName){


    // Input check
    if(fileName == NULL){
        printf("No file provided.\n");
        return -1;
    }

    printf("Reading file: '%s'...\n", fileName);
    FILE * fp = fopen(fileName, "r");
    fseek(fp, 0L, SEEK_END);
    long int sz = ftell(fp);
    printf("File size is: %lu\n", sz);

    printf("Successfully red file '%s'.\n", fileName);
    return sz;
}


struct arrayListString * readFile(char * fileName){

    // Input check
    if(fileName == NULL){
        printf("No file provided.\n");
        return NULL;
    }


    // Prepare for file reading operation.
    FILE * fp = fopen(fileName, "r");
    long int fileLength = 0;

    // Read check
    if(fp == NULL){
        printf("Could not open file %s\n", fileName);
    }

    // Getting length of file
    fileLength = getFileLength(fileName);

    if(fileLength == -1)
        return NULL;

    // Maximum string length in file
    char str[fileLength];

    // Start the chain
//    struct arrayListString * main = malloc(sizeof(struct arrayListString));
    struct arrayListString * main = newArrayListStringItemInt(fileLength);

    // Remember where the chain starts
    struct arrayListString * ret = main;


    int k = 0;

    // Get line-by-line
    while(fgets(str, fileLength, fp) != NULL){

//        printf("'%s'\n", str);
        if(k == 0){
            arrayListStringItemSet(main, 0, str);
        } else {
            arrayListStringItemPush(str, main);
        }

        k++;

    }

    fclose(fp);


    // Return what you remembered
    return ret;
}

struct arrayListString * readFileNoNewLines(char * fileName){

    // Input check
    if(fileName == NULL){
        printf("No file provided.\n");
        return NULL;
    }


    // Prepare for file reading operation.
    FILE * fp = fopen(fileName, "r");
    long int fileLength = 0;

    // Read check
    if(fp == NULL){
        printf("Could not open file %s\n", fileName);
    }

    // Getting length of file
    fileLength = getFileLength(fileName);

    if(fileLength == -1)
        return NULL;

    // Maximum string length in file
    char str[fileLength];

    // Start the chain
//    struct arrayListString * main = malloc(sizeof(struct arrayListString));
    struct arrayListString * main = newArrayListStringItemInt(fileLength);

    // Remember where the chain starts
    struct arrayListString * ret = main;


    int k = 0;

    // Get line-by-line
    while(fgets(str, fileLength, fp) != NULL){

//        printf("'%s'\n", str);

        strcpy(str, removeChar(str, '\n'));

        if(k == 0){
            arrayListStringItemSet(main, 0, str);
        } else {
            arrayListStringItemPush(str, main);
        }

        k++;

    }

    fclose(fp);


    // Return what you remembered
    return ret;
}



