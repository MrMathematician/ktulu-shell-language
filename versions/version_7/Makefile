CC := g++
CFLAGS := -Wall -Wextra -std=c++17

SRCS := main.cpp lexer.hpp adders.cpp 

OBJS := $(SRCS:.cpp=.o)

TARGET := BIN_SHELL 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -g -o $@ $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

