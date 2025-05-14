CC = gcc
CFLAGS = -Wall -Wextra
TARGET = tes
SOURCES = main.c tree.c
HEADERS = tree.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)