//
// Created by Piermarco Barbè on 2019-02-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"
#include "arrayListString.h"
#include "stringsUtils.h"


int main(int argc, char * argv[]){

    struct arrayListString * a = readFile(argv[1]);

    a = arrayListStringApplyCharP(&flipLine, a);

    a = arrayListStringApplyCharPChar(&removeChar, a, '\n');

//    a = arrayListStringApplyCharP(&flipLine, a);


//    printArrayListStringVerbose(a);

    a = arrayListStringRemoveIfMatching("", a);

//    printArrayListStringVerbose(a);
//    printArrayListStringVerbose(a);

    printArrayListStringVerbose(a);

}