/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:46 by baserbet          #+#    #+#             */
/*   Updated: 2026/05/30 20:30:20 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		size;
	t_list	*head;
}	t_stack;

// Parsing
int		parse(int ac, char **av, int **values);

// Stack creation
t_stack	*create_stack(int *values, int size);
void	free_stack(t_stack *stack);

// Stack operations

// Utils
int		is_sorted(t_stack *stack);
int		is_decreasing(t_stack *stack);
int		fill_values(char **nb_array, int **values, int size);
int		get_size(char **nb_array);
char	*join_args(int ac, char **av);
void	free_nb_array(char **nb_array);

#endif
