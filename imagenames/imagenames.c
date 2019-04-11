//
// Created by Piermarco Barbè on 2019-04-03.
//Since i am using libraries written by myself, compiling the midterm can be done with:
//cc imagenames.c arrayListString.c stringsUtils.c readFile.c -o imagenames
//From here, imagenames can be tested.

//

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct arrayListString {
    long long int id;
    char * value;
    struct arrayListString * next;
} arrayListString;




char * getSubstringIntInt(char * s, int begin, int end){

//    printf("%s - %d - %d\n", s, begin, end);

    if(end < begin){
        printf("Error: end < begin: %d < %d.\n", end, begin);

        return NULL;
    }

    if(s == NULL){
        printf("Error: input string is NULL.\n");
        return NULL;
    }

    if(strlen(s) < end){
        printf("Error: end greater than strlen(s) : %d > %lu.\n", end, strlen(s));
        return NULL;
    }


    if(begin <= 0){
        printf("Error: begin must be positive, it was %d.\n", begin);
        return NULL;
    }

    char * r = malloc(end-begin+2);

    memcpy(r, s+begin-1, end-begin+1);

//    printf("Returning %s\n", r);

    r[end-begin+2] = '\0';

    return r;


}


char * appendChar(char * s, char c){
//    printf("%lu\n", strlen(s)+1);
    char * r = malloc(strlen(s)+1);
//    printf("s:%s", s);
//    printf("r:'%s'", r);
    strcpy(r, s);

//    printf("r:'%s'", r);

    r[strlen(s)] = c;
//    printf("r:'%s'", r);
    r[strlen(s)+1] = '\0';
//    printf("r:'%s'", r);
    return r;
}


char * getSubstringCharP(char * s, char * in){

//    printf("%s - %s\n", s, in);

    int i_s = 0;
    int i_in = 0;

    while(i_s <= strlen(s)){
//        printf("[%lu]%s\n", strlen(s+i_s), s+i_s);

        while(*(s + i_s) == *(in + i_in) && i_in < strlen(in) && i_s < strlen(s)){

//            printf("[%d]'%c'|[%d]'%c'\n", i_s, *(s + i_s),i_in, *(in + i_in));



            i_s++;
            i_in++;

        }

        if(i_in == strlen(in)){
//            printf("R:%s\n", s + i_s);
            return s + i_s - i_in;
        } else {
            i_in = 0;
        }



        i_s++;

    }

    return NULL;

}


//
// Created by Piermarco Barbè on 2019-02-26.

int arrayListStringSize(struct arrayListString * a){
    int r = 1;

//    if(a->value == 0) return 0;

    while(a->next != 0){
        r++;
        a = a->next;
    }
    return r;
}

struct arrayListString * newArrayListStringItemVoid(){
    struct arrayListString * _new = malloc(sizeof(struct arrayListString));
    _new->value = 0;
    _new->next = 0;
    return _new;
}

void printArrayListStringItemVerbose(struct arrayListString * a){
    if(a == NULL){
        printf("No arrayListString object provided.\n");
        return;
    }



    if(a->next != NULL){
        printf("[%lld] => '%s' | next => [%lld]\n", a->id, a->value, a->next->id);
    } else {
        printf("[%lld] => '%s' | next => [NULL]\n", a->id, a->value);
    }

}

void printArrayListStringItem(struct arrayListString * a){
    if(a == NULL){
        printf("No arrayListString object provided.\n");
        return;
    }



    if(a->next != NULL){
        if(strlen(a->value) >= 50){
            printf("'%s...', \n", getSubstringIntInt(a->value, 1, 50));
        } else {
            printf("'%s', \n", a->value);
        }
    } else {
        if(strlen(a->value) >= 50){
            printf("'%s...' \n", getSubstringIntInt(a->value, 1, 50));
        } else {
            printf("'%s' \n", a->value);
        }
    }

}


struct arrayListString * newArrayListStringItemInt(int maxStringLength){

//    srand(time(NULL));
//    printf("newArrayListStringItemInt %d\n", maxStringLength);


    struct arrayListString * r = malloc(sizeof(struct arrayListString));

    r->value = malloc(maxStringLength);
    r->next = 0;
    r->id = rand();


//    printf("Creating: ");
//    printArrayListStringItem(r);


    return r;


}

struct arrayListString * newArrayListStringItemString(char * s){

//    printf("newArrayListStringItemString: '%s'\n", s);

    struct arrayListString * r = newArrayListStringItemInt(strlen(s)+1);
    strcpy(r->value, s);

    return r;

}

