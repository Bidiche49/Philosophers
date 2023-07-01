/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:35:00 by ntardy            #+#    #+#             */
/*   Updated: 2023/06/27 12:47:12 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
// # include "strcu.h"

/******************************************/
/*                STRUCTS                 */
/******************************************/

typedef struct s_arguments
{
	int		nbr_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nbr_must_eat;
}				t_arguments;

typedef struct s_philo
{
	int				id_philo;
	int				nb_eat;
	int				hand_l;
	int				hand_r;
	int				dead;
	t_arguments		arg;
	struct s_data	*data;
	struct timeval	start_time;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	mutex_dead;

}				t_philo;

typedef struct s_fork
{
	int				id_fork;
	int				mutex_initialised;
	pthread_mutex_t	mutex_fork;
}				t_fork;

enum e_dataVariables {
	THREADS_PHILOS,
	LIST_PHILOS,
	LIST_FORK,
	ID_PHILO_DEAD,
	ALL_EAT,
	NB_EAT,
	MAX_MUTEX
};

typedef struct s_data
{
	int				list_philos_initialised;
	int				id_philo_dead;
	int				all_eat;
	long			start_time;
	t_fork			*list_fork;
	t_arguments		arg;
	struct s_philo	*list_philos;
	pthread_t		*threads_philos;
	pthread_mutex_t	glob_mutex;
	pthread_mutex_t	mutex[MAX_MUTEX];
}				t_data;

/******************************************/
/*               Fonctions                */
/******************************************/

/*********************************/
/*            errors             */
/*********************************/
int				ft_error(char *error, t_data *data);

/*********************************/
/*             free              */
/*********************************/
void			ft_free(t_data *data);

/*********************************/
/*             utils             */
/*********************************/
void			ft_log(t_data *data, int id, char *action);
void			ft_putchar(char c, int out);
void			ft_putstr(char *str, int out);
int				ft_atoi(char *nbr);
long			ft_start_time(void);
void			ft_chronos(int time, t_philo *philo);

/*********************************/
/*            parsing            */
/*********************************/
int				ft_parsing_arg(char **args, t_data *data);

/*********************************/
/*          init/fill            */
/*********************************/
int				ft_init_mutex(t_data *data);
int				ft_init_data(t_data *data);
int				ft_fill_philos_and_fork(t_data *data);
void			ft_fill_arg(int i, t_arguments *arg, int atoi_arg);

/*********************************/
/*            threads            */
/*********************************/
void			*ft_philosopher_thread(void *philo);
void			ft_stop_threads(t_data *data);

/*********************************/
/*            actions            */
/*********************************/
void			ft_take_fork(t_philo *philo, int id);
void			ft_eat(t_philo *philo);
void			ft_drop_fork(t_philo *philo, int id);
void			ft_sleep(t_philo *philo);

/*********************************/
/*             check             */
/*********************************/
void			*ft_check_philosophers(void *arg);

/*********************************/
/*             mutex             */
/*********************************/
void			ft_mutex_destr(t_data *data);
int				ft_mutex_id_dead(t_data *data, int change, int new_id);
int				ft_mutex_all_eat(t_data *data);
struct timeval	ft_mutex_start_time(t_data *data, int id, int change);

#endif
