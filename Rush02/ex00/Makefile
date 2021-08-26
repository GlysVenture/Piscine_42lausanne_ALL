SRCS	= srcs/check_dict_syntax.c	\
		  srcs/check_value.c		\
		  srcs/dict.c				\
		  srcs/dict_list.c			\
		  srcs/dict_list2.c			\
		  srcs/error_msg.c			\
		  srcs/ft_list_out.c		\
		  srcs/ft_number_letter.c	\
		  srcs/ft_number_letter2.c	\
		  srcs/ft_string.c			\
		  srcs/main.c				\
		  srcs/trim.c				\
		  srcs/ft_string2.c

OBJS	= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

NAME	= rush-02

RM		= rm -f

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean
