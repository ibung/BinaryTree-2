CC = gcc
CFLAGS = -Wall -Wextra
TARGET = tes
SOURCES = main.c ibnu.c
HEADERS = ibnu.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)