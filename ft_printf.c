#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


int	ft_printf(const char *format, ...)
{
	char  letter;
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
        format++;
				print_str = va_arg(arglist, char *);
				printf("%s", print_str);
			}
      else if (*format == 'c')
      {
        format++;
        letter = va_arg(arglist, int);
        printf("%c", letter);
      }
			else if (*format == 'i')
			{
        format++;
				print_nbr = va_arg(arglist, int);
				printf("%i", print_nbr);
			}
		}
    else{
        printf("%c", *format);
        format++;
    }
	}
  va_end(arglist);
	return (0);
} 


int main(void) {
  ft_printf("Hello world!\n%s\n%c\n%i", "Aslan", 'A', 26);
  return 0;
}