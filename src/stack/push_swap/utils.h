/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:43:16 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/16 22:47:35 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../stack.h"
# include "types.h"

t_result	get_(t_compare_func compar, t_stack *stack);
_Bool		is_largest(int a, int b);
_Bool		is_smallest(int a, int b);

#endif
