SRCS	=	ft_atoi.c	ft_isdigit.c	ft_memmove.c	ft_split.c   ft_strlcpy.c \
			ft_strtrim.c  ft_bzero.c	ft_isprint.c	ft_memset.c   ft_calloc.c \
			ft_strchr.c    ft_strlen.c   ft_substr.c	ft_itoa.c     ft_putchar_fd.c \
			ft_strdup.c    ft_strmapi.c  ft_tolower.c	ft_isalnum.c  ft_memchr.c \
			ft_putendl_fd.c  ft_striteri.c  ft_strncmp.c  ft_toupper.c	ft_isalpha.c \
			ft_memcmp.c   ft_putnbr_fd.c   ft_strjoin.c   ft_strnstr.c	ft_isascii.c \
			ft_memcpy.c   ft_putstr_fd.c   ft_strlcat.c   ft_strrchr.c

SRCS_BN =	ft_lstnew_bonus.c	ft_lstlast_bonus.c	ft_lstsize_bonus.c	ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c	ft_lstdelone_bonus.c	ft_lstclear_bonus.c	ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJS_BN = $(SRCS_BN:.c=.o)

NAME	=	libft.a

OBJS 	= $(SRCS:.c=.o)

CC 		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o 	:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
			ar rcs $(NAME) $(OBJS)

clean	: 
			$(RM) $(OBJS) $(OBJS_BN)

fclean	: clean
			$(RM) $(NAME)

re		: fclean all

bonus	: $(OBJS) $(OBJS_BN)
			ar rcs $(NAME) $(OBJS) $(OBJS_BN)

.PHONY	: all clean fclean re bonus
.SECONDARY: