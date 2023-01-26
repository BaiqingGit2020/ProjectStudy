#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *MyThread(void *Args){
	
	char *msg = (char *)Args;

	printf("%s : %s\n",__func__,msg);

	pthread_exit (msg);
}

int main(){

	pthread_attr_t Thread_attr_1;
	pthread_t ThreadID_1,ThreadID_2;
	
	pthread_attr_init(&Thread_attr_1);
	pthread_attr_setdetachstate(&Thread_attr_1,PTHREAD_CREATE_DETACHED);
	pthread_create(&ThreadID_1,&Thread_attr_1,MyThread,"create thread 1");

	pthread_create(&ThreadID_2,NULL,MyThread,"create thread 2");
	pthread_detach(ThreadID_2);
	
	sleep(1); // detached from main thread,So we should wait for thread print

	//printf("hello word!\n");
	
	return 0;
}