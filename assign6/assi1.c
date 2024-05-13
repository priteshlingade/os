// one parent three child processes


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int ret1,ret2,ret3;


	ret1=fork();
	if(ret1==0)
	{
		for(int i=0;i<10;i++)
		{
			printf("child 1 :%d \n",i);
			sleep(1);
		}
		_exit(0);
	}
	
	ret2=fork();
	if(ret2==0)
	{
		for(int i=0;i<10;i++)
		{
			printf("child 2 :%d \n",i);
			sleep(1);
		}
		_exit(0);
	}

	ret3=fork();
	if(ret3==0)
	{
		for(int i=0;i<10;i++)
		{
			printf("child 3 :%d\n",i);
			sleep(1);
		}
		_exit(0);

	}
	else
	{
	for(int i=0;i<10;i++)
		{
			printf("parent  :%d \n",i);
			sleep(1);
		}
	}
return 0;	
}
