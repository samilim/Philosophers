/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:41:40 by salimon           #+#    #+#             */
/*   Updated: 2023/02/17 07:12:10 by salimon          ###   ########.fr       */
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
	//if (philo->meal_count == 1)
 	//	philo->last_meal = philo->datas->timestamp;
 	//else
 	//	philo->last_meal = philo->meal_time;
	//pthread_mutex_lock(&philo->datas->meal);
	//pthread_mutex_unlock(&philo->datas->meal);
	//pthread_mutex_lock(&philo->datas->meal);
	// if (philo->position == (philo->datas->philo_nb -1))
	// {
	pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
	print_log(philo, philo->position + 1, "has taken a fork");
	pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
	print_log(philo, philo->position + 1, "has taken a fork");
	print_log(philo, philo->position + 1, "is eating");
		
	//}
	// else
	// {
	// 	pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
	// 	pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
	// }
	pthread_mutex_lock(&philo->datas->meal);
	//last meal here
	usleep(philo->datas->t_t_eat * 1000);
	philo->last_meal = get_time();
	//smart_sleep(philo->datas, philo->datas->t_t_eat);
	pthread_mutex_unlock(&philo->datas->meal);
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
}