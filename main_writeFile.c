//
// Created by Piermarco Barbè on 2019-03-16.
//

#include "writeFile.h"
#include "arrayListString.h"
#include "readFile.h"
#include "stringsUtils.h"
#include "readFile.h"
#include <strings.h>

int main(){

    char * targetFilename = "./txts/test3.txt";
    char * modifiedFilename = "./txts/test3_modified.txt";

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
    theString = replaceString(theString, " ", " - ");
    arrayListStringItemSet(a, 17, theString);
    wipeFile(modifiedFilename);
    struct arrayListString * b = readFile(modifiedFilename);
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


    a = readFile(modifiedFilename);
    l = arrayListStringItemGet(a, 9);
    theString = l->value;

    theString = removeChar(theString, '\n');

    char buffer[strlen(theString)];

    strcpy(buffer, theString);

    int res = replaceStringInPlace(buffer, "Hey, this is the brand new string!\n");


    if(res < 0){
        printf("Could not replace the string '%s'", buffer);
        return -1;
    }

    printf("Successfully replaced the old string with '%s'.\n", buffer);
    arrayListStringItemSet(a, 9, buffer);
    wipeFile(modifiedFilename);
    writeFileArrayListString(modifiedFilename, "a+", a);

    a = readFile(modifiedFilename);
    l = arrayListStringItemGet(a, 7);
    theString = l->value;
    strcpy(buffer, "");
    strcpy(buffer, theString);
    char * veryLongString = "A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. A very long string. ";

    res = replaceStringInPlace(buffer, veryLongString);

    if(res >= 0){
        printf("replaceStringInPlace should have failed.\n");
        return -1;
    }

    theString = replaceString(theString, theString, "test passed.\n");
    arrayListStringItemSet(a, 7, theString);
    wipeFile(modifiedFilename);
    writeFileArrayListString(modifiedFilename, "a+",  a);


    a = readFile(modifiedFilename);
    l = arrayListStringItemGet(a, 5);
    theString = l->value;
    strcpy(buffer, "");
    strcpy(buffer, theString);
    res = replaceCharInPlace(buffer, 'a');

    if(res < 0){
        printf("replaceCharInPlace failed. It should not have.\n");
    }

//    strcpy(theString, buffer);

    printf("%d occurrences of '%c' in '%s'.\n", res, 'a', theString);
    arrayListStringItemSet(a, 5, buffer);
    printArrayListStringItem(arrayListStringItemGet(a, 5));
    wipeFile(modifiedFilename);
    writeFileArrayListString(modifiedFilename, "a+", a);


}


