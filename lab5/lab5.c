#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem1, sem2;
int n;
int i = 0;
static int dem = 0;
int a[30001];

// Chung ta se tao ra ham delay() dung thoi gian hien tai thay vi su dung ham sleep()
int delay(long seconds)
{
	time_t t1;
	t1 = time(0) + seconds;
	while (time(0) < t1);
}

void* PROCESSA()
{
	while (1)
	{
		if (dem < n)
		{
			a[i++] = rand() % (n - 1);
			dem++;
			printf("\n[PUSH] So luong phan tu trong mang A: %2d", dem);
		}
		int time_delay = rand() % 2 + 1;
		delay(time_delay);
		sem_post(&sem1);
	}
}

void* PROCESSB()
{
	int j, b;
	while (1)
	{
		sem_wait(&sem1);
		if (dem <= n)
		{
			if (dem == 0)
			{
				printf("\n[POP] Nothing in array A");
			}
			else
			{
				dem--;
				b = a[0];
				for (j = 0; j < dem; j++)
				{
					a[j] = a[j + 1];
				}
				printf("\n[POP] So luong phan tu trong mang A: %2d", dem);
			}
		}
		int time_delay = rand() % 2 + 1;
		delay(time_delay);
	}
}

void main()
{
	sem_init(&sem1, 1, 0);
	sem_init(&sem2, 0, 0);
	n = 30001;
	pthread_t th1, th2;
	pthread_create(&th1, NULL, PROCESSA, NULL);
	pthread_create(&th2, NULL, PROCESSB, NULL);
	while(1);
}
