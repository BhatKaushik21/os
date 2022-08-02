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
	int shm_fd,n1=0,n2=1,n3;
	void * ptr;
	shm_fd=shm_open("OS",O_CREAT | O_RDWR,0666);
	ftruncate(shm_fd,4096);
	ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
	printf("Child:\n");
	int n=atoi(argv[1]);
	sprintf(ptr,"0 ");
	ptr+=strlen(ptr);
	printf("0 ");
	if(n>1)
	{
		sprintf(ptr,"1 ");
		ptr+=strlen(ptr);
		printf("1 ");
	}
	int k=2;
	while(k!=n)
	{
		n3=n1+n2;
		sprintf(ptr,"%d ",n3);
		ptr+=strlen(ptr);
		printf("%d ",n3);
		n1=n2;
		n2=n3;
		k++;
	}
	sprintf(ptr,"\n");
	printf("\n");
	return 0;
}