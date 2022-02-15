#include <stdio.h>
#include <stdlib.h>

#define GEP1 4
#define GEP2 2
#define ELEMSZAM 6

void calculate(int gep);
void transfer(int forras[], int cel[], int elem, int celem);
int addJob(int job);

int main()
{

    int gep1[ELEMSZAM], gep2[ELEMSZAM];
    int count=0;
    int i, j;
    i=0;
    j=0;
    int elem=1;
    while(elem < ELEMSZAM){
       gep1[i]= addJob(elem);
       printf("Bejon a %d elem\n",elem);
       transfer(gep1,gep2,i,j);
       printf("Atment a %d elem\n",elem);
       elem++;
       printf("Bejon a %d elem\n", elem);
       gep1[i]=addJob(elem);
       elem++;
       printf("Elkezd szamolni a 2-es gep\n");
       printf("Elkezd szamolni az 1-es gep\n");
       calculate(GEP1);

       i++;
       j++;

    }
    j--;
    for(elem=0;j>=0;j--){
        printf("Visszakuldom a %d . elemet a gep2-rol\n",j+1);
        transfer(gep2,gep1,j,i);
        i++;
    }
    for(j=0; j<i;j++){
        printf("Az 1-es gepen tarolt %d . elem %d\n",j+1,gep1[j]);
    }



    return 0;
}


void calculate(int gep){

    sleep(gep);
    return;

}

void transfer(int forras[], int cel[], int elem, int celem){

        cel[celem]= forras[elem];
        sleep(2);
        return;

}

int addJob(int job){
    return job;
}
