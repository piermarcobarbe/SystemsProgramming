//
// Created by Piermarco Barbè on 2019-03-16.
//

#ifndef SYSTEMSPROGRAMMING_WRITEFILE_H
#define SYSTEMSPROGRAMMING_WRITEFILE_H

#include "arrayListString.h"
#include <stdio.h>

FILE * openFile(char * filename, char * mode);
int closeFile(FILE * fp);
int writeFileCharP(char * filename, char * mode,  char * input);
int writeFileCharPInt(char * filename, char * mode, char * input, int pos);
int writeFileChar(char * filename, char * mode, char input);
int writeFileArrayListString(char * filename, char * mode, struct arrayListString * a);
int wipeFile(char * filename);
#endif //SYSTEMSPROGRAMMING_WRITEFILE_H
