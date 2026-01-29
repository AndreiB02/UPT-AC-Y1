#include <stdlib.h>
#include <stdio.h>
typedef struct elev{
    char nume[20];
    int nota1;
    int nota2;
}elev;
int main(int argc, char* argv[]){

    char* input_filename;
    char* output_filename;
    if(argc == 3){
        input_filename = argv[1];
        output_filename  = argv[2];
    } else {
        printf("Not enough arguments\n");
    }
    //printf(filename);
    FILE* in;
    FILE* out;
    if((in = fopen(input_filename, "r")) == NULL){
        printf("Error opening file %s\n", input_filename);
        return -1;
    }
    if((out= fopen(output_filename, "w")) == NULL){
        printf("Error opening file %s\n", output_filename);
        return -1;
    }
    else{
        // char string[100];
        // fscanf(fr ,"%s", string);
        // printf("%s", string);
        elev e[30];
        int n;
        fscanf(in, "%d", &n);
        printf("Sunt %d elevi ", n);
        for(int i = 0 ; i < n ; i++){
            if(fscanf(in, "%20[^,], %d, %d", e[i].nume, &e[i].nota1, &e[i].nota2)!= 3){
                printf("Incorrect format");
                return -2;
            }
        }
        for(int i = 0 ; i < n ; i++){
            fprintf(out, "%20[^,], %d, %d", e[i].nume, &e[i].nota1, &e[i].nota2);
        }
        
    }
    fclose(in);
    fclose(out);
}