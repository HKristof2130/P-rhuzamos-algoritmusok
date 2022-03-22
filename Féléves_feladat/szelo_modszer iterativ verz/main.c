#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
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



double function_value(double num);

int main()
{
    double tmp;
    clock_t start,end;
    bool found;

    start = clock();
    secant1 = START1;
    secant2 = END1;
    found = false;
    while(!found){
        if( fabs(secant2-SOLUTION) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant2);
            found = true;
        }else{
            tmp = secant2;
            secant2= secant1-( (function_value(secant1)*(secant1-secant2))/ (function_value(secant1)-function_value(secant2)));
            secant1 = tmp;
        }
    }

    secant1 = START2;
    secant2 = END2;
    found= false;
    while(!found){
        if( fabs(secant2-SOLUTION) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant2);
            found = true;
        }else{
            tmp = secant2;
            secant2= secant1-( (function_value(secant1)*(secant1-secant2))/ (function_value(secant1)-function_value(secant2)));
            secant1 = tmp;
        }
    }

    secant1 = START3;
    secant2 = END3;
    found = false;

    while(!found){
        if( fabs(secant2-SOLUTION) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",secant2);
            found = true;
        }else{
            tmp = secant2;
            secant2= secant1-( (function_value(secant1)*(secant1-secant2))/ (function_value(secant1)-function_value(secant2)));
            secant1 = tmp;
        }
    }
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("A szamitashoz felhasznalt ido: %.9f msp\n", time_spent);

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
