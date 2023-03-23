/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:22:30 by salimon           #+#    #+#             */
/*   Updated: 2023/03/23 04:28:50 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine_philo(void *philo_void)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo_void;
	if (!((philo->position + 1) % 2))
		usleep(10000);
	while (1)
	{
		pthread_mutex_lock(&philo->datas->meal);
		if (philo->datas->dining_end || (philo->datas->meal_nb
				!= -1 && philo->meal_count >= philo->datas->meal_nb))
		{
			philo->last_meal = get_time();
			pthread_mutex_unlock(&philo->datas->meal);
			break ;
		}
		pthread_mutex_unlock(&philo->datas->meal);
		if (!eat(philo))
			return (NULL);
		print_log(philo, philo->position + 1, "is sleeping");
		usleep(philo->datas->t_t_sleep * 1000);
		print_log(philo, philo->position + 1, "is thinking");
	}
	return (NULL);
}

int	join_threads(t_datas *datas)
{
	int	i;

	i = 0;
	while (i < datas->philo_nb)
	{
		if (pthread_join(datas->philos[i].id, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	start_philosophers_dining(t_datas *datas)
{
	int	i;

	i = 0;
	datas->timestamp = get_time();
	if (datas->philo_nb == 1)
		return (one_philo_case(datas->philos));
	else
	{
		while (i < datas->philo_nb)
		{
			if ((pthread_create(&datas->philos[i].id, NULL,
						&routine_philo, &(datas->philos[i]))) != 0)
				return (0);
			datas->philos[i].last_meal = datas->timestamp;
			i++;
		}
		check_dining_state(datas);
		return (join_threads(datas));
	}
}

int	init_philos_and_mutexes(t_datas *datas)
{
	int	i;

	i = 0;
	if ((pthread_mutex_init(&datas->meal, NULL) != 0))
		return (0);
	if ((pthread_mutex_init(&datas->logs, NULL) != 0))
		return (0);
	while (i < datas->philo_nb)
	{
		datas->philos[i].datas = datas;
		datas->philos[i].position = i;
		datas->philos[i].left_fork = i;
		datas->philos[i].right_fork = (i + 1) % datas->philo_nb;
		datas->philos[i].last_meal = 0;
		datas->philos[i].meal_count = 0;
		if ((pthread_mutex_init(&datas->forks[i], NULL) != 0))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_datas	datas;

	memset(&datas, 0, sizeof(t_datas));
	if (argc != 5 && argc != 6)
		return (error_management(&datas, 1));
	if (!(check_digits(argc, argv)) || !(parsing(&datas, argc, argv)))
		return (error_management(&datas, 2));
	if (!(init_philos_and_mutexes(&datas)))
		return (error_management(&datas, 3));
	if (!(start_philosophers_dining(&datas)))
		return (error_management(&datas, 4));
	ft_clear(&datas);
	return (0);
}
