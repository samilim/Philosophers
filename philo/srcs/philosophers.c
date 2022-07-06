/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:22:30 by salimon           #+#    #+#             */
/*   Updated: 2022/07/06 20:38:47 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int    parsing(t_datas *datas, int argc, char **argv)
{
    datas->philo_nb = ft_atoi(argv[1]);
    datas->philos = (t_philosopher *)malloc(sizeof(*(datas->philos)) * datas->philo_nb);
    if (!datas->philos)
        return (0);
    datas->t_t_die = ft_atoi(argv[2]);
    datas->t_t_eat = ft_atoi(argv[3]);
    datas->t_t_sleep = ft_atoi(argv[4]);
    datas->death = 0;
    if (datas->philo_nb < 2 || datas->t_t_die < 0 || datas->t_t_eat < 0 || datas->t_t_sleep < 0)
        return (0);
    datas->forks = (pthread_mutex_t *)malloc(sizeof(*(datas->forks)) * datas->philo_nb);
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
    printf("parsing ok\n");
    return (1);
}

/*insérer temps en ms et le mettre à jour avec chaque action*/
void    *routine_philo(void *datas_void)
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    t_datas *datas;
    int pos;

    datas = (t_datas *)datas_void;
    pthread_mutex_lock(&mutex);
    pos = datas->is_eating;
    printf("routine for philo %d\n", pos + 1);
    
    if ((pos + 1) % 2)
        usleep(800000);
    pthread_mutex_unlock(&mutex);
    /*mange*/
    
    // pthread_mutex_lock(&datas->forks[datas->philos[pos].left_fork]);
    // printf("has taken a fork\n");
    // pthread_mutex_lock(&datas->forks[datas->philos[pos].right_fork]);
    // printf("has taken a fork\n");
    // printf("%d is eating\n", pos + 1);
    // pthread_mutex_unlock(&datas->forks[datas->philos[pos].left_fork]);
    // pthread_mutex_unlock(&datas->forks[datas->philos[pos].right_fork]);

    /* si le nombre de repas max est atteint, fin du diner*/

    /*dort*/
    /*pense*/
    //printf("%d is thinking\n", pos);
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
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    i = 0;
    datas->time = get_time();
    while (i < datas->philo_nb)
    {
        datas->is_eating = i;
        printf("is eating = %d\n", datas->is_eating + 1);
        
        printf("about to create thread for philo %d\n", i + 1);
        if ((pthread_create(&datas->philos[i].id, NULL, &routine_philo, datas)) != 0)
                return (0);
        i++;
    }
    //pthread_detach(datas->philosopher[i].id);
    i = 0;
    while (i < datas->philo_nb)
    {
        if (pthread_join(datas->philos[i].id, NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}

int init_philos_and_forks(t_datas *datas)
{
    int i;

    i = 0;
    while (i < datas->philo_nb)
    {
        //datas->philos[i].position = i;
        datas->philos[i].left_fork = i;
        datas->philos[i].right_fork = (i + 1) % datas->philo_nb;
        if ((pthread_mutex_init(&datas->philos[i].meal, NULL) != 0))
            return (0);
        if ((pthread_mutex_init(&datas->forks[i], NULL) != 0))
            return (0);
        i++;
    }
    printf("init philos and forks ok\n");
    return (1);
}

int main(int argc, char **argv)
{
    t_datas datas;
    
    memset(&datas, 0, sizeof(t_datas));
    if (argc != 5 && argc != 6)
        return (error_management(&datas, 1));
    if (!(parsing(&datas, argc, argv)))
        return (error_management(&datas, 2));
    if (!(init_philos_and_forks(&datas)))
        return (error_management(&datas, 3));
    if (!(start_philosophers_dining(&datas)))
        return (error_management(&datas, 4));
    return (0);
}