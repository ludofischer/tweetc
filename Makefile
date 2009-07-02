CC = gcc
CFLAGS = -O2 -Wall -Wextra -std=c99 -pedantic -I /usr/include/libxml2
LDFLAGS = -lcurl -lssl -lcrypto -lrt -ldl -lz -lxml2 -lm
OBJECTS = main.o twitter-actions.o access-url.o url-encode.o authorization-password.o xml.o

ctweet : $(OBJECTS)
	$(CC) -o ctweet $(LDFLAGS) $(OBJECTS)

*.o *.c:
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f *.o ctweet
