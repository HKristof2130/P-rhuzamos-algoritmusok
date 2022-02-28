#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 60

void work();

int main()
{
    pthread_t thread;


    int i;

    for(i=1;i<=SIZE;i++){
        printf("%d munkafolyamat\n",i);
        pthread_create(&thread,NULL,work,NULL);
    }


    return 0;
}


void work(){

    sleep(1);
    return ;
}
