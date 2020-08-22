NAME = Pathfinder
LIBMX = libmx

SRCD = src
INCD = inc
OBJD = obj
INC = libmx.h

SRC = file1.c \
	file2.c \
	file3.c \



INCLUDE = -I $(INCD) \

INCS = $(addprefix $(INCD)/, $(INC))
SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
AR = ar rcs
CC = clang

all: $(NAME)

install: $(NAME) clean

$(LIBMX): $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@printf "\x1b[32;1m$@ created\x1b[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@printf "\x1b[32mcompiled[libmx]: \x1b[0m[$(<:$(SRCD)/%.c=%.c)]\n"

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@
	@printf "\x1b[34;1mdeleted libmx/$(NAME)\x1b[0m\n"

uninstall: clean
	@rm -rf $(NAME)
	@printf "\x1b[34;1mdeleted libmx/$(OBJD)\x1b[0m\n"

clean:
	@rm -rf $(OBJD)


reinstall: uninstall install
