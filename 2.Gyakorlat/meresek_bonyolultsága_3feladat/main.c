#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define SIZE 10

void generateArray(float array[], int size);
void arrayPrint(float array[], int size);
bool strictlyMonotonicRise(float array[], int size);
int binarySearch(float array[], int size);
int recBinarySearch(float array[], int end, int start, float key);
bool floatCompare(float f1,float f2, float epsilon);

int main()
{
    float arr[SIZE];
    generateArray(arr,SIZE);
    arrayPrint(arr,SIZE);
    bool rising = strictlyMonotonicRise(arr,SIZE);
    //printf("A keresett elem a %d helyen van\n", binarySearch(arr,SIZE));
    printf("Elem rec kereseshez:");
    float key = scanf("%f",&key);

    int rec= recBinarySearch(arr,SIZE-1,0,key);

    if(rec == -1){
        printf("Nincs ilyen elem!");
    }else{
        printf("A keresett elem a %d helyen van\n",rec);
    }



    return 0;
}

void generateArray(float array[], int size){

    int i;
    bool ok;
    srand(time(0));
    array[0]= (float)rand()/RAND_MAX;
    array[0]+= rand()%(99)+1;
    for(i=1; i<size;i++){
        do{
            ok=true;
            array[i]= (float)rand()/(float)RAND_MAX;
            array[i]+= rand()%(99)+1;
            if(array[i]<= array[i-1]){
                ok=false;
            }
        }while(!ok);
    }

    return ;
}

void arrayPrint(float array[], int size){

    int i;
    for(i=0; i<size; i++){
        printf("%f\n",array[i]);
    }

    return ;
}

bool strictlyMonotonicRise(float array[], int size){

    int i;
    for(i=1; i<size; i++){
        if(array[i] <= array[i-1]){
            printf("Az elemek nem monoton novekednek\n");
            return false;
        }
    }
    printf("Az elemek monoton novekednek\n");
    return true;
}

int binarySearch(float array[], int size){

    float wanted;
    int i,start,end;
    start=0;
    end= size;
    printf("Melyik elemet szereted megtalalni:");
    scanf("%f",&wanted);
    while( start<= end-1){
        i= (start+end)/2;
        if(wanted < array[i]){
            end= i-1;
        }else if(wanted > array[i]){
            start= i+1;
        }else return i+1;
    }

    printf("Nincs ilyen elem!\n");

}

int recBinarySearch(float array[], int end, int start, float key){

    int i= (start+end)/2;
    printf("tartomany %d - %d\nkozep : %d\n",start,end,i);
    if(start> end){
        return -1;
    }else if( floatCompare(key,array[i],0.00001)){
        return i+1;
    }else if( key < array[i]){
        return recBinarySearch(array,i-1,start,key);
    }else if(key > array[i]){
        return recBinarySearch(array,end,i+1,key);
    }



}


bool floatCompare(float f1,float f2, float epsilon){

    return fabs(f1-f2) < epsilon;
}
