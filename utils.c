/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:51:40 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 17:24:09 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(int ac, char **av)
{
	char	*result;
	char	*tmp;
	int		i;

	result = ft_strdup(av[1]);
	if (!result)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		tmp = ft_strjoin(result, " ");
		free(result);
		result = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}

static int	get_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

static int	fill_values(char **tab, int **values, int size)
{
	int	i;

	*values = malloc(size * sizeof(int));
	if (!*values)
	{
		free_tab(tab);
		return (0);
	}
	i = 0;
	while (tab[i])
	{
		(*values)[i] = (int)ft_atoi(tab[i]);
		i++;
	}
	free_tab(tab);
	return (size);
}

int	is_sorted(t_stack *stack)
{
	int	t;

	t = stack->nb;
	while (stack->next->nb != top)
	{
		if (stack ->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_decreasing(t_stack *stack)
{
	int	t;

	t = stack->nb;
	while (stack->next->nb != top)
	{
		if (stack ->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}
