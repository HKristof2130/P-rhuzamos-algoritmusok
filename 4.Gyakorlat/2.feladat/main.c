#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>



#define NUM_OF_ELEMENTS 30



typedef struct arg_data{
    int thread_number;
} arg_data;

pthread_mutex_t value_mutex = PTHREAD_MUTEX_INITIALIZER;
static int num_of_threads;
static int my_array[NUM_OF_ELEMENTS];
static int odds;
int zeros;


void fill_array(int array[], int array_size);
void print_array(int array[], int array_size);
void run_threads_for_odd(int thread_num);
void run_threads_for_zeros(int thread_num);
void* is_odd(void* arg);
void* is_zero(void* arg);

int main()
{

    odds = 0;
    printf("Hany db szal elgyen?\n");
    scanf("%d",&num_of_threads);
    fill_array(my_array,NUM_OF_ELEMENTS);
    print_array(my_array,NUM_OF_ELEMENTS);
    run_threads_for_odd(num_of_threads);
    printf("Osszesen %d db paratlan szam van\n",odds);

    zeros = 0;
    run_threads_for_zeros(num_of_threads);
    printf("Osszesen %d db nulla van a tombben\n",zeros);



    return 0;
}



void* is_odd(void* arg){
    arg_data* current_thread_data = (arg_data*)arg;
    int start, end, count,i;

    end = (current_thread_data->thread_number) * (NUM_OF_ELEMENTS / num_of_threads);
    start = end - (NUM_OF_ELEMENTS / num_of_threads);
    printf("A futo szal azonositoja: %d\n", current_thread_data->thread_number);

    count = 0;

    pthread_mutex_lock(&value_mutex);
    for ( i = start; i < end ; i++ ){
        if( my_array[i]%2 != 0){
            count++;
        }
    }

    odds += count;
    pthread_mutex_unlock(&value_mutex);

    return NULL;



}

void fill_array(int array[], int array_size){

    int i;


    srand(time(0));
    for (i=0 ; i<array_size; i++){
        array[i] = rand()%(9999)+1;
    }

    return ;
}


void run_threads_for_odd(int thread_num){

    int i;

    for (i = 0; i < NUM_OF_ELEMENTS; i++)
        my_array[i] = i + 1;


    pthread_t id[thread_num];


    arg_data arg_arr[thread_num];


    int no_of_threads = thread_num;
    printf("Keszitek %d db szalat.....\n", no_of_threads);

    int thread_no = 1;


    for (thread_no = 1; thread_no <= thread_num; thread_no++) {
        arg_arr[thread_no - 1].thread_number = thread_no;
        pthread_create(&id[thread_no - 1], NULL, is_odd, &arg_arr[thread_no - 1]);
    }


    for (int i = 1; i <= thread_num; i++)
        pthread_join(id[i - 1], NULL);

    printf("Minden szal befejezte a munkat...\n");

}

void print_array(int array[], int array_size){

    int i;

    printf("A tomb elemei:\n");
    for(i = 0; i< array_size; i++){
        printf("%d \n", array[i]);
        }

}

void* is_zero(void* arg){

    arg_data* current_thread_data = (arg_data*)arg;
    int start,end,count,i;

    end = (current_thread_data->thread_number) * (NUM_OF_ELEMENTS / num_of_threads);
    start = end - (NUM_OF_ELEMENTS / num_of_threads);

    count = 0;
    pthread_mutex_lock(&value_mutex);
    for ( i = start; i < end; i++){
        if( my_array[i] == 0){
            count++;
        }
    }

    zeros += count;
    pthread_mutex_unlock(&value_mutex);

    return NULL;
}

void run_threads_for_zeros(int thread_num){

    int i;

    for (i = 0; i < NUM_OF_ELEMENTS; i++)
        my_array[i] = i + 1;


    pthread_t id[thread_num];


    arg_data arg_arr[thread_num];


    int no_of_threads = thread_num;
    printf("Keszitek %d db szalat.....\n", no_of_threads);

    int thread_no = 1;


    for (thread_no = 1; thread_no <= thread_num; thread_no++) {
        arg_arr[thread_no - 1].thread_number = thread_no;
        pthread_create(&id[thread_no - 1], NULL, is_zero, &arg_arr[thread_no - 1]);
    }


    for (int i = 1; i <= thread_num; i++)
        pthread_join(id[i - 1], NULL);

    printf("Minden szal befejezte a munkat...\n");

}
