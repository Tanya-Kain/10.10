CC = g++
TARGET = real
OBJS = main.o Real.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lm
main.o: main.cpp Real.h
	$(CC) -c main.cpp
Real.o: Real.cpp Real.h
	$(CC) -c Real.cpp

clean:
	rm -f $(OBJS) $(TARGET)
