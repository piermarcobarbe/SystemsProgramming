//
// Created by Piermarco Barbè on 2019-03-27.
//

#ifndef SYSTEMSPROGRAMMING_TRIE_H
#define SYSTEMSPROGRAMMING_TRIE_H


typedef struct Trie {
    int isAKey;
    char c;
    struct Trie * next;
    struct Trie * previous;
    struct Trie * up;
    struct Trie * down;
} Trie;


void printTrie(struct Trie * t);
struct Trie * goToTop(struct Trie * t);
struct Trie * goToBottom(struct Trie * t);
void printTrieRecursiveV(struct Trie * t, int printComplete);
void printTrieRecursiveH(struct Trie * t, int printComplete);
void printVertical(struct Trie * t);
void printHorizontal(struct Trie * t);
int append(Trie * t, Trie * r);
int putAside(Trie * t, Trie * r);
struct Trie * newTrie(char c);
Trie * findInTrie(char c, struct Trie * t);
int existsInVerticalLayer(struct Trie * t, char c);
int insertString(struct Trie * t, char * s);
void navigateTrie(struct Trie * t);




#endif //SYSTEMSPROGRAMMING_TRIE_H
