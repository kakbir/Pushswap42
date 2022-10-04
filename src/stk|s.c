/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk|s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:51:30 by ecayir            #+#    #+#             */
/*   Updated: 2022/09/03 11:11:47 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_stk(t_stk **stk)
{
	int	temp;

	if ((*stk) && (*stk)->next)
	{
		temp = (*stk)->num;
		(*stk)->num = (*stk)->next->num;
		(*stk)->next->num = temp;
	}
}
