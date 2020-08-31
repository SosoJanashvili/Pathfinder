NAME	=	pathfinder

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic)

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc

INC		=	pathfinder.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC	= 		main.c\
        	mx_alloc_clean_up.c\
        	mx_alloc_dist.c\
        	mx_alloc_graph.c\
        	mx_alloc_route.c\
        	mx_alloc_str_array.c\
        	mx_bt_back_path.c\
        	mx_bt_find_all_paths.c\
        	mx_bt_trip_output.c\
        	mx_error_duplicate.c\
        	mx_error_file_exists.c\
        	mx_error_file_is_empty.c\
        	mx_error_inv_num_islands.c\
        	mx_error_inv_num_islands2.c\
        	mx_error_line_not_valid.c\
        	mx_error_sum_of_bridges.c\
        	mx_error_usage.c\
        	mx_floyd_warshall.c\
        	mx_parse_first_line.c\
        	mx_parse_vertices.c\
        	mx_print_output.c


SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)


$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)
clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install