/**
**	\file	ft_getenv.c
**	\author	Alexis Guérin
**	\date	8 janvier 2018
*/

#include "environment.h"

static int	find_var(const char *var, char **environment)
{
	int	i;
	int	len;

	if (var && environment)
	{
		i = -1;
		len = ft_strlen(var);
		while (environment[++i])
			if (ft_strnequ(var, environment[i], len))
				if ((environment[i][len] && environment[i][len] == '='))
					return (i);
	}
	return (-1);
}

/**
**	\brief	Récupération de variable
**
**	La fonction cherche la variable dans l'environnement et renvoie sa valeur.
**	Si la variable n'existe pas, *NULL* est renvoyé.
**
**	\param	name -			variable à chercher
**	\param	environment -	environnement où chercher
*/

char		*ft_getenv(const char *name, char **environment)
{
	int		i;
	char	*value;

	value = NULL;
	if (name && environment)
	{
		if ((i = find_var(name, environment)) >= 0)
		{
			value = environment[i];
			if ((value = ft_strchr(value, '=')))
				value++;
		}
	}
	return (value);
}
