/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:41:40 by salimon           #+#    #+#             */
/*   Updated: 2023/03/23 03:00:12 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	one_philo_case(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
	print_log(philo, philo->position + 1, "has taken a fork");
	usleep(philo->datas->t_t_die * 1000);
	print_log(philo, philo->position + 1, "died");
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	philo->datas->dining_end = 1;
	return (1);
}

void	eat(t_philosopher *philo)
{
	if (philo->position == (philo->datas->philo_nb -1))
	{
		pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
		print_log(philo, philo->position + 1, "has taken a fork");
		pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
		print_log(philo, philo->position + 1, "has taken a fork");
		print_log(philo, philo->position + 1, "is eating");
	}
	else
	{
		pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
		print_log(philo, philo->position + 1, "has taken a fork");
		pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
		print_log(philo, philo->position + 1, "has taken a fork");
		print_log(philo, philo->position + 1, "is eating");
	}
	usleep(philo->datas->t_t_eat * 1000);
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
}
