/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:51:51 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/21 21:33:46 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)(str);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return (&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		total_len;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	index = 0;
	new_str = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new_str)
		return (0);
	while (total_len--)
	{
		if (*s1 != '\0')
			new_str[index] = *s1;
		else
		{
			s1 = s2;
			new_str[index] = *s1;
		}
		s1++;
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	index;
	unsigned int	s_len;

	if (!s)
		return (0);
	index = 0;
	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (index < len && start < s_len && s[index])
	{
		substr[index] = s[start];
		start++;
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s1)
{
	int		s1len;
	int		index;
	char	*cpy;

	index = 0;
	s1len = ft_strlen(s1);
	cpy = (char *)malloc(s1len * sizeof(char) + 1);
	if (!cpy)
		return (0);
	while (s1[index])
	{
		cpy[index] = s1[index];
		index++;
	}
	cpy[index] = '\0';
	return (cpy);
}
