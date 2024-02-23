/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:01:39 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/19 17:47:33 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap/moves.h"
#include "stack.h"
#include "types.h"
#include <stdlib.h>
#include <unistd.h>

void	sort_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = create_stack();
	if (!tmp)
		exit(EXIT_FAILURE);
	if (!is_sorted_stack(stack, 0, -1))
		solve(stack, tmp);
	destroy_stack(tmp, free);
}

_Bool	is_sorted_stack(t_stack *stack, size_t from, ssize_t to)
{
	t_list	*tmp;
	size_t	i;

	tmp = stack->top;
	i = 0;
	while (tmp->next != NULL && i < from)
	{
		tmp = tmp->next;
		i++;
	}
	if (to == -1)
		to = stack->size;
	while (tmp->next != NULL && i < (size_t)to)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (false);
		tmp = tmp->next;
		i++;
	}
	return (true);
}
