//
// Created by Piermarco Barbè on 2019-02-23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"



void printTrie(struct Trie * t){

//    printf("%lu\n", strlen("s"));

    if(t == 0){
        printf("Null ptr");
        return;
    }


        if(t->up){

            printf("     %c  \n", t->up->c);
            printf("     |\n");

        } else {
            printf("     null  \n");
            printf("     |\n");

        }


    if(t->previous && t->next){

        printf("%c ->|%c", t->previous->c, t->c);
        if(t->isAKey == 1){
            printf("*");
        }
        printf("|-> %c\n", t->next->c);



    } else {
        printf("null -> %c -> null\n", t->c);
    }

    if(t->down){
        printf("     |\n");
        printf("     %c  \n", t->down->c);
    }




}

struct Trie * goToTop(struct Trie * t){
    while(t != t->up){
        t = t->up;
    }
    return t;
}

struct Trie * goToBottom(struct Trie * t){
    while (t != t->down){
        t = t->down;
    }
    return t;
}


void printTrieRecursiveV(struct Trie * t, int printComplete){
    if(printComplete){
        printf("    |%c|  \n", t->up->c);
        printf("     |\n");
    }

    if(t->previous && t->next){
        printf("%c ->|%c|-> %c\n", t->previous->c, t->c, t->next->c);
    } else {
        printf("null -> |%c| -> null\n", t->c);
    }

    if(t != t->down){
        printf("     |\n");
        printTrieRecursiveV(t->down, 0);
    } else {
        printf("     |\n");
        printf("    |%c|  \n", t->down->c);
    }

}

void printTrieRecursiveH(struct Trie * t, int printComplete){
    if(printComplete){
        printf("%c -> %c", t->previous->c, t->c);

    } else {
        printf(" -> %c", t->c);
    }

    if(t != t->next){
        printTrieRecursiveH(t->next, 0);
    }
    printf("\n");
}


void printVertical(struct Trie * t){
    printf("printVertical:\n");
    struct Trie * top = goToTop(t);
    printTrieRecursiveV(top, 1);


}


void printHorizontal(struct Trie * t){
    printTrieRecursiveH(t, 1);
}


// For vertical linking
int append(Trie * t, Trie * r){
    t->down = r;
    r->up = t;

    r->previous = t->previous;
    return 0;
}

// For horizontal linking.
int putAside(Trie * t, Trie * r){
    t->next = r;
    r->previous = t;
    return 0;
}


struct Trie * newTrie(char c){
//    printf("newTrie: %c\n", c);
    struct Trie * t = malloc(sizeof(struct Trie));
    t->c = c;
    t->previous = t;
    t->next = t;
    t->up = t;
    t->down = t;
//    printf("Created with char '%c', code %d.\n", c, c);
//    printTrie(t);
    return t;
}

Trie * findInTrie(char c, struct Trie * t){
    while(t != t->next && t->c != c){
        t = t->next;
    }

    if(t->c != c){
        // Not found...
        return 0;
    }

    // Found!
    return t;


}


int existsInVerticalLayer(struct Trie * t, char c){
//    printf("existsInVerticalLayer: '%c', '%c'\n", t->c, c);
    struct Trie * begin = goToTop(t);
    struct Trie * end = goToBottom(t);
    struct Trie * it = begin;
    do {
        if(it->c == c)
            return 1;
        it = it->down;
    } while (it != end);
    return 0;
}

int insertString(struct Trie * t, char * s){

    printf("Trie: '%c', s: %s\n", t->c, s);
    if(t == NULL){
        return 0;
    }

    if(strcmp(s, "") == 0){
        t->previous->isAKey = 1;
        return 0;
    }

    if(t == t->next){
        printf("t == t->next, ");

        if(*s == t->c){
            printf("*s == t->c\n");
            putAside(t, newTrie(*(s+1)));
            insertString(t->next, s+1);
        } else {
            printf("*s != t->c\n");
            append(t, newTrie(*s));
            insertString(t->down, s);
        }

    } else {
        printf("t != t->next, ");
        if(*s == t->c){
            printf("*s == t->c, ");
            insertString(t->next, s+1);
        } else {
            printf("*s != t->c, ");
            if(t != t->down){
                printf("t != t->down\n");
                insertString(t->down, s);
            } else {
                printf("t == t->down\n");
                append(t, newTrie(*s));
                insertString(t->down, s);
            }
        }
    }



    return 0;
}

void navigateTrie(struct Trie * t){
    char c;
    system("clear");
    printTrie(t);
    c = getchar();
    while(c != EOF){
        printf("\n");
//        printf("%c\n", c);
        system("clear");
        printTrie(t);
        c = getchar(); // skip the [
//            printf("%c\n", c);
        c = getchar();
//            printf("%c\n", c);
        switch(c) { // the real value
            case 'A':
                // code for arrow up
                if(t != t->up) t = t->up;
                break;
            case 'B':
                // code for arrow down
                if(t != t->down) t = t->down;
                break;
            case 'C':
                // code for arrow right
                if(t != t->next) t = t->next;
                break;
            case 'D':
                // code for arrow left
                if(t != t->previous) t = t->previous;
                break;
        }
    }

}

//
//int main(int argc, char * argv[]){
//
//    struct Trie * t = newTrie('/');
//    struct Trie * root = t;
//
//    putAside(t, newTrie('c'));
//
//    t = t->next;
//
//
//
//
//
//}
