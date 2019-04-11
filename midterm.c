//
// Created by Piermarco Barbè on 2019-04-01.
//

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct partecipant{
    char * name;
    float value;
    struct partecipant * next;
} partecipant;

typedef struct expense{
    char * description;
    struct partecipant * partecipants;
    struct partecipant * payer;
    struct expense * next;
} expense;

typedef struct credit {
    struct partecipant * receiver;
    struct partecipant * payer;
    float v;
    struct credit * next;
} credit;



struct credit * findCredit(struct partecipant * p, struct credit * root){
    if(!root){
        return 0;
    }

    if(strcmp(p->name, root->receiver->name) == 0){
        return root;
    }

    return findCredit(p, root->next);
}

struct partecipant * newPartecipant(char * name, float v){
    struct partecipant * partecipant1 = malloc(sizeof(struct partecipant));
    partecipant1->name = malloc(strlen(name));
    strcpy(partecipant1->name, name);
    partecipant1->value = v;

    partecipant1->next = 0;

//    printf("Created %s:%f\n", partecipant1->name, partecipant1->value);

    return partecipant1;
}

struct partecipant * newPartecipantFromExisting(struct partecipant * e){
    if(!e){
        return 0;
    }
    return newPartecipant(e->name, e->value);
}


struct expense * newExpense(char * descr, struct partecipant * partecipants, struct partecipant * payer){

    struct expense * e = malloc(sizeof(struct expense));
    e->description = malloc(strlen(descr));
    strcpy(e->description, descr);

//    printf("%s\n", e->description);

    e->payer = newPartecipantFromExisting(payer);

//    printf("%s\n", e->payer->name);

    struct partecipant * first, *last;


    e->partecipants = partecipants;

    e->next = 0;

    return e;

}


void printList(struct partecipant * p){
//    printf("printList\n");
    while(p){
        printf("%s - %f\n", p->name, p->value);
        p = p->next;
    }
}

struct credit * newCredit(struct partecipant * receiver, struct partecipant * payer, float v){
//    printf("newCredit\n");
    struct credit * r = malloc(sizeof(struct credit));
    r->receiver = newPartecipantFromExisting(receiver);
    r->payer = newPartecipantFromExisting(payer);
    r->next = 0;
    r->v = v;

    printf("%s: %f -> %s\n", r->payer->name, r->v, r->receiver->name );

    return r;
}

void appendCredit(struct credit * newCredit, struct credit * creditList ){
    if(!creditList){
        creditList = newCredit;
        return;
    }
    while(creditList->next){
        creditList = creditList->next;
    }

    creditList->next = newCredit;
}

void printCredit(struct credit * creditList ){
    printf("%s owns %f to %s\n", creditList->payer->name, creditList->v, creditList->receiver->name);
}

void printCredits(struct credit * creditList ){

//    printf("printCredits\n");

    while (creditList){
        printCredit(creditList);
        creditList = creditList->next;
    }
    printf("---------------\n");

}

struct credit * printDebt(struct expense * e, struct credit * creditList){
    float tot = 0.0;
    float nPartecipants = 0.0;

    struct partecipant * head = e->partecipants;

    printList(e->partecipants);


    while(e->partecipants){

        nPartecipants = nPartecipants + 1.0;
        tot += e->partecipants->value;
        e->partecipants = e->partecipants->next;

    }


    float equalExpense = tot / nPartecipants;

    printf("EE:%f\n", equalExpense);

    e->partecipants = head;


    while(e->partecipants) {
        if (strcmp(e->partecipants->name, e->payer->name) != 0) {

            appendCredit(newCredit(e->payer, e->partecipants, equalExpense - e->partecipants->value), creditList);


        }
//        else {
//            appendCredit(newCredit(e->payer, e->partecipants,  e->partecipants->value - equalExpense), creditList);
//        }
        e->partecipants = e->partecipants->next;
    }


    printf("BR:");
    printCredits(creditList);

    return creditList;

}

struct credit * creditFromExisting(struct credit * existing){
    return newCredit(existing->receiver, existing->payer, existing->v);
}

void cleanList(struct credit * c){

    printf("Clean.\n");

    struct credit * start = c;
    struct credit * r = 0;

    while(c){

        if(c->v > 0.0){
            r = creditFromExisting(c);
            r = r->next;
        }
        c = c->next;

    }

    c = r;
    printCredits(c);



}

int main(){


    struct partecipant * p = newPartecipant("Pier", 0.0);
    struct partecipant * m = newPartecipant("Marco", 0.0);
    struct partecipant * l = newPartecipant("Leo", 10.0);

    struct credit * credit1 = newCredit(p, m, 0.0);
//    credit1 = 0;

    p->next = m;
    m->next = l;

    struct expense * e1 = newExpense("New expense", p, newPartecipantFromExisting(l));

    p = newPartecipant("Pier", 10.0);
    m = newPartecipant("Marco", 0.0);
    l = newPartecipant("Leo", 0);
//
    p->next = m;
    m->next = l;
//
    struct expense * e2 = newExpense("New expense 2", p, newPartecipantFromExisting(p));

//    printList(e1->partecipants);


    p = newPartecipant("Pier", 0.0);
    m = newPartecipant("Marco", 10.0);
    l = newPartecipant("Leo", 0);

    p->next = m;
    m->next = l;

    struct expense * e3 = newExpense("New expense 3", p, newPartecipantFromExisting(m));



    struct credit * c = printDebt(e1, credit1);

//    cleanList(credit1);

    struct credit * c2 = printDebt(e2, credit1);
//
//    cleanList(credit1);
//
    struct credit * c3 = printDebt(e3, credit1);
//
//    cleanList(credit1);



    printCredits(credit1);
//    cleanList(credit1);




}