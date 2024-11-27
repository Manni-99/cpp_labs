# Compiler and linker
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags
CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g
# Uncomment these lines if using clang++ and libc++
# CPPFLAGS += -stdlib=libc++
# CXXFLAGS += -stdlib=libc++
# LDFLAGS  += -stdlib=libc++

# Targets
PROGS = spell process_text test_edit_distance
LIBS = libdictionary.a

all: $(PROGS)

# Library target
libdictionary.a: dictionary.o word.o
	ar rcs $@ $^

# Spell program
spell: spell.o libdictionary.a spell_checker.o  # Add spell_checker.o here
	$(CXX) $(LDFLAGS) $^ -o $@

# Process Text program
process_text: process_text.o libdictionary.a spell_checker.o  # Add spell_checker.o here
	$(CXX) $(LDFLAGS) $^ -o $@

# Test target to run programs and unit tests
test: $(PROGS)
	./spell
	./process_text
	./test_edit_distance  # Run the test for edit_distance

# Test target for edit distance (separate target for running tests)
test_edit_distance: test_edit_distance.o spell_checker.o  # Use spell_checker.o for the test
	$(CXX) $(LDFLAGS) $^ -o $@

# Individual object file dependencies
dictionary.o: dictionary.cc dictionary.h word.h
word.o: word.cc word.h
spell.o: spell.cc dictionary.h word.h spell_checker.h
spell_checker.o: spell_checker.cpp spell_checker.h  # Add the object for spell_checker.cpp
process_text.o: process_text.cpp dictionary.h word.h
test_edit_distance.o: test_edit_distance.cc spell_checker.h  # Add test file dependency

# Phony targets
.PHONY: all clean distclean test

# Clean rules
clean:
	rm -f *.o $(PROGS) $(LIBS)

distclean: clean
	rm -f *.d

# Include dependency files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

