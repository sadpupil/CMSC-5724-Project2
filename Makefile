CC = g++
CFLAGS = -O3 -Wall -Wextra -std=c++17
INCLUDES = -Iinclude

SRCS = src/data_reader.cpp src/incremental_algorithm.cpp src/perceptron.cpp src/result_verify.cpp src/vector_op.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = myTest

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
