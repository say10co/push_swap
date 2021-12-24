/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:16:46 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/24 16:43:15 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/includes.h"
#include "./includes/get_next_line.h"
#define BUFFER_SIZE 3

int	continue_(t_list **stack_a, t_list **stack_b, char *dm)
{	
	if (!ft_strcmp(dm, "rb\n"))
		rx(stack_b, "");
	else if (!ft_strcmp(dm, "rra\n"))
		rrx(stack_a, "");
	else if (!ft_strcmp(dm, "rrb\n"))
		rrx(stack_b, "");
	else if (!ft_strcmp(dm, "rrr\n"))
	{
		rrx(stack_b, "");
		rrx(stack_a, "");
	}
	else if (!ft_strcmp(dm, "ss\n"))
	{
		sx(stack_a, "");
		sx(stack_b, "");
	}
	else if (!ft_strcmp(dm, "rr\n"))
	{
		rx(stack_b, "");
		rx(stack_a, "");
	}
	else
		return (1);
	return (0);
}

int	throw_error(void)
{			
	write (1, "Error\n", 6);
	return (0);
}

int	get_actions(t_list **stack_a, t_list **stack_b)
{
	char	*dm;
	int		error;

	error = 0;
	dm = get_next_line(0);
	while (dm)
	{
		if (!ft_strcmp(dm, "sa\n"))
			sx(stack_a, "");
		else if (!ft_strcmp(dm, "sb\n"))
			sx(stack_b, "");
		else if (!ft_strcmp(dm, "pa\n"))
			px(stack_b, stack_a, "");
		else if (!ft_strcmp(dm, "pb\n"))
			px(stack_a, stack_b, "");
		else if (!ft_strcmp(dm, "ra\n"))
			rx(stack_a, "");
		else
			error = continue_(stack_a, stack_b, dm);
		free(dm);
		if (error)
			return (throw_error());
		dm = get_next_line(0);
	}
	return (1);
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
	stack_a = form_stack(array, sorted, ac);
	if (get_actions(&stack_a, &stack_b))
	{
		if (is_sorted(stack_a) && !stack_b)
			write(1, "OK", 2);
		else
			write(1, "KO", 2);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	free(sorted);
	free(array);
	return (0);
}
