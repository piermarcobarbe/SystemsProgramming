//
// Created by Ardil on 29.03.19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringsUtils.h"
#include "arrayListString.h"
#include "readFile.h"

struct date{
    int day;
    int month;
    int year;
};

struct person {
    char name[40];
    char surname[40];
    char sex[10];
    int married;
    struct person * married_to;
    struct date birthday;
    struct  person * mother;
    struct  person * father;
    struct person * next;
};

void printName(struct person * p){
    if (!p){
        printf("NULL");
        return;
    }
    printf("%s %s", p->name, p->surname);
}

void printPerson(struct person * p){

    printName(p);
    printf(":");
    printName(p->mother);
    printf(",");
    printName(p->father);
    printf("\n");

}

struct date * newDate(int d, int m, int y){

    if(!d || !m || !y){
        printf("Missing params for newDate.\n");
        return 0;
    }

    struct date * newDate = malloc(sizeof(struct date));
    newDate->day = d;
    newDate->month = m;
    newDate->year =y;
    return newDate;
}


struct date * newDateFromString(char * s){
    int d, m, y;
    long l;

    d = atoi(getSubstringIntInt(s, 1, 3));

    m  =atoi(getSubstringIntInt(s, 4, 6));

    y = atoi(getSubstringIntInt(s, 7, 10));

    printf("%d/", d);

    printf("%d/", m);
    printf("%d\n", y);


    return newDate(d, m, y);

}

struct person * newPerson(char * name, char * surname, struct date * d, struct person * mother, struct person * father){
    if(!name || !surname){
        printf("Missing params for newPerson.\n");
        return 0;
    }

    struct person * newPerson = malloc(sizeof(struct person));
    strcpy(newPerson->name, name);
    strcpy(newPerson->surname, surname);

    newPerson->father = father;
    newPerson->mother = mother;

    if(d)
        newPerson->birthday = *d;

    return newPerson;

}



struct person * newPersonFromString(char * s){

    char *n1, *n2;


    n1 = malloc(strlen(s));
    n2 = malloc(strlen(s));


//    printf("s: %s\n",s);


    strncpy(n1, s,  getSubstringCharP(s,  " ") - s);

//    printf("n1: %s\n", n1);
//    printf("s: %s\n", s);



    strcpy(n2, getSubstringCharP(s, "("));

//    printf("n1: %s\n", n1);
//    printf("n2: %s\n", n2);

    return newPerson(n1, n2, 0, 0, 0);

}

struct person * newPersonFromCompleteString(char * s){
    char * personName, *personSurname, *motherName, *motherSurname, *fatherName, *fatherSurname;

    personName = malloc(getSubstringCharP(s, " ") -s + 1);
    strncpy(personName, s, getSubstringCharP(s, " ") -s);
    personName[getSubstringCharP(s, " ") -s + 1] = 0;
//    printf("Person name: %s\n", personName);

    s = getSubstringCharP(s, " ");
    s++;

    personSurname = malloc(getSubstringCharP(s, "(") -s + 1);
    strncpy(personSurname, s, getSubstringCharP(s, "(") -s);
    personSurname[getSubstringCharP(s, "(") -s + 1] = 0;

//    printf("Person surname: %s\n", personSurname);

    s = getSubstringCharP(s, "(");

    s = s+3;

    fatherName = malloc(getSubstringCharP(s, " ") - s + 1);
    strncpy(fatherName, s,getSubstringCharP(s, " ") - s );
    fatherName[getSubstringCharP(s, " ") - s +1] = 0;
    s = getSubstringCharP(s, " ");
    s++;

//    printf("Father Name: %s\n", fatherName);


    fatherSurname = malloc(getSubstringCharP(s, ",") -s + 1);
    strncpy(fatherSurname, s, getSubstringCharP(s, ",") -s);
    fatherSurname[getSubstringCharP(s, ",") -s +1] = 0;

//    printf("Father surname: %s\n", fatherSurname);

