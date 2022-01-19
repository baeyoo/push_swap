/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:24:14 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:24:18 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcomp(char c, char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == c)
			return (ret + 1);
		ret++;
	}
	return (0);
}

void	ft_free(t_punt *punt)
{
	t_list	*list_a;
	t_list	*temp;

	list_a = punt->head;
	if (list_a)
	{
		while (list_a->next)
		{
			temp = list_a;
			list_a = list_a->next;
			free(temp);
		}
	}
	free(list_a);
}

void	uscita(t_punt *punt)
{
	write(1, "Error\n", 6);
	ft_free(punt);
	exit (0);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*rslt;

	i = 0;
	rslt = malloc(ft_strlen(str) + 1);
	while (*str)
		rslt[i++] = *str++;
	rslt[i] = 0;
	return (rslt);
}

int	check_ordine(t_punt *puntatore, t_punt *punt)
{
	t_list	*lst;
	int		controllo;

	lst = puntatore->head;
	controllo = lst->numero;
	while (lst->next)
	{
		if (controllo > lst->next->numero)
			return (0);
		lst = lst->next;
		controllo = lst->numero;
	}
	lst = punt->head;
	if (lst != NULL)
		return (0);
	return (1);
}
