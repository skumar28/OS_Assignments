/*Print Even and Odd Numbers using PThread
 Created By: Akshay Chopra*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


#define NUMBERS_COUNT 100

//Function for printing the Even numbers
void *fun_Even(void *a)
{
  for(int i=2 ;i< NUMBERS_COUNT; i+=2)
  {
   printf("%d\n",i);
   usleep(100);	 
}
  
}

int main()
{
 int iRetVal;
 pthread_t t1;

 iRetVal=pthread_create(&t1, NULL, fun_Even, NULL);
  
 if(iRetVal)
 {
  printf("Error in Pthread Creation with Error Code %d",iRetVal);	
  return 'F';
 }


 //Printing the odd numbers
 for(int i=1; i< NUMBERS_COUNT; i+=2)
 {
  printf("%d\n",i);
  usleep(100);
 }

  pthread_join(t1, NULL);
  return 'S';

}

