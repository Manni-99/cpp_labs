# Compiler and flags
CXX = g++
CXXFLAGS = -O0 -Wall  # Disable optimization and enable all warnings

# Targets for different executables
TARGETS = tester tagremover primes

# Source files for each target
TESTER_SRC = date.cc date_test.cc
TAGREMOVER_SRC = TagRemover.cc
PRIMES_SRC = PrimeNumber.cc 

# Header files (just for reference)
HEADERS = date.h TagRemover.h PrimeNumbers.h

# Object files for each target
TESTER_OBJ = $(TESTER_SRC:.cc=.o)
TAGREMOVER_OBJ = $(TAGREMOVER_SRC:.cc=.o)
PRIMES_OBJ = $(PRIMES_SRC:.cc=.o)

# Default target builds all executables
all: $(TARGETS)

# Rule to build the tester executable
tester: $(TESTER_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(TESTER_OBJ)

# Rule to build the tagremover executable
tagremover: $(TAGREMOVER_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(TAGREMOVER_OBJ)

# Rule to build the primes executable
primes: $(PRIMES_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(PRIMES_OBJ)

# Rule to build object files from source files
%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -f $(TARGETS) $(TESTER_OBJ) $(TAGREMOVER_OBJ) $(PRIMES_OBJ)
