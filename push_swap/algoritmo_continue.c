/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo_continue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:25:08 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:25:10 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algoritmo_1(t_punt *punt_a, int *support, int inti)
{
	int	sezione;

	sezione = inti / 5;
	if ((ft_nodi(punt_a->head, support[sezione * 4], support[sezione * 4]))
		> (ft_lstsize(punt_a->head) / 2))
	{
		while (check_ordine(punt_a) != 1)
			rra(punt_a);
	}
	else
	{
		while (check_ordine(punt_a) != 1)
			ra(punt_a);
	}
}

void	algoritmo_2(t_punt *punt_a, int *support, int inti)
{
	int	sezione;

	sezione = inti / 5;
	if ((ft_nodi(punt_a->head, support[sezione * 3], support[sezione * 3]))
		< (ft_lstsize(punt_a->head) / 2))
	{
		while (check_ordine(punt_a) != 1)
			ra(punt_a);
	}
	else
	{
		while (check_ordine(punt_a) != 1)
			rra(punt_a);
	}
}

void	algoritmo_3(t_punt *punt_a, int *support, int inti)
{
	int	sezione;

	sezione = inti / 5;
	if ((ft_nodi(punt_a->head, support[sezione * 2], support[sezione * 2]))
		< (ft_lstsize(punt_a->head) / 2))
	{
		while (check_ordine(punt_a) != 1)
			ra(punt_a);
	}
	else
	{
		while (check_ordine(punt_a) != 1)
			rra(punt_a);
	}
}

void	algoritmo_4(t_punt *punt_a, int *support, int inti)
{
	int	sezione;

	sezione = inti / 5;
	if ((ft_nodi(punt_a->head, support[sezione], support[sezione]))
		< (ft_lstsize(punt_a->head) / 2))
	{
		while (check_ordine(punt_a) != 1)
			ra(punt_a);
	}
	else
	{
		while (check_ordine(punt_a) != 1)
			rra(punt_a);
	}
}

void	algoritmo_5(t_punt *punt_a, int *support, int inti)
{
	int	sezione;

	sezione = inti / 5;
	if ((ft_nodi(punt_a->head, support[0], support[0])) < (100 / 2))
	{
		while (check_ordine(punt_a) != 1)
			ra(punt_a);
	}
	else
	{
		while (check_ordine(punt_a) != 1)
			rra(punt_a);
	}
}
