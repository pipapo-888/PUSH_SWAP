/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:42:16 by knomura           #+#    #+#             */
/*   Updated: 2025/08/03 18:54:48 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	is_sorted(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.size - 1)
	{
		if (a.data[i] > a.data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void sort_2(t_stacks *stack)
{
	if (is_sorted(stack -> a))
	{
		printf("ソート済み\n");
		return ;
	}
	else
		swap_a(stack, 1);
	printf("ソートしたよ\n");
}

void sort_3(t_stacks *stack)
{
	int a;
	int b;
	int c;

	a = stack->a.data[0];
	b = stack->a.data[1];
	c = stack->a.data[2];
	if (is_sorted(stack -> a))
		return ;
	if (a > b && b > c)
	{
		swap_a(stack, 1);
		reverse_rotate_a(stack, 1);
	}
	if (a > b && b < c && a > c)
		rotate_a(stack, 1);
	if (a < b && b > c && a < c)
	{
		swap_a(stack ,1);
		rotate_a(stack, 1);
	}
	if (a > b && b < c && a < c)
		swap_a(stack , 1);
	if (a < b && b > c && a > c)
		reverse_rotate_a(stack, 1);
}

void push_swap(t_stacks *stack, int element)
{
	// swap_a(stack, 1);
	// swap_b(stack, 1);
	// ss(stack);
	// push_a(stack);
	// push_b(stack);
	// rotate_a(stack, 1);
	// rotate_b(stack, 1);
	// rr(stack);
	// reverse_rotate_a(stack, 1);
	// reverse_rotate_b(stack, 1);
	// rra(stack);

	if (element == 2)
		sort_2(stack);
	if (element ==  3)
		sort_3(stack);

	printf("Stack A\n");
	for (int i = 0; i < stack->a.size; i++)
		ft_printf("%d %d\n", stack->a.data[i], stack->a.size);
	if (stack->a.size == 0) printf("なし\n");
	printf("Stack B\n");
	for (int i = 0; i < stack->b.size; i++)
		ft_printf("%d %d\n", stack->b.data[i], stack->b.size);
	if (stack->b.size == 0) printf("なし\n");
}

int	main(int argc, char *argv[])
{
	t_stacks stack;
	int i;
	int error;

	error = 0;
	i = 0;
	while (i < argc - 1)
	{
		stack.a.data[i] = ft_safe_atoi(argv[i + 1], &error);
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
	push_swap(&stack, argc - 1);
	return (0);
}
