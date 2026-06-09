/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:09:51 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/09 16:12:11 by baserbet         ###   ########.fr       */
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

void	print_bench(double disorder, int strategy, t_counts *c)
{
	const char	*names[5] = {"", "Simple", "Medium", "Complex", "Adaptive"};
	const char	*complexity[5] = {"", "O(n^2)", "O(n*sqrt(n))",
		"O(n log n)", "O(n log n)"};

	dprintf(2, "[bench] disorder: %.2f%%\n", disorder * 100.0);
	dprintf(2, "[bench] strategy: %s / %s\n",
		names[strategy], complexity[strategy]);
	dprintf(2, "[bench] total_ops: %d\n", total_ops(c));
	dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		c->sa, c->sb, c->ss, c->pa, c->pb);
	dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		c->ra, c->rb, c->rr, c->rra, c->rrb, c->rrr);
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
