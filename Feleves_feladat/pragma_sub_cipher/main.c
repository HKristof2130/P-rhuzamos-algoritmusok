#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <omp.h>


#define KEY_SIZE 8
#define SIZE 200

// kulcs: vas
// probának : sqvtgilpubiueupxnqytvqjnfrbxgmtuswrvuhatzbyfhmdlnxenudbbmbzcswgpmknnyfnwupddltxzalefeiqvxtwillvdnwymagjyneezqhpbbejgbeioőugoőnwoojgbeőigbwőivjnbeőiuebgőojngőijbeőojvneőovjeőovjneőovbedabiebvpiebveivbeqivbqeivbeiővbeqiővuebviőbeőivebvőioeqbviqehbveqbvqiővbqeiővbeőivbeqőviqebviőeqbvőiqbvőiqvbqeivbeqiővbeqivbeqivbqeővibeqvi

void print_Code(char arr[], int size);
void cipher(char abc[],char info[], char key[],int e_inf, int e_key, char ciphered[]);
void decipher(char abc[],char ciphered[], char key[],int e_dec, int e_key, char deciphered[]);

int main()
{


    char abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char key[KEY_SIZE];
    char information[SIZE];
    char ciphered1[SIZE],ciphered2[SIZE],ciphered3[SIZE],ciphered4[SIZE],ciphered5[SIZE],ciphered6[SIZE],ciphered7[SIZE],ciphered8[SIZE],ciphered9[SIZE],ciphered10[SIZE];
    int i,end_info,end_key;
    char ch;
    char deciphered1[SIZE],deciphered2[SIZE],deciphered3[SIZE],deciphered4[SIZE],deciphered5[SIZE],deciphered6[SIZE],deciphered7[SIZE],deciphered8[SIZE],deciphered9[SIZE],deciphered10[SIZE];

    printf("Add meg a kulcsot!\n");
    i = 0;
    while( i< KEY_SIZE && (ch=getchar()) != '\n'){
        key[i] = ch;
        i++;
    }
    end_key = i;

    printf("Add meg a kodolando szoveget!\n");
    i = 0;
    while( i< SIZE && (ch=getchar()) != '\n'){
        information[i] = ch;
        i++;
    }




    end_info= i;

    clock_t start,end;

    start = clock();

    #pragma omp parallel
    {

    // 1
    cipher(abc,information,key,end_info,end_key,ciphered1);
    printf("A kodolt uzenet:\n");
    print_Code(ciphered1,end_info);
    decipher(abc,ciphered1,key,end_info,end_key,deciphered1);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered1,end_info);

      // 2
    cipher(abc,information,key,end_info,end_key,ciphered2);
    decipher(abc,ciphered1,key,end_info,end_key,deciphered2);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered2,end_info);

      // 3
    cipher(abc,information,key,end_info,end_key,ciphered3);
    decipher(abc,ciphered3,key,end_info,end_key,deciphered3);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered3,end_info);


      // 4
    cipher(abc,information,key,end_info,end_key,ciphered4);
    decipher(abc,ciphered4,key,end_info,end_key,deciphered4);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered4,end_info);

      // 5
    cipher(abc,information,key,end_info,end_key,ciphered5);
    decipher(abc,ciphered5,key,end_info,end_key,deciphered5);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered5,end_info);

      // 6
    cipher(abc,information,key,end_info,end_key,ciphered6);
    decipher(abc,ciphered6,key,end_info,end_key,deciphered6);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered6,end_info);

      // 7
    cipher(abc,information,key,end_info,end_key,ciphered7);
    decipher(abc,ciphered7,key,end_info,end_key,deciphered7);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered7,end_info);

      // 8
    cipher(abc,information,key,end_info,end_key,ciphered8);
    decipher(abc,ciphered8,key,end_info,end_key,deciphered8);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered8,end_info);

      // 9
    cipher(abc,information,key,end_info,end_key,ciphered9);
    decipher(abc,ciphered9,key,end_info,end_key,deciphered9);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered9,end_info);

      // 10
    cipher(abc,information,key,end_info,end_key,ciphered10);
    decipher(abc,ciphered10,key,end_info,end_key,deciphered10);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered10,end_info);
    }

    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("A szamitashoz felhasznalt ido: %.12f msp\n", time_spent);

    return 0;
}


void print_Code(char arr[], int size){

    int i;


    for( i=0 ; i != size; i++){
        printf("%c",arr[i]);
    }

    printf("\n");

    return ;
}


void cipher(char abc[],char info[], char key[],int e_inf, int e_key, char ciphered[]){

    char sub_abc[SIZE+KEY_SIZE];
    int i;
    int j;
    bool found;


    for(i = 0 ; i< e_key; i++){
        sub_abc[i] = key[i];
    }

    for( j=0 ; j< 26; j++){
        sub_abc[i] = abc[j];
        i++;
    }



    for( i = 0; i < e_inf; i++){
        j=0;
        found = false;
        while(!found){
            if(info[i] == abc[j]){
                found = true;
            }else {
                j++;
            }
        }

        ciphered[i] = sub_abc[j];

    }

}

void decipher(char abc[],char ciphered[], char key[],int e_dec, int e_key, char deciphered[]){

    char sub_abc[SIZE+KEY_SIZE];
    int i;
    int j;
    bool found;


    for(i = 0 ; i< e_key; i++){
        sub_abc[i] = key[i];
    }

    for( j=0 ; j< 26; j++){
        sub_abc[i] = abc[j];
        i++;
    }

    for ( i = 0; i < e_dec; i++){
        j=0;
        found = false;
        while(!found){
            if(ciphered[i] == sub_abc[j]){
                found = true;
            }else{
                j++;
            }
        }

        deciphered[i] = abc[j];
    }


}
