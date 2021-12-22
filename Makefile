NAME = minitalk

SERV = server
CLT = client
GCC = gcc
FLAGS = -Wall -Werror -Wextra 

S_SRC = server.c	\
	  $(addprefix ft_printf/, ft_printf.c printfutils1.c printfutils2.c)
C_SRC = client.c

S_OBJ = $(S_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)

all: $(NAME)

$(NAME): $(S_OBJ) $(C_OBJ)
	@make -C ft_printf/
	@$(GCC) $(FLAGS) $(S_OBJ) -L ft_printf -o $(NAME)
	@$(GCC) $(FLAGS) $(C_OBJ) -o $(NAME)

%.o: %.c
	@$(GCC) $(FLAGS) -c $< -o $@

clean:
	@make -C ft_printf clean
	@rm -f $(S_OBJ)
	@rm -f $(C_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
