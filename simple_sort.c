/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:07:40 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/06 16:07:42 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_stack *stack)
{
	t_list	*curr;
	int		max;
	int		max_pos;
	int		i;

	curr = stack->head;
	max = *(int *)curr->content;
	max_pos = 0;
	i = 0;
	while (curr)
	{
		if (*(int *)curr->content > max)
		{
			max = *(int *)curr->content;
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

	x = *(int *)(*a)->head->content;
	y = *(int *)(*a)->head->next->content;
	z = *(int *)(*a)->head->next->next->content;
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
