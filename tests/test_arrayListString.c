//
// Created by Piermarco Barbè on 2019-03-28.
//


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

#include "../arrayListString.h"
#include "../stringsUtils.h"



int main(){

    printf("Running test_arrayListString\n");


    struct arrayListString * a = newArrayListStringItemVoid();

    assert(a->value == 0);
    assert(a->next == 0);



    char * s = "This is a test string.";
    int r = arrayListStringItemPush(0, s);
    assert(r == -1);

    r = arrayListStringItemPush(a, 0);
    assert(r == -2);

    r = arrayListStringItemPush(a, s);
    assert(r == 1);
    assert(strcmp(s, a->value) == 0);
    assert(a->next == 0);

    r = arrayListStringItemPush(a, "Another string.");
    assert(r == 2);

    r = arrayListStringItemPush(a, "Yet another string");
    assert(r == 3);







    s = "";
    s = arrayListStringItemPop(a)->value;
    assert(strcmp("Yet another string", s) == 0);
    assert(arrayListStringSize(a) == 2);

    s = arrayListStringItemPop(a)->value;
    assert(strcmp("Another string.", s) == 0);
    assert(arrayListStringSize(a) == 1);

    s = arrayListStringItemPop(a)->value;
    assert(strcmp("This is a test string.", s) == 0);
    assert(arrayListStringSize(a) == 1);

    s = arrayListStringItemPop(a)->value;
    assert(strcmp("This is a test string.", s) == 0);
    assert(arrayListStringSize(a) == 1);




    s = "";
    arrayListStringItemPush(a, "ciao");
    arrayListStringItemPush(a, "come");
    arrayListStringItemPush(a, "stai?");
    arrayListStringItemPush(a, "");
    arrayListStringItemPush(a, "bene");
    arrayListStringItemPush(a, "grazie");


//    printf("%s\n", arrayListStringItemGet(a, 2));

    assert(strcmp(arrayListStringItemGet(a, 2)->value, "come") == 0);
    assert(strcmp(arrayListStringItemGet(a, 4)->value, "") == 0);
    assert(arrayListStringItemGet(a, -1) == 0);
    assert(arrayListStringItemGet(a, 0) == 0);


    s = "Ciao!";

    assert(arrayListStringItemSet(a, 1, s) != 0);
//    printf("%s\n", arrayListStringItemGet(a, 4)->value);
    assert(strcmp(arrayListStringItemGet(a, 1)->value, "ciao") != 0);
    assert(strcmp(arrayListStringItemGet(a, 1)->value, s) == 0);




    struct arrayListString * a2 = newArrayListStringItemString("Another struct!");
    arrayListStringItemPush(a, a2->value);
    assert(strcmp(arrayListStringItemGet(a, arrayListStringSize(a)-1)->value, "Another struct!") == 0);






    a2 = arrayListStringMatch(a, "o");

    assert(strcmp(arrayListStringItemPop(a2)->value, "Another struct!") == 0);
    assert(strcmp(arrayListStringItemPop(a2)->value, "come") == 0);
    assert(strcmp(arrayListStringItemPop(a2)->value, "Ciao!") == 0);

    a2 = arrayListStringMatch(a, "st");

    assert(strcmp(arrayListStringItemPop(a2)->value, "Another struct!") == 0);
    assert(strcmp(arrayListStringItemPop(a2)->value, "stai?") == 0);






    printArrayListString(a);
    struct arrayListString * splittedStrings = arrayListStringSplit(a, " ");
//    printf("SS:\n");
//    printArrayListString(splittedStrings);



//
//
//    struct arrayListString * arrayListStringApplyCharP(char * (*function_ptr)(char *), struct arrayListString * a);
//    struct arrayListString * arrayListStringApplyCharPChar(char * (*function_ptr)(char *, char), struct arrayListString * a, char charForApply);
//
//    struct arrayListString * arrayListStringRemoveIfMatching(char * s, struct arrayListString * a);
//
//

    return 0;
}