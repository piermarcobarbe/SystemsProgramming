//
// Created by Piermarco Barbè on 2019-04-05.
//

struct my_object;

struct my_object * my_object_new();

struct my_object * my_object_less_than(struct my_object * x, struct my_object * y);

struct my_object * A[100];


void sort(struct my_object * begin, struct my_object * end, int (*compare)(struct my_object * x, struct my_object * y)){

    for(struct my_object * p = begin; p != end; ++p){



    }

}

int main(){

    for(int i = 0; i < 100; i++){
        A[i] = my_object_new();
    }

    sort(A, A+100, my_object_less_than);

}