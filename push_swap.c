/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:33 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/03 18:35:35 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//print "Error\n" to stderr (fd 2), as the subject mandates.
void	error_exit(void)
{
	write(2, "Error\n", 6);
}

//Printing stack, purely for debugging 
void	print_stack(t_stack *stack)
{
	t_list	*current;

	ft_printf("Stack (size: %d):\n", stack->size);
	current = stack->head;
	while (current)
	{
		ft_printf("  %d\n", *(int *)current->content);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*values;
	int		size;

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
	printf("Before \n");
	print_stack(stack_a);
	radix_sort_stacks(&stack_a, &stack_b);
	printf("after: \n"); //ranks will be printed out, not values
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
