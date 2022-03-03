#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define SIZE 8



void crew_prefix(int array[], int size);
void print_array(int array[], int size);
void erew_prefix(int array[], int size, int goal_array[]);


int main()
{
    int array[] = {4,7,2,1,6,5,3,5};
    crew_prefix(array,SIZE);
    int array1[] = {4,7,2,1,6,5,3,5};
    int array2[SIZE];
    erew_prefix(array1,SIZE,array2);
    print_array(array2,SIZE);


    return 0;
}

void crew_prefix(int array[], int size){

    int i,j;
    FILE* fp= fopen("prefix.txt","w");



    for(i=1 ;  i < (size/2);i++){
        array[i] = array[i] + array[i-1];
    }
    for(i=size/2+1; i< size; i++){
        array[i] = array[i] + array[i-1];
    }
    j=array[size/2-1];
    for(i=size/2; i < size; i++){
        array[i]= array[i] + j;
    }


    for( i=0; i < size; i++){
        fprintf(fp,"%d  ",array[i]);
    }

    fclose(fp);


    return;

}


void print_array(int array[], int size){

    int i;


    for(i=0; i< size; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    return ;
}

void erew_prefix(int array[], int size, int goal_array[]){

     int i,k;

    printf("A kezdeti tomb: \n");
    print_array(array,size);
    goal_array[0] = array[0];
    for(i=1; i< size; i++){
        goal_array[i] = array[i-1] + array[i];
    }
    printf("A cel tomb: \n");
    print_array(goal_array,size);
    k= 1;
    while(k <  size){
        for(i=k+1; i<size; i++){
            goal_array[i] = goal_array[i-k] + goal_array[i];
        }
        print_array(goal_array,size);
        k= 2*k;
    }

    return ;
}
