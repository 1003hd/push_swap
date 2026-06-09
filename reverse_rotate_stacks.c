/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:26:52 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/09 18:12:53 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Walks to the last node, detaches it,
// and prepends it to the head
// The last element becomes the first. O(n) due to the traversal
// Does nothing if the stack has fewer than 2 elements
void	reverse_rotate(t_stack **s)
{
	t_node	*prev;
	t_node	*last;

	if (!(*s) || (*s)->size < 2)
		return ;
	prev = (*s)->head;
	last = prev->next;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = (*s)->head;
	(*s)->head = last;
}

// Shifts all elements of stack a down by one, last becomes first, prints "rra"
void	rra(t_stack **a, t_counts *c)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	if (c)
		c->rra++;
}

// Shifts all elements of stack b down by one, last becomes first, prints "rrb"
void	rrb(t_stack **b, t_counts *c)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	if (c)
		c->rrb++;
}

// Applies reverse_rotate to both stacks simultaneously, prints "rrr"
void	rrr(t_stack **a, t_stack **b, t_counts *c)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (c)
		c->rrr++;
}
