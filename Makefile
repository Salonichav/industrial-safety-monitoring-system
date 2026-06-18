CC=gcc
CFLAGS=-Wall -pthread

SRC=main.c sensor.c control.c logger.c dashboard.c

all:
	$(CC) $(SRC) -o monitor $(CFLAGS)

clean:
	rm -f monitor
