/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:17:22 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 14:43:41 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_philos(t_data *data)
{
	if (data->list_philos != NULL)
	{
		free(data->list_philos);
		data->list_philos = NULL;
	}
}

void	ft_free_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg.nbr_philo)
	{
		if (!data->list_fork)
			return ;
		if (data->list_fork[i].mutex_initialised)
		{
			pthread_mutex_destroy(&data->list_fork[i].mutex_fork);
			pthread_mutex_destroy(&data->list_philos[i].mutex_time);
			pthread_mutex_destroy(&data->list_philos[i].mutex_dead);
		}
		i++;
	}
	if (data->list_fork != NULL)
	{
		free(data->list_fork);
		data->list_fork = NULL;
	}
}

void	ft_free_threads_philos(t_data *data)
{
	if (data->threads_philos != NULL)
	{
		free(data->threads_philos);
		data->threads_philos = NULL;
	}
}

void	ft_free(t_data *data)
{
	ft_free_fork(data);
	ft_free_philos(data);
	ft_free_threads_philos(data);
}
