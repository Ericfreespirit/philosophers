/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:52:01 by eriling           #+#    #+#             */
/*   Updated: 2021/08/31 16:16:08 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

long	ft_atol(char *str)
{
	long	sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		(str)++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		(str)++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		if (nb < 0 && sign == -1)
			return (0);
		else if (nb < 0 && sign == 1)
			return (-1);
		str++;
	}
	return (nb * sign);
}

int	stock_input(t_input *arg, char **av, int ac)
{
	arg->total_phi = ft_atol(av[1]);
	arg->phi = malloc(sizeof(pthread_t) * arg->total_phi);
	if (arg->phi == NULL)
		return (1);
	arg->fork = malloc(sizeof(pthread_mutex_t) * arg->total_phi);
	if (arg->fork == NULL)
		return (1);
	arg->mutex_print = malloc(sizeof(pthread_mutex_t));
	if (arg->mutex_print == NULL)
		return (1);
	arg->mutex_finish = malloc(sizeof(pthread_mutex_t));
	if (arg->mutex_finish == NULL)
		return (1);
	arg->clock = malloc(sizeof(pthread_mutex_t));
	if (arg->clock == NULL)
		return (1);
	arg->die = ft_atol(av[2]);
	arg->eat = ft_atol(av[3]);
	arg->sleep = ft_atol(av[4]);
	if (ac == 6)
		arg->must_eat = ft_atol(av[5]);
	if (arg->total_phi == 0)
		return (1);
	return (0);
}

int	parse(t_input *arg, char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][j] == '-')
			return (1);
		while (av[i][j])
		{	
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (stock_input(arg, av, ac) == 1)
		return (1);
	return (0);
}
