#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>
int ret;
int arr[2];
char ch='A';

void sigint_handler(int sig)
{
	close(arr[1]);
	close(arr[0]);
	_exit(1);
}



int main()
{
	ret=pipe(arr);
	struct sigaction sa;
	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler=sigint_handler;
	ret = sigaction(SIGINT,&sa,NULL);
	if(ret<0)
	{
		perror("sigaction() fault! \n");
		_exit(1);
	}

	int cnt=0;
	while(1)
	{	
		write(arr[1],&ch,sizeof(ch));
		cnt++;
		printf("byte written : %d\n",cnt);
	}


	return 0;
}
