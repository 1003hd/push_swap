/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:33 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/01 17:30:00 by baserbet         ###   ########.fr       */
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
	t_stack	*stack;
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
	stack = create_stack(values, size);
	free(values);
	if (!stack)
	{
		error_exit();
		return (1);
	}
	printf("Before \n");
	print_stack(stack);
	sa((&stack));
	printf("after: \n");
	print_stack(stack);
	free_stack(stack);
	return (0);
}
