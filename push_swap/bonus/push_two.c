/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:24:03 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:24:06 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	conversione(char **str)
{
	long	negativo;
	long	intero;

	intero = 0;
	negativo = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			negativo = -1;
		(*str)++;
		if (ft_strcomp(**str, "0123456789") == 0)
			return (2147483648);
	}
	while ('0' <= **str && **str <= '9')
	{
		intero = (intero * 10) + **str - 48;
		(*str)++;
	}
	intero *= negativo;
	return (intero);
}

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

int	push(t_list **lst, char **str)
{
	t_punt	punt;
	long	intero;

	while (**str != 0)
	{
		punt.head = *lst;
		intero = 0;
		while (**str == ' ' && **str != 0)
			(*str)++;
		if (**str == 0)
			break ;
		intero = conversione(str);
		if (intero > MAX || intero < MIN)
			uscita(&punt);
		fill_lista(lst, intero);
		if (**str != 32 && **str != 0)
			return (-1);
	}
	return (1);
}
