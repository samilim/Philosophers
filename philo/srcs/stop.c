/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:10:08 by salimon           #+#    #+#             */
/*   Updated: 2023/02/12 05:11:27 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*lancer si 5e arg ; verifie l nb de repas de chaque philo*/
int	check_dining_end(t_datas *datas)
{
	int			i;

	while (1)
	{
		i = 0;
		while (i < datas->philo_nb)
		{
			if (datas->dining_end)
				return (0);
			if (datas->philos[i].meal_count
				< datas->philos[i].datas->meal_nb)
				break ;
			else if (i == (datas->philo_nb - 1) && (datas->philos[i].meal_count
					>= datas->philos[i].datas->meal_nb))
			{
				datas->dining_end = 1;
				return (1);
			}
			i++;
		}
	}
	return (0);
}

/*à placer probablement avant join pour check la death
en continu ou bien créer un thread dédié en deébut de simu?
est-ce aue je dois check le nb de repqs dqns cette meme fonction ?*/
int	check_death(t_datas *datas)
{
	int			i;
	long long	ms;

	while (datas->philo_nb > 1 && !datas->dining_end)
	{
		i = 0;
		while (i < datas->philo_nb)
		{
			printf("checkdeath\n");
			pthread_mutex_lock(&datas->death);
			printf("death time = %lld\n", datas->philos[i].meal_time - datas->philos[i].last_meal);
			if ((datas->philos[i].meal_time
					- datas->philos[i].last_meal) > datas->t_t_die)
			{
				printf("mort found\n");
				ms = get_time() - datas->timestamp;
				print_log(datas->philos, ms, i + 1, "died");
				datas->dining_end = 1;
				pthread_mutex_unlock(&datas->death);
				usleep(1000);
				return (1);
			}
			i++;
		}
	}
	return (1);
}
