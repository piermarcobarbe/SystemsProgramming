//
// Created by Piermarco Barbè on 2019-03-16.
//

#include "writeFile.h"
#include "arrayListString.h"
#include "readFile.h"
#include "stringsUtils.h"
#include "readFile.h"

int main(){

    char * targetFilename = "./tests/test3.txt";
    char * modifiedFilename = "./tests/test3_modified.txt";

    wipeFile(modifiedFilename);

    struct arrayListString * a = readFile(targetFilename);
    struct arrayListString * l = arrayListStringItemGet(a, 19);
    char * theString = l->value;
//    printf("%s\n", theString);
    theString = replaceString(theString, ". ", ".\n");
    arrayListStringItemSet(a, 19, theString);
    writeFileArrayListString(modifiedFilename, "a+", a);

    a = readFile(modifiedFilename);
    l = arrayListStringItemGet(a, 17);
    theString = l->value;
//    printf("theString: %s\n", theString);
    theString = replaceString(theString, " ", " - ");
//    printf("theString: %s\n", theString);
    arrayListStringItemSet(a, 17, theString);
//    printArrayListString(a);
    wipeFile(modifiedFilename);
    struct arrayListString * b = readFile(modifiedFilename);
//    printArrayListString(b);
    writeFileArrayListString(modifiedFilename, "a+", a);

    a = readFile(modifiedFilename);
    l = arrayListStringItemGet(a, 15);
    theString = l->value;
    theString = replaceString(theString, "a", "A");
    theString = replaceString(theString, "b", "B");
    theString = replaceString(theString, "c", "C");
    arrayListStringItemSet(a, 15, theString);
    wipeFile(modifiedFilename);
    writeFileArrayListString(modifiedFilename, "a+", a);

    a =readFile(modifiedFilename);
    l = arrayListStringItemGet(a, 13);
    theString = l->value;
    theString = removeChar(theString, ' ');
    arrayListStringItemSet(a, 13, theString);
    wipeFile(modifiedFilename);
    writeFileArrayListString(modifiedFilename, "a+", a);

    a = readFile(modifiedFilename);
    l = arrayListStringItemGet(a, 11);
    theString = l->value;
    theString = getSubstringCharPCharP(theString, "Justice", ".");
//    printf("ts:%s", theString);
    theString = appendChar(theString, '\n');
//    printf("ts:%s", theString);
    arrayListStringItemSet(a, 11, theString);
//    printArrayListString(a);
    wipeFile(modifiedFilename);
    writeFileArrayListString(modifiedFilename, "a+", a);





}


