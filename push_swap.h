/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:49:46 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/09 16:00:04 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

// Singly-linked stack node. Mirrors t_list but stores the int inline,
// so no void * content / cast is needed.
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}	t_stack;

// Op counters for --bench mode
typedef struct s_counts
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_counts;

// 
typedef struct s_run
{
	double		disorder;
	t_counts	*c;
	int			bench;
	int			strategy;
}	t_run;

// Parsing — returns size on success, -1 on error
int		parse(int ac, char **av, int **values);

// Stack creation
t_stack	*create_stack(int *values, int size);
t_stack	*create_empty_stack(void);
void	free_stack(t_stack *stack);

// Error
void	error_exit(void);

// Low-level move primitives (silent; shared with the checker)
void	swap(t_stack **s);
void	push(t_stack **dst, t_stack **src);
void	rotate(t_stack **s);
void	reverse_rotate(t_stack **s);

// Stack operations (all accept an optional t_counts * — pass NULL to skip)
void	sa(t_stack **a, t_counts *c);
void	sb(t_stack **b, t_counts *c);
void	ss(t_stack **a, t_stack **b, t_counts *c);
void	ra(t_stack **a, t_counts *c);
void	rb(t_stack **b, t_counts *c);
void	rr(t_stack **a, t_stack **b, t_counts *c);
void	pa(t_stack **a, t_stack **b, t_counts *c);
void	pb(t_stack **a, t_stack **b, t_counts *c);
void	rra(t_stack **a, t_counts *c);
void	rrb(t_stack **b, t_counts *c);
void	rrr(t_stack **a, t_stack **b, t_counts *c);

// Utils
int		is_sorted(t_stack *stack);
int		is_decreasing(t_stack *stack);
int		fill_values(char **nb_array, int **values, int size);
int		get_size(char **nb_array);
char	*join_args(int ac, char **av);
void	free_nb_array(char **nb_array);
double	compute_disorder(t_stack *stack);
int		parse_flags(int *ac, char ***av, int *bench);
int		run_strategy(t_stack **a, t_stack **b, t_run *r);
void	print_bench(double disorder, int strategy, t_counts *c);
int		total_ops(t_counts *c);

//Sorting

void	selection_sort_stacks(t_stack **a, t_stack **b, t_counts *c);
void	medium_sort_stacks(t_stack **a, t_stack **b, t_counts *c);
void	sort_three(t_stack **a, t_counts *c);
void	radix_sort_stacks(t_stack **a, t_stack **b, t_counts *c);

#endif