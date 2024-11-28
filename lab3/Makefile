# Compiler and flags
CXX = g++ 
CXXFLAGS = -O0 -Wall #-fsanitize=address  # Disable optimization and enable all warnings
#LDFLAGS = -fsanitize=address
# Target executable
TARGET = tester

# Source files
SRC = User.cc UserTable.cc tester.cc

# Header files (just for reference, no need to list them for compilation)
HEADERS = User.h UserTable.h

# Object files (generated from source files)
OBJ = $(SRC:.cc=.o)

# Default target to build the program
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rule to build object files from source files
%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -f $(TARGET) $(OBJ)

# Optional: to run the program with users.txt as input
run: $(TARGET)
	./$(TARGET) users.txt
