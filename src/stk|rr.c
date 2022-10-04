/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk|rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdemirci <kamil@kakbir.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:50:35 by ecayir            #+#    #+#             */
/*   Updated: 2022/09/05 17:27:14 by kdemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*end_of_stk(t_stk *stk)
{
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	while (stk->next)
		stk = stk->next;
	new->num = stk->num;
	new->next = NULL;
	return (new);
}

void	last_del(t_stk **stk)
{
	t_stk	*temp;

	temp = *stk;
	while (temp)
	{
		if (temp->next->next == NULL)
			break ;
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void	rr_stk(t_stk **stk)
{
	t_stk	*temp;

	temp = end_of_stk(*stk);
	last_del(stk);
	add_front(stk, temp);
}
