/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:18:24 by salimon           #+#    #+#             */
/*   Updated: 2022/09/04 07:48:13 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void ft_clear(t_datas *datas)
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
	free(datas->philos);
	free(datas->forks);
}