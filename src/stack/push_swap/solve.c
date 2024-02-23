/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:19:13 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/25 02:19:26 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "moves.h"
#include "utils.h"
#include <stdlib.h>

static void	sort(t_stack *a, t_stack *b);

void	solve(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		return (sort5(a, b));
	sort(a, b);
}

static void	sort(t_stack *a, t_stack *b)
{
	t_result	smallest;

	while (a->size > 0)
	{
		smallest = get_(is_smallest, a);
		if ((size_t)smallest.index < a->size / 2)
			repeat_move(RA, smallest.index, a, b);
		else
			repeat_move(RRA, a->size - smallest.index, a, b);
		apply_move(PB, a, b);
	}
	repeat_move(PA, b->size, a, b);
}
