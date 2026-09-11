CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -O2

TARGET=optical_monitor
SRC=main.c optical_monitor.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
