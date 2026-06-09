/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:09:51 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/09 18:13:00 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *s)
{
	return (ft_strncmp(s, "--", 2) == 0);
}

int	total_ops(t_counts *c)
{
	return (c->sa + c->sb + c->ss + c->pa + c->pb
		+ c->ra + c->rb + c->rr + c->rra + c->rrb + c->rrr);
}

int	parse_flags(int *ac, char ***av, int *bench)
{
	int	strategy;

	strategy = 4;
	*bench = 0;
	while (*ac > 1 && is_flag((*av)[1]))
	{
		if (ft_strncmp((*av)[1], "--simple", 9) == 0)
			strategy = 1;
		else if (ft_strncmp((*av)[1], "--medium", 9) == 0)
			strategy = 2;
		else if (ft_strncmp((*av)[1], "--complex", 10) == 0)
			strategy = 3;
		else if (ft_strncmp((*av)[1], "--adaptive", 11) == 0)
			strategy = 4;
		else if (ft_strncmp((*av)[1], "--bench", 8) == 0)
			*bench = 1;
		else
		{
			error_exit();
			return (-1);
		}
		(*av)++;
		(*ac)--;
	}
	return (strategy);
}

// Updated: removed int strategy param; now reads r->strategy directly
int	run_strategy(t_stack **a, t_stack **b, t_run *r)
{
	int	used;
	int	strategy;

	strategy = r->strategy;
	used = strategy;
	if (strategy == 4)
	{
		if ((*a)->size <= 5)
			used = 1;
		if (r->disorder < 0.2)
			used = 1;
		else if (r->disorder < 0.8)
			used = 2;
		else
			used = 3;
	}
	if (used == 1)
		selection_sort_stacks(a, b, r->c);
	else if (used == 2)
		medium_sort_stacks(a, b, r->c);
	else
		radix_sort_stacks(a, b, r->c);
	return (used);
}
