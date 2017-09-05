#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

pthread_mutex_t lockmain;
pthread_mutex_t lock;
int MAX_COUNT = 20;
sem_t sem;
sem_t sem2;

int main(){

void * printEven(void *);
pthread_t tid;
int i;
int * v1;
int * v2;
int semVal =  sem_init(&sem,0,0);
int semVal2 =  sem_init(&sem2,0,0);

int status = pthread_create(&tid, NULL, printEven, &tid);

if(status != 0){
   printf("Thread creation failed\n");
}


if(pthread_mutex_init(&lock, NULL) != 0){
	printf("mutex lock initialization failed \n");
	return 1;
}

sem_getvalue(&sem,v1 );
sem_getvalue(&sem2,v2);
printf("Values:  sem : %d and sem2 : %d \n", *v1, *v2);

//main thread printing odd numbers
for(i = 1; i < MAX_COUNT; i = i+2){
   sem_post(&sem);
   printf("%d\n", i);
   sem_wait(&sem2);  
   }

pthread_join(tid,NULL);
pthread_mutex_destroy(&lock);

return 0;
}

void * printEven(void * arg){
int i;

//the newly created thread pinting the even numbers
for(i = 2; i <= MAX_COUNT; i = i+2 ){

  sem_post(&sem2);  
   printf("%d \n", i);
   sem_wait(&sem);

}

return 0;
}
