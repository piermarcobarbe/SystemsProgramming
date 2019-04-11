//
// Created by Piermarco Barbè on 2019-03-16.
//
#include "arrayListString.h"
#include "writeFile.h"
#include "readFile.h"
#include "stringsUtils.h"
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

    printf("closed : %d\n", closed);
    if(closed == 0) return 1;

    return 0;

}



int writeFileCharP(char * filename, char * mode,  char * input){

    printf("writeFileCharP.\n");
    FILE * fp = openFile(filename, mode);

    if(fp == 0){
        printf("Could not write to file %s.\n", filename);
        return -1;
    }

//    input = appendChar(input, '\0');

    printf("strlen: %lu\n", strlen(input));

    for(int i = 0; i <= strlen(input); i++){
        printf("[%d]%c - %d\n",i,  *(input+i), *(input + i));
    }

    printf("Writing '%s': size is %lu\n", input, strlen(input));

    size_t written = fwrite(input, 1, strlen(input), fp);

//    written --;

    printf("writeFileCharP: written %zu bytes.\n", written);

    closeFile(fp);

    if(written >= 0){
        return written ;
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

    if(fileExists(filename)){
        FILE * fp = openFile(filename, mode);
        fputc(input, fp);
        closeFile(fp);
        return 0;
    } else {
        printf("Cannot write '%c' to file '%s': file does not exist.\n", input, filename);
        return 1;
    }

}
int writeFileCharPInt(char * filename, char * mode, char * input, int pos){

        int fileSize = getFileLength(filename);
        int need = 0;

        if(fileSize >= pos + strlen(input)){
            need = fileSize;
        } else {
            need = pos + strlen(input) -1;
        }


        printf("need: %d\n", need);
        char content[need];
        int k = 0;

        FILE *file = fopen(filename, "r");
        while(k <= fileSize){
            content[k] = (char)fgetc(file);
            k++;
        }


        printf("content: '%s'\n", content);

        k = 0;
        int i = 0;
        for(i = pos; i <= strlen(input)-1; i++){
            content[i] = *(input + k);
            printf("content: '%s'\n", content);
            k++;
        }


        if(need < i){
            content[i] = 0;
        } else {
            content[need] = 0;
        }


        printf("content: '%s'\n", content);

        fclose(file);

        deleteFile(filename);
        createFile(filename);

        writeFileCharP(filename, "w+", content);

//        printf("res: %d\n", res);
        return 1;


}

int wipeFile(char * filename){
    if(fileExists(filename)){
        fclose(fopen(filename, "w"));
        return 0;
    } else {
        printf("Cannot wipe file '%s': file does not exist.\n", filename);
        return 1;
    }
}

int fileExists(char * filename){
    FILE * fp = fopen(filename, "r");
    if(fp != NULL){
        return 1;
    }
    return 0;

}
int createFile(char * filename){
    if(fileExists(filename)){
        printf("Cannot create file '%s': file exists yet.\n", filename);
        return 0;
    }
    FILE * fp = fopen(filename, "w");
    fclose(fp);
    return 1;
}



int deleteFile(char * filename){

    if(fileExists(filename)){
        int status = remove(filename);

        if(status == 0){
            printf("File '%s' removed correctly.\n", filename);
            return 1;
        } else {
            printf("File '%s' could not be removed.\n", filename);
            return 0;
        }
    } else {
        printf("Cannot delete file '%s': file does not exist.\n", filename);
        return 0;
    }

}