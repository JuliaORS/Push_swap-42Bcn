/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:23:58 by julolle-          #+#    #+#             */
/*   Updated: 2023/05/24 15:08:21 by julolle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

long long int	ft_atol(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}
