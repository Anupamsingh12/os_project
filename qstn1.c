#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a=0;
void *func(void *var)
{
	for(int i=1;i<a;i++)
	{
		int count=0;
		for(int j=1;j<a;j++)
		{
			if(i%j==0)
			{
				count++;
			}
		}
		if(count==2)
		{
			printf("%d ",i);		
		}

	}
}

int main()
{
	printf("Enter NUmber:- ");
	scanf("%d",&a);
	pthread_t th_id;
	pthread_create(&th_id,NULL,func,NULL);
	pthread_join(th_id,NULL);
	exit(0);
}
