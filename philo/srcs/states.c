/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:41:40 by salimon           #+#    #+#             */
/*   Updated: 2023/02/18 10:21:51 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*one_philo_case(t_philosopher *philo)
{

	pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
	print_log(philo, philo->position + 1, "has taken a fork");
	usleep(philo->datas->t_t_die * 1000);
	print_log(philo, philo->position + 1, "died");
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	philo->datas->dining_end = 1;
	return (NULL);
}

/* nex eat fucntion where death is managed in an other func*/
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
	pthread_mutex_lock(&philo->datas->meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->datas->meal);
	
	usleep(philo->datas->t_t_eat * 1000);
	//smart_sleep(philo->datas, philo->datas->t_t_eat);
	
	if (philo->position == (philo->datas->philo_nb -1))
	{
		pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
		pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	}
	else{
		pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
		pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
	}
}