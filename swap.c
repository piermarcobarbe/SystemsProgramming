//
// Created by Piermarco Barbè on 2019-02-27.
//

#include <stdio.h>

void swap(int * a, int * b){

    int x = *a;

    printf("x:%d, a:%d, b:%d\n", x, *a, *b);

    *a = *b;

    printf("x:%d, a:%d, b:%d\n", x, *a, *b);

    *b = x;
    printf("x:%d, a:%d, b:%d\n", x, *a, *b);


}

int main(){

    int a = 2;
    int b = 4;

    printf("a: %d, b: %d\n", a, b);

    swap(&a, &b);

    printf("a: %d, b: %d\n", a, b);

    return 0;

}
