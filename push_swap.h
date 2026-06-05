/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:46 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/05 17:53:50 by aselezen         ###   ########.fr       */
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
t_stack *create_empty_stack(void);
void	free_stack(t_stack *stack);

// Error
void	error_exit(void);

// Stack operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Utils
int		is_sorted(t_stack *stack);
int		is_decreasing(t_stack *stack);
int		fill_values(char **nb_array, int **values, int size);
int		get_size(char **nb_array);
char	*join_args(int ac, char **av);
void	free_nb_array(char **nb_array);

//Sorting

void	selection_sort_stacks(t_stack **a, t_stack **b);
void	medium_sort_stacks(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	radix_sort_stacks(t_stack **a, t_stack **b);

#endif
