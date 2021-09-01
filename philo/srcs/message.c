/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:53:31 by eriling           #+#    #+#             */
/*   Updated: 2021/08/31 16:14:22 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

void	printf_lock(long philo, int statut, t_input *cpy)
{
	char	sentence[100];
	long	time;

	time = get_current_time(&cpy->start);
	memset(sentence, 0, 100);
	create_sentence(philo + 1, statut, time, sentence);
	pthread_mutex_lock(cpy->mutex_print);
	pthread_mutex_lock(cpy->mutex_finish);
	if (sg()->finish == 1)
	{
		pthread_mutex_unlock(cpy->mutex_finish);
		pthread_mutex_unlock(cpy->mutex_print);
		return ;
	}
	if (statut == DEAD)
		sg()->finish = 1;
	pthread_mutex_unlock(cpy->mutex_finish);
	write(1, sentence, ft_strlen(sentence));
	pthread_mutex_unlock(cpy->mutex_print);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	add_nb(long num, char *str)
{
	long	len;
	long	nb;

	len = 0;
	nb = num;
	if (num == 0)
	{
		*str = '0';
		return ;
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	num = nb;
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
}

void	ft_strcat(char *src, char *dest)
{
	int		i;
	long	len;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	create_sentence(long philo, int statut, long time, char *str)
{
	int	i;
	int	len;

	i = 0;
	add_nb(time, str);
	str[ft_strlen(str)] = ' ';
	add_nb(philo, &str[ft_strlen(str)]);
	str[ft_strlen(str)] = ' ';
	len = ft_strlen(str);
	if (statut == THINK)
		ft_strcat("is thinking\n", &str[len]);
	else if (statut == TAKE_FORK)
		ft_strcat("has taken fork\n", &str[len]);
	else if (statut == EAT)
		ft_strcat("is eating\n", &str[len]);
	else if (statut == SLEEP)
		ft_strcat("is sleeping\n", &str[len]);
	else if (statut == DEAD)
		ft_strcat("died\n", &str[len]);
}
