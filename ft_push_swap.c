/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:42:16 by knomura           #+#    #+#             */
/*   Updated: 2025/08/02 17:52:21 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void push_swap(t_stacks stack, int element)
{
	int i = 0;
	int b[element + 1];

	// swap_a(&stack, 1);
	// swap_b(&stack, 1);
	// ss(&stack);
	// push_a(&stack);
	// push_b(&stack);
	// rotate_a(&stack, 1);
	// rotate_b(&stack, 1);
	// rr(&stack);
	// reverse_rotate_a(&stack, 1);
	// reverse_rotate_b(&stack, 1);
	push_b(&stack);



	// push_a(&stack);

	printf("Stack A\n");
	for (int i = 0; i < stack.a.size; i++)
		ft_printf("%d %d\n", stack.a.data[i], stack.a.size);
	printf("Stack B\n");
	for (int i = 0; i < stack.b.size; i++)
		ft_printf("%d %d\n", stack.b.data[i], stack.b.size);
	// printf("%d", stack.a.data[4]);



}

int	main(int argc, char *argv[])
{
	t_stacks stack;
	int i;
	int temp;

	i = 0;
	while (i < argc - 1)
	{
		temp = ft_atoi(argv[i + 1]);
		stack.a.data[i] = temp;
		i++;
	}
	stack.a.size = argc - 1;
	stack.b.size = 0;

	push_swap(stack, argc - 1);

	return (0);
}
