/**
**	\file	ft_setenv.c
**	\author	Alexis Guérin
**	\date	8 janvier 2018
**
**	\brief	Ajout de variables
*/

#include "environment.h"

static char	**add_var(char *new, char **environment)
{
	int		size;
	char	**copy;

	if (new && environment)
	{
		ft_putendl("add");
		size = 0;
		while (environment[size])
			size++;
		if ((copy = dupenv((const char **)environment, size + 1)))
		{
			ft_strdeldouble(environment);
			copy[size] = ft_strdup(new);
			environment = copy;
		}
		else
			ft_putendl("oups");
	}
	return (environment);
}

static int	alter_var(char *new, char **environment)
{
	int	i;

	if (new && environment)
	{
		i = find_var(new, environment, 1);
		ft_strdel(&environment[i]);
		environment[i] = ft_strdup(new);
	}
	return (1);
}

/**
**	Ajout ou modification de variable
**
**	Si la variable `new` n'existe pas et qu'elle est correctement formatée, celle-ci est ajoutée.
**	Si elle existe, sa valeur est modifiée.
**
**	\param	new -			variable à ajouter ou modifier
**	\param	environment -	environment à modifier
**
**	\return	**environnement** modifié ou **NULL** en cas d'erreur.
*/

char	**ft_setenv(char *new, char **environment)
{
	if (new && *environment)
	{
		if (find_var(new, environment, 1) < 0)
			environment = add_var(new, environment);
		else
			alter_var(new, environment);
	}
	return (environment);
}
