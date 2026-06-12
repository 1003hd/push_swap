/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:33 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/12 19:41:25 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// Frees both stacks (NULL-safe) before erroring out, so a malloc
// failure mid-run does not leak already-built stacks.
void	free_and_exit(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(*a);
	if (b)
		free_stack(*b);
	error_exit();
}

// New helpers to keep main under 5 vars
static int	init_stacks(int ac, char **av, t_stack **a, t_stack **b)
{
	int		*values;
	int		size;

	values = NULL;
	size = parse(ac, av, &values);
	if (size < 0)
		return (error_exit(), -1);
	*a = create_stack(values, size);
	*b = create_empty_stack();
	free(values);
	if (!*a || !*b)
		return (free_and_exit(a, b), -1);
	return (size);
}

// Runs strategy and prints bench
// Updated: no longer passes strategy as separate arg
static void	run_and_bench(t_stack **a, t_stack **b, t_run *r)
{
	r->strategy = run_strategy(a, b, r);
	if (r->count_only)
		return (ft_putnbr_fd(total_ops(r->c), 1), (void)write(1, "\n", 1));
	if (r->bench)
		print_bench(r->disorder, r->strategy, r->c);
}

// r now holds bench and strategy (was separate int vars)
int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_counts	c;
	t_run		r;

	if (ac < 2)
		return (0);
	r.strategy = parse_flags(&ac, &av, &r);
	if (r.strategy < 0 || ac < 2)
		return (r.strategy < 0);
	if (init_stacks(ac, av, &stack_a, &stack_b) < 0)
		return (1);
	ft_memset(&c, 0, sizeof(t_counts));
	c.silent = r.count_only;
	r.disorder = compute_disorder(stack_a);
	r.c = &c;
	run_and_bench(&stack_a, &stack_b, &r);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
