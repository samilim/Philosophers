/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:10:08 by salimon           #+#    #+#             */
/*   Updated: 2023/03/23 03:10:32 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_meals(t_datas *datas)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&datas->meal);
	while (datas-> meal_nb != -1 && i < datas->philo_nb
		&& datas->philos[i].meal_count >= datas->philos[i].datas->meal_nb)
			i++;
	if (i == datas->philo_nb)
		datas->dining_end = 1;
	pthread_mutex_unlock(&datas->meal);
}

// int	check_dining_state(t_datas *datas)
// {
// 	int	i;

// 	while (datas->philo_nb > 1 && !datas->dining_end)
// 	{
// 		i = 0;
// 		while (i < datas->philo_nb && !datas->dead)
// 		{
// 			pthread_mutex_lock(&datas->death);
// 			pthread_mutex_lock(&datas->meal);
// 			if (((get_time() - datas->philos[i].last_meal)) > datas->t_t_die)
// 			{
// 				datas->dead = 1;
// 				if (!datas->dining_end)
// 					printf("%lldms %d %s\n", get_time() - datas->timestamp, i + 1, "died");
// 			}
// 			pthread_mutex_unlock(&datas->meal);
// 			pthread_mutex_unlock(&datas->death);
// 			if (datas->dead)
// 				return (1);
// 			usleep(300);
// 			i++;
// 		}
// 		check_meals(datas);
// 	}
// 	return (1);
// }

int	check_dining_state(t_datas *datas)
{
	int	i;

	while (datas->philo_nb > 1 && !datas->dining_end)
	{
		i = 0;
		while (i < datas->philo_nb && !datas->dining_end)
		{
			//pthread_mutex_lock(&datas->death);
			pthread_mutex_lock(&datas->meal);
			if (((get_time() - datas->philos[i].last_meal)) > datas->t_t_die)
			{
				if (!datas->dining_end)
					printf("%lldms %d %s\n", get_time() - datas->timestamp, i + 1, "died");
				datas->dining_end = 1;
			}
			pthread_mutex_unlock(&datas->meal);
			//pthread_mutex_unlock(&datas->death);
			if (datas->dining_end)
				return (1);
			usleep(300);
			i++;
		}
		check_meals(datas);
	}
	return (1);
}