CC := g++
CFLAGS := -Wall -Wextra -std=c++17

SRCS := ../src/main.cpp ../include/lexer/lexer.hpp ../src/lexer/adders.cpp ../include/logger/logger.hpp

OBJS := $(SRCS:.cpp=.o)

TARGET := BIN_SHELL 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -g -o $@ $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

