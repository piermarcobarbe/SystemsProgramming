//
// Created by Piermarco Barbè on 2019-03-27.
//


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

#include "../trie.h"
#include "../arrayListString.h"
#include "../readFile.h"
#include "../stringsUtils.h"

int main(){
    struct arrayListString * f = readFile("../txts/test4.txt");

    arrayListStringItemPop(f);
    arrayListStringItemPop(f);

    f = arrayListStringItemPop(f);

    struct arrayListString * splitted = arrayListStringSplit(f, " ");


//    arrayListStringItemPop(splitted);
//    splitted = arrayListStringItemPop(splitted);

    printArrayListString(splitted);

//    printf("%d\n", arrayListStringSize(splitted));

    struct Trie * t = newTrie('/');
    putAside(t, newTrie('D'));
    t = t->next;

    while (splitted){
        insertString(t, splitted->value);
        splitted = splitted->next;
    }

//    insertString(t, "ciao");
//    insertString(t, "come");
//    insertString(t, "stai");
//    insertString(t, "caro");
//    insertString(t, "carotide");
//    insertString(t, "amico");

    navigateTrie(t);

    return 0;
}