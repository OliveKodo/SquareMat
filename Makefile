# Makefile for SquareMat project
# your_email@example.com

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
LDFLAGS =

# Source files
MAIN_SRC = Main.cpp SquareMat.cpp SquareMat_operators.cpp
TEST_SRC = Test.cpp SquareMat.cpp SquareMat_operators.cpp

# Executables
MAIN_EXE = MainApp
TEST_EXE = TestApp

# Default target
all: $(MAIN_EXE)

# Main executable
$(MAIN_EXE): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(MAIN_SRC)

# Test executable
$(TEST_EXE): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(TEST_SRC)

# Run the main program
Main: $(MAIN_EXE)
	./$(MAIN_EXE)

# Run tests with doctest
test: $(TEST_EXE)
	./$(TEST_EXE)

# Run valgrind memory check
valgrind: $(MAIN_EXE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_EXE)

# Run valgrind on tests
valgrind-test: $(TEST_EXE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_EXE)

# Clean up
clean:
	rm -f $(MAIN_EXE) $(TEST_EXE)

.PHONY: all Main test valgrind valgrind-test clean