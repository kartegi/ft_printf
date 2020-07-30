
LIBFT = ./libft/libft.a

#N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_flag.c ft_handle_c.c ft_handle_d.c ft_handle_p.c \
		ft_handle_s.c ft_handle_width.c ft_itoa_base.c \
		ft_print_conv.c ft_printf.c
		
SURPL_O = ft_flag.o ft_handle_c.o ft_handle_d.o ft_handle_p.o \
          ft_handle_s.o ft_handle_width.o ft_itoa_base.o \
          ft_print_conv.o ft_printf.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all