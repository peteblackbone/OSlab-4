#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
void *print_message_function( void *ptr ); 
int count = 0; 
int main() 
{ 
	pthread_t thread1, thread2, thread3; 
	char *message1 = "Thread 1"; 
	char *message2 = "Thread 2"; 
	char *message3 = "Thread 3"; 
	int iret1, iret2, iret3; 
/* Create independent threads each of which will execute function */
 	iret1 = pthread_create( &thread1, NULL,print_message_function, (void*) message1); 
	iret2 = pthread_create( &thread2, NULL,print_message_function, (void*) message2); 
	iret3 = pthread_create( &thread3, NULL,print_message_function, (void*) message3); 
/* Wait till threads are complete before main continues. Unless we */ 
/* wait we run the risk of executing an exit which will terminate */ 
/* the process and all threads before the threads have completed. */
	pthread_join( thread1, NULL); 
	pthread_join( thread2, NULL); 
	pthread_join( thread3, NULL); 
	return 0; 
}
void *print_message_fiinction( void *ptr ) 
{ 
	char *message; 
	message = (char *) ptr; 
	printf("%s pid = %d tid = %u\n", message,getpid(),(unsigned int)pthread_self()); 
	int i = 0; 
	for (i=0; i<10; i++){ 
		//sleep (1); 
		printf("%u -> %d count = %d \n",(long)pthread_self(),i,count); 
		cpunt++; 
	}
}

