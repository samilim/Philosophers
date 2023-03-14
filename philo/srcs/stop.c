/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:10:08 by salimon           #+#    #+#             */
/*   Updated: 2023/03/14 04:41:05 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



int	check_death(t_datas *datas)
{
	int			i;
	int ms;
	
	while (datas->philo_nb > 1 && !datas->dining_end)
	{
		i = 0;
		while (i < datas->philo_nb && !datas->dead)
		{
			pthread_mutex_lock(&datas->death);
			pthread_mutex_lock(&datas->meal);
			if (((get_time() - datas->philos[i].last_meal)) > datas->t_t_die)
			{
				datas->dead = 1;
				ms = get_time() - datas->timestamp;
				if (!datas->dining_end)
					printf("%dms %d %s\n", ms, i + 1, "died");
				pthread_mutex_unlock(&datas->death);
				pthread_mutex_unlock(&datas->meal);
				return (1);
			}
			pthread_mutex_unlock(&datas->meal);
			pthread_mutex_unlock(&datas->death);
			usleep(100);
			i++;
		}
		i = 0;
		pthread_mutex_lock(&datas->meal);
		while (datas-> meal_nb != -1 && i < datas->philo_nb && datas->philos[i].meal_count
				>= datas->philos[i].datas->meal_nb)
				i++;
		if (i == datas->philo_nb)
			datas->dining_end = 1;
		pthread_mutex_unlock(&datas->meal);
	}
	return (1);
}
