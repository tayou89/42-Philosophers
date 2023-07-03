#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_string
{
	pthread_mutex_t	*mutex;
	char			*thread;
}	t_string;

void	*print(void *string)
{
	t_string	*structure;
	int			count;
	int			i;

	structure = (t_string *) string;
	pthread_mutex_lock(structure->mutex);
	count = 0;
	i = 0;
	while (i < 13)
	{
		printf("%s count: %d\n", structure->thread, count);
		count++;
		usleep(1);
		i++;
	}
	pthread_mutex_unlock(structure->mutex);
	return (string);
}

int	main(void)
{
	pthread_t		pthread_1;
	pthread_t		pthread_2;
	pthread_t		pthread_3;
	pthread_mutex_t	mutex;
	t_string		*string;

	string = (t_string *) malloc(sizeof(t_string) * 3);
	string[0].thread = "thread_1";
	string[1].thread = "thread_2";
	string[2].thread = "thread_3";
	pthread_mutex_init(&mutex, (void *) 0);
	string[0].mutex = &mutex;
	string[1].mutex = &mutex;
	string[2].mutex = &mutex;
	printf("string[0].data.mutex address: %p\n", string[0].mutex);
	printf("string[1].data.mutex address: %p\n", string[1].mutex);
	printf("string[2].data.mutex address: %p\n", string[2].mutex);
	pthread_create(&pthread_1, (void *) 0, print, (void *) &string[0]);
	pthread_create(&pthread_2, (void *) 0, print, (void *) &string[1]);
	pthread_create(&pthread_3, (void *) 0, print, (void *) &string[2]);
	pthread_join(pthread_1, (void *) 0);
	pthread_join(pthread_2, (void *) 0);
	pthread_join(pthread_3, (void *) 0);
	pthread_mutex_destroy(&mutex);
	free(string);
	return (0);
}
