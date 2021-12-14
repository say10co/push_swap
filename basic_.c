/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:53:42 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/14 11:44:11 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/includes.h"
#include <stdio.h>
int	find_indexof_min(t_list *stack)
{
	int		index_min;
	int		min;
	int		i;
	t_list *curr;

	index_min = 0;
	i = 0;
	min =  *(int *)(stack->content);
	curr = stack;
	while (curr)
	{
		if (*(int *)(curr->content) < min)
		{
			min = *(int *)(curr->content);
			index_min = i;
		}
		curr = curr->next;
		i++;
	}
	return (index_min);
}

int	get_minto_top(t_list **stack_a, t_list **stack_b,int size_a)
{
	int	index_min;
	int	tmp;
	int	i;

	i = 0;
	index_min = find_indexof_min(*stack_a);
	tmp = index_min;
	printf("(%d)\n", tmp);
	if (tmp < size_a / 2)
	{
		while (tmp > 0)
		{ 
			i++;
			printf("ra\n");
			rx(stack_a);
			tmp--;
		}
		px(stack_a, stack_b);
		i++;
		printf("pb\n");
		return (i);
	}
	while (tmp < size_a)
	{
		i++;
		rrx(stack_a);
		printf("rra\n");
		tmp++;
	}	
	px(stack_a, stack_b);
	i++;
	printf("pb\n");
	return (i);
}

int get_allto_stacka(t_list **stack_a, t_list **stack_b)
{
	int i;

	i = 0;
	while (*stack_b)
	{
		i++;
		px(stack_b, stack_a);
		printf("pa\n");
	}
	return (i);
}

int sort_basic(t_list **stack_a, t_list **stack_b, int size_a)
{
	int nb;
	int	i;

	nb = 0;
	i = 0;
	while (i < size_a)
	{
		nb += get_minto_top(stack_a, stack_b, ft_lstsize(*stack_a));
		i++;
	}
	nb += get_allto_stacka(stack_a, stack_b);
	return (nb);
}
