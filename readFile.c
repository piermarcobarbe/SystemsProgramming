//
// Created by Piermarco Barbè on 2019-02-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"
#include "arrayListString.h"

long int getFileLength(char * fileName){


    // Input check
    if(fileName == NULL){
        printf("No file provided.\n");
        return -1;
    }

    printf("Reading file: %s\n", fileName);
    FILE * fp = fopen(fileName, "r");
    fseek(fp, 0L, SEEK_END);
    long int sz = ftell(fp);
    printf("File size is: %lu\n", sz);

    printf("Successfully red %s\n", fileName);
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
//
//        // Allocate enough space for the red line
//        main->value = malloc(strlen(str));
//
//        // Copy the line in the struct field
//        strcpy(main->value, str);
//
//        // Create another chain ring
//        main->next = malloc(sizeof(struct arrayListString));
//
//        // Switch to the new chain ring
//        main = main->next;

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

