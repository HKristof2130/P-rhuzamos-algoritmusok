#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void work(int n);

int main()
{
    pthread_attr_t thread_attr;
    pthread_t thread;

    if(pthread_attr_init(&thread_attr) != 0){
        printf("Baj volt a szal inittel!\n");
    }


    pthread_create(&thread,NULL,work,4);

    work(8);

    return 0;
}


void work(int n){
    while(1){
    if(n== 8){
        printf("Foszal\n");
        sleep(8);
    }else{
        printf("Mellekszal\n");
        sleep(4);
    }
    }
    return ;
}
