CC = /usr/local/Cellar/llvm/13.0.0_1/bin/clang++
CFLAGS = -O3

all: %.exe
	./$<
%.exe: %.cpp
	$(CC) $< -o $@
clean:
	rm *.exe
