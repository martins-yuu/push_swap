/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:41:01 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/16 04:07:29 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linkedlist.h"
#include "ft_stdio.h"
#include "stack.h"
#include <stdlib.h>

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	destroy_stack(t_stack *stack, void (*del)(void *))
{
	ft_lstclear(&stack->top, del);
	free(stack);
}

_Bool	is_empty_stack(t_stack *stack)
{
	return (stack->size == 0);
}

void	*peek_stack(t_stack *stack)
{
	if (is_empty_stack(stack))
		return (NULL);
	return (stack->top->content);
}

void	print_stack(t_stack *stack)
{
	t_list	*node;

	if (!stack)
		return (ft_putchar('\n'));
	node = stack->top;
	ft_putchar('[');
	while (node != NULL)
	{
		ft_putnbr(*(int *)node->content);
		if (node->next != NULL)
			ft_putstr(", ");
		node = node->next;
	}
	ft_putchar(']');
	ft_putchar('\n');
}
