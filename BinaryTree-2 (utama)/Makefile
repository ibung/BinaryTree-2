CC = gcc
CFLAGS = -Wall -Wextra
TARGET = tes
SOURCES = main.c ibnu.c fairuz.c siti.c
HEADERS = include/ibnu.h include/fairuz.h include/siti.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)