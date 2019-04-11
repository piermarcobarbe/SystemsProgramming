//
// Created by Piermarco Barbè on 2019-04-02.
//

#include "../writeFile.h"
#include "../readFile.h"
#include "../arrayListString.h"
#include "../stringsUtils.h"

#include <strings.h>
#include <stdio.h>
#include <assert.h>

int main(){

    char * goodFile = "txts/testWriteFile.txt";
    char * badFile = "THIS_FILE_DOES_NOT_EXIST.txt";


    assert(fileExists(goodFile) == 0);

    assert(createFile(goodFile) == 1);

    assert(fileExists(goodFile) == 1);

    assert(fileExists(badFile) == 0);
    assert(fileExists(NULL) == 0);


    FILE *gfp, *bfp;

    gfp = openFile(goodFile, "r");
    bfp = openFile(badFile, "r");

    assert(gfp != 0);
    assert(bfp == 0);




    assert(closeFile(bfp) == 0);
    assert(closeFile(gfp) == 1);



//
    char * s = "This is a string i want to write.";
    assert(fileExists(goodFile) == 1);

    int writtenBytes = writeFileCharP(goodFile, "a+", s);

    assert(writtenBytes == strlen(s));

    s = "";
    writtenBytes = writeFileCharP(goodFile, "a+", s);
    assert(writtenBytes == 0);

    writtenBytes = writeFileCharP(badFile, "a+", s);
    assert(writtenBytes == 0);
    assert(fileExists(badFile) == 1);
    remove(badFile);
    assert(fileExists(badFile) == 0);




    int result = writeFileCharP(goodFile, "w", "Write this!");
    assert(result == strlen("Write this!"));

    assert(getFileLength(goodFile) == strlen("Write this!"));

//    int deleted = deleteFile(goodFile);
//    assert(deleted == 1);



//    if(fileExists(goodFile)){
//        deleteFile(goodFile);
//    }


    result = writeFileCharP(goodFile, "w", "Ciao ciao!");
    assert(result == 10);

    char * targetString = "Canile!!!!!";

    result = writeFileCharPInt(goodFile, "r+", targetString + 1 ,1);
    assert(result == 1);
    struct arrayListString * c = readFileNoNewLines(goodFile);
    printf("c->value: '%s'\n", c->value);

    printf("strcmp(c->value, \"Canile!!!!!\") : %d\n", strcmp(c->value, targetString));

    for(int i = 0; i < strlen(c->value) ;i++){
        printf("%c - %c\n", *(c->value + i), *(targetString + i));
    }

    assert(strcmp(c->value, targetString) == 0);


    result = deleteFile(goodFile);
    assert(result == 1);

    result = createFile(goodFile);

    result = writeFileCharP(goodFile, "w", "Ciao ciao!");
    assert(result == 10);
    result = writeFileCharPInt(goodFile, "r+", "M", 0);
    assert(result == 1);


    c = readFileNoNewLines(goodFile);
    printf("'%s' \n", c->value);
    assert(strcmp(c->value, "Miao ciao!") == 0);






    return 0;

//    int writeFileCharPInt(char * filename, char * mode, char * input, int pos);
//    int writeFileChar(char * filename, char * mode, char input);
//    int writeFileArrayListString(char * filename, char * mode, struct arrayListString * a);
//    int wipeFile(char * filename);
//    int fileExists(char * filename);
//    int createFile(char * filename);
//    int deleteFile(char * filename);


}