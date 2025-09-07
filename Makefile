CC=clang
ASM=nasm
OBJS=./build/vml.s.o
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	LIB := libvml.dylib
    CFLAGS := -dynamiclib -Wl,-install_name,@loader_path/../build/$(LIB)
	AFLAGS := -fmacho64
else ifeq ($(OS), Linux)
	LIB := libvml.so        
    CFLAGS += -shared
	AFLAGS := -felf64
endif

all: ./build/$(LIB)

./build/$(LIB): ./build/vml.s.o
	$(CC) ./build/vml.s.o $(CFLAGS) -o ./build/$(LIB)

./build/vml.s.o: ./src/vml.s
	$(ASM) $(AFLAGS) ./src/vml.s -o ./build/vml.s.o

clean:
	rm -rf ./build/$(LIB) $(OBJS)
