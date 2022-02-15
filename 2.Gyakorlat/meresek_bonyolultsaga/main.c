#include <stdio.h>
#include <stdlib.h>

#define MERET 5

int calcSum(int tomb[], int meret);
int searchMin(int tomb[], int meret);
int searchMax(int tomb[], int meret);


int main()
{
    int tomb[MERET];
    int i;
    for(int i=0; i<MERET;i++){
        scanf("%d",&tomb[i]);
    }
    printf("A tomb elemeinek osszege: %d\n",calcSum(tomb,MERET));
    printf("A tomb minimum eleme: %d \t maximum eleme: %d \n",searchMin(tomb,MERET),searchMax(tomb,MERET));



    return 0;
}
int calcSum(int tomb[], int meret){

    int i,sum;
    sum=0;
    for(i=0; i<meret;i++){
        sum+= tomb[i];
    }


    return sum;
}

int searchMin(int tomb[], int meret){
    int i;
    int minin=0;
    for(i=1; i<meret; i++){
        if(tomb[minin] > tomb[i]){
            minin = i;
        }
    }

    return tomb[minin];
}

int searchMax(int tomb[], int meret){
    int i;
    int maxin=0;
    for(i=1; i<meret; i++){
        if(tomb[maxin] < tomb[i]){
            maxin = i;
        }
    }

    return tomb[maxin];
}
