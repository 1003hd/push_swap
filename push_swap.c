/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:33 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/06 16:16:52 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*values;
	int			size;
	int			strategy;
	int			bench;
	t_counts	c;
	t_run		r;

	if (ac < 2)
		return (0);
	strategy = parse_flags(&ac, &av, &bench);
	if (strategy < 0)
		return (1);
	if (ac < 2)
		return (0);
	values = NULL;
	size = parse(ac, av, &values);
	if (size < 0)
	{
		error_exit();
		return (1);
	}
	stack_a = create_stack(values, size);
	stack_b = create_empty_stack();
	free(values);
	if (!stack_a || !stack_b)
	{
		error_exit();
		return (1);
	}
	ft_memset(&c, 0, sizeof(t_counts));
	r.disorder = compute_disorder(stack_a);
	r.c = &c;
	strategy = run_strategy(&stack_a, &stack_b, strategy, &r);
	if (bench)
		print_bench(r.disorder, strategy, &c);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
