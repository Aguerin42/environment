/**
**	\file	find_var.c
**	\author	Alexis Guérin
**	\date	8 janvier 2018
*/

#include "environment.h"

/**
**	\brief	Recherche de variable
**
**	La fonction cherche la variable `var` dans l'environnement et renvoie l'indice de sa position.
**	Le booléen `egal` permet d'indiquer si la recherche doit ignorer le caractère égal et ce qui suit lors de la
**	comparaison (`1`) ou non (`0`).
**
**	\return	**indice** de la variable dans `environment` ou **-1** si elle n'y est pas.
*/

int	find_var(const char *var, char **environment, int egal)
{
	int		i;
	int		len;
	char	*ret;

	if (var && environment)
	{
		i = -1;
		if (egal)
		{
			ret = ft_strchr(var, '=');
			len = ret ? ret - var : ft_strlen(var);
		}
		else
			len = ft_strlen(var);
		while (environment[++i])
			if (ft_strnequ(var, environment[i], len))
				if ((environment[i][len] && environment[i][len] == '='))
					return (i);
	}
	return (-1);
}
