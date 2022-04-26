#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "sub-cipher.h"

// kulcs : vas
// probának : sqvtgilpubiueupxnqytvqjnfrbxgmtuswrvuhatzbyfhmdlnxenudbbmbzcswgpmknnyfnwupddltxzalefeiqvxtwillvdnwymagjyneezqhpbbejgbeioőugoőnwoojgbeőigbwőivjnbeőiuebgőojngőijbeőojvneőovjeőovjneőovbedabiebvpiebveivbeqivbqeivbeiővbeqiővuebviőbeőivebvőioeqbviqehbveqbvqiővbqeiővbeőivbeqőviqebviőeqbvőiqbvőiqvbqeivbeqiővbeqivbeqivbqeővibeqvi



int main()
{

    int keySize = 8;
    int arrSize = 200;
    char abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char key[keySize];
    char information[arrSize];
    char ciphered1[arrSize],ciphered2[arrSize],ciphered3[arrSize],ciphered4[arrSize],ciphered5[arrSize],ciphered6[arrSize],ciphered7[arrSize],ciphered8[arrSize],ciphered9[arrSize],ciphered10[arrSize];
    int i,end_info,end_key;
    char ch;
    char deciphered1[arrSize],deciphered2[arrSize],deciphered3[arrSize],deciphered4[arrSize],deciphered5[arrSize],deciphered6[arrSize],deciphered7[arrSize],deciphered8[arrSize],deciphered9[arrSize],deciphered10[arrSize];



    printf("Add meg a kulcsot!\n");
    i = 0;
    while( i< keySize && (ch=getchar()) != '\n'){
        key[i] = ch;
        i++;
    }
    end_key = i;

    printf("Add meg a kodolando szoveget!\n");
    i = 0;
    while( i< arrSize && (ch=getchar()) != '\n'){
        information[i] = ch;
        i++;
    }
    end_info= i;


    clock_t start,end;
    start = clock();

    // 1
    cipher(abc,information,key,end_info,end_key,ciphered1, keySize, arrSize);
    printf("A kodolt uzenet:\n");
    print_Code(ciphered1,end_info);
    decipher(abc,ciphered1,key,end_info,end_key,deciphered1, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered1,end_info);

      // 2
    cipher(abc,information,key,end_info,end_key,ciphered2, keySize, arrSize);
    decipher(abc,ciphered1,key,end_info,end_key,deciphered2, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered2,end_info);

      // 3
    cipher(abc,information,key,end_info,end_key,ciphered3, keySize, arrSize);
    decipher(abc,ciphered3,key,end_info,end_key,deciphered3, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered3,end_info);


      // 4
    cipher(abc,information,key,end_info,end_key,ciphered4, keySize, arrSize);
    decipher(abc,ciphered4,key,end_info,end_key,deciphered4, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered4,end_info);

      // 5
    cipher(abc,information,key,end_info,end_key,ciphered5, keySize, arrSize);
    decipher(abc,ciphered5,key,end_info,end_key,deciphered5, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered5,end_info);

      // 6
    cipher(abc,information,key,end_info,end_key,ciphered6, keySize, arrSize);
    decipher(abc,ciphered6,key,end_info,end_key,deciphered6, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered6,end_info);

      // 7
    cipher(abc,information,key,end_info,end_key,ciphered7, keySize, arrSize);
    decipher(abc,ciphered7,key,end_info,end_key,deciphered7, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered7,end_info);

      // 8
    cipher(abc,information,key,end_info,end_key,ciphered8, keySize, arrSize);
    decipher(abc,ciphered8,key,end_info,end_key,deciphered8, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered8,end_info);

      // 9
    cipher(abc,information,key,end_info,end_key,ciphered9, keySize, arrSize);
    decipher(abc,ciphered9,key,end_info,end_key,deciphered9, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered9,end_info);

      // 10
    cipher(abc,information,key,end_info,end_key,ciphered10, keySize, arrSize);
    decipher(abc,ciphered10,key,end_info,end_key,deciphered10, keySize, arrSize);
    printf("A visszakodolt uzenet:\n");
    print_Code(deciphered10,end_info);




    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("A szamitashoz felhasznalt ido: %.12f msp\n", time_spent);

    return 0;
}











