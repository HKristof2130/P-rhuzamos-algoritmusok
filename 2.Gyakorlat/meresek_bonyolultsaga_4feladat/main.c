#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateTextFile(int n);

int main()
{
    printf("Mennyi elem legyen a fajlban?\n");
    int num;
    num= scanf("%d",&num);
    int i;
    for(i=0; i<10; i++){
        printf("%d ", i);
    }
    printf("\n");
    generateTextFile(num);

    return 0;
}


void generateTextFile(int n){

    char abc[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','p','u','v','w','x','y','z',' ','\n','0','1','2','3','4','5','6','7','8','9'};
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
