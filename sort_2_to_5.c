/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 00:42:04 by knomura           #+#    #+#             */
/*   Updated: 2025/09/14 17:43:06 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.size - 1)
	{
		if (a.data[i].data > a.data[i + 1].data)
			return (0);
		i++;
	}
	return (1);
}

void	sort_2(t_stacks *stack)
{
		swap_a(stack, 1);
}

void	sort_3(t_stacks *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a.data[0].data;
	b = stack->a.data[1].data;
	c = stack->a.data[2].data;
	if (a > b && b > c)
	{
		swap_a(stack, 1);
		reverse_rotate_a(stack, 1);
	}
	if (a > b && b < c && a > c)
		rotate_a(stack, 1);
	if (a < b && b > c && a < c)
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
	if (a > b && b < c && a < c)
		swap_a(stack, 1);
	if (a < b && b > c && a > c)
		reverse_rotate_a(stack, 1);
}

void	which_to_push_b(t_stacks *stack, int target)
{
	int	i;

	i = 0;
	while (i < stack->a.size && stack->a.data[i].rank != target)
		i++;
	while (stack->a.data[0].rank != target)
	{
		if (i <= stack->a.size / 2)
			rotate_a(stack, 1);
		else
			reverse_rotate_a(stack, 1);
	}
	push_b(stack);
}

void	sort_5(t_stacks *stack)
{
	which_to_push_b(stack, 0);
	if (is_sorted(stack->a))
	{
		push_a(stack);
		return ;
	}
	which_to_push_b(stack, 1);
	if (stack->a.size == 3)
		sort_3(stack);
	else
		sort_2(stack);
	push_a(stack);
	push_a(stack);
}
