//
// Created by Piermarco Barbè on 2019-03-16.
//

#include "writeFile.h"
#include "arrayListString.h"
#include "readFile.h"
#include "stringsUtils.h"
#include "readFile.h"

int main(){
    FILE * fp = openFile("./tests");


    char * targetFilename = "./tests/test3.txt";
    struct arrayListString * a = readFile(targetFilename);
    fp = openFile(targetFilename);

    printArrayListString(a);

//    printf("%p\n", &fp);
}


