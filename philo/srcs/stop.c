/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:10:08 by salimon           #+#    #+#             */
/*   Updated: 2022/09/26 03:34:02 by salimon          ###   ########.fr       */
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
en continu ou bien créer un thread dédié en deébut de simu?*/
int	check_death(t_datas *datas)
{
	int			i;
	long long	ms;

	while (1)
	{
		i = 0;
		while (i < datas->philo_nb)
		{
			if ((datas->philos[i].meal_time
					- datas->philos[i].last_meal) > datas->t_t_die)
			{
				ms = get_time() - datas->timestamp;
				print_log(datas->philos, ms, i + 1, "died");
				datas->dining_end = 1;
				return (1);
			}
			i++;
		}
	}
	return (1);
}
