#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int ret,no1,no2,num1,num2,r,res,s;
int main()
{

int arr1[2],arr2[2];


ret=pipe(arr1);
ret=pipe(arr2);

	ret=fork();
	if(ret==0)
	{
		//child
		close(arr1[0]);
		close(arr2[1]);
		printf("enter no1 : \n");
		scanf("%d",&no1);
		printf("enter no2 : \n");
		scanf("%d",&no2);

		write(arr1[1],&no1,sizeof(no1));
		write(arr1[1],&no2,sizeof(no2));
		
		read(arr2[0],&r,sizeof(r));
		printf("addition= %d\n",r);
		close(arr1[1]);
		close(arr2[0]);

	}

	else
	{
		//parent
		close(arr1[1]);
		close(arr2[0]);
		
		read(arr1[0],&num1,sizeof(num1));
		read(arr1[0],&num2,sizeof(num2));
		
		res=num1+num2;

		write(arr2[1],&res,sizeof(res));

		close(arr1[0]);
		close(arr2[1]);
		waitpid(-1,&s,0);
	}

return 0;
}

