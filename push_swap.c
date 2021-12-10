/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:39:04 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/10 11:10:06 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "includes.h"

/*----One Liners----*/
void print_stack(int *stack,int len){int i= 0;while(i < len){printf("%d\n", stack[i]);i++;}}
void print_stack_l(t_list *stack){t_list *curr = stack;while(curr){printf("%d\n", *(int *)curr->content); curr = curr->next;}}

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


void	generate_output(t_list **stack_a, t_list **stack_b, int max_l)
{
	int 	i;
	int		flag1;
	int		flag2;
	int		flag3;
	int		count;
	t_list *curr;
	

	
	i = 0;
	while (i < max_l)
	{
		flag1 = 1;
		flag2 = -1;
		flag3 = 1;
		curr = *stack_a;
		count = 0;
		while (curr && (flag1 != flag2))
		{
			if ((*(int *) (curr->content) >> i)&1)
			{
				if (flag3){flag3= 0; flag1 = *(int *) (curr->content);}else {flag2 = *(int *) (curr->content);}
				if (flag1 != flag2){rx(stack_a); printf("ra ");}
			}
			else
			{
				count++;
				printf("pb ");
				px(stack_a, stack_b);
			}	
			//print_stack_l(*stack_a);
			curr = *stack_a;
		}	
		i++;
		while (count--)
		{
			printf("pa ");
			px(stack_b, stack_a);
		}
	}
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

int	main(int ac, char **args)
{
	t_list *stack_a;
	t_list *stack_b;
	int		flow;
	int		max_l;
	int		max_bits = 0;

	stack_b = NULL;
	ac--;
	stack_a = form_stack(++args);
	max_l = max_instack(stack_a);
	while ((max_l >> max_bits) != 0) ++max_bits;
	flow = min_instack(stack_a);
	add_flow(stack_a, flow);
	generate_output(&stack_a, &stack_b, max_bits);
	print_stack_l(stack_a);
	return (0);
}