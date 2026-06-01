/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aselezen <aselezen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:18:07 by baserbet          #+#    #+#             */
/*   Updated: 2026/06/01 13:43:42 by aselezen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **stack_a){
    t_list *first;
    t_list *second;
    
    first = (*stack_a)->head;
    second = first->next;
    first->next = second->next;
    second->next = first;
    (*stack_a)->head = second;
    
}

// void sb(){}
// void ss(){}
// void pa(){}
// void pb(){}
// void ra(){}
// void rb(){}
// void rr(){}
// void rra(){}
// void rrb(){}
// void rr(){}