CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = apc

all:
	$(CC) $(CFLAGS) main.c DLL.c Operations.c -o $(TARGET)

clean_o:
	rm -f *.o

clean_exe:
	rm -f $(TARGET)