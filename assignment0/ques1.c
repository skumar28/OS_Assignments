#include<stdio.h>
#include<pthread.h>

int MAX_COUNT = 1000;

int main(){

void * printEven(void *);
pthread_t tid;
int i;

int status = pthread_create(&tid, NULL, printEven, &tid);

if(status != 0){
   printf("Thread creation failed\n");
}
//main thread printing odd numbers
for(i = 1; i < 1000; i = i+2){
   printf("%d\n", i);
}

pthread_join(tid,NULL);

return 0;
}

void * printEven(void * arg){
int i;

//the newly created thread pinting the even numbers
for(i = 2; i <= MAX_COUNT; i = i+2 ){
   printf("%d \n", i);
}

return 0;
}
