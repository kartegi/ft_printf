void	ft_puchar(char c);

int	ft_printf(const char *format, ...)
{
	char	print_char;
	va_list	arglist;

	va_start(arglist, format);
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			if(*format == 'c')
			{
				print_char = va_arg(arglist, char);
				ft_putchar(print_char);
			}
		}
	}
	return (0);
}
