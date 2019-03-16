//
// Created by Piermarco Barbè on 2019-03-15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringsUtils.h"


int main(){
    char * _ = "12345abc0123def1234ghi";
    char * s = malloc(strlen(_));

    strcpy(s, _);

    printf("%s\n", s);
    deleteDigits(s);

    printf("%s\n", s);
}