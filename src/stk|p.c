/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk|p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:45:43 by ecayir            #+#    #+#             */
/*   Updated: 2022/09/11 13:53:12 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	p_stk2(t_stk **here, t_stk **there)
{
	t_stk	*temp;

	if (*here)
	{
		temp = malloc(sizeof(t_stk));
		temp->next = NULL;
		temp->prev = NULL;
		temp->num = (*here)->num;
		add_front(there, temp);
		temp = (*here);
		(*here) = (*here)->next;
		free(temp);
	}
}

void	p_stk(t_stk **here, t_stk **there)
{
	t_stk	*temp;

	if (!(*there) && (*here))
	{
		*there = malloc(sizeof(t_stk));
		(*there)->next = NULL;
		(*there)->prev = NULL;
		(*there)->num = (*here)->num;
		temp = (*here);
		(*here) = (*here)->next;
		free(temp);
		(*here)->prev = NULL;
	}
	else
		p_stk2(here, there);
}
