/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:00:03 by aguerin           #+#    #+#             */
/*   Updated: 2018/03/31 14:00:40 by aguerin          ###   ########.fr       */
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

char	**dupenv(const char **environment, int size);

char	*ft_getenv(const char *name, const char **environment);
int		find_var(const char *var, const char **environment, int egal);

int		ft_setenv(char *new, char ***environment);
int		ft_vcontenv(const char *var, const char *content, char ***environment);

int		ft_unsetenv(char *var, char ***environment);

int		print_env(const char **environment);

#endif
