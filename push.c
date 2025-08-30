/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:53 by knomura           #+#    #+#             */
/*   Updated: 2025/08/31 04:07:02 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stack)
{
	int	i;

	if (stack->b.size == 0)
		return ;
	i = stack->a.size;
	while (i > 0)
	{
		stack->a.data[i] = stack->a.data[i - 1];
		i--;
	}
	stack->a.data[0] = stack->b.data[0];
	stack->a.size++;
	stack->b.size--;
	i = 0;
	while (i < stack->b.size)
	{
		stack->b.data[i] = stack->b.data[i + 1];
		i++;
	}
	printf("pa\n");
}

void	push_b(t_stacks *stack)
{
	int	i;

	if (stack->a.size == 0)
		return ;
	i = stack->b.size;
	while (i > 0)
	{
		stack->b.data[i] = stack->b.data[i - 1];
		i--;
	}
	stack->b.data[0] = stack->a.data[0];
	stack->a.size--;
	stack->b.size++;
	i = 0;
	while (i < stack->a.size)
	{
		stack->a.data[i] = stack->a.data[i + 1];
		i++;
	}
	printf("pb\n");
}
