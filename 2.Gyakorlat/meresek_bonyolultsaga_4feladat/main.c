#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateTextFile(int n);
int numberOfRows(int n);
int numberOfEmptyRows(int n);

int main()
{
    printf("Mennyi elem legyen a fajlban?\n");
    int num;
    scanf("%d",&num);
    generateTextFile(num);
    printf("A sorok szama a fajlban : %d \n",numberOfRows(num));
    FILE* file= fopen("empty.txt","w");
    int i;
    char newl= '\n';
    fprintf(file,"%c",'a');
    for(i=1; i<=3;i++){
        fprintf(file,"%c",newl);
    }
    fprintf(file,"%c",'b');
    printf("A ures sorok szama a fajlban : %d \n",numberOfEmptyRows(num));
    sleep(10);
    fclose(file);


    return 0;
}


void generateTextFile(int n){

    char abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','p','u','v','w','x','y','z',' ','0','1','2','3','4','5','6','7','8','9','\n'};
    FILE* fp= fopen("textfile.txt","w");
    int i, index;
    char tmp[n];
    srand(time(0));
    for(i=0; i<n; i++){
        index = rand()%39 ;
        printf("A %d index :%d\n",i+1,index);
        tmp[i] = abc[index];
    }

    for(i=0; i<n;i++){
        fprintf(fp,"%c",tmp[i]);
    }

    fclose(fp);

    return ;

}

int numberOfRows(int n){

    int count=1;
    FILE* fp= fopen("textfile.txt","r");
    int i;
    char tmp[n+1];
    for(i=0; i<n; i++){
        fscanf(fp,"%c",&tmp[i]);
    }
    tmp[i]=  '\0';

    for(i=0; i<n; i++){
        if(tmp[i] == '\n'){
            count ++;
        }
    }

    return count;
}

int numberOfEmptyRows(int n){
    int count=0;
    FILE* fp= fopen("empty.txt","r");
    if(fp == NULL){
        printf("Nem lehet megnyitni\n");
        return -1;
    }
    int i;
    printf("megnyitottam\n");
    i=0;
    char tmp[6];
    char c;
    /*while(fscanf(fp,"%c",&tmp[i]) ){
        printf("%02x\n",(int)tmp[i]);
        i++;
    }*/
    fscanf(fp,"%c",&c);
    printf("%d\n",(int)c);

    //tmp[i]= '\0';

    printf("beszkeneltem\n");

    for(i=0; i!='\0'; i++){
        if(tmp[i] == '\n'){
                printf("Egy ures sor a %d indexnel\n",i);
            if(tmp[i+1] == '\r'){
                printf("Megegy ures sor a %d indexnel\n",i);
                count ++;
            }
        }
    }
    fclose(fp);

    return count;
}
