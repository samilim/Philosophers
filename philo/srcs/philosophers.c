/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:22:30 by salimon           #+#    #+#             */
/*   Updated: 2022/09/18 23:00:44 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parsing(t_datas *datas, int argc, char **argv)
{
	datas->philo_nb = ft_atoi(argv[1]);
	datas->philos
		= (t_philosopher *)malloc(sizeof(*(datas->philos)) * datas->philo_nb);
	if (!datas->philos)
		return (0);
	datas->t_t_die = ft_atoi(argv[2]);
	datas->t_t_eat = ft_atoi(argv[3]);
	datas->t_t_sleep = ft_atoi(argv[4]);
	datas->death = 0;
	datas->dining_end = 0;
	if (datas->philo_nb < 2 || datas->t_t_die < 0
		|| datas->t_t_eat < 0 || datas->t_t_sleep < 0)
		return (0);
	datas->forks
		= (pthread_mutex_t *)malloc(sizeof(*(datas->forks)) * datas->philo_nb);
	if (!datas->forks)
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

/*
execute la routine de chaque philo
insérer temps en ms et le mettre à jour avec chaque action*/
void *routine_philo(void *philo_void)
{
	t_philosopher *philo;
	long long ms;

	philo = (t_philosopher *)philo_void;

	if (!((philo->position + 1) % 2))
		usleep(800);
	// philo->last_meal = philo->datas->timestamp;

	while (!philo->datas->death)
	{
		/*mange*/
		eat(philo);
		if (philo->datas->death || (philo->datas->meal_nb != -1 && philo->meal_count >= philo->datas->meal_nb))
			break;
		/*dort*/
		ms = get_time() - philo->datas->timestamp;
		print_log(philo, ms, philo->position + 1, "is sleeping\n");
		usleep(philo->datas->t_t_sleep * 1000);
		/*pense*/
		ms = get_time() - philo->datas->timestamp;
		print_log(philo, ms, philo->position + 1, "is thinking\n");
	}
	return (NULL);
}

/*
pthread_create créé un thread pour chaque philosopher
pthread_join agit comme un wait
 sert à protéger les threads en cas d'erreur si create pthread != 0
*/
int start_philosophers_dining(t_datas *datas)
{
	int i;

	i = 0;
	datas->timestamp = get_time();
	while (i < datas->philo_nb)
	{
		// datas->is_eating = i;
		if ((pthread_create(&datas->philos[i].id, NULL, &routine_philo, &(datas->philos[i]))) != 0)
			return (0);
		i++;
	}
	/*verif mort avant join ??*/
	// check_dining_end(datas);
	i = 0;
	while (i < datas->philo_nb)
	{
		if (pthread_join(datas->philos[i].id, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int init_philos_and_mutexes(t_datas *datas)
{
	int i;

	i = 0;
	if ((pthread_mutex_init(&datas->meal, NULL) != 0))
		return (0);
	if ((pthread_mutex_init(&datas->logs, NULL) != 0))
		return (0);

	while (i < datas->philo_nb)
	{
		datas->philos[i].datas = datas;
		datas->philos[i].position = i;
		datas->philos[i].left_fork = i;
		datas->philos[i].right_fork = (i + 1) % datas->philo_nb;
		datas->philos[i].meal_time = 0;
		datas->philos[i].last_meal = 0;
		datas->philos[i].meal_count = 0;
		if ((pthread_mutex_init(&datas->forks[i], NULL) != 0))
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
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
