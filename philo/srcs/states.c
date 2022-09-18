/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:41:40 by salimon           #+#    #+#             */
/*   Updated: 2022/09/18 15:37:39 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    eat(t_philosopher *philo)
{
    long long   ms;

    pthread_mutex_lock(&philo->datas->meal);
    if (philo->meal_count == 0)
        philo->last_meal = philo->datas->timestamp;
    philo->meal_time = get_time();

    //printf("temps = %lld\n", philo->meal_time - philo->last_meal);
    if ((philo->meal_time - philo->last_meal) > philo->datas->t_t_die) //mutex ?
    {
        ms = get_time() - philo->datas->timestamp;
        print_log(philo, ms, philo->position + 1, "died");
        philo->datas->death = 1;
        return ;
    }
    pthread_mutex_unlock(&philo->datas->meal);
    
    pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
    ms = philo->meal_time - philo->datas->timestamp;
    print_log(philo, ms, philo->position + 1, "has taken a fork\n");
    pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
    print_log(philo, ms, philo->position + 1, "has taken a fork\n");
    //printf("%d : l fork = %d\n", philo->position + 1, philo->left_fork);
    //printf("%d : r fork = %d\n\n", philo->position + 1, philo->right_fork);

    philo->meal_count++;
    philo->last_meal = philo->meal_time;

    print_log(philo, ms, philo->position + 1, "is eating");
    usleep(philo->datas->t_t_eat * 1000);
    
    ms = get_time() - philo->datas->timestamp;
    //printf("%lld : %d repose les fourchettes\n", ms, philo->position + 1);
    pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
    pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
}


