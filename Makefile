NAME = pipex

SRCS = 	srcs/main.c \
		srcs/create_cmd_path.c \
		srcs/first_fork_fct.c \
		srcs/free.c \

OBJS = $(SRCS:.c=.o)

LIBS = libft/libft.a

CFLAGS = #-Wall -Wextra -Werror -O3

all : $(NAME)

%.o : %.c includes/pipex.h
	gcc -c $(CFLAGS) $< -o $(<:.c=.o) -g

$(NAME) : $(OBJS)
	cd libft && make bonus && cd ..
	gcc $(CFLAGS) -o pipex $(LIBS) $(OBJS)

clean : 
	rm -f $(OBJS)
	cd libft && make clean

fclean : clean
	rm -f $(NAME) $(LIBS)

re : fclean all

.PHONY : all clean fclean re