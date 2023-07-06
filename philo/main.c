#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include "philo.h"

int	main(void)
{
	struct timeval	time;
	int				i;

	gettimeofday(&time, (void *) 0);
	printf("start_sec: %llu\n", (unsigned long long) time.tv_sec);
	printf("start_usec: %llu\n", (unsigned long long) time.tv_usec);
	i = 0;
	while (i < 1000000)
		i++;
	gettimeofday(&time, (void *) 0);
	printf("end_sec: %llu\n", (unsigned long long) time.tv_sec);
	printf("end_usec: %llu\n", (unsigned long long) time.tv_usec);
	return (0);
}
