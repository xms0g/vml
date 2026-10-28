CC=clang
ASM=nasm
OBJS=./build/vml.asm.o
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

./build/$(LIB): ./build/vml.asm.o
	$(CC) ./build/vml.asm.o $(CFLAGS) -o ./build/$(LIB)

./build/vml.asm.o: ./src/vml.asm
	$(ASM) $(AFLAGS) ./src/vml.asm -o ./build/vml.asm.o

clean:
	rm -rf ./build/$(LIB) $(OBJS)
