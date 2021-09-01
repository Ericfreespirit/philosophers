/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:46:28 by eriling           #+#    #+#             */
/*   Updated: 2021/08/31 15:54:53 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_FUNC_H
# define PHILO_ONE_FUNC_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include "philo_one_struct.h"
# include <unistd.h>
# define DEAD 0
# define THINK 1
# define TAKE_FORK 2
# define EAT 3
# define SLEEP 4

long	ft_atol(char *str);
int		parse(t_input *arg, char **av, int ac);
int		stock_input(t_input *arg, char **av, int ac);
void	free_programm(t_input *tmp);
void	init_thread_mutex(t_input *tmp);
t_input	*init_struct(t_input *arg, int ac);
void	*bon_appetit(void *tmp);
long	get_current_time(struct timeval *start);
void	ft_putnbr(long num);
void	print_fork(t_input *tmp);
void	printf_lock(long philo, int statut, t_input *cpy);
void	*bon_appetit(void *arg);
void	ft_sleep(long sleep);
int		god_is_watching(t_input *tmp, int ac);
void	create_sentence(long philo, int statut, long time, char *str);
int		ft_strlen(char *str);
t_sg	*sg(void);
#endif
