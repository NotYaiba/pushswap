SRCS =  push_swap.c\
		comds.c\
		helpers.c\
		helpers2.c\
		list_utils.c\
		ft_split.c\
		push_fiveh.c\
		helpers3.c\
		list_utils3.c\
		list_utils2.c\
		sort_four.c\
		sort_three.c\
		sort_oneh.c\
		sort_oneh_utils.c\
		comds2.c\
		comds3.c\
		init_struct.c\
		helpers4.c\
		helpers5.c\
		libft.c\

SRCSB = checker.c\
		comds.c\
		comds2.c\
		comds3.c\
		helpers.c\
		helpers2.c\
		get_next_line.c\
		get_next_line_utils.c\
		list_utils.c\
		ft_split.c\
		helpers3.c\
		list_utils3.c\
		list_utils2.c\
		init_struct.c\
		libft.c\

INCL = -INCLUDES/

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}

NAME = push_swap
NAMEB = checker


all : $(NAME)

$(NAME) :	${OBJS}
		@gcc -Wall -Werror   -c ${SRCS}  
		@gcc  -Wall  -Werror ${OBJS} -o ${NAME} 
bonus : ${OBJSB}
		@gcc -Wall -Werror -c ${SRCSB}
		@gcc -Wall -Werror ${OBJSB} -o ${NAMEB} 
clean :
		@rm -f ${OBJS}
		@rm -f ${OBJSB}
fclean : clean
		@rm -f $(NAME)
		@rm -f $(NAMEB)
re : fclean
		make all

