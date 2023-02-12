/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:41:40 by salimon           #+#    #+#             */
/*   Updated: 2023/02/12 05:53:06 by salimon          ###   ########.fr       */
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

void	die(t_philosopher *philo)
{
	print_log(philo, philo->position + 1, "died");
	pthread_mutex_lock(&philo->datas->death);
	//pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	//pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
	philo->datas->dining_end = 1;
	pthread_mutex_unlock(&philo->datas->death);
	return ;
}

/*old eat func*/
// void	eat(t_philosopher *philo)
// {
// 	long long	ms;

// 	if (philo->meal_count == 1)
// 		philo->last_meal = philo->datas->timestamp;
// 	else
// 		philo->last_meal = philo->meal_time;
// 	//pthread_mutex_lock(&philo->datas->meal);
// 	if (philo->datas->dining_end)
// 	{
// 		//pthread_mutex_unlock(&philo->datas->meal);
// 		return ;
// 	}
// 	//pthread_mutex_unlock(&philo->datas->meal);

// 	if (philo->position == (philo->datas->philo_nb -1))
// 	{
// 		pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
// 		pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
// 		pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
// 	}

	
// 	philo->meal_time = get_time();
// 	if ((philo->meal_time - philo->last_meal) > philo->datas->t_t_die)
// 	{
// 		pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
// 		pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
// 		// if (philo->position == (philo->datas->philo_nb -1))
// 		// {
// 		// 	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
// 		// 	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
// 		// }
// 		// else
// 		// {
// 		// 	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
// 		// 	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
// 		// }
// 	 	return (die(philo));
// 	}
// 	ms = philo->meal_time - philo->datas->timestamp;
// 	print_log(philo, ms, philo->position + 1, "has taken a fork");
// 	print_log(philo, ms, philo->position + 1, "has taken a fork");
// 	print_log(philo, ms, philo->position + 1, "is eating");
// 	usleep(philo->datas->t_t_eat * 1000);
// 	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
// 	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
// }

// void	eat(t_philosopher *philo)
// {
// 	long long	ms;

// 	if (philo->meal_count == 1)
// 		philo->last_meal = philo->datas->timestamp;
// 	else
// 		philo->last_meal = philo->meal_time;
// 	//pthread_mutex_lock(&philo->datas->meal);
// 	if (philo->datas->dining_end)
// 	{
// 		//pthread_mutex_unlock(&philo->datas->meal);
// 		return ;
// 	}
// 	//pthread_mutex_unlock(&philo->datas->meal);

// 	if (philo->position == (philo->datas->philo_nb -1))
// 	{
// 		pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
// 		pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
// 		pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
// 	}

	
// 	philo->meal_time = get_time();
// 	if ((philo->meal_time - philo->last_meal) > philo->datas->t_t_die)
// 	{
// 		pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
// 		pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
// 		// if (philo->position == (philo->datas->philo_nb -1))
// 		// {
// 		// 	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
// 		// 	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
// 		// }
// 		// else
// 		// {
// 		// 	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
// 		// 	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
// 		// }
// 	 	return (die(philo));
// 	}
// 	ms = philo->meal_time - philo->datas->timestamp;
// 	print_log(philo, ms, philo->position + 1, "has taken a fork");
// 	print_log(philo, ms, philo->position + 1, "has taken a fork");
// 	print_log(philo, ms, philo->position + 1, "is eating");
// 	usleep(philo->datas->t_t_eat * 1000);
// 	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
// 	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
// }

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
	pthread_mutex_lock(&philo->datas->meal);
	print_log(philo, philo->position + 1, "is eating");
		
	//}
	// else
	// {
	// 	pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
	// 	pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
	// }
	
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->datas->meal);
	usleep(philo->datas->t_t_eat * 1000);
	pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
}