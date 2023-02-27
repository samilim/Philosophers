/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:22:30 by salimon           #+#    #+#             */
/*   Updated: 2023/02/27 06:22:11 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
execute la routine de chaque philo
insérer temps en ms et le mettre à jour avec chaque action*/
void	*routine_philo(void *philo_void)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo_void;
	if (philo->datas->philo_nb == 1)
		return (one_philo_case(philo));
	if (!((philo->position + 1) % 2))
		usleep(800);
	while (1/*!philo->datas->dining_end*/)
	{
		pthread_mutex_lock(&philo->datas->meal);
		if (philo->datas->dining_end || (philo->datas->meal_nb
				!= -1 && philo->meal_count >= philo->datas->meal_nb))
		{
			//philo->last_meal = get_time();
			pthread_mutex_unlock(&philo->datas->meal);
			break ;
		}
		pthread_mutex_unlock(&philo->datas->meal);
		eat(philo);
		philo->meal_count++;
		print_log(philo, philo->position + 1, "is sleeping");
		smart_sleep(philo->datas, philo->datas->t_t_sleep);
		//usleep(philo->datas->t_t_sleep * 1000);
		print_log(philo, philo->position + 1, "is thinking");
	}
	return (NULL);
}


int	start_philosophers_dining(t_datas *datas)
{
	int	i;

	i = 0;
	datas->timestamp = get_time();
	while (i < datas->philo_nb)
	{
		if ((pthread_create(&datas->philos[i].id, NULL,
					&routine_philo, &(datas->philos[i]))) != 0)
			return (0);
		datas->philos[i].last_meal = datas->timestamp;//
		i++;
	}
/*
	pthread_t       meal_thread;
    pthread_t       death_thread;
	
	
	//philos_thread = malloc(sizeof(pthread_t) * datas->philo_nb); gne?
	if (!(pthread_create(&death_thread, NULL, &check_death, datas) != 0))
			return (0);
	printf("YO\n");
	if (!(pthread_create(&meal_thread, NULL, &check_meals, datas) != 0))
			return (0);
	pthread_join(death_thread, NULL);
	pthread_join(meal_thread, NULL);
	*/
	check_death(datas);
	i = 0;
	while (i < datas->philo_nb)
	{
		if (pthread_join(datas->philos[i].id, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_philos_and_mutexes(t_datas *datas)
{
	int	i;

	i = 0;
	if ((pthread_mutex_init(&datas->meal, NULL) != 0))
		return (0);
	if ((pthread_mutex_init(&datas->logs, NULL) != 0))
		return (0);
	if ((pthread_mutex_init(&datas->death, NULL) != 0))
		return (0);
	while (i < datas->philo_nb)
	{
		datas->philos[i].datas = datas;
		datas->philos[i].position = i;
		datas->philos[i].left_fork = i;
		datas->philos[i].right_fork = (i + 1) % datas->philo_nb;
		//datas->philos[i].meal_time = 0;
		datas->philos[i].last_meal = 0;
		datas->philos[i].meal_count = 0;
		if ((pthread_mutex_init(&datas->forks[i], NULL) != 0))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_datas	datas;

	memset(&datas, 0, sizeof(t_datas));
	if (argc != 5 && argc != 6)
		return (error_management(&datas, 1));
	if (!(parsing(&datas, argc, argv)))
		return (error_management(&datas, 2));
	if (!(init_philos_and_mutexes(&datas)))
		return (error_management(&datas, 3));
	if (!(start_philosophers_dining(&datas)))
		return (error_management(&datas, 4));
	ft_clear(&datas);
	return (0);
}
