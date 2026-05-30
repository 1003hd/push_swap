/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:18:07 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 17:28:48 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
}

static void	push(t_stack *dst, t_stack *src)
{
	t_list	*node;

	if (src->size == 0)
		return ;
	node = src->head;
	src->head = src->head->next;
	src->size--;
	node->next = dst->head;
	dst->head = node;
	dst->size++;
}

static void	rotate(t_stack *stack)
{
	t_list	*last;

	if (stack->size < 2)
		return ;
	last = ft_lstlast(stack->head);
	last->next = stack->head;
	stack->head = stack->head->next;
	last->next->next = NULL;
}

static void	reverse_rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*second_last;

	if (stack->size < 2)
		return ;
	last = ft_lstlast(stack->head);
	second_last = stack->head;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = stack->head;
	stack->head = last;
}
