/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:02:24 by salimon           #+#    #+#             */
/*   Updated: 2023/02/26 14:01:24 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void ft_clear(t_datas *datas) /*déplacer les mutex destroy hors de cette fct ?*/
{
	int i;

	i = 0;
	while (i < datas->philo_nb)
	{
		pthread_mutex_destroy(&datas->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&datas->meal);
	pthread_mutex_destroy(&datas->logs);
	pthread_mutex_destroy(&datas->death);
	free(datas->philos);
	free(datas->forks);
}

/*permet de terminer le sleep prematurement quand une death est detectee*/
int smart_sleep(t_datas *datas, long long ms)
{
	int time;

	time = 0;
	// printf("smart sleep with ms = %lld\n", ms);
	while (time < ms)
	{
		// printf("usleep %d ", time);
		// printf("\ndining end = %d \n", datas->dining_end);
		if (datas->dining_end)
		{
			return (1);
		}
		usleep(1000);
		time++;
	}
	/*OU
	i = get_time();
	while not dead
		si gettime - i >= ttdie
			break
		usleep50
	*/
	return (0);
}

int ft_atoi(const char *nb)
{
	unsigned int i;
	int signe;
	int nmb;

	signe = 1;
	i = 0;
	nmb = 0;
	while (nb[i] == ' ' || (nb[i] >= 8 && nb[i] <= 13))
		i++;
	while (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			signe *= -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
		nmb = nmb * 10 + nb[i++] - '0';
	return (nmb * signe);
}

long long get_time(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void print_log(t_philosopher *philo, int id, char *message)
{
	int ms;

	pthread_mutex_lock(&philo->datas->logs);
	ms = get_time() - philo->datas->timestamp;
	// printf("ABOUT TO PRINT AT %dms\n", ms);
	if (!philo->datas->dining_end)
		printf("%dms %d %s\n", ms, id, message);
	pthread_mutex_unlock(&philo->datas->logs);
}
