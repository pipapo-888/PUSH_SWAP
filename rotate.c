/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:13:49 by knomura           #+#    #+#             */
/*   Updated: 2025/08/02 17:07:59 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_stacks *stack, int print)
{
	int temp;

	if (stack->a.size == 0)
		return ;
	temp = stack->a.data[0];
	for (int i = 0; i < stack->a.size - 1; i++)
	{
		stack->a.data[i] = stack->a.data[i + 1];
	}
	stack->a.data[stack->a.size - 1] = temp;
	if (print)
		ft_printf("ra\n");
}

void rotate_b(t_stacks *stack, int print)
{
	int temp;

	if (stack->b.size == 0)
		return ;
	temp = stack->b.data[0];
	for (int i = 0; i < stack->b.size - 1; i++)
	{
		stack->b.data[i] = stack->b.data[i + 1];
	}
	stack->b.data[stack->b.size - 1] = temp;
	if (print)
		ft_printf("rb\n");
}

void rr(t_stacks *stack)
{
	rotate_a(stack, 0);
	rotate_b(stack, 0);
	ft_printf("rr\n");
}
