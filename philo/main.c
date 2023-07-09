#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_data
{
	pthread_mutex_t	mutex;
	int				number;
}	t_data;

void	*ft_thread(void *data)
{
	t_data *all;

	all = (t_data *) data;
	pthread_mutex_lock(&all->mutex);
	while (all->number < 10)
	{
		printf("all->number: %d\n", all->number);
		all->number++;
	}
	all->number = 0;
	pthread_mutex_unlock(&all->mutex);
	return (data);
}

int	main(void)
{
	pthread_t		thread[2];
	t_data 			data;

	pthread_mutex_init(&data.mutex, (void *) 0);
	data.number = 0;
	pthread_create(&thread[0], (void *) 0, ft_thread, (void *)  &data);
	pthread_create(&thread[1], (void *) 0, ft_thread, (void *)  &data);
	pthread_join(thread[0], (void *) 0);
	pthread_join(thread[1], (void *) 0);
	return (0);
}
