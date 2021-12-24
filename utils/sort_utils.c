/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:30:32 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/20 21:40:07 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/includes.h"

void	swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int	*min_(int *array, int size)
{
	int	*min;
	int	i;

	min = array;
	i = 0;
	while (++i < size)
	{
		if (array[i] < *min)
			min = &array[i];
	}
	return (min);
}

int	is_sorted(t_list *lst)
{
	int	c;
	int	n;

	if (!lst || lst->next == NULL)
		return (1);
	c = *(int *)(lst->content);
	n = *(int *)(lst->next->content);
	return (c < n && is_sorted(lst->next));
}

int	get_indexof(int *array, int num)
{
	int	i;

	i = 0;
	while (array[i] != num)
		i++;
	return (i);
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
