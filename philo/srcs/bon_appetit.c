/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_appetit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:28:37 by eriling           #+#    #+#             */
/*   Updated: 2021/08/31 16:00:03 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

int	pair_take_fork(t_input *cpy)
{
	pthread_mutex_lock(cpy->fork_left);
	printf_lock(cpy->index_phi, TAKE_FORK, cpy);
	if (cpy->total_phi > 1)
	{
		pthread_mutex_lock(cpy->fork_right);
		printf_lock(cpy->index_phi, TAKE_FORK, cpy);
	}
	else if (cpy->total_phi == 1)
		return (1);
	return (0);
}

void	impair_take_fork(t_input *cpy)
{
	pthread_mutex_lock(cpy->fork_right);
	printf_lock(cpy->index_phi, TAKE_FORK, cpy);
	pthread_mutex_lock(cpy->fork_left);
	printf_lock(cpy->index_phi, TAKE_FORK, cpy);
}

int	eat_sleep_think(t_input *cpy)
{
	printf_lock(cpy->index_phi, EAT, cpy);
	if (cpy->must_eat > 0)
		cpy->must_eat -= 1;
	if (cpy->must_eat == 0)
	{
		pthread_mutex_unlock(cpy->fork_left);
		pthread_mutex_unlock(cpy->fork_right);
		return (1);
	}
	ft_sleep(cpy->eat);
	pthread_mutex_lock(cpy->clock);
	cpy->time_last_dish = get_current_time(&cpy->start);
	pthread_mutex_unlock(cpy->fork_left);
	pthread_mutex_unlock(cpy->fork_right);
	pthread_mutex_unlock(cpy->clock);
	printf_lock(cpy->index_phi, SLEEP, cpy);
	ft_sleep(cpy->sleep);
	printf_lock(cpy->index_phi, THINK, cpy);
	return (0);
}

void	*bon_appetit(void *arg)
{
	t_input	*cpy;

	cpy = (t_input *)arg;
	printf_lock(cpy->index_phi, THINK, cpy);
	while (1)
	{
		if (cpy->index_phi % 2 == 0)
		{
			if (pair_take_fork(cpy) == 1)
				return (NULL);
		}
		else if (cpy->index_phi % 2 == 1)
			impair_take_fork(cpy);
		if (eat_sleep_think(cpy) == 1)
			return (NULL);
		pthread_mutex_lock(cpy->mutex_finish);
		if (sg()->finish == 1)
		{
			pthread_mutex_unlock(cpy->mutex_finish);
			return (NULL);
		}
		pthread_mutex_unlock(cpy->mutex_finish);
	}
	return (NULL);
}
