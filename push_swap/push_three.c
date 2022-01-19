/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:28:42 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:28:44 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_max_three(t_list *lst)
{
	int	i;
	int	k;
	int	checker;

	checker = lst->numero;
	i = 1;
	k = 1;
	while (lst->next)
	{
		if (lst->next->numero > checker)
		{	
			checker = lst->next->numero;
			k = i + 1;
		}
		i++;
		lst = lst->next;
	}
	return (k);
}

int	pos_min_three(t_list *lst)
{
	int	i;
	int	k;
	int	checker;

	checker = lst->numero;
	i = 1;
	k = 1;
	while (lst->next)
	{
		if (lst->next->numero < checker)
		{
			checker = lst->next->numero;
			k = i + 1;
		}
		i++;
		lst = lst->next;
	}
	return (k);
}

void	mossa_tre(t_punt *list)
{
	if (pos_max_three(list->head) == 1)
	{
		if (pos_min_three(list->head) == 3)
		{
			sa(list);
			rra(list);
		}
		else
			ra(list);
	}
	else if (pos_max_three(list->head) == 3)
		sa(list);
	else if (pos_max_three(list->head) == 2)
	{
		if (pos_min_three(list->head) == 1)
		{
			sa(list);
			ra(list);
		}
		else
			rra(list);
	}
}

void	mosse_tre(t_list *list)
{
	if (pos_max_three(list) == 1)
	{
		if (pos_min_three(list) == 3)
			printf("sa\nrra\n");
		else
			printf("ra\n");
	}
	else if (pos_max_three(list) == 3)
		printf("sa\n");
	else if (pos_max_three(list) == 2)
	{
		if (pos_min_three(list) == 1)
			printf("sa\nra\n");
		else
			printf("rra\n");
	}
}

int	pushtree(t_punt *puntatore)
{
	t_list	*list;

	list = puntatore->head;
	if (check_ordine(puntatore) == 0)
		mossa_tre(puntatore);
	return (0);
}
