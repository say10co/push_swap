/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:23:20 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/22 00:47:29 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"
#include <stdio.h>

t_list	*form_stack(int *array, int *sorted, int ac)
{
	int		i;
	int		*t;
	t_list	*root;

	root = NULL;
	i = 0;
	while (i < ac)
	{
		t = (int *) malloc(sizeof(int));
		if (!t)
		{
			ft_lstclear(&root, free);
			return (NULL);
		}
		*t = get_indexof(sorted, array[i]);
		ft_lstadd_back(&root, ft_lstnew((void *)t));
		i++;
	}
	return (root);
}

int	*sort_(char **args, int ac, int **res)
{
	int	i;
	int	*array;
	int	*sorted;

	i = 0;
	array = (int *)(malloc(sizeof(int) * ac));
	sorted = (int *)(malloc(sizeof(int) * ac));
	if (!sorted || !array)
	{
		free(array);
		free(sorted);
		return (NULL);
	}
	while (args[i])
	{
		array[i] = ft_atoi(args[i]);
		sorted[i] = array[i];
		i++;
	}
	i = -1;
	*res = array;
	while (++i < ac)
		swap(&sorted[i], min_(&sorted[i], ac - i));
	return (sorted);
}

int	sort_basic(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (i++ < size_a)
	{
		nb += get_minto_top(stack_a, stack_b, ft_lstsize(*stack_a));
	}
	nb += get_allto_stacka(stack_a, stack_b);
	return (nb);
}

int	small_stack(t_list **stack_a, t_list **stack_b, int count)
{
	if (is_sorted(*stack_a))
		return (0);
	if (count == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			return (sx(stack_a, "sa\n"));
	}
	if (count == 3)
		return (three_(stack_a));
	else
		return (five(stack_a, stack_b));
}

int	check_double_count(char **av, int c)
{
	int	i;
	int	j;

	i = 0;
	while (av[i] && c)
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
				return (0);
			if (!ft_strcmp("-0", av[i]) && !ft_strcmp("0", av[j]))
				return (0);
			if (!ft_strcmp("0", av[i]) && !ft_strcmp("-0", av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}
