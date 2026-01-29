#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct record{
    int day;
    int month;
    int year;
    char CUR1[4];
    char CUR2[4];
    double value;
} record_t;

record_t * addData(record_t *data, record_t r, int *nr_records){
    record_t *aux = realloc(data, sizeof(record_t) * (*nr_records + 1));
    if(!aux){
        perror("error during realloc");
        return NULL;
    }
    data = aux;
    data[*nr_records] = r;
    *nr_records +=1;
    return data;
}
int compareRecordsByDate(const void* el1, const void* el2){
    record_t r1 = *(record_t*) el1;
    record_t r2 = *(record_t*) el2;
    if (r1.year > r2.year)
    {
        return 1;
    }
    else if (r1.year < r2.year)
    {
        return -1;
    }
    else
    {
        if (r1.month > r2.month)
        {
            return 1;
        }
        else if (r1.month < r2.month)
        {
            return -1;
        }
        else
        {
            if (r1.day > r2.day)
            {
                return 1;
            }
            else if (r1.day < r2.day)
            {
                return -1;
            }
            return 0;
        }
    }
}
void printRecords(int nr_records, record_t data[]){
    for ( int i= 0; i < nr_records ; i++){
        printf("%d-%d-%d %3s/%3s %lf\n",data[i].day,data[i].month,data[i].year, data[i].CUR1, data[i].CUR2, data[i].value);
    }
}
record_t* filterRecordsByCurrencyPair(record_t* data,  int nr_records, int *filtered_records,  char CUR1[], char CUR2[]){
    record_t *newData = NULL;
    *filtered_records = 0;
    for ( int i= 0; i < nr_records ; i++){
        if(strcmp(data[i].CUR1, CUR1) == 0 || strcmp(data[i].CUR2, CUR2) == 0){
            if(!( newData =addData(newData, data[i], &(*filtered_records)))) {
            perror("error adding data");
            return NULL;
        }
        }
    }
    return newData;
}
int main(int argc, char* argv[]){
    if(argc != 4){
        perror("not enough arguments");
        return -1;
    }
    FILE *f = fopen(argv[1], "rt");

    if(!f){
        perror("error opening file");
        return -2;
    }
    int nr_records = 0;
    record_t *data = NULL;
    int filtered_records = 0;
    record_t *newData = NULL;

    record_t temp = { 0, 0, 0,"", "", 0.0};


    while(fscanf(f, "%d-%d-%d %3[^/]/%3s %lf",&temp.day,&temp.month,&temp.year, temp.CUR1, temp.CUR2, &temp.value) == 6){
        // here we could search if temp appears in data
        
        //printf("%d-%d-%d %3s/%3s %lf\n",temp.day,temp.month,temp.year, temp.CUR1, temp.CUR2, temp.value);
        // add the record to data
        if(!( data = addData(data, temp, &nr_records))) {
            perror("error adding data");
            return -1;
        }
    }
    newData = filterRecordsByCurrencyPair(data,nr_records, &filtered_records, argv[2], argv[3]);
    qsort(newData, filtered_records, sizeof(record_t), compareRecordsByDate);
    printRecords(filtered_records,newData);
}