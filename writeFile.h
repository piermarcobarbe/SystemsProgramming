//
// Created by Piermarco Barbè on 2019-03-16.
//

#ifndef SYSTEMSPROGRAMMING_WRITEFILE_H
#define SYSTEMSPROGRAMMING_WRITEFILE_H

#include "arrayListString.h"
#include <stdio.h>

FILE * openFile(char * filename);
int closeFile(FILE * fp);
int writeFileCharP(char * filename, char * input);
int writeFileArrayListString(char * filename, struct arrayListString * a);
int writeFileChar(char * filename, char input);
#endif //SYSTEMSPROGRAMMING_WRITEFILE_H
