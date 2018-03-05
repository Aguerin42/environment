/**
** \file	ft_unsetenv.c
** \author	Alexis Guérin
** \date	8 janvier 2017
**
** \brief	Suppression de variables
*/

#include "environment.h"

static int	ft_unset(char ***environment, int i)
{
	int		len;
	char	**environ;

	if (environment && i >= 0)
	{
		environ = NULL;
		ft_strdel(&environment[0][i]);
		environment[0][i] = environment[0][i + 1];
		while (environment[0][++i])
			environment[0][i] = environment[0][i + 1];
		if (!(len = ag_strlendouble(*environment)))
			len = 1;
		if (len && !(environ = dupenv((const char**)*environment, len)))
			return (ft_putendl("unsetenv: duplication error"));
		ag_strdeldouble(environment);
		*environment = environ;
		return (0);
	}
	return (1);
}

/**
** \brief	Suppression de variable d'environnement.
**
** \param	var			- variables à supprimer
** \param	environment - environnement à modifier
**						La variable doit avoir été allouée dynamiquement.
**
** \return	**0** si la suppression a été effectuée avec succès
**			ou une valeur **non nulle** en cas d'erreur.
*/

int			ft_unsetenv(char *var, char ***environment)
{
	int	ret;

	ret = 1;
	if (var && environment && environment[0])
		ret = ft_unset(environment, find_var(var, (const char**)environment[0], 0));
	else if (!var)
		return (ft_putendl_fd("unsetenv: not enough arguments", 2));
	return (ret);
}
