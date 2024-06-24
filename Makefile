//Wasimshebalny@gmail.com
CXX = g++
CXXFLAGS = -g -Wno-builtin-declaration-mismatch

.PHONY: all clean catan test run_demo run_test tidy

# Source files
SOURCES = Board.cpp Catan.cpp Hexas.cpp Player.cpp Tools.cpp Cards.cpp DevelopmentCard.cpp Nodes.cpp Paths.cpp
TEST_SOURCES = Test.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Default target
all: demo test

# Build demo executable
demo: $(OBJECTS) demo.o
	$(CXX) $(CXXFLAGS) $^ -o demo

# Build test executable
test: $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

# Run the demo executable
run_demo: demo
	./demo

# Run the test executable
run_test: test
	./test

# catan target to run the demo
catan: run_demo

# Clang-tidy target for static analysis
tidy:
	clang-tidy $(SOURCES) $(TEST_SOURCES) -checks=bugprone-*,g++-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f *.o demo test