void printArrayListStringVerbose(struct arrayListString * a){

    printf("\n\n");

    if(a == NULL){
        printf("No arrayListString provided.\n");
    }


    while(a != NULL){
        printArrayListStringItemVerbose(a);
        a = a->next;
    }

    printf("\n\n");


}

void printArrayListString(struct arrayListString * a){

    printf("\n\n");

    if(a == NULL){
        printf("No arrayListString provided.\n");
    }

    printf("[\n");

    while(a != NULL){
        printArrayListStringItem(a);
        a = a->next;
    }
    printf("\n]\n");

    printf("\n\n");


}

int arrayListStringItemPush(char * s, arrayListString * a){

//    printf("Pushing.\n");

    if(a == NULL){
        printf("No arrayListString provided.\n");
        return -1;
    }

    if(s == NULL){
        printf("No String provided.\n");
        return -2;
    }

    int k = 1;

    if(a->value == NULL){
        a->value = malloc(strlen(s)+1);
        strcpy(a->value, s);
        a->value[strlen(s)+1] = 0;
        return k;
    }

    struct arrayListString * prev;

    while(a->next != NULL){

//        printf("a: ");
//        printArrayListStringItem(a);
        prev = a;
        a = a->next;
        k++;

    }
    k++;

//    printf("Last is %llu\n", a->id);


    struct arrayListString * n = newArrayListStringItemString(s);
//    printf("HERE\n");

//    printf("New obj: \n");

//    printArrayListStringItem(n);

    a->next = n;
    n->next = NULL;
//    printf("%d\n", k);
    return k;
}

struct arrayListString * arrayListStringMatch(struct arrayListString * a, char * t){

    struct arrayListString * last = newArrayListStringItemVoid();
    struct arrayListString * ret = last;


    while(a != NULL) {

        if (strstr(a->value, t)) {
            arrayListStringItemPush(a->value, last);
        }
//        else {
//            printf("%s not matching with %s\n", a->value, t);
//        }
        a = a->next;
    }


    return ret;

}

struct arrayListString * newArrayListString(int size, int maxStringLen){


    struct arrayListString * last = newArrayListStringItemInt(maxStringLen);
    struct arrayListString * head = last;
    struct arrayListString * lN;
    int k = 1;

    while(k < size){
        lN = newArrayListStringItemInt(maxStringLen);

        last->next = lN;

//        printf("%llu -> %llu\n", last->id, lN->id);
        last = last->next;

        k++;
    }
    last->next = NULL;

//    printf("Last is ");
//    printArrayListStringItem(last);

//    free(last);


    return head;


}


struct arrayListString * arrayListStringItemGet(struct arrayListString * a, int pos){

    if(pos <= 0)
        return 0;

    int k = 1;
    while(k <= pos && a != NULL){
        a = a->next;
        k++;
    }


    if(a == NULL){
        printf("arrayListStringItemGet: OutOfBounds.\n");
        return NULL;
    }


    return a;

}
struct arrayListString * arrayListStringItemSet(struct arrayListString * a, int pos, char * s) {



    int k = 1;
    while(k <= pos && a != NULL){
        a = a->next;
        k++;
    }


    if(a == NULL){
        printf("arrayListStringItemSet: OutOfBounds.\n");
        return NULL;
    }

    free(a->value);

    a->value = malloc(strlen(s)+1);

    strcpy(a->value, s);

    return a;


}

struct arrayListString * arrayListStringItemPop(struct arrayListString * a){
    struct arrayListString * prev;
    struct arrayListString * result;

    while(a->next != NULL){
//        printf("%s\n", a->value);
        prev = a;
        a = a->next;
    }

    result = prev->next;
    prev->next = NULL;

    if(result == 0){
        return prev;
    }

    return result;

}

struct arrayListString * arrayListStringApplyCharP(char * (*function_ptr)(char *), struct arrayListString * a){

    struct arrayListString * r = a;

    while(a != NULL){

        a->value = (*function_ptr)(a->value);
        a = a->next;
    }


    return r;
}

struct arrayListString * arrayListStringApplyCharPChar(char * (*function_ptr)(char *, char), struct arrayListString * a, char charForApply){

    struct arrayListString * r = a;

    while(a != NULL){

        a->value = (*function_ptr)(a->value, charForApply);
        a = a->next;
    }


    return r;
}


struct arrayListString * arrayListStringRemoveIfMatching(char * s, struct arrayListString * a) {
    struct arrayListString * head = NULL;
    struct arrayListString * last= NULL;
//    head->next = NULL;

