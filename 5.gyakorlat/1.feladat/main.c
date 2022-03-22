#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void generate_array(double arr[], int size);
void print_array(double arr[], int size);
double product_array(double arr[], int size);

int main()
{
    double my_array[SIZE];
    double sum1;

    generate_array(my_array,SIZE);
    print_array(my_array,SIZE);
    sum1 = product_array(my_array,SIZE);
    printf("A tomb osszege: %.4lf",sum1);


    return 0;
}

void generate_array(double arr[], int size){

    int i;

    srand(time(0));
    for ( i = 0; i < size; i++){
        arr[i] = (double)rand()/(double)RAND_MAX;
        arr[i] += rand()%199+1;
    }

    return ;

}

void print_array(double arr[], int size){

    int i;


    for( i = 0; i < size; i++){
        printf(" %.4lf ",arr[i]);
    }
    printf("\n");

    return;

}

double product_array(double arr[], int size){

    int i;
    double sum;


    sum = 1;
    for ( i = 0; i < size; i++){
        sum *= arr[i];
    }

    return sum ;
}
