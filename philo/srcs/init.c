/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:07:26 by eriling           #+#    #+#             */
/*   Updated: 2021/09/01 09:27:17 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

void	stock_struct_val(t_input *cpy, t_input *arg, int ac)
{
	long	i;

	i = 0;
	while (i < arg->total_phi)
	{
		cpy[i].total_phi = arg->total_phi;
		cpy[i].index_phi = i;
		cpy[i].die = arg->die;
		cpy[i].eat = arg->eat;
		cpy[i].sleep = arg->sleep;
		if (ac == 6)
			cpy[i].must_eat = arg->must_eat;
		else
			cpy[i].must_eat = -1;
		i++;
	}
}

void	stock_struct_val2(t_input *cpy, t_input *arg)
{
	long	i;

	i = 0;
	while (i < arg->total_phi)
	{
		cpy[i].statut = 1;
		cpy[i].time_last_dish = 0;
		cpy[i].phi = arg->phi;
		cpy[i].fork = arg->fork;
		cpy[i].mutex_print = arg->mutex_print;
		cpy[i].mutex_finish = arg->mutex_finish;
		cpy[i].clock = arg->clock;
		if (i == 0 && arg->total_phi > 1)
			cpy[i].fork_right = &arg->fork[arg->total_phi - 1];
		else
			cpy[i].fork_right = &arg->fork[i - 1];
		cpy[i].fork_left = &arg->fork[i];
		i++;
	}
	sg()->finish = 0;
}

t_input	*init_struct(t_input *arg, int ac)
{
	t_input	*cpy;
	long	i;

	i = 0;
	cpy = calloc(sizeof(t_input), arg->total_phi);
	if (cpy == NULL)
		return (NULL);
	stock_struct_val(cpy, arg, ac);
	stock_struct_val2(cpy, arg);
	return (cpy);
}

t_sg	*sg(void)
{
	static t_sg	*sg = NULL;

	if (sg)
		return (sg);
	sg = malloc(sizeof(sizeof(t_sg)));
	return (sg);
}

void	init_thread_mutex(t_input *tmp)
{
	long	i;

	i = 0;
	while (i < tmp->total_phi)
		pthread_mutex_init(&tmp->fork[i++], NULL);
	pthread_mutex_init(tmp->mutex_print, NULL);
	pthread_mutex_init(tmp->mutex_finish, NULL);
	pthread_mutex_init(tmp->clock, NULL);
	i = 0;
	gettimeofday(&tmp->start, NULL);
	while (i < tmp->total_phi)
	{
		tmp[i].start = tmp->start;
		pthread_create(&tmp->phi[i], NULL, bon_appetit, (void *)&tmp[i]);
		pthread_detach(tmp->phi[i]);
		usleep(200);
		i++;
	}
}
