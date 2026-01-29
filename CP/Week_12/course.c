#include <stdio.h>
#include <stdlib.h>
int* copyNegatives(int n, int t[]){
   int *neg = NULL;
    int nNeg = 0;
    for(int i =0 ; i<n ; i++){
        if(t[i]<0){
            int* auxPt = realloc(neg, (nNeg+1) * sizeof(int));
            if(!auxPt){ //realloc failed
                free(neg);
                printf("Error during realloc\n");
                return NULL;
            }
            neg = auxPt;
            neg[nNeg] = t[i];
            nNeg++;

        }
    }
    /// we need to somehow mark the end of the array
    /// because our functions copies negatives
    /// we mark the end of the array with 0
    int* auxPt = realloc(neg , (nNeg+1) * sizeof(int));
    if(!auxPt){
        neg = auxPt;
        neg[nNeg] = 0; 
    }
    /// to avoid duplication:
    /// allocate one more slot always
    return neg;
}


int main(){
    int v[] = {1,2,3,4,-5,-1,8};
    int* neg = copyNegatives(sizeof(v)/sizeof(v[0]), v);
    /// copyNegatives CAN fail -> add != NULL condition, but 
    /// its still not recommended to do it this way, neg[i] might
    /// still be attempted -> DO IF STATEMENTS .

    for(int i = 0 ; neg[i] < 0 && neg!=NULL; i++){
        printf("%d ", neg[i]);
    }

    free(neg);// not really necessary, most of the times, after free()
    // we end the program, so the system would do this anyways
}