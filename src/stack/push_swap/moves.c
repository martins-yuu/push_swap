/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:37:48 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/25 02:05:09 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "ft_stdio.h"
#include "moves.h"
#include <stdlib.h>

static void	print_move(t_move move);
static void	merge_move(t_move *move);

void	apply_move(t_move move, t_stack *a, t_stack *b)
{
	static size_t	moves = 0;

	ft_putnbr(++moves);
	ft_putchar(')');
	merge_move(&move);
	if (move & SA || move & SS)
		swap_stack(a);
	if (move & SB || move & SS)
		swap_stack(b);
	if (move & PA && !is_empty_stack(b))
		push_stack(a, pop_stack(b));
	if (move & PB && !is_empty_stack(a))
		push_stack(b, pop_stack(a));
	if (move & RA || move & RR)
		rotate_stack(a);
	if (move & RB || move & RR)
		rotate_stack(b);
	if (move & RRA || move & RRR)
		reverse_rotate_stack(a);
	if (move & RRB || move & RRR)
		reverse_rotate_stack(b);
	print_move(move);
	ft_putstr("a: ");
	print_stack(a);
	ft_putstr("b: ");
	print_stack(b);
}

void	repeat_move(t_move move, size_t times, t_stack *a, t_stack *b)
{
	size_t	i;

	i = 0;
	while (i < times)
	{
		apply_move(move, a, b);
		i++;
	}
}

static void	print_move(t_move move)
{
	if (move & SA || move & SB)
		ft_putstr("s");
	if (move & SS)
		ft_putstr("ss");
	if (move & PA || move & PB)
		ft_putstr("p");
	if (move & RA || move & RB)
		ft_putstr("r");
	if (move & RR || move & RRA || move & RRB)
		ft_putstr("rr");
	if (move & RRR)
		ft_putstr("rrr");
	if (move & SA || move & PA || move & RA || move & RRA)
		ft_putstr("a");
	if (move & SB || move & PB || move & RB || move & RRB)
		ft_putstr("b");
	ft_putchar('\n');
}

static void	merge_move(t_move *move)
{
	if (*move == (SA | SB))
		*move = SS;
	if (*move == (RA | RB))
		*move = RR;
	if (*move == (RRA | RRB))
		*move = RRR;
}
