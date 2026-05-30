/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:19:05 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 20:21:38 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	ft_lstclear(&stack->head, free);
	free(stack);
}

t_stack	*create_stack(int *values, int size)
{
	t_stack	*stack;
	t_list	*node;
	int		i;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < size)
	{
		node = ft_lstnew(malloc(sizeof(int)));
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		*(int *)node->content = values[i];
		ft_lstadd_back(&stack->head, node);
		stack->size++;
		i++;
	}
	return (stack);
}
