#Comandos
DEL			=	rm -f
CC			=	gcc 
CCFLAGS		=	-Wall -Wextra -Werror 
MLX			=	-lXext -lX11 -lm -lbsd 

#Nombre ejecutable
NAME		=	mlx.o


#Directorios
SRC_DIR = srcs/
OBJ_DIR = objs/

#Ficheros
SRC_FILES	= main

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIBFT		=	libft
MINILIBX	= 	mlx

#Librerias 
LIBS		= $(MINILIBX)/libmlx.a $(MLX) $(LIBFT)/libft.a 


# REGLAS # 
all:	minilibx libft $(NAME)

#Compilar 
$(NAME):$(OBJ)
		$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(GREEN)TEST HAS BEEN COMPILED!$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(YELLOW)Compiled!$(NC)"

objs/main.o : src/main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< 
	
# $@ : The file name of the target of the rule. If the target is an archive member, then ‘$@’ is the name of the archive file.
# $< : The name of the first prerequisite.

#compilar librerias individuales
libft:
	@echo "$(YELLOW)COMPILING LIBFT...$(NC)"
	@$(MAKE) -C ./$(LIBFT)
	@echo "$(GREEN)LIBFT HAS BEEN COMPILED$(NC)"

minilibx:
	@echo "$(YELLOW)COMPILING MINILIBX...$(NC)"
	@$(MAKE) -C ./$(MINILIBX)
	@echo "$(GREEN)MINILIBX HAS BEEN COMPILED$(NC)"

# Eliminar tmp mlx
fclean_mlx:
	@make fclean -C ./$(MINILIBX)
	@echo "$(RED)MINILIBX FULL CLEANED!$(NC)"


# Eliminar tmp libft
fclean_libft:
	@make fclean -C ./$(LIBFT)
	@echo "$(RED)LIBFT FULL CLEANED!$(NC)"

# Eliminar temporales
clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(RED)OBJS AND DIRECTORY CLEANED!$(NC)"


# Eliminar temporales y ejecutable fclean_mlx
fclean: clean  fclean_libft
	@$(RM) $(NAME)
	@echo "$(RED)EXECUTABLE CLEANED!$(NC)"


re: fclean all
