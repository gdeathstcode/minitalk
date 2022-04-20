SERVER   = server
CLIENT   = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJ_SERVER = $(SRCS_SERVER:.c=.o)
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)

HDRS_SERVER = server.h
HDRS_CLIENT = client.h

INCLUDES = .

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra

LIBS	 = -L./libft -lft
LIBFT	 = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C libft

$(SERVER): $(OBJ_SERVER) $(HDRS_SERVER)
	$(CC) $(OBJ_SERVER) $(LIBS) -o $@

$(CLIENT): $(OBJ_CLIENT) $(HDRS_CLIENT)
	$(CC) $(OBJ_CLIENT) $(LIBS) -o $@

%$(SRCS_CLIENT).o: %$(SRCS_CLIENT).c $(HDRS_CLIENT)
	$(CC) $(FLAGS) -c $< -o $@

%$(SRCS_SERVER).o: %$(SRCS_SERVER).c $(HDRS_SERVER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(SERVER) $(CLIENT)

re: fclean all