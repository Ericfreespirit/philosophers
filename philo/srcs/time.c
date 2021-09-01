/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:16:21 by eriling           #+#    #+#             */
/*   Updated: 2021/08/31 16:13:02 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

void	ft_sleep(long sleep)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (get_current_time(&start) < sleep)
	{
		usleep(100);
	}
}

long	get_current_time(struct timeval *start)
{
	struct timeval	end;
	long			time;

	gettimeofday(&end, NULL);
	time = (end.tv_sec * 1000 + end.tv_usec / 1000)
		- (start->tv_sec * 1000 + start->tv_usec / 1000);
	return (time);
}
