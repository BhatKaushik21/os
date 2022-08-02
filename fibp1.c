#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int shmid,i;
	pid_t pid;
	void * ptr;
	shmid=shmget((key_t) 1122,4096,0666 | IPC_CREAT);
	ptr=shmat(shmid,NULL,4096);
	if(argc>1)
	{
		sscanf(argv[1],"%d",&i);
		if(i<1)
		{
			printf("Invalid\n");
			exit(0);
		}
	}
	else
	{
		printf("N is not passed through command line\n");
		exit(0);
	}
	pid=fork();
	if(pid==0)
		execlp("./fib","fib",argv[1],NULL);
	else if(pid>1)
	{
		wait(NULL);
		printf("Parent:Child completed\n");
		printf("Parent :Printing\n");
		printf("%s ",(char*)ptr);
		//shmctl(shmid,IPC_RMID,NULL);
	}
	shmdt(ptr);
	return 0;
}