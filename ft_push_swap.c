/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:55:53 by knomura           #+#    #+#             */
/*   Updated: 2025/08/31 05:47:21 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
	// printf("size: %d\n", stack->a.size);
	// printf(" Data | Rank\n");
	// printf("-------------\n");
	// for (int i = 0; i < stack->a.size; i++)
	// 	printf("%5d | %4d\n", stack->a.data[i].data, stack->a.data[i].rank);
}

void	push_swap(t_stacks *stack, int element)
{
	set_rank(stack);
	if (element == 2)
		sort_2(stack);
	else if (element == 3)
		sort_3(stack);
	else if (element == 5)
		sort_5(stack);
	// else
	// 	sort_all(stack);

	// printf("Stack A\n");
	// for (int i = 0; i < stack->a.size; i++)
	// 	ft_printf("%d %d\n", stack->a.data[i].data, stack->a.size);
	// if (stack->a.size == 0)
	// 	printf("なし\n");
	// printf("Stack B\n");
	// for (int i = 0; i < stack->b.size; i++)
	// 	ft_printf("%d %d\n", stack->b.data[i].data,  stack->b.size);
	// if (stack->b.size == 0)
	// 	printf("なし\n");
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
	push_swap(&stack, argc - 1);
	return (0);
}
