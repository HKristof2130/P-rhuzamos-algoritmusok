#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>


#define START1 -50
#define END1 50

#define START2 -100
#define END2 100

#define START3 -200
#define END3 200

#define SOLUTION -3.0






double secant1, secant2;
double secant3, secant4;
double secant5, secant6;



double function_value(double num);
void * secant_method1();
void * secant_method2();
void * secant_method3();
void * start_secant1();
void * start_secant2();
void * start_secant3();

int main()
{

    pthread_t secant_thread1;
    pthread_t secant_thread2;
    pthread_t secant_thread3;


    printf("Hello eloszor parhuzamositassal fogom alkalmazni a szelomodszert az x^3-4x^2-4x+51 fuggvennyel tobb intervallumon.\n");


    secant1 = START1;
    secant2 = END1;
    secant3 = START2;
    secant4 = END2;
    secant5 = START3;
    secant6 = END3;

    clock_t begin = clock();
    pthread_create(&secant_thread1,NULL,start_secant1,NULL);
    pthread_create(&secant_thread2,NULL,start_secant2,NULL);
    pthread_create(&secant_thread3,NULL,start_secant3,NULL);

    pthread_join(secant_thread1,NULL);
    pthread_join(secant_thread2,NULL);
    pthread_join(secant_thread3,NULL);
    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("A szamitashoz felhasznalt ido: %.3f msp\n", time_spent);



    return 0;
}


double function_value(double num){

    double result;


    result = 0;
    result += (pow(num, 3.0));
    result -= (4*(pow(num,2.0)));
    result -= (num*4);
    result += 51.0;


    return result;

}

void * secant_method1(){

    double tmp;

    tmp = secant2;
    secant2= secant1-( (function_value(secant1)*(secant1-secant2))/ (function_value(secant1)-function_value(secant2)));
    secant1 = tmp;

    return NULL;
}

void * secant_method2(){

    double tmp;

    tmp = secant3;
    secant4= secant3-( (function_value(secant3)*(secant3-secant4))/ (function_value(secant3)-function_value(secant4)));
    secant3 = tmp;

    return NULL;
}

void * secant_method3(){

    double tmp;

    tmp = secant5;
    secant6= secant5-( (function_value(secant5)*(secant5-secant6))/ (function_value(secant5)-function_value(secant6)));
    secant5 = tmp;

    return NULL;
}

void* start_secant1(){

bool found;
pthread_t sc;

found = false;

 while( !found){

        if( fabs(secant2-SOLUTION) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant2);
            found = true;
        }else{
            pthread_create(&sc,NULL,secant_method1,NULL);
            pthread_join(sc,NULL);

        }
}



}


void* start_secant2(){

bool found;
pthread_t sc;

found = false;

 while( !found){

        if( fabs(secant4-SOLUTION) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant4);
            found = true;
        }else{
            pthread_create(&sc,NULL,secant_method2,NULL);
            pthread_join(sc,NULL);

        }
}

}

void * start_secant3(){

bool found;
pthread_t sc;

found = false;

 while( !found){

        if( fabs(secant6-SOLUTION) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant6);
            found = true;
        }else{
            pthread_create(&sc,NULL,secant_method3,NULL);
            pthread_join(sc,NULL);

        }
}

}


