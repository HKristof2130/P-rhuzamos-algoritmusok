#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>


#define START1 -500
#define END1 500

#define START2 -1000
#define END2 1000

#define START3 -2000
#define END3 2000








double secant1, secant2;
double secant3, secant4;
double secant5, secant6;



double function_value(double num);
void * start_secant1();
void * start_secant2();
void * start_secant3();

int main()
{
    clock_t start,end;
    pthread_t secant_thread1;
    pthread_t secant_thread2;
    pthread_t secant_thread3;


    printf("Hello eloszor parhuzamositassal fogom alkalmazni a szelomodszert az 10*x^3-3x^2-11x-11 fuggvennyel tobb intervallumon.\n");


    secant1 = START1;
    secant2 = END1;
    secant3 = START2;
    secant4 = END2;
    secant5 = START3;
    secant6 = END3;

    start = clock();

    pthread_create(&secant_thread1,NULL,start_secant1,NULL);
    pthread_create(&secant_thread2,NULL,start_secant2,NULL);
    pthread_create(&secant_thread3,NULL,start_secant3,NULL);


    pthread_join(secant_thread1,NULL);
    pthread_join(secant_thread2,NULL);
    pthread_join(secant_thread3,NULL);



    end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Ossz futasi ido: %.3f msp\n", time_spent);



    return 0;
}


double function_value(double num){

    double result;


    result = 0;
    result += 10*(pow(num, 3.0));
    result -= (3*(pow(num,2.0)));
    result -= (num*11);
    result -= 11.0;


    return result;

}



void* start_secant1(){

    bool found;
    int steps;
    double tmp;

    found = false;
    steps = 0;

    while( !found){

        steps++;
        if( fabs(secant2-secant1) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant2);
            found = true;
        }else{
        tmp = secant2;
        secant2= secant1-( (function_value(secant1)*(secant1-secant2))/ (function_value(secant1)-function_value(secant2)));
        secant1 = tmp;

        }
    }

    printf ("A megtett lepesek: %d\n",steps);


}


void* start_secant2(){

    bool found;
    int steps;
    double tmp;

    found = false;
    steps = 0;

    while( !found){

        steps++;
        if( fabs(secant4-secant3) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant4);
            found = true;
        }else{
        tmp = secant4;
        secant4= secant3-( (function_value(secant3)*(secant3-secant4))/ (function_value(secant3)-function_value(secant4)));
        secant3 = tmp;

        }
    }

    printf ("A megtett lepesek: %d\n",steps);


}

void * start_secant3(){

    bool found;
    int steps;
    double tmp;

    found = false;
    steps = 0;

    while( !found){

        steps++;
        if( fabs(secant6-secant5) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant6);
            found = true;
        }else{
        tmp = secant6;
        secant6 = secant5-( (function_value(secant5)*(secant5-secant6))/ (function_value(secant5)-function_value(secant6)));
        secant5 = tmp;

        }
    }

    printf ("A megtett lepesek: %d\n",steps);

}


