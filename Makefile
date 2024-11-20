
SRCS	=	ft_printf.c	ft_putchar.c	ft_puthex.c	ft_putnbr.c \
			ft_putstr.c	ft_putptr.c	ft_putunbr.c

NAME	=	libftprintf.a 

OBJS 	= $(SRCS:.c=.o)

CC 		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

RESET		=	'\033[0m'
GREEN		=	'\033[32m'
GRAY		=	'\033[2;37m'
ITALIC		=	'\033[3m'
.c.o 	:
			@echo $(ITALIC)$(GREEN) "     - Compiling the file /$<..." $(RESET)
			@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
			@echo $(ITALIC)$(GRAY) "     - Compiling the library $(NAME)..." $(RESET)
			@ar rcs $(NAME) $(OBJS)

clean	: 
			@echo $(ITALIC)$(GRAY) "     - deleting the object files..." $(RESET)
			@$(RM) $(OBJS)

fclean	: clean
			@echo $(ITALIC)$(GRAY) "     - deleting the $(NAME)..." $(RESET)
			@$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
.SECONDARY: