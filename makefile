CC = g++
CFLAGS = -std=c++14 -c -Wall
SRCS = LAlib.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = LAlib.h
OUT = test.out

build: compile
	$(CC) $(OBJS) -o $(OUT)

compile: $(srcs)
	$(CC) $(CFLAGS) $(SRCS)

rebuild: clean compile build

clean:
	rm *.o
