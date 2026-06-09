/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:51:40 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/09 18:14:21 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*cur;
	int		a;
	int		b;

	if (!stack->head)
		return (1);
	cur = stack->head;
	while (cur->next)
	{
		a = cur->value;
		b = cur->next->value;
		if (a > b)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	is_decreasing(t_stack *stack)
{
	t_node	*cur;
	int		a;
	int		b;

	if (!stack->head)
		return (1);
	cur = stack->head;
	while (cur->next)
	{
		a = cur->value;
		b = cur->next->value;
		if (a < b)
			return (0);
		cur = cur->next;
	}
	return (1);
}

// Counts inverted pairs / total pairs, returns 0.0 if already sorted
// 1.0 if fully reversed. Must be called before any sorting moves.
double	compute_disorder(t_stack *stack)
{
	t_node	*ci;
	t_node	*cj;
	double	mistakes;
	double	total;

	if (!stack->head || stack->size < 2)
		return (0.0);
	mistakes = 0;
	total = 0;
	ci = stack->head;
	while (ci)
	{
		cj = ci->next;
		while (cj)
		{
			total++;
			if (ci->value > cj->value)
				mistakes++;
			cj = cj->next;
		}
		ci = ci->next;
	}
	return (mistakes / total);
}
