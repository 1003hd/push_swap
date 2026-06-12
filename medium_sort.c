/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:51:40 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/12 17:10:39 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(t_stack *a, t_stack *b, int val)
{
	t_node	*cur;
	int		rank;

	rank = 0;
	cur = a->head;
	while (cur)
	{
		if (cur->value < val)
			rank++;
		cur = cur->next;
	}
	cur = b->head;
	while (cur)
	{
		if (cur->value < val)
			rank++;
		cur = cur->next;
	}
	return (rank);
}

static int	find_max_pos(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		max_pos;
	int		i;

	cur = b->head;
	max = cur->value;
	max_pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->value > max)
		{
			max = cur->value;
			max_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (max_pos);
}

static void	max_to_top(t_stack **b, t_counts *c)
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

static void	push_to_b(t_stack **a, t_stack **b, int sz, t_counts *c)
{
	int	ceiling;
	int	pushed;
	int	r;

	ceiling = sz;
	pushed = 0;
	while ((*a)->size > 0)
	{
		r = get_rank(*a, *b, (*a)->head->value);
		if (r < ceiling)
		{
			pb(a, b, c);
			pushed++;
			if (r < ceiling - sz / 2)
				rb(b, c);
			if (pushed % sz == 0)
				ceiling += sz;
		}
		else
			ra(a, c);
	}
}

void	medium_sort_stacks(t_stack **a, t_stack **b, t_counts *c)
{
	int	sz;
	int	n;

	n = (*a)->size;
	if (n < 2 || is_sorted(*a))
		return ;
	sz = isqrt(n);
	if (sz < 1)
		sz = 1;
	push_to_b(a, b, sz, c);
	while ((*b)->size > 0)
	{
		max_to_top(b, c);
		pa(a, b, c);
	}
}
