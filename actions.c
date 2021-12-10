/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:28:49 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:20 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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

void	px(t_list **from, t_list **to)
{
	t_list *f_r;
	
	f_r = (*from);
	*from = (*from)->next;
	ft_lstadd_front(to, f_r);
}

void rx(t_list **stack_x)
{
	t_list *x_next;

	x_next = (*stack_x)->next;
	(*stack_x)->next = NULL;
	ft_lstadd_back(&x_next, *stack_x);
	*stack_x = x_next;
}

