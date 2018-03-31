/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:04:44 by aguerin           #+#    #+#             */
/*   Updated: 2018/03/31 14:21:08 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	print_env.c
**	\author	Alexis Guérin
**	\date	8 janvier 2018
**
**	\brief	Affichage de l'environnement
*/

#include "environment.h"

/*
**	\brief	Affichage des variables d'environnement
**
**	\param	environment	- environnement à afficher
**
**	\return	**0** si l'affichage s'est effectué correctement
**			ou **1** en cas d'erreur.
*/

int	print_env(const char **environment)
{
	int	i;

	i = 0;
	if (environment)
		while (environment[i])
			ft_putendl(environment[i++]);
	return (!i);
}
