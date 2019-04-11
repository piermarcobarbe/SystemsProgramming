//
// Created by Piermarco Barbè on 2019-03-18.
//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

#include "../stringsUtils.h"


int main(){

    char * s = "Initial String.";
    s = appendChar(s, '.');
    char * expected = "Initial String..";
    assert(strcmp(expected, s) == 0);

    s = "Initial String.";
    s = appendChar(s, '\0');
    expected = "Initial String.";
    assert(strcmp(s, expected) == 0);



    s = "abcd";
    char * r = getSubstringCharPCharP(s, "ab", "cd");
    assert(strcmp(r, s) == 0);

    r = getSubstringCharPCharP(s, "b", "c");
    assert(strcmp(r, "bc") == 0);

    r = getSubstringCharPCharP(s, "a", "c");
    assert(strcmp(r, "abc") == 0);

    r = getSubstringCharPCharP(s, "a", "d");
    assert(strcmp(r, s) == 0);

    r = getSubstringCharPCharP(s, "d", "a");
    assert(r == NULL);

    r = getSubstringCharPCharP(s, "a", "e");
    assert(r == NULL);

    r = getSubstringCharPCharP(s, "e", "a");
    assert(r == NULL);




    s = "abcd";
    r = getSubstringCharP(s, "ab");
    assert(strcmp(s, r) == 0);

    r = getSubstringCharP(s, "bc");
    assert(strcmp(r, "bcd") == 0);

    r = getSubstringCharP(s, "b");
    assert(strcmp(r, "bcd") == 0);

    r = getSubstringCharP(s, "z");
    assert(r == NULL);

    r = getSubstringCharP(s, "d");
    assert(strcmp(r, "d") == 0);


    s = "This is a string with which i am testing replaceString.";
    r = replaceString(s, " ", "-");
    assert(strcmp(r, "This-is-a-string-with-which-i-am-testing-replaceString.") == 0);

    r = replaceString(s, "a", " ");
    assert(strcmp(r, "This is   string with which i  m testing repl ceString.") == 0);

    r = replaceString(s, "This", "That");
//    printf("%s\n%d\n", strcmp(r, "That is a string with which i am testing replaceString."), r);
    assert(strcmp(r, "That is a string with which i am testing replaceString.") == 0);

    r = replaceString(s, s, "");
    assert(strcmp(r, "") == 0);

    r = replaceString(s, s, s);
    assert(strcmp(s,r) == 0);




    s = "abcdef";
    r = flipLine(s);
//    printf("r:%s\n", r);
    assert(strcmp(r, "fedcba") == 0);

    s = "";
    r = flipLine(s);
    assert(strcmp(r, "") == 0);

    s = "abc\ndef";
    r = flipLine(s);
    assert(strcmp(r, "fed\ncba") == 0);

    s = "abc\0def";
    r = flipLine(s);
    assert(strcmp(r, "cba") == 0);





    s = "abcdef";
    r = removeChar(s, 'a');
    assert(strcmp(r, "bcdef") == 0);

    s = "abcdef";
    r = removeChar(s, 'f');
    assert(strcmp(r, "abcde") == 0);


    s = "a";
    r = removeChar(s, 'a');
    assert(strcmp(r, "") == 0);

    s = "abc\ndef";
    r = removeChar(s, '\n');
    assert(strcmp(r, "abcdef") == 0);


    s = "abcdef\0g";
    r = removeChar(s, '\0');
    assert(strcmp(s, "abcdef") == 0);




    s = "abcdef";
    r = removeFirstChar(s, 'a');
    assert(strcmp(r, "bcdef") == 0);

    s = "abcabc";
    r = removeFirstChar(s, 'a');
    assert(strcmp(r, "bcabc") == 0);

    s = "12345678";
    r = removeFirstChar(s,'5');
    assert(strcmp(r, "1234678") == 0);




    s = "123456";
    r = getSubstringIntInt(s, 1, 5);
    assert(strcmp(r, "12345") == 0);

    r = getSubstringIntInt(s, 2, 1);
    assert(r == NULL);

    r = getSubstringIntInt(s, -1, 1);
    assert(r == NULL);

    r = getSubstringIntInt(s, 1, -1);
    assert(r == NULL);

    r = getSubstringIntInt(s, 3, 3);
    assert(strcmp(r, "3") == 0);



    s = "111222333444555";
    int res = 0;
    res = getCharFromString(s, '1');
    assert(res == 0);

    res = getCharFromString(s, '3');
    assert(res == 6);

    res = getCharFromString(s, '5');
    assert(res == 12);

    res = getCharFromString(s, '0');
    assert(res == -1);


    s = "111222333444555";
    char buf[50];
    strcpy(buf, s);
    res = deleteDigits(buf);
    assert(res == 0);
    assert(strcmp(buf, "") == 0);


    s = "123abc123def123ghi";
    strcpy(buf, s);
    res = deleteDigits(buf);
    assert(res == 0);
    assert(strcmp(buf, "abcdefghi") == 0);






    s = "123abc123def123ghi";
    strcpy(buf, s);
    res = removeCharInPlace(buf, '1');
//    printf("%d\n", res);
//    printf("%s\n", buf);
    assert(res == 3);
    assert(strcmp(buf, "23abc23def23ghi") == 0);


    res = removeCharInPlace(buf, '2');
    assert(res == 3);
    assert(strcmp(buf, "3abc3def3ghi") == 0);



    return 0;
}