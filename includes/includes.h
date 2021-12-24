/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:36:50 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/22 00:50:29 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_vars
{
	int		flag;
	int		flag1;
	char	*c;
	char	*x;
}t_vars;

//***********actions**************

int		px(t_list **from, t_list **to, char *s);
int		rx(t_list **stack_x, char *s);
int		rrx(t_list **stack_x, char *s);
int		sx(t_list **stack, char *s);

//************basic***************
int		three_(t_list **stack_a);
int		get_minto_top(t_list **stack_a, t_list **stack_b, int size_a);
int		get_allto_stacka(t_list **stack_a, t_list **stack_b);
int		five(t_list **stack_a, t_list **stack_b);

//************errors***************
int		ft_strcmp(char *s1, char *s2);
int		check_args(char ***args, int *ac);

//************pushswapfunc*********
void	init_vars(t_vars *vars, int a_b);
int		crap(int n, int num, int shift);
int		radix_sort(t_list **stack_a, t_list **stack_b, int shift, int one_zero);
int		generate_output(t_list **stack_a, t_list **stack_b, int max_l);

//************pushswaputils********
t_list	*form_stack(int *array, int *sorted, int ac);
int		*sort_(char **args, int ac, int **res);
int		small_stack(t_list **stack_a, t_list **stack_b, int count);
int		check_double_count(char **av, int c);

//***********sort_utils************
void	swap(int *i, int *j);
int		*min_(int *array, int size);
int		is_sorted(t_list *lst);
int		get_indexof(int *array, int num);
int		sort_basic(t_list **stack_a, t_list **stack_b, int size_a);
int		max_instack(t_list *stack);

#endif
