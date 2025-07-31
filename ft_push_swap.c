/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:42:16 by knomura           #+#    #+#             */
/*   Updated: 2025/07/31 18:06:33 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void push_swap(t_stacks stack, int element)
{
	int i = 0;
	int b[element + 1];

	swap_a(stack);
	for (int i = 0; i < element; i++)
		ft_printf("%d\n", stack.a.data[i]);




}

int	main(int argc, char *argv[])
{
	t_stacks stack;
	int i;
	int temp;

	i = 0;
	printf("%d\n", argc);

	while (i < argc - 1)
	{
		temp = ft_atoi(argv[i + 1]);
		stack.a.data[i] = temp;
		i++;
	}


	push_swap(stack, argc - 1);

	return (0);
}
