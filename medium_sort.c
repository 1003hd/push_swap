/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:51:40 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/04 17:05:36 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** get_rank: returns the rank (0..n-1) of value 'val' across both stacks.
** Rank = how many numbers in A and B are strictly smaller than val.
** A and B together always hold the original n numbers during phase 1,
** so the rank stays stable no matter how many elements moved to B.
** Pure list walk -> costs zero push_swap operations.
**   a   = stack A (numbers still to sort)
**   b   = stack B (numbers already pushed)
**   val = the value whose rank we want
*/
static int	get_rank(t_stack *a, t_stack *b, int val)
{
	t_list	*cur;
	int		rank;

	rank = 0;
	cur = a->head;
	while (cur)
	{
		if (*(int *)cur->content < val)
			rank++;
		cur = cur->next;
	}
	cur = b->head;
	while (cur)
	{
		if (*(int *)cur->content < val)
			rank++;
		cur = cur->next;
	}
	return (rank);
}

/*
** find_max_pos: returns the position (0 = top) of the largest value in B.
** Walks the list from top to bottom tracking the biggest seen so far.
** Free walk -> costs zero push_swap operations.
**   b = stack B to scan
*/
static int	find_max_pos(t_stack *b)
{
	t_list	*cur;
	int		max;
	int		max_pos;
	int		i;

	cur = b->head;
	max = *(int *)cur->content;
	max_pos = 0;
	i = 0;
	while (cur)
	{
		if (*(int *)cur->content > max)
		{
			max = *(int *)cur->content;
			max_pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (max_pos);
}

/*
** max_to_top: rotates B until its largest value sits on top.
** Picks the cheaper direction: rb (forward) if the max is in the top half,
** rrb (backward) if it is in the bottom half. Saves operations.
**   b = address of stack B pointer (so rb/rrb can mutate it)
*/
static void	max_to_top(t_stack **b)
{
	int	pos;
	int	size;

	pos = find_max_pos(*b);
	size = (*b)->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

/*
** push_to_b: phase 1. Empties A into B chunk by chunk (smallest ranks first).
** 'ceiling' is the top rank of the chunk currently being collected.
** If top of A belongs to this chunk -> pb it; if it is also in the chunk's
** lower half -> rb to sink it, keeping B roughly descending. Otherwise ra
** to defer it for a later lap. Every full chunk (sz pushes) raises ceiling.
**   a  = address of stack A pointer (source)
**   b  = address of stack B pointer (destination)
**   sz = chunk size (number of ranks per chunk)
*/
static void	push_to_b(t_stack **a, t_stack **b, int sz)
{
	int	ceiling;
	int	pushed;
	int	r;

	ceiling = sz;
	pushed = 0;
	while ((*a)->size > 0)
	{
		r = get_rank(*a, *b, *(int *)(*a)->head->content);
		if (r < ceiling)
		{
			pb(a, b);
			pushed++;
			if (r < ceiling - sz / 2)
				rb(b);
			if (pushed % sz == 0)
				ceiling += sz;
		}
		else
			ra(a);
	}
}

/*
** medium_sort_stacks: O(n*sqrt(n)) chunk sort, entry point.
** Phase 1: push_to_b spreads A into B as ~sqrt(n) ordered chunks.
** Phase 2: pull B's max to top and pa back, leaving A sorted ascending.
** Chunk size sz tuned by n: ~5 chunks small, ~11 chunks for big inputs.
** Returns early if already sorted or fewer than 2 elements.
**   a = address of stack A pointer (input, ends sorted)
**   b = address of stack B pointer (empty helper stack)
*/
void	medium_sort_stacks(t_stack **a, t_stack **b)
{
	int	sz;
	int	n;

	n = (*a)->size;
	if (n < 2 || is_sorted(*a))
		return ;
	sz = n / 5;
	if (n > 100)
		sz = n / 11;
	if (sz < 1)
		sz = 1;
	push_to_b(a, b, sz);
	while ((*b)->size > 0)
	{
		max_to_top(b);
		pa(a, b);
	}
}
