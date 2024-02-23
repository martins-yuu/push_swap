/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:51:47 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/16 22:26:21 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_linkedlist.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	t_list	*top;
	size_t	size;
}			t_stack;

t_stack		*create_stack(void);
void		destroy_stack(t_stack *stack, void (*del)(void *));
_Bool		is_empty_stack(t_stack *stack);
void		*peek_stack(t_stack *stack);
void		push_stack(t_stack *stack, void *content);
void		*pop_stack(t_stack *stack);
void		swap_stack(t_stack *stack);
void		rotate_stack(t_stack *stack);
void		reverse_rotate_stack(t_stack *stack);
void		sort_stack(t_stack *stack);
_Bool		is_sorted_stack(t_stack *stack, size_t from, ssize_t to);
void		print_stack(t_stack *stack);

#endif
