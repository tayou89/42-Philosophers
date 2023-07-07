#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include "philo.h"

void	*count_number(void *number);

int	main(void)
{
	pthread_t	thread;
	int			number;

	number = 0;
	if (pthread_create(&thread, (void *) 0, count_number, &number) != 0)
		return (1);
	pthread_detach(thread);
	if (pthread_join(thread, (void *) 0) != 0)
		perror("");
	return (0);
}

void	*count_number(void *number)
{
	int	n;

	n = (int) (void *) number;
	while (n < 100)
		n++;
	return (number);
}
