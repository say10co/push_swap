/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:28:49 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/15 02:15:25 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void	set_last_null(t_list **root)
{
	t_list *curr;

	curr = *root;
	if (!(*root))
		return ;
	if (!((*root)->next))
		*root = NULL;
	while (curr->next && curr->next->next)
		curr = curr->next;
	curr->next = NULL;
		
}

int	px(t_list **from, t_list **to, char *s)
{
	t_list *f_r;
	
	write(1, s, 3);
	f_r = (*from);
	*from = (*from)->next;
	ft_lstadd_front(to, f_r);
	return (1);
}

int rx(t_list **stack_x, char *s)
{
	t_list *x_next;

	write(1, s, 3);
	x_next = (*stack_x)->next;
	(*stack_x)->next = NULL;
	ft_lstadd_back(&x_next, *stack_x);
	*stack_x = x_next;
	return (1);
}

int rr(t_list **stack_a, t_list **stack_b, char *s)
{
	write(1, s, 3);
	rx(stack_a, s);
	rx(stack_b, s);
	return (1);
}

int rrx(t_list **stack_x, char *s)
{
	t_list *last;

	write(1, s, 4);
	last = ft_lstlast(*stack_x);
	set_last_null(stack_x);
	last->next = *stack_x;
	*stack_x = last;
	return (1);
}

int	sx(t_list **stack, char *s)
{
	t_list *tmp;
	
	write(1, s, 3);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next =  *stack;
	*stack = tmp;
	return (1);
}
