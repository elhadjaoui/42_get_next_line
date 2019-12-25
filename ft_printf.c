/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simoo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:59:59 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/24 14:05:15 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include  <stdarg.h>
#include  <stdlib.h>
#include  <unistd.h>
#include <string.h>

//*************************************
int		calci(unsigned long int nb)
{
	int	i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
//******************************************
int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL || *s == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}
//*******************************************************
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		i++;
	}
	if (!(cp = (char*)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
//*********************************
char    *ft_strjoin1(char  *s1, char  *s2,char o,char c)
{
	int        len1;
	int        len2;
	int			k;
	char    *p;

	k = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
	if  (s2 == NULL)
		s2 = ft_strdup("");
	 if (o == 'c' && c == '\0')
          k = 1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char*)malloc(len2 + len1 + 1 + k);
	if (p == NULL)
		return (NULL);
	while (len1 != 0 && *s1 != '\0')
		*p++ = *s1++;
	while (k == 1)
    {
        *p++ = *s1++;
        break;
    }
	while (*s2 != '\0')
		*p++ = *s2++;
	*p = '\0';
	p = p - (len2 + len1 + k);
	// free((char *)s1 - len1);
	// free((char *)s2 - len2);
	return (p);
}
//******************************************************
char    *ft_strjoin(char  *s1, char  *s2)
{
	int        len1;
	int        len2;
	
	char    *p;

	if (s1 == NULL)
		s1 = ft_strdup("");
	if  (s2 == NULL)
		s2 = ft_strdup("");
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char*)malloc(len2 + len1 + 1);
	if (p == NULL)
		return (NULL);
	while (len1 != 0 && *s1 != '\0')
		*p++ = *s1++;
	while (*s2 != '\0')
		*p++ = *s2++;
	*p = '\0';
	p = p - (len2 + len1);
	//  free((char *)s1 - len1);
	//  free((char *)s2 - len2);
	return (p);
}
//****************************************************************
char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned	int	copy;
	int				i;
	int				sign;

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
//***************************************************


//******************************************
char *ft_ctos(char c)
{
	
	char *p;
	char *s;
	p = malloc(2 * sizeof(char));
	p[0] = c;
	p[1] = 0;
	return p;
}
//*****************************

