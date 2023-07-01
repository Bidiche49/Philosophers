/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:28:50 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 13:49:19 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_philo *philo)
{
	ft_log(philo->data, philo->id_philo, "is sleeping");
	ft_chronos(philo->arg.time_to_sleep, philo);
	ft_log(philo->data, philo->id_philo, "is thinking");
}

void	ft_take_fork(t_philo *philo, int id)
{
	if (id == philo->arg.nbr_philo && philo->arg.nbr_philo > 1)
	{
		pthread_mutex_lock(&philo->data->list_fork[0].mutex_fork);
		philo->hand_r = 1;
		ft_log(philo->data, id, "has taken a fork");
	}
	pthread_mutex_lock(&philo->data->list_fork[id - 1].mutex_fork);
	philo->hand_l = 1;
	ft_log(philo->data, id, "has taken a fork");
	if (id != philo->arg.nbr_philo && philo->arg.nbr_philo > 1)
	{
		pthread_mutex_lock(&philo->data->list_fork[id].mutex_fork);
		philo->hand_r = 1;
		ft_log(philo->data, id, "has taken a fork");
	}
}

void	ft_drop_fork(t_philo *philo, int id)
{
	if (id == philo->arg.nbr_philo && philo->arg.nbr_philo > 1)
	{
		pthread_mutex_unlock(&philo->data->list_fork[0].mutex_fork);
	}
	pthread_mutex_unlock(&philo->data->list_fork[id - 1].mutex_fork);
	if (id != philo->arg.nbr_philo && philo->arg.nbr_philo > 1)
	{
		pthread_mutex_unlock(&philo->data->list_fork[id].mutex_fork);
	}
	philo->hand_l = 0;
	philo->hand_r = 0;
}

void	ft_eat(t_philo *philo)
{
	while (philo->hand_l != 1 || philo->hand_r != 1)
	{
		pthread_mutex_lock(&philo->mutex_dead);
		if (philo->dead == 1)
		{
			pthread_mutex_unlock(&philo->mutex_dead);
			return ;
		}
		pthread_mutex_unlock(&philo->mutex_dead);
		usleep(50);
	}
	ft_mutex_start_time(philo->data, philo->id_philo - 1, 1);
	ft_log(philo->data, philo->id_philo, "is eating");
	ft_chronos(philo->arg.time_to_eat, philo);
	if (philo->arg.nbr_must_eat > 0)
	{
		pthread_mutex_lock(&philo->data->mutex[NB_EAT]);
		philo->nb_eat++;
		pthread_mutex_unlock(&philo->data->mutex[NB_EAT]);
	}
}
