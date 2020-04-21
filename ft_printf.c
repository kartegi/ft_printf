#include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);

int	ft_printf(const char *format, ...)
{
	char	print_char;
	char	*print_str;
	int	print_nbr;
	va_list	arglist;

	va_start(arglist, format);
	while(*format)
	{
		if (*format == '%')
		{
		  	format++;
		  	if (*format == 's')
			{
				print_str = va_arg(arglist, char *);
				ft_putstr(print_str);
			}
		  	else if (*format == 'c')
		  	{
				print_char = va_arg(arglist, int);
				ft_putchar(print_char);
		  	}
			else if (*format == 'i')
			{
				print_nbr = va_arg(arglist, int);
				ft_putnbr(print_nbr);
			}
			else if(*format == '%')
				ft_putchar('%');
			format++;
		}
	    	else
			ft_putchar(*format++);
	}
      	va_end(arglist);
	return (0);
} 


int main(void) {
  ft_printf("Hello world!\n%s\n%c\n%i ahahhahah\n", "Aslan", 'A', 26);
  return 0;
}
