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
	int shm_fd,i;
	pid_t pid;
	void * ptr;
	const int size=4096;
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
		execlp("./fib","fib",argv[1]);
	else if(pid>1)
	{
		wait(NULL);
		printf("Parent:Child completed\n");
		shm_fd=shm_open("OS",O_RDONLY,0666);
		ptr=mmap(0,size,PROT_READ,MAP_SHARED,shm_fd,0);
		printf("Parent :Printing\n");
		printf("%s ",(char*)ptr);
		shm_unlink("OS");
	}
	return 0;
}