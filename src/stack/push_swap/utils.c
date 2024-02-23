/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:36:34 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/20 02:56:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"
#include "types.h"
#include <stdlib.h>
#include <unistd.h>

t_result	get_(t_compare_func compar, t_stack *stack)
{
	t_result	res;
	t_list		*tmp;
	ssize_t		position;
	int			current;

	tmp = stack->top;
	res.value = *(int *)tmp->content;
	res.index = 0;
	position = 0;
	while (tmp != NULL)
	{
		current = *(int *)tmp->content;
		if (compar(current, res.value))
		{
			res.value = current;
			res.index = position;
		}
		tmp = tmp->next;
		position++;
	}
	return (res);
}

_Bool	is_largest(int a, int b)
{
	return (a > b);
}

_Bool	is_smallest(int a, int b)
{
	return (a < b);
}
