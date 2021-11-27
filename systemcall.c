#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t p;
	int i;
	p=fork();
	if(p==1)
	{
		printf("fork error");
		exit(-1);
	}
	else
	
		if(p==0)
		{
			for(i=0;i<5;i++)
			{
				execlp("ls","ls","-l",NULL);
				printf("child process \n");
			}
		}
	
     else
	{
		wait(0);
		for(i=0;i<5;i++)
		{
			printf("parent process\n");
		}
		exit(0);
	}
}