    s = getSubstringCharP(s, ",");
    s+=3;

    motherName = malloc(getSubstringCharP(s, " ") -s + 1);
    strncpy(motherName, s, getSubstringCharP(s, " ") -s);
    motherName[getSubstringCharP(s, " ") -s +1] = 0;

//    printf("Mother name: %s\n", motherName);

    s = getSubstringCharP(s, " ");
    s++;

    motherSurname = malloc(getSubstringCharP(s, ")") -s+1);
    strncpy(motherSurname, s, getSubstringCharP(s, ")") -s);
    motherSurname[getSubstringCharP(s, ")") - s + 1] = 0;


    struct person * p = newPerson(personName, personSurname, 0, newPerson(motherName, motherSurname, 0,0,0), newPerson(fatherName, fatherSurname, 0, 0, 0));
    return p;

}


struct person * findPerson( struct person * root, struct person * target){

    if(!root){
//        printf("Failed.\n");
        return 0;
    }

//    printf("Looking for ");
//    printName(target);

//    printf(". Comparing with");
//    printPerson(root);




    if(strcmp(root->name, target->name) == 0){
        if(strcmp(root->surname, target->surname) == 0){
//            printf("Found ");
//            printName(root);
//            printf("\n");
            return root;
        }
    }

    return findPerson(root->next, target);

}

void linkPeople(struct person * head, struct person * root){

//    printf("Trying to link ");
//    printPerson(head);
//    printf("\n");

    struct person * maybeMother = findPerson(root, head->mother);
    struct person * maybeFather = findPerson(root, head->father);


    if(maybeFather && maybeMother){

        if(head->surname != maybeFather->surname){

            head->father = maybeMother;

//            printf("Now ");
//            printName(maybeMother);
//            printf("  is ");
//            printName(head);
//            printf("'s father.\n" );

            linkPeople(maybeMother, root);

            head->mother = maybeFather;

//            printf("Now ");
//            printName(maybeFather);
//            printf("  is ");
//            printName(head);
//            printf("'s mother.\n" );

            linkPeople(maybeFather, root);

        } else {

            head->mother = maybeMother;
//            printf("Now ");
//            printName(maybeMother);
//            printf("  is ");
//            printName(head);
//            printf("'s mother.\n" );
            linkPeople(maybeMother, root);

            head->father = maybeFather;

//            printf("Now ");
//            printName(maybeFather);
//            printf("  is ");
//            printName(head);
//            printf("'s father.\n" );

            linkPeople(maybeFather, root);
        }

//        printf("Linked ");
//        printName(head);
//        printf("\n");
    }




}

void findAncestors(struct person * p){
    if(!p){
        return;
    }
    printPerson(p);
    findAncestors(p->father);
    findAncestors(p->mother);
}

int main(int argc, char **argv){

    struct arrayListString * lines = readFileNoNewLines(argv[1]);
//    printArrayListString(lines);
    int k = 1;

//    printArrayListString(lines);


    struct person *p, *head, *root, *last;

    while(lines){
        last = p;
        p = newPersonFromCompleteString(lines->value);
        printPerson(p);

        if(! head){
            head = p;
            root = p;
            last = p;
        }

        last->next = p;


        lines = lines->next;
        k++;
        if(k > 2000){
            break;
        }
    }

    printf("----\n");



//

    while(head){
        linkPeople(head, root);
        head = head->next;
    }

    head = root;
//
//

    findAncestors(head);

    char n[50], s[50];
    struct person * i;

    printf("Enter name: ");
    scanf("%s %s", n, s);
    printf("Looking for '%s %s'\n\n", n, s);


    while(1){

        i = newPerson(n, s, 0, 0, 0);
//        printPerson(i);
        i = findPerson(root, i);
        findAncestors(i);

        printf("Enter name: ");
        scanf("%s %s", n, s);
        printf("Looking for '%s %s'\n\n", n, s);

    }

//    query(head);
}