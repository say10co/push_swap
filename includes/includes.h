/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:36:50 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/15 02:10:44 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/libft.h"

int		px(t_list **from, t_list **to, char *s);
int	 	rrx(t_list **stack_x, char *s);
int	 	rx(t_list **stack_x, char *s);
int		sx(t_list **stack, char *s);
int		min_instack(t_list *stack);
void	add_flow(t_list *stack, int flow);
int		max_instack(t_list *stack);
int		is_sorted(t_list *lst);
int		*sort_(char **args, int	ac, int **res);
t_list *form_stack(int *array, int *sorted, int ac);

//****basic****
int		sort_basic(t_list **stack_a, t_list **stack_b, int size_a);
int		get_allto_stacka(t_list **stack_a, t_list **stack_b);
int		get_minto_top(t_list **stack_a, t_list **stack_b, int size_a);
int		three_(t_list **stack_a);
int		five(t_list **stack_a, t_list **stack_b);
#endif
