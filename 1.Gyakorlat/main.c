#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define MERET 3
#define ALSO 500
#define FELSO 1000

int primKeres(int hatar);
void arrayWritei(int t[], int meret);
void arrayReaderi(int t[], int meret);
void arrayWritef(float t[], int meret);
void arrayReaderf(float t[], int meret);
void arrayWrited(double t[], int meret);
void arrayReaderd(double t[], int meret);
void randomNummberG( char nev[], int elem);


int main()
{
    /*
    // 2es feladat
    printf("\t \t \t \t \t \t \t \t \t \t \t \t \t \t12345678\n");
    printf("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000012345678\n");

    // 3as feladat
    time_t now;
    time(&now);

    int i;
    for(i=0; i<=2; i++){
        printf(" %s \n",ctime(&now));
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


    //8-as feladat

    int ti[MERET];
    int k;
    printf("Kerek int szamokat!\n");
    for(k=0; k<MERET; k++){
        scanf("%d",&ti[k]);
    }
    arrayWritei(ti,MERET);
    arrayReaderi(ti,MERET);

    float tf[MERET];
    printf("Kerek float szamokat!\n");
    for(k=0; k<MERET; k++){
        scanf("%f",&tf[k]);
    }
    arrayWritef(tf,MERET);
    arrayReaderf(tf,MERET);

    double td[MERET];
    printf("Kerek double szamokat!\n");
    for(k=0; k<MERET;k++){
        scanf("%lf",&td[k]);
    }

    arrayWrited(td,MERET);
    arrayReaderd(td,MERET);
    */

    /////   9es feladat

    printf("Adja meg, hogy mi legyen a fajl neve: ");
    char fajlnev[30];
    scanf("%s",&fajlnev);
    int elemszam;
    printf("Adja meg az elemszamot:  ");
    scanf("%d",&elemszam);

    randomNummberG(fajlnev,elemszam);



    return 0;
}


int primKeres(int hatar){

    int i,j,db=0, fele;
    int  osztok;
    for(i=2; i<= hatar; i++){
        fele = i/2;
        osztok = 0;
        j=2;
        while( j<fele && osztok == 0){
            if(i%j == 0){
                osztok++;
            }else{
                j++;
            }
        }

        if(osztok == 0){
            db++;
        }


    }

    return db;

}

void arrayWritei(int t[], int meret){

    FILE* fp= fopen("integerArray.txt","w");
    int i;
    for(i=0; i<meret; i++){

        fprintf(fp,"%d\n",t[i]);
    }

    fclose(fp);
    return;
}

void arrayReaderi(int t[], int meret){

    FILE* fp;
    int helpArray[meret];
    int i=0;
    printf("Add meg a fajl nevet: ");
    char fajl[40];
    scanf("%s",&fajl);
    if (fp  = fopen(fajl, "r"))
  {
    while (fscanf(fp, "%d", &helpArray[i]) != EOF)
    {
      i++;
    }


    helpArray[i] = '\0';

    printf("A beolvasott szamok\n");
    for (i = 0; helpArray[i] != '\0'; i++)
      printf("%d\n", helpArray[i]);
  }


    int filesize= ftell(fp);
    printf("A fajl merete: %d mb\n", filesize);
    fclose(fp);


    return ;

}

void arrayWritef(float t[], int meret){

    FILE* fp= fopen("floatArray.txt","w");
    int i;
    for(i=0; i<meret; i++){

        fprintf(fp,"%f\n",t[i]);
    }

    fclose(fp);
    return;

}

void arrayReaderf(float t[], int meret){

    FILE* fp;
    float helpArray[meret];
    int i=0;
    printf("Add meg a fajl nevet: ");
    char fajl[40];
    scanf("%s",&fajl);
    if (fp  = fopen(fajl, "r"))
  {
    while (fscanf(fp, "%f", &helpArray[i]) != EOF)
    {
      i++;
    }


    helpArray[i] = '\0';

    printf("A beolvasott szamok\n");
    for (i = 0; helpArray[i] != '\0'; i++)
      printf("%f\n", helpArray[i]);
  }


    int filesize= ftell(fp);
    printf("A fajl merete: %d mb\n", filesize);
    fclose(fp);


    return ;
}


void arrayWrited(double t[], int meret){

    FILE* fp= fopen("doubleArray.txt","w");
    int i;
    for(i=0; i<meret; i++){

        fprintf(fp,"%lf\n",t[i]);
    }

    fclose(fp);
    return;


}



void arrayReaderd(double t[], int meret){

    FILE* fp;
    double helpArray[meret];
    int i=0;
    printf("Add meg a fajl nevet: ");
    char fajl[40];
    scanf("%s",&fajl);
    if (fp  = fopen(fajl, "r"))
  {
    while (fscanf(fp, "%lf", &helpArray[i]) != EOF)
    {
      i++;
    }


    helpArray[i] = '\0';

    printf("A beolvasott szamok\n");
    for (i = 0; helpArray[i] != '\0'; i++)
      printf("%lf\n", helpArray[i]);
  }


    int filesize= ftell(fp);
    printf("A fajl merete: %d mb\n", filesize);
    fclose(fp);


    return ;
}

void randomNummberG( char nev[] , int elem){

    FILE* fp= fopen(nev,"w");
    int i;
    time_t start,end;
    start= time(NULL);
    int szam ;
    for(i=0; i<elem; i++){
        szam = rand()%(99999)+1;
        fprintf(fp,"%d\n",szam );
    }
    fclose(fp);
    end= time(NULL);
    printf("A müvelet %.lf msp-t vett igenybe",difftime(end,start));

    return;

}

