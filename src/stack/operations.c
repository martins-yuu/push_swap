/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:55:03 by yuuko             #+#    #+#             */
/*   Updated: 2024/02/24 01:50:11 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	push_stack(t_stack *stack, void *content)
{
	t_list	*node;

	node = ft_lstaddcontent_front(&stack->top, content);
	if (!node)
		exit(EXIT_FAILURE);
	stack->top = node;
	stack->size++;
}

void	*pop_stack(t_stack *stack)
{
	t_list	*tmp;
	void	*content;

	if (is_empty_stack(stack))
		return (NULL);
	tmp = stack->top;
	content = tmp->content;
	stack->top = tmp->next;
	ft_lstdelone(tmp, NULL);
	stack->size--;
	return (content);
}

void	swap_stack(t_stack *stack)
{
	void	*first;
	void	*second;

	if (stack->size < 2)
		return ;
	first = pop_stack(stack);
	second = pop_stack(stack);
	push_stack(stack, first);
	push_stack(stack, second);
}

void	rotate_stack(t_stack *stack)
{
	void	*content;

	if (stack->size < 2)
		return ;
	content = pop_stack(stack);
	if (!ft_lstaddcontent_back(&stack->top, content))
		exit(EXIT_FAILURE);
	stack->size++;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_list	*tmp;
	void	*content;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	while (tmp->next->next)
		tmp = tmp->next;
	content = tmp->next->content;
	ft_lstdelone(tmp->next, NULL);
	tmp->next = NULL;
	if (!ft_lstaddcontent_front(&stack->top, content))
		exit(EXIT_FAILURE);
}
