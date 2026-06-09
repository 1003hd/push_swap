/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:18:07 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/09 18:12:40 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Relinks the first two nodes of a stack so the second becomes the head
// Does nothing if the stack has fewer than 2 elements
void	swap(t_stack **s)
{
	t_node	*first;
	t_node	*second;

	if (!(*s) || (*s)->size < 2)
		return ;
	first = (*s)->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*s)->head = second;
}

// Swaps the top two elements of stack a, prints "sa"
void	sa(t_stack **a, t_counts *c)
{
	swap(a);
	write(1, "sa\n", 3);
	if (c)
		c->sa++;
}

// Swaps the top two elements of stack b, prints "sb"
void	sb(t_stack **b, t_counts *c)
{
	swap(b);
	write(1, "sb\n", 3);
	if (c)
		c->sb++;
}

// Swaps the top two elements of both stacks simultaneously, prints "ss"
void	ss(t_stack **a, t_stack **b, t_counts *c)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (c)
		c->ss++;
}
