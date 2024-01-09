/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:29:59 by yichan            #+#    #+#             */
/*   Updated: 2023/08/16 04:53:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_all_space(char *str)
{
	while ((*str >= '\t' && *str <= '\r') || *str == ' ' || *str == '\n')
		str ++;
	printf("check: space success\n");
	if (*str == '\0')
		return (1);
	printf("check: space fail\n");
	return (0);
}
