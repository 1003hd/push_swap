/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:54:25 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/03 18:19:19 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int	find_max_pos(t_stack *stack)
{
	t_list	*curr;
	int		max;
	int		max_pos;
	int		i;

	curr = stack->head;
	max = *(int *)curr->content;
	max_pos = 0;
	i = 0;
	while (curr)
	{
		if (*(int *)curr->content > max)
		{
			max = *(int *)curr->content;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

static void	move_max_to_top_b(t_stack **b)
{
	int	pos;
	int	size;

	pos = find_max_pos(*b);
	size = (*b)->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

void	selection_sort_stacks(t_stack **a, t_stack **b)
{
	while ((*a)->size > 0)
		pb(a, b);

	while ((*b)->size > 0)
	{
		move_max_to_top_b(b);
		pa(a, b);
	}
}