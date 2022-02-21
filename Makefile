HEADER = fract.h

RM = rm -f 

SRC = mandelbrot.c\
		julia.c\
		main.c\
		fract_utils.c\
		fract_utils1_1.c\
		fract_utils1_2.c 
BONUS = mandelbrot_5.c\
	main_bonus.c\
	fract_utils_bonus.c\
	fract_utils1_1_bonus.c\
	fract_utils_1_2_bonus.c

NAME = fractol

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(HEADER)
		gcc -Wall -Wextra -Weror -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS) $(NAME)
		gcc -Wall -Wextra -Weror -lmlx -framework OpenGL -framework AppKit $(OBJ_BONUS) -o $(NAME)

%.o : %.c $(HEADER)
		gcc -Wall -Wextra -Werror  -c $< -o $@

clean: 
		$(RM) $(OBJ) ${OBJ_BONUS}

fclean: clean
		$(RM) $(NAME) 

re: fclean $(NAME)
