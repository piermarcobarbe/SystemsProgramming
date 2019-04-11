//
// Created by Piermarco Barbè on 2019-04-01.
//

#include "../readFile.h"
#include "../arrayListString.h"
#include "../stringsUtils.h"
#include "../writeFile.h"

#include <assert.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    char * filename = "txts/test4.txt";
    char * pushingString = "Pushing this string\n";

    int beforeSize = getFileLength(filename);

    struct arrayListString * file = readFile(filename);

    printArrayListString(file);

    arrayListStringItemPush(file, pushingString);

    wipeFile(filename);

    writeFileArrayListString(filename, "a+", file);

    int afterSize = getFileLength(filename);

    assert(beforeSize + strlen(pushingString) == afterSize);


    return 0;
}