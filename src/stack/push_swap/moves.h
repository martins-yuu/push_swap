/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 01:16:44 by yuuko             #+#    #+#             */
/*   Updated: 2024/03/17 13:41:14 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "../stack.h"

typedef enum e_move
{
	SA = 1 << 1,
	SB = 1 << 2,
	SS = 1 << 3,
	PA = 1 << 4,
	PB = 1 << 5,
	RA = 1 << 6,
	RB = 1 << 7,
	RR = 1 << 8,
	RRA = 1 << 9,
	RRB = 1 << 10,
	RRR = 1 << 11,
}		t_move;

void	apply_move(t_move move, t_stack *a, t_stack *b);
void	repeat_move(t_move move, size_t times, t_stack *a, t_stack *b);
void	solve(t_stack *a, t_stack *b);
void	sort5(t_stack *a, t_stack *b);

#endif
