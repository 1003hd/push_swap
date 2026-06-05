/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 00:00:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/05 00:00:00 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Counts how many elements of vals are strictly smaller than v.
// Since values are distinct, this gives the unique rank of v (0..size-1).
static int	count_smaller(int *vals, int size, int v)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		if (vals[i] < v)
			c++;
		i++;
	}
	return (c);
}

// Replaces every value by its rank index (0..size-1) so radix bit count
// is bounded by log2(size). Returns 0 on malloc failure, 1 otherwise.
static int	normalize(t_stack *a)
{
	int		*vals;
	t_list	*cur;
	int		i;

	vals = malloc(sizeof(int) * a->size);
	if (!vals)
		return (0);
	cur = a->head;
	i = 0;
	while (cur)
	{
		vals[i++] = *(int *)cur->content;
		cur = cur->next;
	}
	cur = a->head;
	while (cur)
	{
		*(int *)cur->content = count_smaller(vals, a->size, *(int *)cur->content);
		cur = cur->next;
	}
	free(vals);
	return (1);
}

// Number of bits needed to represent the largest index (size - 1).
static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

// Binary radix sort: for each bit, push elements with bit==0 to b,
// rotate elements with bit==1 to the bottom of a, then pull b back.
static void	radix(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	max_bits = get_max_bits((*a)->size);
	bit = 0;
	while (bit < max_bits)
	{
		size = (*a)->size;
		i = 0;
		while (i < size)
		{
			if (((*(int *)(*a)->head->content) >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while ((*b)->size > 0)
			pa(a, b);
		bit++;
	}
}

// Entry point. Handles trivial sizes, normalizes to indices, then sorts.
void	radix_sort_stacks(t_stack **a, t_stack **b)
{
	if ((*a)->size < 2 || is_sorted(*a))
		return ;
	if ((*a)->size == 2)
		return (sa(a));
	if (!normalize(*a))
		return (error_exit());
	if ((*a)->size == 3)
		sort_three(a);
	else
		radix(a, b);
}
