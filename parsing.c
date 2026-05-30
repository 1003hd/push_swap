/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:30:19 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 20:29:50 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_nb(char *s)
{
	long	n;
	int		i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1])
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	n = ft_atoi(s);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

static int	has_dup(char **nb_array)
{
	int	i;
	int	j;

	i = 0;
	while (nb_array[i])
	{
		j = i + 1;
		while (nb_array[j])
		{
			if (ft_atoi(nb_array[i]) == ft_atoi(nb_array[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_nb_array(char **nb_array)
{
	int	i;

	i = 0;
	if (!nb_array)
		return (0);
	while (nb_array[i])
	{
		if (!is_valid_nb(nb_array[i]))
		{
			free_nb_array(nb_array);
			return (0);
		}
		i++;
	}
	if (has_dup(nb_array))
	{
		free_nb_array(nb_array);
		return (0);
	}
	return (1);
}

int	parse(int ac, char **av, int **values)
{
	char	**nb_array;
	char	*joined;

	*values = NULL;
	if (ac < 2)
		return (0);
	joined = join_args(ac, av);
	if (!joined)
		return (0);
	nb_array = ft_split(joined, ' ');
	free(joined);
	if (!check_nb_array(nb_array))
		return (0);
	return (fill_values(nb_array, values, get_size(nb_array)));
}
