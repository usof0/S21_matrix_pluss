CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

# OS detection
UNAME_S := $(shell uname -s)

GTEST_LIBS = -lgtest -lgtest_main -lpthread
GTEST_INCLUDE = 

ifeq ($(UNAME_S), Darwin)  # macOS
    GTEST_LIBS = -L/usr/local/lib -lgtest -lgtest_main -lpthread
    GTEST_INCLUDE = -I/usr/local/include
endif

ifeq ($(UNAME_S), Linux)   # Linux
    GTEST_LIBS = -lgtest -lgtest_main -lpthread
    GTEST_INCLUDE = 
endif

# Directories
SRC_DIR = .
OBJ_DIR = .
UNIT_TEST_DIR = unit_test

# Files
TARGET_LIB = s21_matrix_oop.a
TEST_EXEC = test_suite

# Source files
SRC_FILES = $(SRC_DIR)/s21_matrix_oop.cpp
UNIT_TESTS = $(wildcard $(UNIT_TEST_DIR)/*.cpp)
OBJECTS = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

.PHONY: all clean test

all: $(TARGET_LIB) test

$(TARGET_LIB): $(OBJECTS)
	ar rcs $@ $^
	rm -rf *.o

# Create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) -c $< -o $@

test: $(TARGET_LIB)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) $(UNIT_TESTS) $(TARGET_LIB) $(GTEST_LIBS) -o $(TEST_EXEC)
	@./$(TEST_EXEC)

clean:
	rm -rf *.o *.a test_suite

rebuild: clean all
