CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -lcurl -lssl -lcrypto -lrt -lssl -lcrypto -ldl -lz -lz

timeline:
	$(CC) -o get_friends_timeline $(LDFLAGS) get_friends_timeline.c

*:
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f *.o get_friends_timeline main
