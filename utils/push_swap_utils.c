/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:23:20 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/11 11:46:36 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	min_instack(t_list *stack)
{
	t_list	*curr;
	int		min;

	min = *(int *)(stack->content);
	curr = stack;
	while (curr)
	{
		if (*(int *)(curr->content) < min)
			min = *(int *)(curr->content);
		curr = curr->next;
	}
	if (min < 0)
		return (-min);
	return (0);
}

void	add_flow(t_list *stack, int flow)
{
	t_list	*curr;

	curr = stack;
	while (curr)
	{
		*(int *)(curr->content) += flow;
		curr = curr->next;
	}
}

int	max_instack(t_list *stack)
{
	t_list	*curr;
	int		max;

	max = *(int *)(stack->content);
	curr = stack;
	while (curr)
	{
		if (*(int *)(curr->content) > max)
			max = *(int *)(curr->content);
		curr = curr->next;
	}
	return (max);
}

int	is_sorted(t_list *lst)
{
	int c;
	int	n;

	if (!lst || lst->next == NULL)
		return (1);
	c = *(int *)(lst->content);
   	n = *(int *)(lst->next->content); 	
	return ( c < n  && is_sorted(lst->next));
}

t_list *form_stack(char **args)
{
	int		i;
	int		*t;
	t_list	**root;

	root = (t_list **)(malloc(sizeof(t_list *)));
	*root = NULL;
	i = 0;
	while (args[i])
	{
		t = (int *) malloc(sizeof(int));
		*t = ft_atoi(args[i]);
		ft_lstadd_back(root, ft_lstnew((void *)t));
		i++;
	}
	return (*root);
}
