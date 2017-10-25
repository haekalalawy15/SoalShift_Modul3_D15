#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

//int pthread_create(pthread_t * thread,const pthread_attr_t * attr,void * (*start_routine)(void *),void *arg);

pthread_t tid1;
pthread_t tid2;
int status_lohan=100;
int status_kepiting=100;
int status=0;

void* lohan(void *arg)
{
	while((status_lohan>0)&&(status_lohan<=100)&&status!=1)
	{
		if (status==1)return NULL;
		sleep(10);
		status_lohan -=15;
		system("clear");
		printf("Status Lohan: %d\n",status_lohan);
		printf("Status Kepiting: %d\n",status_kepiting);
		printf("memberi makan kepiting: 1 , memberi makan lohan: 2\n");
	}
	
	printf("lohan mati\n");
	status=1;
	return (0);
}

void* kepiting(void *arg)
{

    while((status_kepiting>0)&&(status_kepiting<=100)&&status!=1)
	{
		if(status==1)return 0;
		sleep(20);
		status_kepiting-=10;
		system("clear");
		printf("Status Lohan: %d\n",status_lohan);
		printf("Status Kepiting: %d\n",status_kepiting);
		printf("memberi makan kepiting: 1 , memberi makan lohan: 2\n");
	} 
	
	printf("kepiting mati\n");
	status=1;
	return (0);
}

int main()
{
	int command;
	
	pthread_create(&tid1,NULL,&lohan,NULL);
	pthread_create(&tid2,NULL,&kepiting,NULL);
	printf("memberi makan kepiting: 1 , memberi makan lohan: 2\n");
	while((status_lohan>0)&&(status_lohan<=100)&&(status_kepiting>0)&&(status_kepiting<=100))
	{
		if(status==1)break;
		scanf("%d",& command);
		if(command==2){
			status_lohan+=10;
			if(status_lohan>100){
				printf("lohan mati\n");
				break;
			}
		}
		else if(command==1){
			status_kepiting+=10;
			if(status_kepiting>100){
				printf("kepiting mati\n");
				break;
			}
		}
	}
return 0;
}
