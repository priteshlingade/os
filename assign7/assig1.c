#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main()
{

int pid,signo,err;

printf("enter process id : ");
scanf("%d",&pid);

printf("\n enter signal no. ");
scanf("%d",&signo);

err=kill(pid,signo);

	if(err==0)
	{
		printf("process kill sucessfully \n");
	}

	else
	{
		printf("procell kill fail \n");

	}

return 0;
}
