/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:23:01 by aguezzi           #+#    #+#             */
/*   Updated: 2022/07/24 17:23:10 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_tab(char **tab);

void	print_tab(char **tab);

int		str_is_4(char **tab, char *str);

int		verif_data_user(int argc, int i, char *str);

int		verif_case_number(char **tab, int i, int j, int k);

int		put_error_message(void);
