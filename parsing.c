/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:30:19 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 17:00:11 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

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

static int	has_dup(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (!is_valid_nb(tab[i]))
		{
			free_tab(tab);
			return (0);
		}
		i++;
	}
	if (has_dup(tab))
	{
		free_tab(tab);
		return (0);
	}
	return (1);
}

int	parse(int ac, char **av, int **values)
{
	char	**tab;
	char	*joined;

	*values = NULL;
	if (ac < 2)
		return (0);
	joined = join_args(ac, av);
	if (!joined)
		return (0);
	tab = ft_split(joined, ' ');
	free(joined);
	if (!check_tab(tab))
		return (0);
	return (fill_values(tab, values, get_size(tab)));
}