    while (a != NULL) {

//        printf("Checking [%llu] '%s'\n", a->id, a->value);

        if (strcmp(a->value, s) != 0) {

            if (head == NULL && last == NULL) {
                head = a;
                last = a;
            } else {
                last->next = a;
                last = last->next;
            }

        } else {
//            printf("Removing [%llu]'%s' matching with '%s'\n", a->id, a->value, s);
        }

        a = a->next;


    }

    last->next = NULL;

    return head;
}

struct arrayListString * arrayListStringSplit(struct arrayListString * a, char * sep){
    struct arrayListString * res = newArrayListStringItemVoid();
    char * s;
    int c = 1;
    int l = 1;

    while(a != 0){
        s = a->value;

//        printf("%s\n", s);
        s = getSubstringCharP(s, sep);

        while(s){

            l = c;

            c = s - a->value;

//            printf("Subs = '%s'\n", getSubstringIntInt(a->value, l, c));

            arrayListStringItemPush(appendChar(getSubstringIntInt(a->value, l, c), '\0'), res);
//            printf("%s\n", s);

            s = getSubstringCharP(s+1, sep);


            c+=strlen(sep)+1;
        }

        l = c;
        c = strlen(a->value);
//        printf("Subs = '%s'\n", getSubstringIntInt(a->value, l, c));
        arrayListStringItemPush(appendChar(getSubstringIntInt(a->value, l, c), '\0'), res);



        c = 1;
        l = 1;


        a = a->next;
    }
//    res = a;

    return res;


}

//
// Created by Piermarco Barbè on 2019-03-06.
//





char * getSubstringCharPCharP(char * s, char * begin, char * end){


    char * start = getSubstringCharP(s, begin);


    if(start == NULL){
        printf("Could not find '%s' in '%s'\n", begin, s);
        return NULL;
    }

    char * finish = getSubstringCharP(start, end);

    if(finish == NULL){
        printf("Could not find '%s' in '%s'\n", end, start);
        return NULL;
    }
//    printf("start:%s\nfinish:%s\n", start, finish);

    int count = 0;
    char * m = start;

    while(start != finish){
        count++;
        start++;
    }

    start = m;
//    printf("diff:%d\n", count);

    count += strlen(end);

    char * r = malloc(count+1);

    strncpy(r, start, count);

    r[count+1] = '\0';
//    printf("%s\n", r);

    return r;

}

char * replaceString(char * s, char * out, char * in){

//    printf("out: %lu - '%s'\n", strlen(out), out);
//    printf("in: %lu - '%s'\n", strlen(in), in);

    if(strlen(out) == 0){
        printf("Empty out parameter.\n");
        return s;
    }



    int occurrences = 0;
    char * nextOccurrence = getSubstringCharP(s, out);

//    printf("nextOccurrence:%s\n", nextOccurrence);
    while(nextOccurrence != NULL){
        occurrences++;
        nextOccurrence = getSubstringCharP(nextOccurrence+strlen(out), out);
    }



//    printf("Found %d occurrences.\nCalculating output size...", occurrences);

    int retSize = strlen(s);


//    printf("strlen(s): %d\n", retSize);

    int occurrencesDiff = strlen(in) - strlen(out);

    if(occurrences > 0){
        int delta = occurrencesDiff * occurrences;
        retSize += delta;
    }
//    retSize++;

//    printf(" %d bytes.\n", retSize);

    char * r = malloc(retSize);

    nextOccurrence = getSubstringCharP(s, out);

    int i_s = 0;
    int i_r = 0;
    int i_in = 0;

    while(nextOccurrence != NULL){
        while((s+i_s) != nextOccurrence){

//            printf("%s\n", r);
            r[i_r] = s[i_s];
            i_s++;
            i_r++;

        }

//        printf("(before)R:%s\nFound point:'%s'\n", r, s+i_s);

        while(*(in + i_in) != 0){
            r[i_r] = in[i_in];
//            printf("r:%s\n", r);
            i_in++;
            i_r++;
        }

        i_in = 0;
//        printf("(after)R:%s\n\n", r);

        i_s += strlen(out);
        nextOccurrence = getSubstringCharP(nextOccurrence+strlen(out), out);
    }

//    printf("r2: '%s'\n", r);

    while((*(s + i_s) != 0)){
        r[i_r] = s[i_s];
//        printf("R:'%s'\n", r);
        i_s++;
        i_r++;
    }

    *(r+i_r) = '\0';


    return r;
}

