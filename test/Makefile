CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC_TEST = test.c
SRC_BENCH = benchmark.c
TARGET_TEST = test
TARGET_BENCH = benchmark

all: $(TARGET_TEST) $(TARGET_BENCH)

$(TARGET_TEST): $(SRC_TEST) ../libs/mt/src/mt.c
	$(CC) $(CFLAGS) -o $@ $^ -I../include -I../libs/mt/include -L../build -lvml

$(TARGET_BENCH): $(SRC_BENCH)
	$(CC) $(CFLAGS) -o $@ $^ -I../include -L../build -lvml

clean:
	rm -f $(TARGET_TEST) $(TARGET_BENCH)

.PHONY: all clean