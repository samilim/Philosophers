/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:10:08 by salimon           #+#    #+#             */
/*   Updated: 2023/02/26 14:23:18 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*lancer si 5e arg ; verifie l nb de repas de chaque philo*/
/*int	check_meals(t_datas *datas)
{
	int			i;

	while (!datas->dining_end)
	{
		i = 0;
		while (datas->meal_nb != -1 && i < datas->philo_nb)
		{
			pthread_mutex_lock(&datas->death);
			if (datas->philos[i].meal_count
				< datas->philos[i].datas->meal_nb)
			{
				pthread_mutex_unlock(&datas->death);
				break ;
			}
			else if (i == (datas->philo_nb - 1) && (datas->philos[i].meal_count
					>= datas->philos[i].datas->meal_nb))
			{
				datas->maxmeals = 1;
				datas->dining_end = 1;
				//usleep(300);
				pthread_mutex_unlock(&datas->death);
				return (1);
			}
			pthread_mutex_unlock(&datas->death);
			i++;
		}
	}
	return (0);
}*/

void	*check_meals(void *datas_void)
{
	int			i;
	t_datas	*datas;

	datas = (t_datas *)datas_void;

	while (!datas->dining_end)
	{
		i = 0;
		while (datas->meal_nb != -1 && i < datas->philo_nb)
		{
			pthread_mutex_lock(&datas->death);
			if (datas->philos[i].meal_count
				< datas->philos[i].datas->meal_nb)
			{
				pthread_mutex_unlock(&datas->death);
				break ;
			}
			else if (i == (datas->philo_nb - 1) && (datas->philos[i].meal_count
					>= datas->philos[i].datas->meal_nb))
			{
				datas->maxmeals = 1;
				datas->dining_end = 1;
				//usleep(300);
				pthread_mutex_unlock(&datas->death);
				return (NULL);
			}
			pthread_mutex_unlock(&datas->death);
			i++;
		}
	}
	return (NULL);
}

/*à placer probablement avant join pour check la death
en continu ou bien créer un thread dédié en deébut de simu?
est-ce aue je dois check le nb de repqs dqns cette meme fonction ?*/
// int	check_death(t_datas *datas)
// {
// 	int			i;
// 	int ms;
	
// 	while (datas->philo_nb > 1 /*&& !datas->dining_end*/)
// 	{
// 		//printf("CHECKDEATH\n");
// 		i = 0;
// 		while (i < datas->philo_nb)
// 		{
// 			//printf("checkdeath\n");
// 			usleep(800);
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
// 				return (1);
// 			}
// 			pthread_mutex_unlock(&datas->death);
// 			i++;
// 		}
// 	}
// 	return (1);
// }

// int	check_death(t_datas *datas)
// {
// 	int			i;
// 	int ms;
	
// 	while (datas->philo_nb > 1 && !datas->dining_end)
// 	{
// 		//printf("CHECKDEATH\n");
// 		i = 0;
// 		while (i < datas->philo_nb && !datas->dead)
// 		{
// 			//printf("checkdeath\n");
// 			pthread_mutex_lock(&datas->death);
// 			//printf("last_meal = %lld\n", datas->philos[i].last_meal);
// 			//printf("death time = %lld\n", datas->philos[i].last_meal - get_time());
// 			//get_time() - datas->philos[i].last_meal) > datas->t_t_die
// 			if (((get_time() - datas->philos[i].last_meal)) > datas->t_t_die)
// 			{
// 				datas->dining_end = 1;
// 				datas->dead = 1;
// 				ms = get_time() - datas->timestamp;
// 				if (!datas->maxmeals)
// 					printf("%dms %d %s\n", ms, i + 1, "died");
// 				pthread_mutex_unlock(&datas->death);
// 				usleep(100);
// 				return (1);
// 			}
// 			pthread_mutex_unlock(&datas->death);
// 			i++;
// 		}
// 		if (datas->dead)
// 			break;
// 		i = 0;
// 		while (datas-> meal_nb != -1 && i < datas->philo_nb && datas->philos[i].meal_count
// 				>= datas->philos[i].datas->meal_nb)
// 			i++;
// 		if (i == datas->philo_nb)
// 			datas->dining_end = 1;
// 	}
// 	return (1);
// }

void	*check_death(void *datas_void)
{
	int			i;
	int ms;
	t_datas	*datas;

	datas = (t_datas *)datas_void;
	
	while (datas->philo_nb > 1 /*&& !datas->dining_end*/)
	{
		//printf("CHECKDEATH\n");
		i = 0;
		while (i < datas->philo_nb)
		{
			//printf("checkdeath\n");
			usleep(300);
			pthread_mutex_lock(&datas->death);
			//printf("last_meal = %lld\n", datas->philos[i].last_meal);
			//printf("death time = %lld\n", datas->philos[i].last_meal - get_time());
			//get_time() - datas->philos[i].last_meal) > datas->t_t_die
			if (((get_time() - datas->philos[i].last_meal)) > datas->t_t_die)
			{
				datas->dining_end = 1;
				ms = get_time() - datas->timestamp;
				if (!datas->maxmeals)
					printf("%dms %d %s\n", ms, i + 1, "died");
				pthread_mutex_unlock(&datas->death);
				usleep(800);
				return (NULL);
			}
			pthread_mutex_unlock(&datas->death);
			i++;
		}
	}
	return (NULL);
}
