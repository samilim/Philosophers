//11 fev ver
// void	*routine_philo(void *philo_void)
// {
// 	t_philosopher	*philo;
// 	long long		ms;

// 	philo = (t_philosopher *)philo_void;
// 	if (philo->datas->philo_nb == 1)
// 		return (one_philo_case(philo));
// 	if (!((philo->position + 1) % 2))
// 		usleep(400);
// 	while (1)
// 	{
// 		pthread_mutex_lock(&philo->datas->meal);
// 		if (philo->datas->dining_end || (philo->datas->meal_nb
// 				!= -1 && philo->meal_count >= philo->datas->meal_nb))
// 		{
// 			pthread_mutex_unlock(&philo->datas->meal);
// 			break ;
// 		}
// 		philo->meal_count++;
// 		pthread_mutex_unlock(&philo->datas->meal);
// 		eat(philo);
// 		ms = get_time() - philo->datas->timestamp;
// 		print_log(philo, ms, philo->position + 1, "is sleeping");
// 		usleep(philo->datas->t_t_sleep * 1000);
// 		ms = get_time() - philo->datas->timestamp;
// 		print_log(philo, ms, philo->position + 1, "is thinking");
// 	}
// 	return (NULL);
// }


// void	*routine_philo(void *philo_void)
// {
// 	t_philosopher	*philo;
// 	long long		ms;

// 	philo = (t_philosopher *)philo_void;
// 	if (philo->datas->philo_nb == 1)
// 		return (one_philo_case(philo));
// 	if (!((philo->position + 1) % 2))
// 		usleep(400);
// 	while (!philo->datas->dining_end)
// 	{
		
// 		pthread_mutex_lock(&philo->datas->meal);
// 		if (philo->datas->dining_end || (philo->datas->meal_nb
// 				!= -1 && philo->meal_count >= philo->datas->meal_nb))
// 		{
// 			pthread_mutex_unlock(&philo->datas->meal);
// 			break ;
// 		}
// 		pthread_mutex_unlock(&philo->datas->meal);
// 		eat(philo);
// 		ms = get_time() - philo->datas->timestamp;
// 		print_log(philo, ms, philo->position + 1, "is sleeping");
// 		usleep(philo->datas->t_t_sleep * 1000);
// 		ms = get_time() - philo->datas->timestamp;
// 		print_log(philo, ms, philo->position + 1, "is thinking");
// 	}
// 	return (NULL);
// }

/*
pthread_create créé un thread pour chaque philosopher.
pthread_join agit comme un wait
 sert à protéger les threads en cas d'erreur si create pthread != 0.
verif mort et dinig end avant join ?
*/
// int	start_philosophers_dining(t_datas *datas)
// {
// 	int	i;

// 	i = 0;
// 	datas->timestamp = get_time();
// 	while (i < datas->philo_nb)
// 	{
// 		if ((pthread_create(&datas->philos[i].id, NULL,
// 					&routine_philo, &(datas->philos[i]))) != 0)
// 			return (0);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < datas->philo_nb)
// 	{
// 		if (pthread_join(datas->philos[i].id, NULL) != 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }






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


/*BULLSHIT
void	die(t_philosopher *philo)
{
	int ms;
	//print_log(philo, philo->position + 1, "died");
	ms = get_time() - philo->datas->timestamp;
	printf("%dms %d %s\n", ms, id, message);
	pthread_mutex_lock(&philo->datas->death);
	//pthread_mutex_unlock(&(philo->datas->forks[philo->left_fork]));
	//pthread_mutex_unlock(&(philo->datas->forks[philo->right_fork]));
	philo->datas->dining_end = 1;
	pthread_mutex_unlock(&philo->datas->death);
	return ;
}
*/