//
// Created by Piermarco Barbè on 2019-04-05.
//

#include <stdio.h>

int x_7(){
        return 7;
};

int x_10(){
        return 10;
};

int main(){
//    f is a pointer to a function that returns int and takes no parameters;
    int (*f)();

//    f points to `x_10`;
    f = x_10;

//    f aka x_10 is executed; its value goes in r.
    int r = f();

//    display r;
    printf("%d\n", r);

    return 0;

}