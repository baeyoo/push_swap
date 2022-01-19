/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:27:57 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:27:59 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_lista(t_list **lst, int valore)
{
	t_list	*_new;
	t_list	*appoggio;

	_new = (t_list *)malloc(sizeof(t_list));
	_new->next = NULL;
	_new->numero = valore;
	if (*lst == NULL)
	{
		*lst = _new;
		return ;
	}
	appoggio = *lst;
	while (appoggio->next != NULL)
		appoggio = appoggio->next;
	appoggio->next = _new;
}

void	fill_list(t_list **lst, int valore)
{
	t_list	*_new;

	_new = (t_list *)malloc(sizeof(t_list));
	_new->next = *lst;
	_new->numero = valore;
	*lst = _new;
}
