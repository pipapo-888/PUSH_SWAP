/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:53 by knomura           #+#    #+#             */
/*   Updated: 2025/08/02 15:06:50 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_stacks *stack)
{
	if (stack->b.size == 0)
		return;
	for (int i = stack -> a.size; i > 0; i--)
	{
		stack->a.data[i] = stack->a.data[i - 1];
	}
	stack->a.data[0] = stack->b.data[0];
	stack->a.size++;
	stack->b.size--;
	for (int i = 0; i < stack->b.size; i++)
	{
		stack->b.data[i] = stack->b.data[i + 1];
	}
	printf("pa\n");
}

void push_b(t_stacks *stack)
{
	if (stack->a.size == 0)
		return;
	for (int i = stack -> b.size; i > 0; i--)
	{
		stack->b.data[i] = stack->b.data[i - 1];
	}
	stack->b.data[0] = stack->a.data[0];
	stack->a.size--;
	stack->b.size++;
	for (int i = 0; i < stack->a.size; i++)
	{
		stack->a.data[i] = stack->a.data[i + 1];
	}
	printf("pb\n");
}
