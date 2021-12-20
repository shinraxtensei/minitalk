SERVER = server

CLIENT = client

PRINTF = ./ft_printf/ft_printf.a

HEADER = minitalk.h


CFLAGS = -Wall -Wextra -Werror

all: $(PRINTF) $(CLIENT) $(SERVER) $(HEADER)

$(SERVER): server.c $(HEADER)
	@gcc server.c utils.c $(PRINTF) -o $@
	@echo $@ ----------------- ready -----------------

$(CLIENT): client.c $(HEADER)
	@gcc $(CFLAGS) client.c utils.c $(PRINTF) -o $@
	@echo $@ ----------------- ready -----------------



$(PRINTF):
	@make -C./ft_printf

clean:
	@make clean -C ./ft_printf

fclean: clean
	rm -rf $(SERVER) $(CLIENT) Minitalk.a
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all re clean fclean