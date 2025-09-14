/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:55:53 by knomura           #+#    #+#             */
/*   Updated: 2025/09/14 17:35:02 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	find_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_all(t_stacks *stack, int size)
{
	int	max_bits;
	int	rank_num;
	int	i;
	int	j;

	max_bits = find_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			rank_num = stack->a.data[0].rank;
			if (((rank_num >> i) & 1) == 1)
				rotate_a(stack, 1);
			else
				push_b(stack);
			j++;
		}
		while (stack->b.size > 0)
			push_a(stack);
		i++;
	}
	return ;
}

void	push_swap(t_stacks *stack, int element)
{
	set_rank(stack);
	if (is_sorted(stack->a))
		return ;
	if (element == 2)
		sort_2(stack);
	else if (element == 3)
		sort_3(stack);
	else if (element <= 5)
		sort_5(stack);
	else
		sort_all(stack, stack->a.size);
}

int	main(int argc, char *argv[])
{
	t_stacks	stack;
	int			i;
	int			error;

	error = 0;
	i = 0;
	while (i < argc - 1)
	{
		stack.a.data[i].data = ft_safe_atoi(argv[i + 1], &error);
		i++;
	}
	has_double(stack.a.data, argc - 1, &error);
	if (error)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack.a.size = argc - 1;
	stack.b.size = 0;
	push_swap(&stack, stack.a.size);
	return (0);
}
