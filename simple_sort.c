/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:07:40 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/09 18:12:58 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_stack *stack)
{
	t_node	*curr;
	int		max;
	int		max_pos;
	int		i;

	curr = stack->head;
	max = curr->value;
	max_pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->value > max)
		{
			max = curr->value;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

static void	move_max_to_top_b(t_stack **b, t_counts *c)
{
	int	pos;
	int	size;

	pos = find_max_pos(*b);
	size = (*b)->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b, c);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b, c);
	}
}

void	selection_sort_stacks(t_stack **a, t_stack **b, t_counts *c)
{
	if ((*a)->size < 2 || is_sorted(*a))
		return ;
	while ((*a)->size > 0)
		pb(a, b, c);
	while ((*b)->size > 0)
	{
		move_max_to_top_b(b, c);
		pa(a, b, c);
	}
}

// Optimal sort for exactly 3 elements (max 2 operations).
void	sort_three(t_stack **a, t_counts *c)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->head->value;
	y = (*a)->head->next->value;
	z = (*a)->head->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, c);
	else if (x > y && y > z)
	{
		sa(a, c);
		rra(a, c);
	}
	else if (x > y && y < z && x > z)
		ra(a, c);
	else if (x < y && y > z && x < z)
	{
		sa(a, c);
		ra(a, c);
	}
	else if (x < y && y > z && x > z)
		rra(a, c);
}
