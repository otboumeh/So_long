# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 16:25:10 by otboumeh          #+#    #+#              #
#    Updated: 2024/07/03 09:39:33 by otboumeh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Comandos
DEL			=	rm -f
CC			=	gcc 
CCFLAGS		=	-Wall -Wextra -Werror 
MLX			=	-lXext -lX11 -lm -lbsd 

#Nombre ejecutable
NAME		=	so_long

#Ficheros
SRC_FILES	= main mlx_fonctions error map_verification read_map
	

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIBFT		=	src/libft
MINILIBX	= 	mlx

#Librerias 
LIBS		= $(MINILIBX)/libmlx.a $(MLX) $(LIBFT)/libft.a

#Directorios
SRC_DIR = src/
OBJ_DIR = objs/

# REGLAS # 
all:	minilibx libft $(NAME)

#Compilar 
$(NAME):$(OBJ)
		$(CC) $(OBJ) $(LIBS) -o $(NAME)
	

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)

	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(YELLOW)Compiled!$(NC)"
	
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