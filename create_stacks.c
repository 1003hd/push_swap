/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:19:05 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/06 14:55:28 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack)
		return ;
	cur = stack->head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(stack);
}

t_stack	*create_stack(int *values, int size)
{
	t_stack	*stack;
	t_node	*node;
	t_node	**tail;
	int		i;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	tail = &stack->head;
	i = 0;
	while (i < size)
	{
		node = new_node(values[i]);
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		*tail = node;
		tail = &node->next;
		stack->size++;
		i++;
	}
	return (stack);
}

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	return (stack);
}
