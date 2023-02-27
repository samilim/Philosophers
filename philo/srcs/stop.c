/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:10:08 by salimon           #+#    #+#             */
/*   Updated: 2023/02/27 06:40:23 by salimon          ###   ########.fr       */
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
			if (((get_time() - datas->philos[i].last_meal)) > datas->t_t_die)
			{
				datas->dead = 1;
				ms = get_time() - datas->timestamp;
				if (!datas->dining_end)
					printf("%dms %d %s\n", ms, i + 1, "died");
				pthread_mutex_unlock(&datas->death);
				return (1);
			}
			pthread_mutex_unlock(&datas->death);
			usleep(100);
			i++;
		}
		if (datas->dead)
			break;
		i = 0;
		while (datas-> meal_nb != -1 && i < datas->philo_nb && datas->philos[i].meal_count
				>= datas->philos[i].datas->meal_nb)
			i++;
		if (i == datas->philo_nb)
			datas->dining_end = 1;
	}
	return (1);
}

// void	*check_death(void *datas_void)
// {
// 	int			i;
// 	int ms;
// 	t_datas	*datas;

// 	datas = (t_datas *)datas_void;
	
// 	while (datas->philo_nb > 1 /*&& !datas->dining_end*/)
// 	{
// 		//printf("CHECKDEATH\n");
// 		i = 0;
// 		while (i < datas->philo_nb)
// 		{
// 			//printf("checkdeath\n");
// 			usleep(300);
// 			pthread_mutex_lock(&datas->death);
// 			//printf("last_meal = %lld\n", datas->philos[i].last_meal);
// 			//printf("death time = %lld\n", datas->philos[i].last_meal - get_time());
// 			//get_time() - datas->philos[i].last_meal) > datas->t_t_die
// 			if (((get_time() - datas->philos[i].last_meal)) > datas->t_t_die)
// 			{
// 				datas->dining_end = 1;
// 				ms = get_time() - datas->timestamp;
// 				if (!datas->maxmeals)
// 					printf("%dms %d %s\n", ms, i + 1, "died");
// 				pthread_mutex_unlock(&datas->death);
// 				usleep(800);
// 				return (NULL);
// 			}
// 			pthread_mutex_unlock(&datas->death);
// 			i++;
// 		}
// 	}
// 	return (NULL);
// }
