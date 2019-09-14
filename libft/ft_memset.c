/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:04:14 by bjesse            #+#    #+#             */
/*   Updated: 2019/04/11 20:56:26 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	byte;
	unsigned char	*a;

	a = (unsigned char*)b;
	byte = (unsigned char)c;
	while (len-- > 0)
		*a++ = byte;
	return (b);
}
