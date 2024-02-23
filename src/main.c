/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:40:36 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/15 22:49:42 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "parse.h"
#include "stack/stack.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_stack	*numbers;

	if (argc == 1)
		exit(EXIT_FAILURE);
	numbers = parse_numbers((const char **)argv + 1, argc - 1);
	if (!numbers)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	sort_stack(numbers);
	destroy_stack(numbers, free);
	return (EXIT_SUCCESS);
}
