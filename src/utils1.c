/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:53:24 by ecayir            #+#    #+#             */
/*   Updated: 2022/09/05 17:24:01 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_list	*ft_init(t_list *fb)
{
	fb = malloc(sizeof(t_list));
	if (!fb)
		return (0);
	fb->len = 0;
	fb->stk_a = NULL;
	fb->stk_b = NULL;
	return (fb);
}

char	**fill_args(t_list *fb, int ac, char **av)
{
	if (ac == 2)
		fb->split = ft_split(av[1], ' ');
	else
		fb->split = &av[1];
	return (fb->split);
}

void	check_dup(char **s, int i, int j)
{
	int	dup;

	while (s[++i])
	{
		dup = ps_atoll(s[i]);
		j = i;
		while (s[++j])
			if (dup == ps_atoll(s[j]))
				ft_exit("Error\n");
	}
}

bool	check_overflow(char *s)
{
	long long	n;

	n = ps_atoll(s);
	if (n <= INT_MAX && n >= INT_MIN)
		return (true);
	return (false);
}

void	check_number(char **s, int i, int j)
{
	while (s[++i])
	{
		j = -1;
		if (!check_overflow(s[i]))
			ft_exit("Error\n");
		while (s[i][++j])
		{
			if (ft_isalpha(s[i][j]) || s[i][j] == '.' ||
				(s[i][j] == '-' && s[i][j + 1] == '\0') ||
				(s[i][j] == '+' && s[i][j + 1] == '\0'))
				ft_exit("Error\n");
		}
	}
}
