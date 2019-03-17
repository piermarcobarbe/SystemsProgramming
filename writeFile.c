//
// Created by Piermarco Barbè on 2019-03-16.
//
#include "arrayListString.h"
#include "writeFile.h"
#include <strings.h>
#include <stdio.h>

FILE * openFile(char * filename, char * mode){
    FILE * fp = fopen(filename, mode);

    if(fp != NULL){
//        printf("Successfully opened file '%s'\n", filename);
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



int writeFileCharP(char * filename, char * mode,  char * input){
    FILE * fp = openFile(filename, mode);

    size_t written = fwrite(input, sizeof(char), strlen(input), fp);

//    printf("writeFileCharP: written %zu bytes.\n", written);

    closeFile(fp);

    if(written > 0){
        return written;
    } else {
        return -1;
    }


}

int writeFileArrayListString(char * filename, char * mode, struct arrayListString * a){
    int written = 0;
    while(a != NULL){
        written += writeFileCharP(filename, mode, a->value);
//        printf("Written %d bytes...\n", written);
        a = a->next;
    }
    if (written > 0){
        return written;
    }
    return -1;

}

int writeFileChar(char * filename, char * mode, char input){
    FILE * fp = openFile(filename, mode);
    fputc(input, fp);
    closeFile(fp);
    return 0;

}
int writeFileCharPInt(char * filename, char * mode, char * input, int pos){
    FILE * fp = openFile(filename, mode);

    fseek(fp, pos, SEEK_SET);
    fwrite(input, strlen(input), 1, fp );

    closeFile(fp);
    return 0;
}

int wipeFile(char * filename){
    fopen(filename, "w");
    return 0;
}

