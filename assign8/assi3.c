#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int ret,s,i;
	i=1;
	while(1)
	{

		ret=fork();
		if(ret==0)
		{
			printf("child : %d\n ",i);
			_exit(0);
		}
		else if(ret==-1)
		break;

		else
		{
			i++;
		}
		
	

	}
for(int j=1;i<=i;j++)
wait(&s);

return 0;
}
