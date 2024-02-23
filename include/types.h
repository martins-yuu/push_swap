/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:58:37 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/20 03:58:28 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <unistd.h>

typedef enum e_bool
{
	false,
	true,
}				t_bool;

typedef struct s_result
{
	int			value;
	ssize_t		index;
}				t_result;

typedef _Bool	(*t_compare_func)(int a, int b);

#endif
