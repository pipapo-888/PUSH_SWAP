/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:42:16 by knomura           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/24 17:51:49 by knomura          ###   ########.fr       */
=======
/*   Updated: 2025/08/03 21:15:44 by knomura          ###   ########.fr       */
>>>>>>> 17a3e0bd6fbbbbd67455f6b0bfb8da81de8430cc
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

void bubble_sort(int *arr, int size)
{
	int i;
	int j;
	int temp;

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

void set_rank(t_rank *rank)
{
	int temp[MAX_SIZE];
	int i;
	int ran;

	i = 0;
	while (i < rank -> size)
	{
		temp[i] = rank->data[i];
		i++;
	}
	bubble_sort(temp, rank->size);
	i = 0;
	while (i < rank->size)
	{
		ran = 0;
		while (temp[ran] != rank->data[i])
			ran++;
		rank->rank[i] = ran;
		i++;
	}

	    printf("size: %d\n", rank->size);
    printf("Index | Data | Rank\n");
    printf("---------------------\n");
    for (int i = 0; i < rank->size; i++)
    {
        printf("%5d | %4d | %4d\n", i, rank->data[i], rank->rank[i]);
    }
}

void push_swap(t_stacks *stack, int element)
{
	t_rank rank;
	for (int i = 0; i < stack->a.size - 1; i++)
		rank.data[i] = stack->a.data[i];
	rank.size = stack->a.size;

	set_rank(&rank);
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
		ft_printf("%d %d\n", stack->b.data[i],  stack->b.size);
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
