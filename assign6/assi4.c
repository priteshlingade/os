#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

	int ret1,ret2,ret3;

	ret1=fork();
	if(ret1==0)
	{
		ret2=fork();
		if(ret2==0)
		{
			ret3=fork();
			if(ret3==0)
			{
				printf("child 3 : \n");
				printf("pid  = %d\n",getpid());
				printf("ppid = %d\n \n",getppid());
				_exit(0);
			}
   				 printf("child 2 : \n");
                 printf("pid  = %d\n",getpid());
                 printf("ppid = %d\n \n",getppid());
                _exit(0);

		}
		    	 printf("child 3 : \n");
                 printf("pid  = %d\n",getpid());
 			     printf("ppid = %d\n \n",getppid());
                 _exit(0);
	}


return 0;
}
