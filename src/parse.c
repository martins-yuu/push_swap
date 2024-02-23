/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 04:10:12 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/17 19:43:08 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "stack/stack.h"
#include "types.h"
#include <limits.h>
#include <stdlib.h>

#define INT_MAX_DIGITS 10

static int		*get_value(const char *str);
static _Bool	is_number(const char *str);
static _Bool	in_range(long long num, long long min, long long max);
static _Bool	is_duplicate(int num, t_stack *stack);

t_stack	*parse_numbers(const char *list[], int count)
{
	t_stack	*stack;
	size_t	i;
	int		*num;

	stack = create_stack();
	i = count;
	while (i > 0)
	{
		i--;
		num = get_value(list[i]);
		if (!num || is_duplicate(*num, stack))
		{
			free(num);
			destroy_stack(stack, free);
			return (NULL);
		}
		push_stack(stack, num);
	}
	return (stack);
}

static int	*get_value(const char *str)
{
	long long	*num;

	if (!str || !*str)
		return (NULL);
	if (!is_number(str))
		return (NULL);
	num = malloc(sizeof(long long));
	if (!num)
		exit(EXIT_FAILURE);
	*num = ft_atoll(str);
	if (!in_range(*num, INT_MIN, INT_MAX))
	{
		free(num);
		return (NULL);
	}
	return ((int *)num);
}

static _Bool	is_number(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > INT_MAX_DIGITS)
		return (false);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static _Bool	in_range(long long num, long long min, long long max)
{
	return (num >= min && num <= max);
}

static _Bool	is_duplicate(int num, t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp != NULL)
	{
		if (num == *(int *)tmp->content)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
