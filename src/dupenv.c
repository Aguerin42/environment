/**
**	\file	dupenv.c
**	\author	Alexis Guérin
**	\date	8 janvier 2018
**
**	\brief	Copie de l'environnement
*/

#include "environment.h"

/**
**	\brief	Copie de l'environnement
**
**	La fonction alloue la mémoire nécessaire pour pouvoir copier l'environnement
**	et retourne cette copie.
**
**	\param	environment	- environnement à copier
**	\param	size		- taille du nouvel environmment
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
					ft_strdeldouble(&copy);
	}
	return (copy);
}
