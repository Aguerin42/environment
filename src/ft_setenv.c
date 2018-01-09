/**
**	\file	ft_setenv.c
**	\author	Alexis Guérin
**	\date	8 janvier 2018
**
**	\brief	Ajout de variables
*/

#include "environment.h"

static int	add_var(char *new, char ***environment)
{
	int		size;
	int		len;
	char	**copy;

	if (!new || !environment)
		return (1);
	size = 0;
	while (environment[0][size])
		size++;
	if ((copy = dupenv((const char **)*environment, size + 1)))
	{
		ft_strdeldouble(*environment);
		if (ft_strchr(new, '='))
			copy[size] = ft_strdup(new);
		else
		{
			len = ft_strlen(new);
			copy[size] = ft_strnew(len + 1);
			ft_strcpy(copy[size], new);
			copy[size][len] = '=';
		}
		*environment = copy;
		return (0);
	}
	return (1);
}

static int	alter_var(char *new, char **environment, int i)
{
	if (new && environment && ft_strchr(new, '='))
	{
		ft_strdel(&environment[i]);
		environment[i] = ft_strdup(new);
	}
	return (1);
}

static int	set(char *new, char ***environment)
{
	int	i;

	if (new && environment)
	{
		if (new[0] == '=')
			return (ft_putendl_fd("setenv: bad assignment", 2));
		if ((i = find_var(new, environment[0], 1)) < 0)
			return (add_var(new, environment));
		else
			return (alter_var(new, *environment, i));
	}
	return (1);
}

/**
**	Ajout ou modification de variable
**
**	Si la variable `new` n'existe pas et qu'elle est correctement formatée,
**	celle-ci est ajoutée. Si elle existe, sa valeur est modifiée.
**
**	\param	new -			variables à ajouter ou modifier
**	\param	environment -	environment à modifier
**
**	\return	**0** en cas de succès, **1** en cas d'erreur.
*/

int			ft_setenv(char **new, char ***environment)
{
	int	i;
	int	ret;

	i = 0;
	if (new && environment && *environment)
	{
		ret = 0;
		while (new[i])
			if (set(new[i++], environment))
				ret = 1;
		return (ret);
	}
	return (1);
}
