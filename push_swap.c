/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:33 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 19:58:31 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free a NULL-terminated string array (ft_split output).
static void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

//split each argv on spaces, convert each token via ft_atoi, push to stack.
//ft_split drops empty tokens, so "1   4" and "1 4" parse the same.
//returns 1 ok, 0 on split alloc failure. no numeric/range/dup check yet.
int	parse_stack(t_stack *stack, int argc, char **argv)
{
	char	**tokens;
	int		i;
	int		j;

	stack->size = 0;
	stack->head = NULL;
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		j = 0;
		while (tokens[j])
		{
			ft_lstadd_back(&stack->head,
				ft_lstnew((void *)(long)ft_atoi(tokens[j])));
			stack->size++;
			j++;
		}
		free_split(tokens);
		i++;
	}
	return (1);
}

//debug print: stack size + each value top to bottom.
void	print_stack(t_stack *stack)
{
	t_list	*current;

	ft_printf("Stack (size: %d):\n", stack->size);
	current = stack->head;
	while (current)
	{
		ft_printf("  %d\n", (int)(long)current->content);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	if (argc < 2)
		return (0);
	if (!parse_stack(&stack_a, argc, argv))
		return (1);
	print_stack(&stack_a);
	return (0);
}