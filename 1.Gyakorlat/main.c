#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<stdbool.h>

#define ALSO 500
#define FELSO 1000

int primKeres(int hatar);


int main()
{
    /*
    // 2es feladat
    printf("\t \t \t \t \t \t \t \t \t \t \t \t \t \t12345678\n");
    printf("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000012345678\n");

    // 3as feladat
   /* time_t now;
    time(&now);

    int i;
    for(i=0; i<=2; i++){
        printf(" %s \n",ctime(&now));
        getch();
        sleep(61); //itt 1 perc 1 msp-t vár a program
        i++;
    }

    // 4es feladat

    int norm;
    float leb;
    srand(time(0));
    norm = rand()%(FELSO-ALSO+1)+ALSO;
    printf("Random szam: %d\n",norm);

    leb = (float)rand()/RAND_MAX;
    leb+= (float)(rand()%(FELSO-ALSO+1)+ALSO);
    printf(" A lebegopontos veletlen szam: %f \n", leb);

    // 5os feladat

    int als,fels;

    bool ok=false;


     int norm2;

    do{
        printf("Adja meg az also hatart: ");
        scanf("%d",&als);
        printf("Adja meg a felso hatart: ");
        scanf("%d",&fels);
        if(fels <= als){
            printf("A felso hatar kisebb egynelo mint az also!!!\n");
        }else{
            ok = true;
            norm2= rand()%(fels-als+1)+als;
            printf(" A random szam: %d \n",norm2);
        }

    }while(!ok);


    // 6os feladat

    ok=false;

    int megoldas;
    printf("Indul a feladat!\n");
    int muv =  rand()%(4-1+1)+1;
    if(muv==1){

                printf("%d + %d = ",norm,norm2);
                time_t start= time(NULL);
                do{
                scanf("%d",&megoldas);
                if(megoldas == norm+norm2){
                    time_t end = time(NULL);
                    printf("Gratula helyes megoldas!\nIdo: %.0f masodperc \n", difftime(end, start));
                    ok=true;
                }else{
                    printf("Hibas megoldas! \n");
                }
            }while(!ok);
    }else if(muv == 2){

                printf("%d - %d = ",norm,norm2);
                time_t start= time(NULL);
                do{
                scanf("%d",&megoldas);
                if(megoldas == norm-norm2){
                    time_t end = time(NULL);
                    printf("Gratula helyes megoldas!\nIdo: %.0f masodperc \n", difftime(end, start));
                    ok=true;
                }else{
                    printf("Hibas megoldas! \n");
                }
            }while(!ok);


    }else if( muv == 3){

                printf("%d * %d = ",norm,norm2);
                time_t start= time(NULL);
                do{
                scanf("%d",&megoldas);
                if(megoldas == norm*norm2){
                    time_t end = time(NULL);
                    printf("Gratula helyes megoldas!\nIdo: %.0f masodperc\n", difftime(end, start));
                    ok=true;
                }else{
                    printf("Hibas megoldas! \n");
                }
            }while(!ok);

    }else{

                printf("%d/%d = ",norm,norm2);
                time_t start= time(NULL);
                do{
                scanf("%d",&megoldas);
                if(megoldas == norm/norm2){
                    time_t end = time(NULL);
                    printf("Gratula helyes megoldas!\nIdo: %.0f masodperc\n", difftime(end, start));
                    ok=true;
                }else{
                    printf("Hibas megoldas! \n");
                }
            }while(!ok);

    }
    */
    // 7-es feladat

    time_t pstart,pend;
    int primek;
    int j;
    for(j=1000; j<=45000; j+=1000){
        pstart = time(NULL);
        primek = primKeres(j);
        pend= time(NULL);
        printf("0 es %d kozott  %d db primszam van\nFutas: %.2f msp\n",j,primek, difftime(pend, pstart));
    }
    // 70k korul erte el a 2msp-t es 90k korul a 3msp-t



    return 0;
}


int primKeres(int hatar){

    int i,j,db=0;
    int  osztok;
    for(i=2; i<= hatar; i++){
        j = i/2;
        osztok = 0;
        while( j>1 && osztok == 0){
            if(i%j == 0){
                osztok++;
            }else{
                j--;
            }
        }

        if(osztok == 0){
            db++;
        }


    }

    return db;

}
