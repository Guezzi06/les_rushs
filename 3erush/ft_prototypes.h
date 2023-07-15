/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:32:23 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/31 16:04:05 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
char	*dic(char *str);
char	**decomp(int nbr);
int		*ft_decoupe(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);

#endif
