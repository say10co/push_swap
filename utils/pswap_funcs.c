/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:46:05 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/21 14:48:46 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/includes.h"

void	init_vars(t_vars *vars, int a_b)
{
	vars->flag = -42;
	vars->flag1 = 1;
	vars->c = "ra\n";
	vars->x = "pb\n";
	if (!a_b)
	{
		vars->c = "rb\n";
		vars->x = "pa\n";
	}
}

int	crap(int n, int num, int shift)
{
	if (n)
		return ((num >> shift) & 1);
	return (!((num >> shift) & 1));
}

int	radix_sort(t_list **stack_a, t_list **stack_b, int shift, int one_zero)
{
	int		nb;
	t_vars	vars;
	t_list	*curr;

	nb = 0;
	curr = *stack_a;
	init_vars(&vars, one_zero);
	while ((*stack_a) && (*(int *)(curr->content)) != vars.flag)
	{
		if (crap(one_zero, *(int *)(curr->content), shift))
		{
			if (vars.flag1 && vars.flag == -42)
			{
				vars.flag1 = 0;
				vars.flag = (*(int *)(curr->content));
			}
			nb += rx(stack_a, vars.c);
		}
		else
			nb += px(stack_a, stack_b, vars.x);
		curr = *stack_a;
	}
	return (nb);
}

int	generate_output(t_list **stack_a, t_list **stack_b, int max_l)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < max_l && !(is_sorted(*stack_a)))
	{
		nb += radix_sort(stack_a, stack_b, i, 1);
		if (i + 1 < max_l)
			nb += radix_sort(stack_b, stack_a, i + 1, 0);
		else
			nb += get_allto_stacka(stack_a, stack_b);
		i++;
	}
	return (nb);
}
