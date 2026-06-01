/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:25:54 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/01 18:11:04 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Detaches the head node and appends it to the tail
// The first element becomes the last. O(n) due to the traversal
// Does nothing if the stack has fewer than 2 elements
static void	rotate(t_stack **s)
{
	t_list	*first;
	t_list	*last;

	if (!(*s) || (*s)->size < 2)
		return ;
	first = (*s)->head;
	last = first;
	while (last->next)
		last = last->next;
	(*s)->head = first->next;
	first->next = NULL;
	last->next = first;
}

// Shifts all elements of stack a up by one, first becomes last, prints "ra"
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

// Shifts all elements of stack b up by one, first becomes last, prints "rb"
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

// Applies rotate to both stacks simultaneously, prints "rr"
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}