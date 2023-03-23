/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 02:54:52 by salimon           #+#    #+#             */
/*   Updated: 2023/03/23 01:43:10 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*check si les arguments ne contiennent que des chiffres*/
int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if ((argv[1][0] == '\0') || (argv[2][0] == '\0')
		|| (argv[3][0] == '\0') || (argv [4][0] == '\0'))
		return (0);
	if (argc == 6 && argv[5][0] == '\0')
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && argv[i][j] == '+')
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parsing(t_datas *datas, int argc, char **argv)
{
	datas->philo_nb = ft_atoi(argv[1]);
	datas->philos
		= (t_philosopher *)malloc(sizeof(*(datas->philos)) * datas->philo_nb);
	datas->forks
		= (pthread_mutex_t *)malloc(sizeof(*(datas->forks)) * datas->philo_nb);
	if (!datas->philos || !datas->forks)
		return (0);
	datas->t_t_die = ft_atoi(argv[2]);
	datas->t_t_eat = ft_atoi(argv[3]);
	datas->t_t_sleep = ft_atoi(argv[4]);
	datas->dining_end = 0;
	datas->dead = 0;
	if (datas->philo_nb < 1 || datas->philo_nb > 1000
		|| datas->t_t_die < 0 || datas->t_t_eat < 0 || datas->t_t_sleep < 0)
		return (0);
	if (argc == 6)
	{
		datas->meal_nb = ft_atoi(argv[5]);
		if (datas->meal_nb <= 0)
			return (0);
	}
	else
		datas->meal_nb = -1;
	return (1);
}
