/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:28:08 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:28:11 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_array(t_list **lst, char *argv[], int *support, int a)
{
	t_punt	punt;
	int		i;
	long	intero;

	i = 0;
	punt.head = *lst;
	while (i < a)
	{
		if (ft_isdigit(argv[a - i]) == 0)
			uscita1(&punt, support);
		intero = ft_atoi(argv[a - i]);
		if (intero > MAX || intero < MIN)
			uscita1(&punt, support);
		support[i] = intero;
		fill_list(lst, intero);
		i++;
	}
	quicksort(support, 0, a - 1);
}

int	switch_(t_punt *puntatore_a, t_punt *puntatore_b, int *support, int a)
{
	if (a == 2)
	{
		if (check_ordine(puntatore_a) == 0)
			sa(puntatore_a);
	}
	else if (a == 3)
		pushtree(puntatore_a);
	else if (a == 5)
		pushfive(puntatore_a, puntatore_b);
	else if (a <= 50)
		algo(puntatore_a, puntatore_b, support, a);
	else if (a <= 100)
		algoritmo(puntatore_a, puntatore_b, support, a);
	else
		algoritmo(puntatore_a, puntatore_b, support, a);
	return (0);
}

void	check_array(t_punt *punt_a, int *support, int a)
{
	int	i;

	i = 0;
	while (i < (a - 1))
	{
		if (support[i + 1] == support[i])
		{
			ft_free(punt_a);
			free(support);
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	if (check_ordine(punt_a) == 1)
	{
		ft_free(punt_a);
		free(support);
		exit(0);
	}
}

void	main_dos(t_punt *puntatore_a, t_punt *puntatore_b, int *support, int a)
{
	check_array(puntatore_a, support, a);
	switch_(puntatore_a, puntatore_b, support, a);
	ft_free(puntatore_a);
	free(support);
}

int	main(int argc, char *argv[])
{
	t_punt	puntatore_a;
	t_punt	puntatore_b;
	int		*support;
	int		a;

	a = argc - 1;
	puntatore_a.head = NULL;
	puntatore_b.head = NULL;
	if (a == 0)
		return (0);
	else if (a == 1)
	{
		a = push_two(&puntatore_a.head, &argv[1], &support);
		if (a <= 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	else
	{
		support = (int *)malloc(sizeof(int) * (a));
		fill_array(&puntatore_a.head, argv, support, a);
	}
	main_dos(&puntatore_a, &puntatore_b, support, a);
}
