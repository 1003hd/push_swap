/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:51:40 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 20:22:12 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*cur;
	int		a;
	int		b;

	if (!stack->head)
		return (1);
	cur = stack->head;
	while (cur->next)
	{
		a = (int)(intptr_t)cur->content;
		b = (int)(intptr_t)cur->next->content;
		if (a > b)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	is_decreasing(t_stack *stack)
{
	t_list	*cur;
	int		a;
	int		b;

	if (!stack->head)
		return (1);
	cur = stack->head;
	while (cur->next)
	{
		a = (int)(intptr_t)cur->content;
		b = (int)(intptr_t)cur->next->content;
		if (a < b)
			return (0);
		cur = cur->next;
	}
	return (1);
}