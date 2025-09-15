/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:48:32 by knomura           #+#    #+#             */
/*   Updated: 2025/09/15 16:02:36 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_stacks *stack, int print)
{
	t_rank	temp;
	int		i;

	if (stack->a.size == 0)
		return ;
	i = stack->a.size;
	temp = stack->a.data[stack->a.size - 1];
	while (i > 0)
	{
		stack->a.data[i] = stack->a.data[i - 1];
		i--;
	}
	stack->a.data[0] = temp;
	if (print)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stacks *stack, int print)
{
	t_rank	temp;
	int		i;

	if (stack->b.size == 0)
		return ;
	i = stack->b.size;
	temp = stack->b.data[stack->b.size - 1];
	while (i > 0)
	{
		stack->b.data[i] = stack->b.data[i - 1];
		i--;
	}
	stack->b.data[0] = temp;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stacks *stack)
{
	reverse_rotate_a(stack, 0);
	reverse_rotate_b(stack, 0);
	ft_printf("rrr\n");
}
