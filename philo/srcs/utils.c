/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:02:24 by salimon           #+#    #+#             */
/*   Updated: 2023/03/23 01:52:16 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_clear(t_datas *datas)
{
	int	i;

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
int	smart_sleep(t_datas *datas, long long ms)
{
	int	time;

	time = 0;
	while (time < ms)
	{
		pthread_mutex_lock(&datas->death);
		pthread_mutex_lock(&datas->meal);
		if (datas->dining_end || datas->dead)
		{
			pthread_mutex_unlock(&datas->death);
			pthread_mutex_unlock(&datas->meal);
			return (1);
		}
		pthread_mutex_unlock(&datas->death);
		pthread_mutex_unlock(&datas->meal);
		usleep(1000);
		time++;
	}
	return (0);
}

int	ft_atoi(const char *nb)
{
	unsigned int	i;
	int				signe;
	int				nmb;

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

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	print_log(t_philosopher *philo, int id, char *message)
{
	int	ms;

	pthread_mutex_lock(&philo->datas->logs);
	ms = get_time() - philo->datas->timestamp;
	pthread_mutex_lock(&philo->datas->death);
	pthread_mutex_lock(&philo->datas->meal);
	if (!philo->datas->dining_end && !philo->datas->dead)
		printf("%dms %d %s\n", ms, id, message);
	pthread_mutex_unlock(&philo->datas->meal);
	pthread_mutex_unlock(&philo->datas->death);
	pthread_mutex_unlock(&philo->datas->logs);
}
