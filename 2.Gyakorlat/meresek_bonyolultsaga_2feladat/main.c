#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN 1
#define MAX 50
#define MERET 10

void generateUniqeArray(int tomb[], int meret, int min , int max);
void pChanceDouble(int tomb[], int meret);
void arrayPrint(int tomb[], int meret);
bool isUniqe(int tomb[], int meret);

int main()
{
    int tomb[MERET];
    generateUniqeArray(tomb,MERET,MIN,MAX);
    if(isUniqe(tomb,MERET)){
        printf("Egyediek az elemek\n");
    }else printf("Nem egyediek az elemek\n");
    pChanceDouble(tomb,MERET);
    arrayPrint(tomb,MERET);
    if(isUniqe(tomb,MERET)){
        printf("Egyediek az elemek\n");
    }else printf("Nem egyediek az elemek\n");

    return 0;
}

void generateUniqeArray(int tomb[], int meret,int min, int max){

    bool ok;
    int tmp,i,j;
    srand(time(0));
    for(i=0; i<meret-1; i++){
    do{
        tmp= rand()%(max-min)+min;
        printf("%d\n",tmp);
        ok=true;
        for(j=0; j<i; j++){

            if(tmp == tomb[j]){
                ok = false;
                break;
            }
        }
    }while(!ok);

    printf("A %d. elem a :%d \n",i+1,tmp);
    tomb[i] = tmp;

    }

    return ;
    }

    void pChanceDouble(int tomb[], int meret){

        int i;
        double chance;
        srand(time(0));
        for(i=0; i<meret-1;i++){
            chance = rand()/ ((double)RAND_MAX);
            printf("%.2lf \n",chance);
            if(chance>= 0.5){
                tomb[i] = tomb[i]*2;
            }
        }



    return;
}

void arrayPrint(int tomb[], int meret){
    int i;
    for(i=0; i<meret-1;i++){
        printf("%d. elem %d\n",i+1,tomb[i]);
    }
    return ;
}

bool isUniqe(int tomb[], int meret){

    bool ok= true;
    int i,j;
    for(i=0; i<meret-1; i++){
        for(j=i+1; j<meret-1;j++){
            if(tomb[i] == tomb[j]){
                ok=false;
                break;
            }
        }
    }

    if(ok){
        return true;
    }else return false;
}




