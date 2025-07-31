/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:42:16 by knomura           #+#    #+#             */
/*   Updated: 2025/07/31 13:24:35 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int a[argc];
	int i;

	i = 0;
	ft_printf("%d\n", argc);

	while (i < argc - 1)
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}


	push_swap(a);

	return (0);
}

void push_swap(int *a)
{

	int i = 0;

	for (int i = 0; a[i]; i++)
	{
		ft_printf("%d", a[i]);
	}


}
