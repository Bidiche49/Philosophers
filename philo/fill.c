/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:54:48 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 13:45:30 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_malloc_lists(t_data *data)
{
	data->list_philos = malloc(sizeof(t_philo) * (data->arg.nbr_philo));
	if (data->list_philos == NULL)
		return (ft_error("malloc KO !", data));
	data->list_fork = malloc(sizeof(t_fork) * (data->arg.nbr_philo));
	if (data->list_fork == NULL)
		return (ft_error("malloc KO !", data));
	data->threads_philos = malloc(sizeof(pthread_t) * (data->arg.nbr_philo));
	if (data->threads_philos == NULL)
		return (ft_error("malloc KO !", data));
	return (0);
}

int	ft_fill_forks(t_data *data, int i)
{
	while (i < data->arg.nbr_philo)
	{
		data->list_fork[i].id_fork = i + 1;
		if (pthread_mutex_init(&data->list_fork[i].mutex_fork, NULL) != 0)
			return (ft_error("mutex_init KO !", data));
		else
			data->list_fork[i].mutex_initialised = 1;
		i++;
	}
	return (0);
}

int	ft_fill_philos(t_data *data, int i)
{
	while (i < data->arg.nbr_philo)
	{
		data->list_philos[i].id_philo = i + 1;
		data->list_philos[i].hand_l = 0;
		data->list_philos[i].hand_r = 0;
		data->list_philos[i].nb_eat = 0;
		data->list_philos[i].arg = data->arg;
		gettimeofday(&data->list_philos[i].start_time, NULL);
		data->list_philos[i].data = data;
		data->list_philos[i].dead = 0;
		if (pthread_mutex_init(&data->list_philos[i].mutex_time, NULL) != 0)
			return (ft_error("mutex_init KO !", data));
		if (pthread_mutex_init(&data->list_philos[i].mutex_dead, NULL) != 0)
			return (ft_error("mutex_init KO !", data));
		i++;
	}
	return (0);
}

int	ft_fill_philos_and_fork(t_data *data)
{
	int	i;

	i = 0;
	if (ft_malloc_lists(data) == 1)
		return (1);
	if (ft_fill_forks(data, i) != 0)
		return (1);
	if (ft_fill_philos(data, i) != 0)
		return (1);
	data->start_time = ft_start_time();
	while (i < data->arg.nbr_philo)
	{
		pthread_create(&data->threads_philos[i], NULL,
			ft_philosopher_thread, (void *)&data->list_philos[i]);
		i++;
	}
	pthread_mutex_lock(&data->glob_mutex);
	data->list_philos_initialised = 1;
	pthread_mutex_unlock(&data->glob_mutex);
	i = 0;
	while (i < data->arg.nbr_philo)
		pthread_join(data->threads_philos[i++], NULL);
	return (0);
}

void	ft_fill_arg(int i, t_arguments *arg, int atoi_arg)
{
	if (i == 1)
		arg->nbr_philo = atoi_arg;
	if (i == 2)
		arg->time_to_die = atoi_arg;
	if (i == 3)
		arg->time_to_eat = atoi_arg;
	if (i == 4)
		arg->time_to_sleep = atoi_arg;
	if (i == 5)
		arg->nbr_must_eat = atoi_arg;
}
