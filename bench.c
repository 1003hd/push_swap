/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:40:00 by aselezen          #+#    #+#             */
/*   Updated: 2026/06/09 18:40:00 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Writes "label: value" to stderr (fd 2), no trailing newline.
static void	put_kv(char *label, int value)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(value, 2);
}

// Writes ratio (0.0-1.0) as a percentage with two decimals, e.g. "73.50%".
static void	put_percent(double ratio)
{
	int	whole;
	int	frac;

	whole = (int)(ratio * 100.0);
	frac = (int)(ratio * 10000.0) % 100;
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (frac < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac, 2);
	ft_putchar_fd('%', 2);
}

static void	put_counts(t_counts *c)
{
	put_kv("[bench] total_ops: ", total_ops(c));
	put_kv("\n[bench] sa: ", c->sa);
	put_kv(" sb: ", c->sb);
	put_kv(" ss: ", c->ss);
	put_kv(" pa: ", c->pa);
	put_kv(" pb: ", c->pb);
	put_kv("\n[bench] ra: ", c->ra);
	put_kv(" rb: ", c->rb);
	put_kv(" rr: ", c->rr);
	put_kv(" rra: ", c->rra);
	put_kv(" rrb: ", c->rrb);
	put_kv(" rrr: ", c->rrr);
	ft_putchar_fd('\n', 2);
}

void	print_bench(double disorder, int strategy, t_counts *c)
{
	const char	*names[5] = {"", "Simple", "Medium", "Complex", "Adaptive"};
	const char	*cx[5] = {"", "O(n^2)", "O(n*sqrt(n))", "O(n log n)",
		"O(n log n)"};

	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent(disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd((char *)names[strategy], 2);
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd((char *)cx[strategy], 2);
	put_counts(c);
}
