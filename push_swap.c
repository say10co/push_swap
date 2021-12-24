/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:39:04 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/22 01:08:52 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./includes/includes.h"

int	count_bits(int max_l)
{
	int	l;

	l = 0;
	while ((max_l >> l) != 0)
		l++;
	return (l);
}

int	main(int ac, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*array;
	int		*sorted;

	if (!check_args(&args, &ac))
		return (0);
	stack_b = NULL;
	sorted = sort_(args, --ac, &array);
	if (!sorted)
		return (0);
	stack_a = form_stack(array, sorted, ac);
	if (!stack_a)
		return (0);
	if (ac <= 5)
		small_stack(&stack_a, &stack_b, ac);
	else
		generate_output(&stack_a, &stack_b, count_bits(max_instack(stack_a)));
	free(sorted);
	free(array);
	ft_lstclear(&stack_a, free);
	return (0);
}
