//#include "ft_printf.h"
#include <stdio.h>
//
//int	main(void)
//{
//	char x = 'x';
//	void *p0 = &x;
//	char *str = "sdf";
//	ft_printf("%p\n", str);
//	printf("%p\n", str);
//	return (0);
//}

#include "includes/ft_printf.h"

int	main(void)
{
	long long int x = -2147483649;
	ft_printf("%lli", x);
	return (0);
}