size_t	ft_putstr(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = ft_strlen(str);
	write(1, str, i);
	free(str);
	return(i);
}
//**************************************
char *ft_Uinttos(unsigned int n)
{   
	char			*ptr;
	unsigned	int	copy;
	int				i;

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
//************************
void	ft_bzero(void *s, size_t n)
{
	char *h;

	h = (char *)s;
	while (n--)
		*h++ = 0;
}
//*************************************
void	*ft_calloc(size_t count, size_t size)
{
	void *p;

	p = malloc(count * size);
	if (p != NULL)
	{
		ft_bzero(p, count * size);
		return (p);
	}
	return (NULL);
}
//**********************************************
int ft_ft_atoi(const char *str)
{
	int i;
	unsigned int nb;
	int sign;

	sign = 1;
	i = -1;
	nb = 0;
	while (str[++i] != '\0')
	{
		if ((str[i] > '/' && str[i] < ':') || str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			if (str[i] == '+' || str[i] == '-')
				i++;
			while (str[i] > '/' && str[i] < ':')
			{
				nb = nb * 10 + str[i++] - 48;
			}
			return (nb * sign);
		}
		else if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			return (nb * sign);
	}
	return (nb * sign);
}
//**********************************************
char *func1(int a,int b,char *s,int len)
{
	

int k;
	char *ptr;
	char ko;
	char *p;

	k = 0;
	p = ft_strdup("");
	ptr = ft_strdup("");
	// if (ft_ft_atoi(s) == 0 && ++a)
	// 		s = ft_strdup("");
while((a - b != 0) && (a - len != 0) && a--)
	  		p = ft_strjoin(ft_strdup(" "),p);
			 if (s[0] == '-')
			 {
				s =  s + 1;
				p = ft_strjoin(p,ft_strdup("-"));
			} 
			if (b > len){
				while(b - len != 0 && b != 0 && b--)
					p = ft_strjoin(p,ft_strdup("0"));
			}
			
			return  ft_strjoin(p,s);
}

//*****************************************************
char *func2(int a,int b,char *s,int len)
{
	int temoin;
	int k;
	char *ptr;
	char *ko;

	
	k = 0;
	ko = s;
	ptr = ft_strdup("");
	temoin = b;

	if (s[0] == '-')
	{
		s = s + 1;
		ptr = ft_strdup("-");
		//free(ko);
	}
	if (ft_ft_atoi(s) == 0 )
	{
		len = 0;
		s = ft_strdup("");
	}
	if (b > len)
	{
		while (b - len != 0 && b != 0 && b--)
			s = ft_strjoin(ft_strdup("0"), s);
		
		k += len;
	}

	b = temoin;
	
	while ((a - b != 0) && (a - len != 0) && a--)
				s = ft_strjoin(s ,ft_strdup(" "));
		s = ft_strjoin(ptr,s);
	return (s);
}
//*************************************************
char *func3(int b,char *s)
{
	int k;
	char *ptr;
	char *ko;
	char *p;

	p = ft_strdup("");
	k = ft_strlen(s);
	ko = s;

	ptr = ft_strdup("");
	if (s[0] == '-' && --k)
	{
		s = s + 1;
		ptr = ft_strdup("-");
		//free(ko);
	}
	while(b - k != 0 && b != 0 && --b)
			p = ft_strjoin(p,ft_strdup("0"));
		p = ft_strjoin(ptr,p);
			
		return ft_strjoin(p,s);
}
//**************************************
char *ft_tolower(char *c)
{
	int i;

	i = 0;
	while(c[i])
	{
		if (c[i] >= 'A' && c[i] <= 'F')
			c[i] = c[i] + 32;
		i++;
	}
	return (c);
}
//**********************************

char *ft_Phextos(unsigned long int n)
{
	char *s;
	s = NULL;

	while(n > 0)
	{
		if (n % 16 >= 10 && n % 16 <= 15 )
			s = ft_strjoin(ft_ctos(n % 16 + 55), s);
		else
			s = ft_strjoin(ft_itoa(n % 16),s);
		n = n / 16;
	}
	return (s == NULL ? ft_strdup("0x0") : ft_strjoin(ft_strdup("0x"),ft_strdup(ft_tolower(s))));
}

//************************************
int ft_atoi(const char **str, va_list ap)
{
	 int nb;
	int sign;
	int k;

	nb = 0;
	sign = 1;
	if (**str == '-' && (*str)++)
		sign = -1;
	if (**str == '*' && (*str)++)
	{
		nb = va_arg(ap, int);
		k = nb;
	}
	else
		while (**str > '/' && **str < ':')
		{
			nb = nb * 10 + **str - 48;
			(*str)++;
		}
		if (sign == -1 && k < 0)
			sign = 1;
	return (nb * sign);
}

//***********************************************
char *ft_hextos(unsigned int n, char c)
{
	char *s;
	s = NULL;
	if (c == 'u')
		return ft_Uinttos(n);
	if (n == 0)
	 	return ft_strdup("0");
	while (n > 0)
	{
		if (n % 16 >= 10 && n % 16 <= 15)
			s = ft_strjoin(ft_ctos(n % 16 + 55), s);
		else
			s = ft_strjoin(ft_itoa(n % 16), s);
		n = n / 16;
	}
	
	return (c == 'x' ? ft_strdup(ft_tolower(s)) : (s));
}
//*********************************
char *ft_sp_ze(int a, int b, char *s, char o)
{
	//char *p;
	int k;
	int j;
	int len;

	va_list ap;
	k = 0;
	j = 0;
	if ((a < 0) && (j = 1))
		a *= -1;
	len = ft_strlen(s);
	// if (ft_ft_atoi(s) == 0 && a != 0 && (o == 'd' || o == 'i' || o == 'u'))
	// 	len = 0;
	//(a > b && a > len) ? (p = ft_calloc(1, a + 1)) : (b > len ? (p = ft_calloc(1, b + 1)) : (p = ft_calloc(1, len + 1)));
	if (s[0] == '-' && a--)
		len--;
	if (a > b && a > len  && j != 1)
		return func1(a, b,s, len);
	if (a > b && a > len  && j == 1)
		return   func2(a, b, s,len);
	else if (b >= a && b > len )
		return func3(b, s);
	return (s);
}
char *ft_sp_String(int a, int b, char *s, char o)
{

	char *p;
	int k;
	int j;
	int len;

	k = 0;
	j = 0;
	while ((a - b != 0) && (a - len != 0) && a--)
		p[k++] = ' ';
	if (s[0] == '-')
	{
		s = s + 1;
		p[k++] = '-';
	}
	if (b < len)
	{
		s[b] = '\0';
	}
	return len == 0 ? ft_strjoin(p, ft_strdup("")) : ft_strjoin(p, s);

	return (ft_strdup(""));
}
//****************************************
char *ft_cv(char p, va_list ap, char *s)
{
	char *tt;
	char c;

	if (p == 'd' || p == 'i')
		return (ft_strjoin(s, ft_itoa(va_arg(ap, int))));
	else if (p == 'x' || p == 'X' || p == 'u')
		return (ft_strjoin(s, ft_hextos(va_arg(ap, unsigned int), p)));
	else if (p == 's')
	{
		tt = va_arg(ap, char *);
		return ((tt != NULL) ? ft_strjoin(s, ft_strdup(tt)) :
		 ft_strjoin(s, ft_strdup("(null)")));
	}
	else if (p == 'c')
	{
		c = va_arg(ap, int);
		return (ft_strjoin(s, ft_ctos(c)));
	}
	else if (p == 'p')
		return (ft_strjoin(s, ft_Phextos(va_arg(ap, unsigned long int))));

	return (ft_strjoin(s, ft_ctos(p)));
}
//****************************************
char *unique(int nu1,char *ptr)
{
int len;
	char *s;
	char *ptt;
	char *ko;

	ko = ptr;
	len = ft_strlen(ptr);
	ptt = ft_strdup("");
	
	if (ptr[0] == '-')
	{
		ptr = ptr + 1;
		ptt = ft_strdup("-");
		
	}
		while (nu1 - len != 0)
		{
			ptr = ft_strjoin(ft_strdup("0"), ptr);
			nu1--;
		}
	ptr = ft_strjoin(ptt, ptr);
		
free(ko);
	// ptr = ft_strjoin(s, ptr);
		return ptr;
}
//****************************************
char *fucking_star(int z, int dot, int nu1, char *ptr)
{
	int len;
	char *s;
	char *ptt;
	char *ko;

	ko = ptr;
	len = ft_strlen(ptr);
	ptt = ft_strdup("");
		s = ft_strdup("");
	if (ptr[0] == '-')
	{
		ptr = ptr + 1;
		ptt = ft_strdup("-");
		free(ko);
	}
		while (nu1 - len != 0)
		{
			ptr = ft_strjoin(ft_strdup("0"), ptr);
			nu1--;
		}
	ptr = ft_strjoin(ptt, ptr);
			return ptr;
}
//*************************************
char *hadihia(char p, int nu1, int nu2, va_list ap)
{
	char *s;

	s = ft_strdup("");
	if (p == 'd' || p == 'i' || p == 'x' || p == 'X' || p == 'u'
	 || p == 'p' || p == 'c')
		return ft_sp_ze(nu1, nu2, ft_cv(p, ap, s), p);

	if (p == 's')
		return ft_sp_String(nu1, nu2, ft_cv(p, ap, s), p);
	return ft_strdup("");
}
//************************************************
int ft_isflag(char p)
{
	if (p == '.' || p == '*' || p == '-' || (p >= 48 && p <= 57))
		return (1);
	if (p != 's' || p != 'd' || p != 'u' || p != 'i' || p != 'x' ||
	 p != 'X' || p != 'p' || p != 'c')
		return (2);
	return (0);
}
//**************************************
char *ft_flag(const char **l, va_list ap, int dot, int z)
{
	int nu1;
	int nu2;
	char *s;

	s = NULL;
	nu2 = 0;
	if (ft_isflag(**l) == 1 && (nu1 = 0) == 0)
	{
		while (ft_isflag(**l) != 2)
			if (**l == '.' && (*l)++)
				dot = 1;
			else if (**l == '0' && (*l)++)
				z = 1;
			else if ((**l >= 48 && **l <= 57) || **l == '-' || **l == '*')
			(!dot) ? (nu1 = ft_atoi(l, ap)): 
					(nu2 = ft_atoi(l, ap));
		if ((z == 1 && nu2 < 0))
		 	s = ft_strjoin(s, fucking_star(z, dot, nu1, ft_cv(**l, ap, s)));
		else if ((z == 1 && nu2 == 0 && dot == 0))
		 	 s = ft_strjoin(s, unique(nu1,ft_cv(**l, ap, s)));
		else
			s = ft_strjoin(s, hadihia(**l, nu1, nu2, ap));
	}
	else
		s = ft_cv(**l, ap, s);
	return (s);
}
//*************************************
int ft_printf(const char *fmt, ...)
{
	va_list ap;
	char *s;
	char *ptr;

	va_start(ap, fmt);
	s = NULL;
	ptr = ft_strdup("");
	while (*fmt != 0)
	{
		if (*fmt == '%' && ++fmt)
			s = ft_strjoin(s, ft_flag(&fmt, ap, 0, 0));
		else
			s = ft_strjoin(s, ft_ctos(*fmt));
		fmt++;
	}
	va_end(ap);
	return (ft_putstr(s));
}

int main ()
{
	//char o = 'c';
	//printf("%p", &o);
	//printf("%d\n", ft_printf("name : %s age : %d address : %x : %p\n", "jamal",23,0x1D10, &o));
	//char *p  = NULL;
	// //ft_printf("nothing %s", "ff");
    // printf("%d\n",ft_printf("|%05.d|\n",0));
	//   printf("%d\n", printf("|%05.d|\n", 0));
	// // ft_printf("||%4.c||\n", '\0');
	// // ft_printf("|%010.*d|\n", -20,-521);
	// // printf("|%010.*d|\n",-20, -521);
	
	    ft_printf("|%4.2d|", 0);
		 printf("\n");
	       printf("|%4.2d|", 0);
   printf("--------------------------\n\n");
	char *p = "thesvdfvdvdfv";
  printf("|%c---%s---%u---%x---%X---%d---%p---|",'s',NULL,-0,0,0,0,p);
  printf("\n");
    ft_printf("|%c---%s---%u---%x---%X---%d---%p---|",'s',NULL,0,0,0,0,p);

	//       printf("\n");
	 // ft_printf("%x|",0);

// int a = printf("|%-*.3d|",-8,-100);
// printf("\n");
// int b = ft_printf("|%-*.3d|",-8,-100);
// printf("\n");

// printf ("%d \n%d", a , b);
//     ft_printf("|%0*.*x|%04.2d| %*.c| |%s| | %-20p | %14.20u|\n",-14,-18,0x4dfca, 2147483647, -12,' ', NULL, p, -10);
//     printf("|%0*.*x|%04.2d| %*.c| |%s| | %-20p | %14.20u|\n",-14,18, 0x4dfca ,2147483647, -12,' ', NULL, p, -10);
	printf("\n\n");
	ft_printf("hakam %%%-12d, %000004.i %% %010.*u    %011X, %10p\n", -1996, 1, 6, -22, 35764523, (void *)328947);
    printf("hakam %%%-12d, %000004.i %% %010.*u    %011X, %10p\n", -1996, 1, 6, -22, 35764523, (void *)328947);
	printf("\n\n");
	ft_printf("%0*.*d|\n", -10,0, -10);
    printf("%0*.*d|\n",-10,0, -10);
printf("\n\n");
	ft_printf("%010.*d|\n",0,52);
    printf("%010.*d|\n",0,52);
printf("\n\n");

	//  printf("%10.12s\n", p);
	// ft_printf("%10.12s\n", p);

	// 	ft_printf("%-10.*d|\n",-140,-52);
    // printf("%-10.*d|\n",-140,-52);

	// 	ft_printf("%10.*d|\n",140,-52);
    // printf("%10.*d|\n",140,-52);
	// printf("\n\n");

// 	ft_printf("%d\n",ft_printf("%p : hello :  %s : hello : %05d : hello %i : hello : %c : hello %x : hello : %X : hello : %u\n", p,"hh",45,789,'d', 0xf47, 0xf47, 429496729));
// 	ft_printf("%d\n",printf("%p : hello :  %s : hello : %05d : hello %i : hello : %c : hello %x : hello : %X : hello : %u\n", p,"hh",45,789,'d', 0xf47, 0xf47, 429496729));
// printf("\n\n");

// 	printf("%d\n", ft_printf("%%%d, %s, %c, %u, %x,%X, %p", 214, "simo", 'k', 214748364,0x4f,0x4f,&p));
// 	printf("%d\n", printf("%%%d, %s, %c, %u, %x,%X, %p", 214, "simo", 'k', 214748364,0x4f,0x4f,&p));
	// //printf("%d\n", printf("%x", 	2147483648));
	// //printf("%d\n", printf("name : %s age : %d address : %x : %p\n", "jamal",23,0x1D10, &o));
	// //ft_printf("%m");
	// //printf("%d\n", ft_printf("%c\n", 	97));
	// //printf("%d\n", printf("%c\n", 	97));
	return 0;
}
