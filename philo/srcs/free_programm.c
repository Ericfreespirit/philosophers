/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_programm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:50:38 by eriling           #+#    #+#             */
/*   Updated: 2021/09/01 09:27:34 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

void	free_programm(t_input *tmp)
{
	long	i;

	i = 0;
	while (i < tmp->total_phi)
	{
		pthread_join(tmp->phi[i], NULL);
		i++;
	}
	i = 0;
	while (i < tmp->total_phi)
	{
		pthread_mutex_destroy(&tmp->fork[i]);
		i++;
	}
	pthread_mutex_destroy(tmp->mutex_print);
	pthread_mutex_destroy(tmp->mutex_finish);
	pthread_mutex_destroy(tmp->clock);
	free(tmp->mutex_finish);
	free(tmp->clock);
	free(tmp->phi);
	free(tmp->fork);
	free(tmp->mutex_print);
	free(tmp);
	free(sg());
}
