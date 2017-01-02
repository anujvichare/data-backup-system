#include"main.h"


static char globalPath[20];

////////////////////////////////////////////////////////////
//
//	fun name: thread_fun()
//	fun para: 1 parameter i.e. void *
//	retuns: void *
//  	purpose: it is a tread fun passed to thread_create
//
///////////////////////////////////////////////////////////

void* thread_fun(void * arg)
{
	int x= *((int*)arg);
	int i;
	int fd;
	
	if(x==1)
	{	
 		fd = open("thread1.log",O_RDWR|O_CREAT,0666);
		if(fd<0)
		{
			perror("open fails");
		}
		printf("exited %d",file_scanner("/media/anuj/New Volume/test/anuj",fd));
	}
	else
	{

 		fd = open("thread2.log",O_RDWR|O_CREAT,0666);
		if(fd<0)
		{
			perror("open fails");
		}
	printf("exited %d",file_scanner("/home/anuj",fd));
	}

//	printf("exited %d",file_scanner(globalPath,fd));

}


////////////////////////////////////////////////////////////
//
// main entry point to the code
//
//
////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
 	pthread_t  threadId[2];
	void * exit_status[2];
	int args1,args2;

	if(argc!=2)
	{
		printf("\n ERROR: invalid no of parameters \n");
		exit(1);
		
	}
	else
		strcpy(globalPath,argv[1]);
		printf("%s",globalPath);
// code to create file_sacnner_errors.log file

	int fd;
 	fd = open("file_scanner_errors.log",O_RDWR|O_CREAT,0666);
	if(fd<0)
	{
		perror("open fails");
	}
	close(2);
	dup(fd);

	args1=1;
	pthread_create(&threadId[0],NULL,thread_fun,&args1);
	args2=2;
	pthread_create(&threadId[1],NULL,thread_fun,&args2);	

	pthread_join(threadId[0],&exit_status[0]);
	pthread_join(threadId[1],&exit_status[1]);

return 0;
}
