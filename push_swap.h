/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:54:13 by knomura           #+#    #+#             */
/*   Updated: 2025/07/31 20:21:23 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "LIBFT/libft.h"
#include "PRINTF/ft_printf.h"

#define MAX_SIZE 1000

typedef struct {
	int data[MAX_SIZE];
	int size;
} t_stack;

typedef struct {
	t_stack a;
	t_stack b;
} t_stacks;

void swap_a(t_stacks *stack);
void swap_b(t_stacks *stack);
void ss(t_stacks *stack);

#endif
