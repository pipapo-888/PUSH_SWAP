/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:44:03 by knomura           #+#    #+#             */
/*   Updated: 2025/09/07 21:40:35 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_safe_atoi(const char *str, int *error)
{
	long	result;
	int		minus;
	int		i;

	minus = 1;
	result = 0;
	i = 1;
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= '0' && str[0] <= '9')))
		*error = 1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			*error = 1;
		i++;
	}
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (minus * result > INT_MAX || minus * result < INT_MIN)
		*error = 1;
	return (minus * result);
}

void	has_double(t_rank *data, int size, int *error)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i].data == data[j].data)
			{
				*error = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	set_rank(t_stacks *stack)
{
	int	temp[MAX_SIZE];
	int	i;
	int	ran;

	i = 0;
	while (i < stack->a.size)
	{
		temp[i] = stack->a.data[i].data;
		i++;
	}
	bubble_sort(temp, stack->a.size);
	i = 0;
	while (i < stack->a.size)
	{
		ran = 0;
		while (temp[ran] != stack->a.data[i].data)
			ran++;
		stack->a.data[i].rank = ran;
		i++;
	}
}
