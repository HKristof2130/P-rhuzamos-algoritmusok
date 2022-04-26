#ifndef SUB-CIPHER_H_INCLUDED
#define SUB-CIPHER_H_INCLUDED

void print_Code(char arr[], int arraySize){

    int i;


    for( i=0 ; i != arraySize; i++){
        printf("%c",arr[i]);
    }

    printf("\n");

    return ;
}


void cipher(char abc[],char info[], char key[],int e_inf, int e_key, char ciphered[], int keySize, int arraySize){

    char sub_abc[arraySize+keySize];
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

void decipher(char abc[],char ciphered[], char key[],int e_dec, int e_key, char deciphered[], int keySize, int arraySize){

    char sub_abc[arraySize+keySize];
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


#endif // SUB-CIPHER_H_INCLUDED
