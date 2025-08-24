/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:54:13 by knomura           #+#    #+#             */
/*   Updated: 2025/08/24 17:41:30 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// #include "LIBFT/libft.h"
#include "PRINTF/ft_printf.h"

#define MAX_SIZE 1000

typedef struct {
	int data[MAX_SIZE];
	int rank[MAX_SIZE];
	int size;
} t_rank;

typedef struct {
	int data[MAX_SIZE];
	// int rank[MAX_SIZE];
	int size;
} t_stack;

typedef struct {
	t_stack a;
	t_stack b;
} t_stacks;

void swap_a(t_stacks *stack, int print);
void swap_b(t_stacks *stack, int print);
void ss(t_stacks *stack);
void push_a(t_stacks *stack);
void push_b(t_stacks *stack);
void rotate_a(t_stacks *stack, int print);
void rotate_b(t_stacks *stack, int print);
void rr(t_stacks *stack);
void reverse_rotate_a(t_stacks *stack, int print);
void reverse_rotate_b(t_stacks *stack, int print);
void rrr(t_stacks *stack);

int	ft_safe_atoi(const char *str, int *error);

void has_double(int *data, int size, int *error);


#endif
