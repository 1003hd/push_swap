/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:30:19 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/09 18:09:33 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_nb(char *s)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	n = 0;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		n = n * 10 + (s[i] - '0');
		if (sign * n > INT_MAX || sign * n < INT_MIN)
			return (0);
		i++;
	}
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

//returns number of values on success, -1 on any error.
int	parse(int ac, char **av, int **values)
{
	char	**nb_array;
	char	*joined;
	int		size;

	*values = NULL;
	if (ac < 2)
		return (-1);
	joined = join_args(ac, av);
	if (!joined)
		return (-1);
	nb_array = ft_split(joined, ' ');
	free(joined);
	if (!nb_array)
		return (-1);
	if (!nb_array[0])
		return (free_nb_array(nb_array), -1);
	if (!check_nb_array(nb_array))
		return (-1);
	size = get_size(nb_array);
	if (fill_values(nb_array, values, size) == 0)
		return (-1);
	return (size);
}
