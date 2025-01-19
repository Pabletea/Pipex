# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 10:52:55 by pabalons          #+#    #+#              #
#    Updated: 2024/10/04 11:31:03 by pabalons         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c \

OBJS		=	$(SRCS:.c=.o)

BONUS		=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \

BONUS_OBJS	=	$(BONUS:.c=.o)

BONUS_FLAG = .bonus_compiled

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(BONUS_FLAG)

$(BONUS_FLAG): $(OBJS) $(BONUS_OBJS)
				ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
				touch $(BONUS_FLAG)

.PHONY:			all clean fclean re bonus
