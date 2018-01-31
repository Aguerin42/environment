/**
**	\file	environment.h
**	\author	Alexis Guérin
**	\date	8 janvier 2018
*/

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "libft.h"
# include "libag.h"

char	**dupenv(const char **environment, int size);

char	*ft_getenv(const char *name, char **environment);
int		find_var(const char *var, char **environment, int egal);

int		ft_setenv(char **new, char ***environment);

int		ft_unsetenv(char **args, char ***environment);

int		print_env(const char **environment);

#endif
