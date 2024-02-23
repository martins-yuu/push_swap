# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 10:09:46 by yuuko             #+#    #+#              #
#    Updated: 2024/03/26 22:27:16 by yuuko            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

# **************************************************************************** #
#    Misc                                                                      #
# **************************************************************************** #
RED			:=	$(shell tput setaf 1)
GREEN		:=	$(shell tput setaf 2)
YELLOW		:=	$(shell tput setaf 3)
BLUE		:=	$(shell tput setaf 4)
MAGENTA		:=	$(shell tput setaf 5)
RESET		:=	$(shell tput sgr0)
TITLE		:=	$(YELLOW)$(basename $(NAME))$(RESET)

# 1: action, 2: target, 3: color
define message
	$(info [$(TITLE)] $(3)$(1)$(RESET) $(2))
endef

RM			:=	rm -f
MAKEFLAGS	+=	--silent --no-print-directory

# **************************************************************************** #
#    Dependencies                                                              #
# **************************************************************************** #
LIBS		:=	\
	lib/libft/libft.a \

INCS		:=	\
	include \
	lib/libft/include \

# **************************************************************************** #
#    Sources                                                                   #
# **************************************************************************** #
SRC_DIR		:=	src

SRCS		:=	\
	main.c \
	parse.c \
	stack/stack.c \
	stack/operations.c \
	stack/sort.c \
	stack/push_swap/solve.c \
	stack/push_swap/sort5.c \
	stack/push_swap/moves.c \
	stack/push_swap/utils.c \

SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))

# **************************************************************************** #
#    Build                                                                     #
# **************************************************************************** #
BUILD_DIR	:=	build

OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(OBJS:.o=.d)

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:=	$(addprefix -L,$(dir $(LIBS)))
LDLIBS		:=	-lft

ifdef WITH_DEBUG
	TITLE += $(MAGENTA)debug$(RESET)
	CFLAGS += -g
endif

ifdef WITH_SANITIZER
	TITLE += $(MAGENTA)sanitizer$(RESET)
	CFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(call message,CREATED,$(NAME),$(BLUE))

$(LIBS):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(call message,CREATED,$(basename $(notdir $@)),$(GREEN))

clean:
	for lib in $(dir $(LIBS)); do $(MAKE) -C $$lib clean; done
	$(RM) -r $(BUILD_DIR)
	$(call message,DELETED,$(BUILD_DIR),$(RED))

fclean: clean
	for lib in $(dir $(LIBS)); do $(MAKE) -C $$lib fclean; done
	$(RM) $(NAME)
	$(call message,DELETED,$(NAME),$(RED))

re:
	$(MAKE) fclean
	$(MAKE) all

run: re
	./$(NAME)

update:
	git stash
	git pull
	git submodule update --init
	git stash pop

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v 'info'

print-%:
	$(info '$*'='$($*)')

.PHONY: all clean fclean re run update
.SILENT:
.IGNORE: clean fclean run

-include $(DEPS)
