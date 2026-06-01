/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:46 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/01 13:00:10 by aselezen         ###   ########.fr       */
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

// Parsing — returns size on success, -1 on error
int		parse(int ac, char **av, int **values);

// Stack creation
t_stack	*create_stack(int *values, int size);
void	free_stack(t_stack *stack);

// Error
void	error_exit(void);

// Error
void	error_exit(void);

// Stack operations

void sa(t_stack **stack_a);

// Utils
int		is_sorted(t_stack *stack);
int		is_decreasing(t_stack *stack);
int		fill_values(char **nb_array, int **values, int size);
int		get_size(char **nb_array);
char	*join_args(int ac, char **av);
void	free_nb_array(char **nb_array);

#endif
