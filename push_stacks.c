/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:25:07 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/01 17:26:26 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Detaches the head node of src and prepends it to dst
// Updates size on both stacks
// Does nothing if src is empty
static void	push(t_stack **dst, t_stack **src)
{
	t_list	*node;

	if (!(*src) || (*src)->size == 0)
		return ;
	node = (*src)->head;
	(*src)->head = node->next;
	(*src)->size--;
	node->next = (*dst)->head;
	(*dst)->head = node;
	(*dst)->size++;
}

// Takes the top element of b and puts it on top of a, prints "pa"
void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

// Takes the top element of a and puts it on top of b, prints "pb"
void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