char * replaceChar(char * s, char out, char in){
    char * r = malloc(strlen(s));
    int count = 0;

    for(int i = 0; i < strlen(s); i++){
        if(s[i] == out){
            r[count] = in;
        } else {
            r[count] = s[i];
        }
        count ++;
    }

    return r;
}

char * flipLine(char * s){

    char * r = malloc(strlen(s)+1);

//    printf("%d.\n", strlen(s));

    for(int i = strlen(s)-1; i >=0; i--){
//        printf("[%d] %c",i, s[i]);
        r[strlen(s) - 1 - i] = s[i];
    }

    r[strlen(s)] = 0;

//    printf("\n");
//
//    printf("s:%s\n", s);
//    printf("r:%s\n", r);

    return r;
}


char * removeChar(char * s, char c){

    char * r = malloc(strlen(s));
    int count = 0;

    for(int i = 0; i < strlen(s); i++){
        if(s[i] != c){
            r[count] = s[i];
            count ++;
        }
    }

    return r;
}

char * removeFirstChar(char * s, char c){

    char * r = malloc(strlen(s));
    int count = 0;
    int skip = 0;

    for(int i = 0; i <= strlen(s); i++){
//        printf("r:%s\n", r);
        if(skip == 0){
            if(s[i] != c){
                r[count] = s[i];
                count ++;
            } else {
                skip = 1;
            }
        } else {
            r[count] = s[i];
            count ++;
        }
    }

    return r;

}


int getCharFromString(char * s, char c){

    for(int i = 0; i < strlen(s); i++){

//        printf("Comparing %c with %c\n", *(s+i), c);
        if(*(s+i) == c){
            return i;
        }
    }
    return -1;

}



int deleteDigits(char * s){

    char * r = malloc(strlen(s));
    int s_i = 0;
    int r_i = 0;

//    printf("%s\n", s);
    while(*(s+s_i) != 0){
//            printf("%c\n", *(s+s_i));
        switch (*(s+s_i)){
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
                s_i++;
                break;
            default:
                *(r+r_i) = *(s+s_i);
                s_i++;
                r_i++;

        }
    }
    *(r+r_i) = '\0';

//        printf("%s\n", r);

    strcpy(s, r);

    return 0;
}

int replaceStringInPlace(char * s, char * r){

    if(strlen(r) > strlen(s)){
        printf("replaceStringInPlace: Could not copy %lu bytes in %lu bytes.\n", strlen(r), strlen(s));
        return -1;
    }

    int i = 0;

    printf("Before: '%s'", s);

    while(s[i] != 0){
        printf("%d\n", s[i]);
        s[i] = 0;
        i++;
    }

    i = 0;

    while(r[i] != 0){
        s[i] = r[i];
        printf("Copied '%c'", s[i]);
        i++;
    }

    printf("After: '%s'\n", s);
    return i;

}

int removeCharInPlace(char * s, char c){

    if(s == NULL){
        printf("replaceCharInPlace: input string is null.\n");
        return -1;
    }

    if(!(c)){
        printf("replaceCharInPlace: input char is null.\n");
        return -2;
    }

    int i = 0;
    int j = 0;
    int occurrences = 0;
    while(s[i] != 0){
        if(s[i] == c){
            printf("%c\n", s[i]);
            occurrences++;
            j = i;
            while(s[j] != 0){
                s[j] = s[j+1];
                j++;
            }
        }
        i++;
    }

    return occurrences;
}
//
// Created by Piermarco Barbè on 2019-02-26.
//



long int getFileLength(char * fileName){


    // Input check
    if(fileName == NULL){
//        printf("No file provided.\n");
        return -1;
    }

//    printf("Reading file: '%s'...\n", fileName);
    FILE * fp = fopen(fileName, "r");
    fseek(fp, 0L, SEEK_END);
    long int sz = ftell(fp);
//    printf("File size is: %lu\n", sz);

//    printf("Successfully red file '%s'.\n", fileName);
    return sz;
}


struct arrayListString * readFile(char * fileName){

    // Input check
    if(fileName == NULL){
//        printf("No file provided.\n");
        return NULL;
    }


    // Prepare for file reading operation.
    FILE * fp = fopen(fileName, "r");
    long int fileLength = 0;

    // Read check
    if(fp == NULL){
//        printf("Could not open file %s\n", fileName);
        return 0;
    }

    // Getting length of file
    fileLength = getFileLength(fileName);

    if(fileLength == -1)
        return NULL;

    // Maximum string length in file
    char str[fileLength];

    // Start the chain
//    struct arrayListString * main = malloc(sizeof(struct arrayListString));
    struct arrayListString * main = newArrayListStringItemInt(fileLength);

