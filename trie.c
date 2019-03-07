//
// Created by Piermarco Barbè on 2019-02-23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Trie {
    int isAKey;
    char c;
    struct Trie * next;
    struct Trie * previous;
    struct Trie * up;
    struct Trie * down;
} Trie;


int main(int argc, char * argv[]){
    Trie * t = malloc(sizeof(struct Trie));
    t->c = 'c';
//    printf("%d\n", t->isAKey);
//    printf("%c\n", t->c);


    Trie * r = findInTrie('c', t);

    return 0;
}


// For vertical linking
int append(Trie * t, Trie * r){
    t->down = r;
    r->up = t;
    return 0;
}

// For horizontal linking.
int putAside(Trie * t, Trie * r){
    t->next = r;
    r->previous = t;
    return 0;
}


int newTrie(struct Trie * t){
    t->previous = t;
    t->next = t;
    t->up = t;
    t->down = t;
    return 0;
}

Trie * findInTrie(char c, struct Trie * t){
    while(t != t->next && t->c != c){
        t = t->next;
    }

    if(t->c != c){
        // Not found...
        return nullptr;
    }

    // Found!
    return t;


}

int createBranch(char * s, struct Trie * t){
    for(int i = 0; i < strlen(s); i++){
        if(findInTrie(s[i], t)){
            // if char exists yet
            t = t->down;
        } else{
            t = t->next;
        }
    }
    return 0;
}

void printTrie(struct Trie * t){

    if(t == 0){
        printf("Null ptr");
        return;
    }

    printf("      %c  ", t->up->c);
    printf("       |");
    printf("%c -> %c -> %c", t->previous->c, t->c, t->next->c);

}