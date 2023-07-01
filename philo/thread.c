/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:31:46 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 13:48:31 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*infinity_loop(t_philo *philo)
{
	while (1)
	{
		if (ft_mutex_id_dead(philo->data, 0, 0) != 0)
			return (NULL);
		if (philo->nb_eat == philo->arg.nbr_must_eat)
			return (NULL);
		ft_take_fork(philo, philo->id_philo);
		if (philo->arg.nbr_philo == 1)
			usleep(philo->arg.time_to_die * 1000);
		if (ft_mutex_id_dead(philo->data, 0, 0) != 0)
			return (ft_drop_fork(philo, philo->id_philo), NULL);
		ft_eat(philo);
		if (ft_mutex_id_dead(philo->data, 0, 0) != 0)
			return (ft_drop_fork(philo, philo->id_philo), NULL);
		ft_drop_fork(philo, philo->id_philo);
		if (ft_mutex_id_dead(philo->data, 0, 0) != 0)
			return (NULL);
		ft_sleep(philo);
		if (ft_mutex_all_eat(philo->data) == 1)
			return (NULL);
	}
}

void	*ft_philosopher_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0 || philo->arg.nbr_philo == philo->id_philo)
		usleep(500);
	ft_mutex_start_time(philo->data, philo->id_philo - 1, 1);
	return (infinity_loop(philo));
}
