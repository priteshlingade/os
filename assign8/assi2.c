#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int ret, i;

	for(i=0;i<3;i++)
	{
		ret=fork();

		if(ret==0)
		{
			for(int j=0;j<10;j++)
			{
				printf("child %d : %d\n",i,j);
				sleep(1);
			}
		_exit(0);
		}

			for(int i=0;i<10;i++)
			{
				printf("parent : %d\n",i);
				sleep(1);
			}
		}

return 0;
}
