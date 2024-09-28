# Variables
CC = g++                                # Compiler
CFLAGS = -c -Wall -Wextra               # Compilation flags (compile, show all warnings)
TARGET = vector_demo                    # Target executable name

# Default target (builds the target executable)
all: $(TARGET)

# Target: build the executable from object files
$(TARGET): main.o Vector.o
	$(CC) main.o Vector.o -o $(TARGET)

# Target: build the Vector object file from source
Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) Vector.cpp

# Target: build the main object file from source
main.o: main.cpp Vector.h
	$(CC) $(CFLAGS) main.cpp

# Clean up object files and executable
clean:
	rm -f *.o $(TARGET)

# End of Makefile
