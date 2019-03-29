//
// Created by Piermarco Barbè on 2019-03-06.
//

#ifndef SYSTEMSPROGRAMMING_STRINGSUTILS_H
#define SYSTEMSPROGRAMMING_STRINGSUTILS_H

char * appendChar(char * s, char c);
char * getSubstringCharPCharP(char * s, char * begin, char * end);
char * getSubstringCharP(char * s, char * in);
char * replaceString(char * s, char * out, char * in);
char * replaceChar(char * s, char out, char in);
char * flipLine(char * s);
char * removeChar(char * s, char c);
char * removeFirstChar(char * s, char c);
char * getSubstringIntInt(char * s, int begin, int end);
int getCharFromString(char * s, char c);
int deleteDigits(char * s);
int replaceStringInPlace(char * s, char * r);
int removeCharInPlace(char * s, char c);


#endif //SYSTEMSPROGRAMMING_STRINGSUTILS_H
