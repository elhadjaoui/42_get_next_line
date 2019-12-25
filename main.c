/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:27:26 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/02 20:40:26 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int        calci(unsigned int nb)
{
	int    i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
char *ft_addtos(unsigned long int n)
{   
	char      *ptr;
	unsigned  long int  copy;
	int        i;

	copy = n;
	i = calci(copy);
	if (!(ptr = malloc(i  + 1)))
		return (NULL);
	ptr[i] = '\0';
	while (copy > 9)
	{
		ptr[--i] = (copy % 10) + 48;
		copy /= 10;
	}
	ptr[--i] = copy + 48;

	return (ptr);

}
char    *ft_itoa(int n)
{
	char            *ptr;
	unsigned    int    copy;
	int                i;
	int                sign;

	sign = 0;
	if (n < 0 && ++sign)
		copy = n * -1;
	else
		copy = n;
	i = calci(copy);
	if (!(ptr = malloc(i + sign + 1)))
		return (NULL);
	ptr[i + sign] = '\0';
	while (copy > 9)
	{
		ptr[--i + sign] = (copy % 10) + 48;
		copy /= 10;
	}
	ptr[--i + sign] = copy + 48;
	if (n < 0)
		ptr[--i + sign] = '-';
	return (ptr);
}


int main() 
{
	float a = 15.0;
	printf("%d",sizeof(a));
	printf("%f",a);

	//printf("%s", ft_hextos(k, 'x', 'p'));
	return 0;
}
