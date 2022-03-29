#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


#define START1 -50
#define END1 50

#define START2 -100
#define END2 100

#define START3 -200
#define END3 200


double function_value(double num);
double secant_method(double sec1, double sec2);

int main()
{
    clock_t start , end;
    double secant1, secant2;
    double secant3, secant4;
    double secant5, secant6;
    double r1,r2,r3;



    printf("Hello masodszor openmp-vel  parhuzamositani fogom a szelomodszert az x^3-4x^2-4x+51 fuggvennyre tobb intervallumon.\n");

    secant1 = START1;
    secant2 = END1;

    secant3 = START2;
    secant4 = END2;


        secant5 = START3;
        secant6 = END3;


    start = clock();

    #pragma omp parallel
    {
       r1 = secant_method(secant1,secant2);
       r2 = secant_method(secant3,secant4);
       r3 = secant_method(secant5,secant6);
    }




    end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Ossz futasi ido: %.9f msp\n", time_spent);

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

    double tmp;

    found = false;


    while( !found){

        if( fabs(sec2-sec1) <= 0.00000001  ){
            printf("Megvannak a gyokok a szelo modszerrel: %.9lf\n",sec2);
            found = true;
        }else{
        tmp = sec2;
        sec2= sec1-( (function_value(sec1)*(sec1-sec2))/ (function_value(sec1)-function_value(sec2)));
        sec1 = tmp;

        }
    }

    return sec2;

}

