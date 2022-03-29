#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


#define START1 -500
#define END1 500

#define START2 -1000
#define END2 1000

#define START3 -2000
#define END3 2000

#define SOLUTION -3.0






double secant1, secant2;
double secant3, secant4;
double secant5, secant6;



double function_value(double num);
double secant_method(double sec1, double sec2);

int main()
{
    double tmp;
    clock_t start,end;
    double r1,r2,r3;


    start = clock();
    secant1 = START1;
    secant2 = END1;

    secant3 = START2;
    secant4 = END2;

    secant5 = START3;
    secant6 = END3;


    r1 = secant_method(secant1,secant2);
    r2 = secant_method(secant3,secant4);
    r3 = secant_method(secant5,secant6);


    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("A szamitashoz felhasznalt ido: %.12f msp\n", time_spent);

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

double secant_method(double sec1, double sec2){

    bool found;
    int steps = 0;
    double tmp;

    found = false;


    while( !found){

        steps ++;
        if( fabs(sec2-sec1) <= 0.00000001  ){
            printf("Megvan a gyok a szelo modszerrel: %.9lf\n",sec2);
            found = true;
        }else{
        tmp = sec2;
        sec2= sec1-( (function_value(sec1)*(sec1-sec2))/ (function_value(sec1)-function_value(sec2)));
        sec1 = tmp;

        }

    }
    printf("Lepesek szama : %d\n",steps);

    return sec2;

}
