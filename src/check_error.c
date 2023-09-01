/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:12:18 by julolle-          #+#    #+#             */
/*   Updated: 2023/06/12 17:10:24 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_errors(int argc, char **argv)
{
	if (ft_isnum(argv) == -1 || ft_isint(argv) == -1 || ft_no_rep(argv) == -1)
		return (-1);
	if (argc == 2)
		return (-1);
	return (0);
}

int	ft_isnum(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				if (!(j == 0 && argv[i][j] == '-'))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isint(char **argv)
{
	int				i;
	long long int	num;

	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_no_rep(char **argv)
{
	int	i;
	int	j;
	int	num;

	i = 2;
	j = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		j = 1;
		while (j < i)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
