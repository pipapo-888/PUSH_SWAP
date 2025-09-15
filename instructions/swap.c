/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:43:00 by knomura           #+#    #+#             */
/*   Updated: 2025/09/15 16:02:44 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stacks *stack, int print)
{
	t_rank	temp;

	temp = stack -> a.data[0];
	stack -> a.data[0] = stack -> a.data[1];
	stack -> a.data[1] = temp;
	if (print)
		ft_printf("sa\n");
}

void	swap_b(t_stacks *stack, int print)
{
	t_rank	temp;

	temp = stack -> b.data[0];
	stack -> b.data[0] = stack -> b.data[1];
	stack -> b.data[1] = temp;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stacks *stack)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	ft_printf("ss\n");
}
