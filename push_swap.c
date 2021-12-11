/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:39:04 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/11 11:43:30 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./includes/includes.h"

/*----One Liners----*/
void print_stack(int *stack,int len){int i= 0;while(i < len){printf("%d\n", stack[i]);i++;}}
void print_stack_l(t_list *stack){t_list *curr = stack;while(curr){printf("%d\n", *(int *)curr->content); curr = curr->next;}}

int radix_sort(t_list **stack_a, t_list **stack_b, int shift, int one_zero)
{
	int		nb;
	int		flag;
	int		flag1;
	t_list *curr;	

	flag = -42;
	flag1 = 1;
	nb = 0;
	curr = *stack_a;
	while ((*stack_a) && (*(int *)(curr->content)) != flag)
	{
		if ((*(int *) (curr->content) >>shift)&one_zero)
		{
			if (flag1 && flag == -42)
			{
				flag1 = 0;
				flag = (*(int *) (curr->content));
			}
			rx(stack_a);
			nb++;
		}
		else
		{
			nb++;
			px(stack_a, stack_b);
		}
		curr = *stack_a;
	}
	return (nb);
}


int	generate_output(t_list **stack_a, t_list **stack_b, int max_l)
{
	int 	i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < max_l && !(is_sorted(*stack_a)))
	{	
		nb += radix_sort(stack_a, stack_b, i, 1);	
		if (i + 1 < max_l)
			nb += radix_sort(stack_b, stack_a, i+1, 0);
		else
		{
			while(*stack_b)
			{
				nb++;
				px(stack_b, stack_a);
			}
		}
		i++;
	}
	return(nb);
}

int	main(int ac, char **args)
{
	t_list *stack_a;
	t_list *stack_b;
	int		flow;
	int		max_l;
	int		max_bits = 0;

	if (ac > 2)
	{
		stack_b = NULL;
		ac--;
		stack_a = form_stack(++args);
		flow = min_instack(stack_a);
		add_flow(stack_a, flow);
		max_l = max_instack(stack_a);

		while ((max_l >> max_bits) != 0) ++max_bits;
		int	o = generate_output(&stack_a, &stack_b, max_bits);
		add_flow(stack_a, -flow);

		print_stack_l(stack_a);
		printf("NB_actions = %d\n", o);
	}
	return (0);
}
