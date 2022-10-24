/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:41:40 by salimon           #+#    #+#             */
/*   Updated: 2022/10/17 18:04:56 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*one_philo_case(t_philosopher *philo)
{
	long long	ms;

	ms = get_time() - philo->datas->timestamp;
	pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
	print_log(philo, ms, philo->position + 1, "has taken a fork");
	usleep(philo->datas->t_t_die * 1000);
	ms = get_time() - philo->datas->timestamp;
	print_log(philo, ms, philo->position + 1, "died");
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	philo->datas->dining_end = 1;
	return (NULL);
}

void	die(t_philosopher *philo)
{
	long long	ms;

	ms = get_time() - philo->datas->timestamp;
	print_log(philo, ms, philo->position + 1, "died");
	pthread_mutex_lock(&philo->datas->death);
	philo->datas->dining_end = 1;
	pthread_mutex_unlock(&philo->datas->death);
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
	return ;
}

void	eat(t_philosopher *philo)
{
	long long	ms;

	pthread_mutex_lock(&philo->datas->meal);
	if (philo->meal_count == 0)
		philo->last_meal = philo->datas->timestamp;
	else
		philo->last_meal = philo->meal_time;
	if (philo->datas->dining_end)
		return ;
	pthread_mutex_unlock(&philo->datas->meal);
	if (philo->position == (philo->datas->philo_nb -1))
	{
		pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
		pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
	}
	else
	{
		pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
		pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
	}

	philo->meal_time = get_time();
	if ((philo->meal_time - philo->last_meal) > philo->datas->t_t_die)
	 	return (die(philo));
	ms = philo->meal_time - philo->datas->timestamp;
	print_log(philo, ms, philo->position + 1, "has taken a fork");
	print_log(philo, ms, philo->position + 1, "has taken a fork");
	print_log(philo, ms, philo->position + 1, "is eating");
	usleep(philo->datas->t_t_eat * 1000);
	philo->meal_count++;
	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	
}
