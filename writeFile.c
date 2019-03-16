//
// Created by Piermarco Barbè on 2019-03-16.
//
#include "arrayListString.h"
#include "writeFile.h"
#include <strings.h>
#include <stdio.h>

FILE * openFile(char * filename){
    FILE * fp = fopen(filename, "a+");

    if(fp != NULL){
        printf("Successfully opened file '%s'\n", filename);
        return fp;
    }

    printf("Failed to open file '%s'.\n", filename);
    return NULL;

}

int closeFile(FILE * fp){

    int closed = fclose(fp);

    if(closed == 0) return 0;

    return 1;

}


#if 0
int writeFileCharP(char * filename, char * input);
int writeFileArrayListString(char * filename, struct arrayListString * a);
int writeFileChar(char * filename, char input);
#endif
