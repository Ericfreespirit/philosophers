/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   god_is_watching.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 10:45:11 by eriling           #+#    #+#             */
/*   Updated: 2021/09/01 08:54:28 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

int	god_kill(t_input *tmp)
{
	long	time;

	time = get_current_time(&tmp->start);
	if (time - tmp->time_last_dish > tmp->die)
	{
		printf_lock(tmp->index_phi, DEAD, tmp);
		sg()->finish = 1;
		pthread_mutex_unlock(tmp->clock);
		return (0);
	}
	return (1);
}

int	philo_endless_hungry(t_input *tmp)
{
	long	i;

	i = 0;
	while (i < tmp->total_phi)
	{
		pthread_mutex_lock(tmp->clock);
		if (god_kill(&tmp[i]) == 0)
			return (1);
		pthread_mutex_unlock(tmp->clock);
		i++;
		if (i == tmp->total_phi)
			i = 0;
	}
	return (0);
}

int	philo_defined_hungry(t_input *tmp)
{
	long	i;
	long	count;

	i = 0;
	count = 0;
	while (i < tmp->total_phi)
	{
		pthread_mutex_lock(tmp->clock);
		if (tmp[i].must_eat == 0)
			count++;
		if (god_kill(&tmp[i]) == 0)
			return (1);
		pthread_mutex_unlock(tmp->clock);
		i++;
		if (count == tmp->total_phi)
			break ;
		else if (i == tmp->total_phi)
		{
			i = 0;
			count = 0;
		}
	}
	return (1);
}

int	god_is_watching(t_input *tmp, int ac)
{
	init_thread_mutex(tmp);
	if (ac == 5)
	{
		if (philo_endless_hungry(tmp) == 1)
			return (1);
	}
	else if (ac == 6)
	{
		if (philo_defined_hungry(tmp) == 1)
			return (1);
	}
	return (0);
}
