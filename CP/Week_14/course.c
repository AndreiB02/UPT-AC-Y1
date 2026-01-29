#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char key[11];
    char value[11];
}Record_t;

int findRecord(Record_t r, Record_t data[], int nRecords){
    for ( int  i = 0; i < nRecords; i++){
        if(strcmp(data[i].key, r.key) == 0)
            return i;
    }
    return -1;
}
Record_t *addData(Record_t record, Record_t * data, int *n ){
    Record_t *aux = realloc(data, (*n + 1) * sizeof(Record_t));
    if( !aux){
        perror("error during realloc");
        return NULL;
    }
    data = aux;
    data[*n] = record;
    *n = *n + 1;
    return data;
}

void printRecords(int n, Record_t t[]){
    for ( int i= 0; i < n ; i++){
        printf("%10s %10s", t[i].key, t[i].value);
    }
}

// compares anyting we want, need this header for qsort
//we typecast to records
int compareRecords(const void* el1, const void* el2){
    Record_t r1 = *(Record_t*) el1;
    Record_t r2 = *(Record_t*) el2;
    return stcmp(r1.key, r2.key);
}

int main(int argc, char *argv){

    if(argc!= 2){
        perror(" write the file name to open");
        return -1;
    }
    FILE* f = fopen(argv[1], "rt");

    if(!f){
        perror("could not open file");
        return -2;
    }

    Record_t *data = NULL;
    int nRecords = 0;

    Record_t temp = {"", ""};

    while(fscanf(f, "%10s = %10s", temp.key, temp.value) == 2){
        int position;
        if((position = findRecord(temp, data, nRecords)) >= 0){
            strcpy(data[position].value, temp.value);
        }
        else{
            if(!(data = addData(temp, data , &nRecords))){
                perror("some error trying to add data");
                return -3;
            }
        }
    }

    printRecords(nRecords, data);
    qsort(data, nRecords, sizeof(Record_t), compareRecords);
    printRecords(nRecords, data);
    return 0;
}