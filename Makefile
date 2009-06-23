CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -lcurl -lssl -lcrypto -lrt -lssl -lcrypto -ldl -lz -lz
OBJECTS = main.o check_auth.o update_status.o get_friends_timeline.o write_preferences.o get_credentials.o access_url.o

timeline:
	$(CC) $(CFLAGS) -o get_friends_timeline $(LDFLAGS) get_friends_timeline.c


ctweet : $(OBJECTS)
	$(CC) -o ctweet $(LDFLAGS) $(OBJECTS)

*.o *.c:
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f *.o ctweet
