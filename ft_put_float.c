#include <stdio.h>
#include <unistd.h>

long long int ft_powerof(int n)
{
	long long int result;
	int exp;
	int base;

	exp = n;
	base = 10;
	result = 1;
	while(exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

void  ft_putrem(double rem, int base)
{
	int           i;
	int           flag;
	long long int power;


	i = 0;
	flag = 0;
	power = ft_powerof(base);
	while(i < base)
	{
		if ((int)(rem * power) % 10 >= 5 && i == 0)
			flag = 1;
		rem = rem * 10.0;
		if(flag == 1 && i == base - 1)
			rem++;
		i++;
	}
	printf("%lli", (long long int)rem);
}


void  ft_putfloat(double n)
{
	int     num;
	double  rem;

	rem = (int)n - n;
	num = n - rem;
	if(rem < 0.0)
		rem *= -1;
	printf("%i.", num);
	ft_putrem(rem, 7);
}

int main(void)
{
	// printf("%lli", ft_powerof(9));
	double x = 1234.123456;
	// ft_putrem(x, 6);
	printf("\nLib printf: %.7f\n", x);
	printf("Asl printf: ");
	ft_putfloat(x);
	printf("\n");
	return 0;
}