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
    int r = arrayListStringItemPush(s, NULL);
    assert(r == -1);

    r = arrayListStringItemPush(NULL, s);
    assert(r == -2);

    r = arrayListStringItemPush(s, a);
    assert(r == 1);
    assert(strcmp(s, a->value) == 0);
    assert(a->next == 0);

    r = arrayListStringItemPush("Another string.", a);
    assert(r == 2);

    r = arrayListStringItemPush("Yet another string", a);
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
    arrayListStringItemPush("ciao", a);
    arrayListStringItemPush("come", a);
    arrayListStringItemPush("stai?", a);
    arrayListStringItemPush("", a);
    arrayListStringItemPush("bene", a);
    arrayListStringItemPush("grazie", a);


//    printf("%s\n", arrayListStringItemGet(a, 2));

    assert(strcmp(arrayListStringItemGet(a, 2)->value, "come") == 0);
    assert(strcmp(arrayListStringItemGet(a, 4)->value, "") == 0);
    assert(arrayListStringItemGet(a, -1) == 0);
    assert(arrayListStringItemGet(a, NULL) == 0);


    s = "Ciao!";

    assert(arrayListStringItemSet(a, 1, s) != 0);
//    printf("%s\n", arrayListStringItemGet(a, 4)->value);
    assert(strcmp(arrayListStringItemGet(a, 1)->value, "ciao") != 0);
    assert(strcmp(arrayListStringItemGet(a, 1)->value, s) == 0);




    struct arrayListString * a2 = newArrayListStringItemString("Another struct!");
    arrayListStringItemPush(a2->value, a);
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
    printf("SS:\n");
    printArrayListString(splittedStrings);



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