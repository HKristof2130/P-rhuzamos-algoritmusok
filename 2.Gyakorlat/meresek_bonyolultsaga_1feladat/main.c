#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MERET 6000

int calcSum(int tomb[], int meret);
int searchMin(int tomb[], int meret);
int searchMax(int tomb[], int meret);
int recSum(int tomb[], int n);
int recMin(int tomb[], int n, int i);
int recMax(int tomb[], int n, int i);
void randFill(int tomb[], int meret);

int main()
{
    int tomb[MERET];
    int i;
    /*printf("Adja meg a tomb elemeit:\n");
    for(int i=0; i<MERET;i++){
        scanf("%d",&tomb[i]);
    }
    printf("A tomb elemeinek osszege: %d\n",calcSum(tomb,MERET));
    printf("A tomb minimum eleme: %d \t maximum eleme: %d \n",searchMin(tomb,MERET),searchMax(tomb,MERET));
    */
    int rectomb[MERET];
    randFill(rectomb,MERET);
    int n= MERET;
    i=0;
    printf("A tomb osszege: %d\n",calcSum(rectomb,MERET));
    printf("A tomb minimum eleme: %d \t maximum eleme: %d \n",searchMin(rectomb,MERET),searchMax(rectomb,MERET));
    time_t start,end;
    start = time(NULL);
    printf("Rekurziv osszeg: %d\n",recSum(rectomb,n));
    end = time(NULL);
    printf("A futasi ido : %.0f msp\n", difftime(end,start));
    start = time(NULL);
    printf("A tomb min eleme: %d\n", recMin(rectomb,n,i));
    end = time(NULL);
    printf("A futasi ido : %.0f msp\n", difftime(end,start));
    start = time(NULL);
    printf("A tomb max eleme: %d\n", recMax(rectomb,n,i));
    end = time(NULL);
    printf("A futasi ido : %.0f msp\n", difftime(end,start));



    return 0;
}
int calcSum(int tomb[], int meret){

    int i,sum;
    sum=0;
    time_t start= time(NULL);
    for(i=0; i<meret;i++){
        sum+= tomb[i];
    }
    time_t end = time(NULL);
    printf("A futasi ido : %.0f msp\n", difftime(end,start));

    return sum;
}

int searchMin(int tomb[], int meret){
    int i;
    int minin=0;
    time_t start= time(NULL);
    for(i=1; i<meret; i++){
        if(tomb[minin] > tomb[i]){
            minin = i;
        }
    }
    time_t end = time(NULL);
    printf("A futasi ido : %.0f msp\n", difftime(end,start));

    return tomb[minin];
}

int searchMax(int tomb[], int meret){
    int i;
    int maxin=0;
    time_t start= time(NULL);
    for(i=1; i<meret; i++){
        if(tomb[maxin] < tomb[i]){
            maxin = i;
        }
    }
    time_t end = time(NULL);
    printf("A futasi ido : %.0f msp\n", difftime(end,start));

    return tomb[maxin];
}

int recSum(int tomb[], int n){
    n--;
    if(n==0){
        return tomb[n];
    }else{
        return tomb[n]+recSum(tomb,n);
    }


}

int recMin(int tomb[], int n,int i){
   n--;
   if(tomb[i]> tomb[n]){
        i=n;
   }
   if(n==0){
    return tomb[i];
   }else{
        return recMin(tomb,n,i);
   }
}

int recMax(int tomb[], int n, int i){

      n--;
   if(tomb[i] < tomb[n]){
        i=n;
   }
   if(n==0){
    return tomb[i];
   }else{
        return recMax(tomb,n,i);
   }

}

void randFill(int tomb[], int meret){

    int i;
    srand(time(0));
    for(i=0; i<meret-1;i++){
        tomb[i] = rand()%(10000)+1;
    }

    return;
}
