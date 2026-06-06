/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 00:00:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/06 15:11:07 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		*(int *)cur->content = count_smaller(vals, a->size,
				*(int *)cur->content);
		cur = cur->next;
	}
	free(vals);
	return (1);
}

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	radix(t_stack **a, t_stack **b, t_counts *c)
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
				ra(a, c);
			else
				pb(a, b, c);
			i++;
		}
		while ((*b)->size > 0)
			pa(a, b, c);
		bit++;
	}
}

void	radix_sort_stacks(t_stack **a, t_stack **b, t_counts *c)
{
	if ((*a)->size < 2 || is_sorted(*a))
		return ;
	if ((*a)->size == 2)
	{
		sa(a, c);
		return ;
	}
	if (!normalize(*a))
	{
		error_exit();
		return ;
	}
	if ((*a)->size == 3)
		sort_three(a, c);
	else
		radix(a, b, c);
}
