/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:38:30 by eriling           #+#    #+#             */
/*   Updated: 2021/08/31 16:14:54 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one_struct.h"
#include "philo_one_func.h"

int	main(int ac, char **av)
{
	t_input	arg;
	t_input	*tmp;

	if (ac == 5 || ac == 6)
	{
		if (parse(&arg, av, ac) == 1)
		{
			printf("Error\nParse\n");
			return (0);
		}
		tmp = init_struct(&arg, ac);
		if (god_is_watching(tmp, ac) == 1)
			free_programm(tmp);
	}
	else
		printf("Error\nNumber arg false\n");
	return (0);
}
