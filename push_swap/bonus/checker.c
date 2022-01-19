/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:19:50 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 15:20:54 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_repeat(t_list **list)
{
	t_list	*list_a;

	list_a = NULL;
	if (*list)
		list_a = *list;
	while (list_a->next)
	{
		if (list_a->numero == list_a->next->numero)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

int	ritorno_dos(char *line, t_punt *puntatore_a, t_punt *puntatore_b)
{
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\0')
		ra(puntatore_a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\0')
		rb(puntatore_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\0')
		rr(puntatore_a, puntatore_b);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ritorno(char *line, t_punt *puntatore_a, t_punt *puntatore_b)
{
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\0')
		pa(puntatore_a, puntatore_b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\0')
		pb(puntatore_a, puntatore_b);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\0')
		sa(puntatore_a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\0')
		sb(puntatore_b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\0')
		ss(puntatore_a, puntatore_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' \
	&& line[3] == '\0')
		rra(puntatore_a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' \
	&& line[3] == '\0')
		rrb(puntatore_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' \
	&& line[3] == '\0')
		rrr(puntatore_a, puntatore_b);
	else if (ritorno_dos(line, puntatore_a, puntatore_b) == 0)
		return (0);
	return (1);
}

int	cute_switch(int argc, char *argv[], t_punt *puntatore_a)
{
	int	flag;

	flag = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == 0)
			return (0);
		flag = push(&puntatore_a->head, &argv[1]);
		if (flag <= 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	else
		fill_listaa(&puntatore_a->head, argv, argc - 1);
	return (5);
}

int	main(int argc, char *argv[])
{
	t_punt	puntatore_a;
	t_punt	puntatore_b;
	char	*line;
	int		flag;

	puntatore_a.head = NULL;
	puntatore_b.head = NULL;
	if (cute_switch(argc, argv, &puntatore_a) == 0)
		return (0);
	flag = 1;
	doppini(&puntatore_a);
	while (flag > 0)
	{
		flag = get_next_line(&line, 0, &puntatore_a, &puntatore_b);
		free(line);
	}
	if (check_ordine(&puntatore_a, &puntatore_b) == 0 && flag != -1)
		write(1, "KO\n", 3);
	else if (flag != -1)
		write(1, "OK\n", 3);
	ft_free(&puntatore_a);
	ft_free(&puntatore_b);
	return (0);
}
