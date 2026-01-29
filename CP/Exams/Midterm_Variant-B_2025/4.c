#include <stdio.h>
#include <stdlib.h>

typedef struct Record{
    int hour;
    int minute;
    int second;
    int milisecond;
    char TICK[10];
    double sell_value;
    double buy_value;
} Record_t;
double increase(int n, int m) {
    //increase from n to m by x%
    return 100*(m-n)/n; // ->x
}
Record_t* addData(Record_t* data,Record_t r, int *nr_records){

    Record_t *aux = realloc(data, sizeof(Record_t) * (*nr_records + 1)); 
    if(!aux){
        perror("error during realloc");
        return NULL;
    }
    data = aux;
    data[*nr_records] = r;
    *nr_records +=1; 
    return data;
}
int toSeconds(int h,int m, int s){
    return h*3600 + m * 60 + s;
}
int compareTime(const void* el1, const void* el2){
    Record_t r1 = *(Record_t*) el1;
    Record_t r2 = *(Record_t*) el2;
    int t1 = toSeconds(r1.hour,r1.minute,r1.second);
    int t2 = toSeconds(r2.hour,r2.minute,r2.second);
    if(t1 < t2 ) return -1;
    else if(t1 > t2 ) return 1;
    else  return r1.milisecond <= r2.milisecond;

}


Record_t* filterByPriceIncrease(Record_t* data, int nr_records, int *nr_records_filter){
    Record_t* filter = NULL;
    *nr_records_filter = 0;

    for(int i = 0; i < nr_records; i++){
        if(increase(data[i].sell_value, data[i].buy_value) >= 20){
            if(!(filter = addData( filter, data[i], &(*nr_records_filter) ))){
                perror("error when filtering");
                return NULL;
            }
        }
    }
    return filter;
}
void printRecord(Record_t* data, int nr_records){
    for(int i = 0; i <  nr_records; i++){
        printf("%02d:%02d:%02d.%02d %10s %lf %lf\n",data[i].hour, data[i].minute, data[i].second, data[i].milisecond, data[i].TICK, data[i].sell_value, data[i].buy_value);
    }
}

int main(int argc, char *argv[]){

    if(argc != 2){
        perror("invalid number of arguments");
        return -1;
    }
    FILE *f = fopen(argv[1] , "rt");
    if(!f){
        perror("error opening file");
        return -2;
    }
    Record_t temp = { 0,0,0,0,"",0.0,0.0};

    Record_t* data = NULL;
    int nr_records = 0;

    Record_t* filter_data = NULL;
    int nr_records_filter = 0;
    while(fscanf(f,"%2d:%2d:%2d.%2d %10s %lf %lf",
    &temp.hour, &temp.minute, &temp.second, &temp.milisecond, temp.TICK, &temp.sell_value, &temp.buy_value) == 7)
    {
        /*printf("%02d:%02d:%02d.%02d %10s %lf %lf\n",
    temp.hour, temp.minute, temp.second, temp.milisecond, temp.TICK, temp.sell_value, temp.buy_value);
    */
        if(!(data = addData(data, temp, &nr_records))){
            perror("error adding data");
            return -1;
        }


    }

    printRecord(data, nr_records);
    if(!(filter_data = filterByPriceIncrease(data, nr_records, &nr_records_filter ))){
        perror("error when filtering1");
        return -1;
    }
    printf("------Filter-------\n");
    printRecord(filter_data,nr_records_filter);
    printf("------Sorted-------\n");
    qsort(filter_data, nr_records_filter, sizeof(Record_t), compareTime);
    printRecord(filter_data, nr_records_filter);
}

/*
10:15:05.12 AAPL 185.00 184.00
11:00:22.00 MSFT 310.00 399.00
12:30:45.88 TSLA 700.00 695.00
12:30:50.10 TSLA 850.00 845.00
14:20:10.05 BTC 45000.00 67000.00
10:15:00.50 AAPL 100.00 150.50
*/