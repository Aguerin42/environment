/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:00:03 by aguerin           #+#    #+#             */
/*   Updated: 2018/04/19 18:35:16 by tgrange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	\file	environment.h
**	\author	Alexis Guérin
**	\date	8 janvier 2018
*/

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "libft.h"
# include "libag.h"
# include "liberror.h"

char	**dupenv(const char **environment, int size);

char	*ft_getenv(const char *name, const char **environment);
int		find_var(const char *var, const char **environment, int egal);

int		ft_setenv(char *new, char ***environment);
int		ft_vcontenv(const char *var, const char *content, char ***environment);

int		ft_unsetenv(char *var, char ***environment);

int		print_env(const char **environment);

#endif
