/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:41:40 by salimon           #+#    #+#             */
/*   Updated: 2022/09/26 03:54:21 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_philosopher *philo)
{
	long long	ms;

	pthread_mutex_lock(&philo->datas->meal);
	if (philo->meal_count == 0)
		philo->last_meal = philo->datas->timestamp;
	else
		philo->last_meal = philo->meal_time;
	pthread_mutex_unlock(&philo->datas->meal);
	if (philo->datas->dining_end)
		return ;
	pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
	if(philo->datas->philo_nb == 1)
	{
		ms = get_time() - philo->datas->timestamp;
		print_log(philo, ms, philo->position + 1, "has taken a fork");
		usleep(philo->datas->t_t_die * 1000);
		ms = get_time() - philo->datas->timestamp;
		print_log(philo, ms, philo->position + 1, "died");
		pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
		philo->datas->dining_end = 1;
		return ;
	}
	pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
	philo->meal_time = get_time();
	// printf("temps = %lld\n", philo->meal_time - philo->last_meal);
	// printf("meal time = %lld\n", philo->meal_time);
	// printf("last meal = %lld\n", philo->last_meal);
	if ((philo->meal_time - philo->last_meal) > philo->datas->t_t_die)
	{
		ms = get_time() - philo->datas->timestamp;
		print_log(philo, ms, philo->position + 1, "died");
		philo->datas->dining_end = 1;
		pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
		pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
		return ;
	}
	ms = philo->meal_time - philo->datas->timestamp;
	print_log(philo, ms, philo->position + 1, "has taken a fork");
	print_log(philo, ms, philo->position + 1, "has taken a fork");
	philo->meal_count++;
	// philo->last_meal = philo->meal_time;
	print_log(philo, ms, philo->position + 1, "is eating");
	usleep(philo->datas->t_t_eat * 1000);
	//smart_sleep(philo->datas, philo->datas->t_t_eat);
	// ms = get_time() - philo->datas->timestamp;
	// printf("%lld : %d repose les fourchettes\n", ms, philo->position + 1);
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
}