    // Remember where the chain starts
    struct arrayListString * ret = main;


    int k = 0;

    // Get line-by-line
    while(fgets(str, fileLength, fp) != NULL){

//        printf("'%s'\n", str);
        if(k == 0){
            arrayListStringItemSet(main, 0, str);
        } else {
            arrayListStringItemPush(str, main);
        }

        k++;

    }

    fclose(fp);


    // Return what you remembered
    return ret;
}

struct arrayListString * readFileNoNewLines(char * fileName){

    // Input check
    if(fileName == NULL){
//        printf("No file provided.\n");
        return NULL;
    }


    // Prepare for file reading operation.
    FILE * fp = fopen(fileName, "r");
    long int fileLength = 0;

    // Read check
    if(fp == NULL){
//        printf("Could not open file %s\n", fileName);
    }

    // Getting length of file
    fileLength = getFileLength(fileName);

    if(fileLength == -1)
        return NULL;

    // Maximum string length in file
    char str[fileLength];

    // Start the chain
//    struct arrayListString * main = malloc(sizeof(struct arrayListString));
    struct arrayListString * main = newArrayListStringItemInt(fileLength);

    // Remember where the chain starts
//    struct arrayListString * ret = main;


    int k = 0;


    fread(str, 1, fileLength, fp);

    strcpy(str, replaceString(str, "\n",""));

    strcpy(main->value, str);

    fclose(fp);

    // Return what you remembered
    return main;
}









char * getFileNameFromComplete(char * s, char * ext){

//    printf("getFileNameFromComplete: %s\n", s);

    char * last = s;

    char * pch;
//    printf ("Splitting string \"%s\" into tokens:\n",s);
    pch = strtok (s, "/");

//    printf("%s", pch);

    while (pch != NULL)
    {
//        printf ("%s\n",pch);
        last = pch;
        pch = strtok (NULL, "/");
    }

    // last is complete filename


//    last = replaceString(last, ext, "");

    int need = strlen(last) - strlen(ext);

//    printf("need:%d\n", need);
    char * ret = malloc(need);

    strncpy(ret, last, need);

    ret[need]  = 0;
//    printf("ret: %s\n", ret);

    last = ret;

//    printf("returning '%s'\n", last);


    return last;

}

char * formatString(char * s, struct arrayListString * extensions){

    struct arrayListString * root = extensions;

    char * extension;

    while(root){
        extension = getSubstringIntInt(s, strlen(s) - strlen(root->value)+1, strlen(s));
//        printf("ext: %s\n", extension);
        if(strcmp(extension, root->value) == 0){
//            printf("Match on %s \n", extension);
//            printf("'%s'\n", getFileNameFromComplete(s, extension));
            return getFileNameFromComplete(s, extension);
        }
        root = root->next;
    }

    return 0;

//    return last;

}

int main(int argc, char * argv[]){


    struct arrayListString * extensions = newArrayListStringItemVoid();
    struct arrayListString * head_extensions = extensions;

    if(argc == 2){

        struct arrayListString * inputFile = readFile(argv[1]);

        int k = 0;

        while (inputFile){

            if(k == 0){
                arrayListStringItemSet(extensions, 0, replaceString(inputFile->value, "\n", ""));
            } else {
                arrayListStringItemPush(replaceString(inputFile->value, "\n", ""), extensions);
            }

            k++;
            inputFile = inputFile->next;

        }


    } else {

        arrayListStringItemSet(extensions, 0, ".jpg");

        arrayListStringItemPush(".jpeg", extensions);
        arrayListStringItemPush(".png", extensions);
        arrayListStringItemPush(".tiff", extensions);
        arrayListStringItemPush(".tif", extensions);
    }







//    root_inputFile = inputFile;




//    printArrayListString(extensions);

    struct arrayListString * input = newArrayListStringItemVoid();

    char str[1000];

    int c = 0;



    while(fgets(str, sizeof(str), stdin)){


        strcpy(str, removeChar(str, '\n'));

//        printf("str: %s\n", str);

        if(c == 0){
            arrayListStringItemSet(input, 0, str);
        } else {
            arrayListStringItemPush(str, input);
        }
        c++;
        continue;
    }
//
//
//    printArrayListString(input);

//    printf("%d\n", arrayListStringSize(input));
    if(arrayListStringSize(input) == 1){
        return 0;
    }
//
    char * s;

    while (input){
        s = formatString(input->value, extensions);

        if(s){
            printf("%s\n", s);
        }
        input = input->next;
    }
//
    return 0;
}