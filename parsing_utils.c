/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:25:40 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 20:29:28 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(int ac, char **av)
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

int	get_size(char **nb_array)
{
	int	size;

	size = 0;
	while (nb_array[size])
		size++;
	return (size);
}

int	fill_values(char **nb_array, int **values, int size)
{
	int	i;

	*values = malloc(size * sizeof(int));
	if (!*values)
	{
		free_nb_array(nb_array);
		return (0);
	}
	i = 0;
	while (nb_array[i])
	{
		(*values)[i] = (int)ft_atoi(nb_array[i]);
		i++;
	}
	free_nb_array(nb_array);
	return (size);
}

void	free_nb_array(char **nb_array)
{
	int	i;

	i = 0;
	while (nb_array[i])
		free(nb_array[i++]);
	free(nb_array);
}
