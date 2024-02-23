/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:10:37 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/17 13:41:19 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "moves.h"
#include "utils.h"

static void	sort4(t_stack *a, t_stack *b);
static void	sort3(t_stack *a);

void	sort5(t_stack *a, t_stack *b)
{
	t_result	smallest;

	if (a->size <= 4)
		return (sort4(a, b));
	smallest = get_(is_smallest, a);
	if (smallest.index == 1)
		apply_move(RA, a, NULL);
	else if (smallest.index == 2)
		repeat_move(RA, 2, a, NULL);
	else if (smallest.index == 3)
		repeat_move(RRA, 2, a, NULL);
	else if (smallest.index == 4)
		apply_move(RRA, a, NULL);
	if (is_sorted_stack(a, 0, -1))
		return ;
	apply_move(PB, a, b);
	sort4(a, b);
	apply_move(PA, a, b);
}

static void	sort4(t_stack *a, t_stack *b)
{
	t_result	smallest;

	if (a->size <= 3)
		return (sort3(a));
	smallest = get_(is_smallest, a);
	if (smallest.index == 1)
		apply_move(RA, a, NULL);
	else if (smallest.index == 2)
		repeat_move(RA, 2, a, NULL);
	else if (smallest.index == 3)
		apply_move(RRA, a, NULL);
	if (is_sorted_stack(a, 0, -1))
		return ;
	apply_move(PB, a, b);
	sort3(a);
	apply_move(PA, a, b);
}

static void	sort3(t_stack *a)
{
	t_result	smallest;
	t_result	largest;

	if (a->size == 1)
		return ;
	if (a->size == 2)
		return (apply_move(SA, a, NULL));
	smallest = get_(is_smallest, a);
	largest = get_(is_largest, a);
	if (largest.index == 0)
		apply_move(RA, a, NULL);
	else if (largest.index == 1)
		apply_move(RRA, a, NULL);
	if (*(int *)peek_stack(a) != smallest.value)
		apply_move(SA, a, NULL);
}
