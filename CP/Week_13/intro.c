#include <stdlib.h>
#include <stdio.h>

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
        int n;
        int* v = (int*) malloc(n * sizeof(int));
        fscanf(in, "%d", &n);
        for(int i = 0; i < n ; i++){
            fscanf(in, "%d", &v[i]);
        }
        for(int i = 0; i < n ; i++){
            fprintf(out,"%d " , v[i]);
            printf("%d ", v[i]);
        }
    }
    fclose(in);
    fclose(out);
}