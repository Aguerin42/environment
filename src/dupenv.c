/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:01:00 by aguerin           #+#    #+#             */
/*   Updated: 2018/03/31 14:08:12 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	dupenv.c
**	\author	Alexis Guérin
**	\date	8 janvier 2018
**
**	\brief	Copie de l'environnement
*/

#include "environment.h"

/*
**	\brief	Copie de l'environnement
**
**	La fonction alloue la mémoire nécessaire pour pouvoir copier l'environnement
**	et retourne cette copie.
**
**	\param	environment	- environnement à copier
**	\param	size		- taille de l'environmment
**
**	\return	**copie** de l'environnement ou **NULL** en cas d'erreur.
*/

char	**dupenv(const char **environment, int size)
{
	int		i;
	char	**copy;

	copy = NULL;
	if (environment && size > 0)
	{
		i = -1;
		if ((copy = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
			while (++i < size && copy)
				if (environment[i] && !(copy[i] = ft_strdup(environment[i])))
					ag_strdeldouble(&copy);
	}
	return (copy);
}
