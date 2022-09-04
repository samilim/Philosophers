/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 03:41:40 by salimon           #+#    #+#             */
/*   Updated: 2022/09/04 04:43:51 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    eat(t_philosopher *philo)
{

    long long   meal_time;
    long long   ms;
    meal_time = get_time(); //décalage de 1 ms (grave ou pas ?)
    
    ms = meal_time - philo->datas->timestamp;
    pthread_mutex_lock(&(philo->datas->forks[philo->left_fork]));
    print_log(philo, ms, philo->position + 1, "has taken a fork\n");
    pthread_mutex_lock(&(philo->datas->forks[philo->right_fork]));
    print_log(philo, ms, philo->position + 1, "has taken a fork\n");


    philo->last_meal = meal_time;
    
    pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
    pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));

    pthread_mutex_lock(&philo->datas->meal);
    philo->meal_count++;
    //if (philo->datas->meal_nb == -1 || (philo->datas->meal_nb != -1 && philo->meal_count <= philo->datas->meal_nb))

    pthread_mutex_unlock(&philo->datas->meal);

    print_log(philo, ms, philo->position + 1, "is eating");
    usleep(philo->datas->t_t_eat * 1000);
}


