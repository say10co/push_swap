/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:39:04 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/15 02:21:07 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./includes/includes.h"

/*----One Liners----*/
void print_stack(int *stack,int len){int i= 0;while(i < len){printf("%d\n", stack[i]);i++;}}
void print_stack_l(t_list *stack){t_list *curr = stack;while(curr){printf("%d\n", *(int *)curr->content); curr = curr->next;}}
void print_stack_l_(t_list *stack, int *ar){t_list *curr = stack;while(curr){printf("%d\n", ar[*(int *)curr->content]); curr = curr->next;}}


int	crap(int n, int num, int shift)
{
	if (n)
		return ((num >> shift)&1);
	return (!((num >> shift)&1));
}

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

	char *c = "ra ";
	char *x = "pb ";
	if (one_zero != 1)
	{
		c = "rb ";
		x = "pa ";
	}

	while ((*stack_a) && (*(int *)(curr->content)) != flag)
	{
		if (crap(one_zero, *(int *) (curr->content), shift))
		{
			if (flag1 && flag == -42)
			{
				flag1 = 0;
				flag = (*(int *)(curr->content));
			}
			rx(stack_a, c);
			nb++;
		}
		else
		{
			nb++;
			px(stack_a, stack_b, x);
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
		if (i + 1< max_l)
			nb += radix_sort(stack_b, stack_a, i+1, 0);
		else 
		{
			while(*stack_b)
			{
				nb++;
				px(stack_b, stack_a, "pa ");
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
	int		max_l;
	int		*array;
	int		*sorted;
	int		o;

	if (ac > 2)
	{
		o = 0;
		sorted = sort_(++args, --ac, &array);
		stack_a = form_stack(array, sorted, ac);	
		max_l = max_instack(stack_a);
		while ((max_l >> o) != 0)
			o++;
		if (ac == 3)
			o = three_(&stack_a);
		else if (ac == 5)
			o = five(&stack_a, &stack_b);
		else if (ac > 2 && ac <= 5 )
			o = sort_basic(&stack_a, &stack_b, ac);
		else
			o = generate_output(&stack_a, &stack_b, o);	
		//print_stack_l(stack_a);
		printf("\n");
		printf("NB_actions = %d\n", o);
		if (is_sorted(stack_a))
			printf("sorted!");
		else
			printf("NOT!!!!");
	}
	return (0);
}
