/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:53:42 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/21 11:58:48 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/includes.h"

int	three_(t_list **stack_a)
{
	int	one;
	int	two;
	int	three;

	one = *(int *)(*stack_a)->content;
	two = *(int *)(*stack_a)->next->content;
	three = *(int *)(*stack_a)->next->next->content;
	if (one < two && two < three)
		return (0);
	else if (three < one && one < two)
		return (rrx(stack_a, "rra\n"));
	else if (two < three && three < one)
		return (rx(stack_a, "ra\n"));
	else if (one < three && three < two)
		return (rrx(stack_a, "rra\n") + sx(stack_a, "sa\n"));
	else if (three < two && two < one)
		return (sx(stack_a, "sa\n") + rrx(stack_a, "rra\n"));
	else
		return (sx(stack_a, "sa\n"));
}

int	find_indexof_min(t_list *stack)
{
	int		index_min;
	int		min;
	int		i;
	t_list	*curr;

	index_min = 0;
	i = 0;
	min = *(int *)(stack->content);
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

int	get_minto_top(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	index_min;
	int	tmp;
	int	i;

	i = 0;
	index_min = find_indexof_min(*stack_a);
	tmp = index_min;
	if (tmp < size_a / 2)
	{
		while (tmp > 0)
		{
			i += rx(stack_a, "ra\n");
			tmp--;
		}
		return (i + px(stack_a, stack_b, "pb\n"));
	}
	while (tmp < size_a)
	{
		i += rrx(stack_a, "rra\n");
		tmp++;
	}	
	return (i + px(stack_a, stack_b, "pb\n"));
}

int	get_allto_stacka(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (*stack_b)
		i += px(stack_b, stack_a, "pa\n");
	return (i);
}

int	five(t_list **stack_a, t_list **stack_b)
{
	int	nb;

	nb = 0;
	nb += get_minto_top(stack_a, stack_b, ft_lstsize(*stack_a));
	if (ft_lstsize(*stack_a) == 4)
		nb += get_minto_top(stack_a, stack_b, ft_lstsize(*stack_a));
	nb += three_(stack_a);
	nb += get_allto_stacka(stack_a, stack_b);
	return (nb);
}	
