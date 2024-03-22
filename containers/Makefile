TARGET = s21_containers.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c++20 -lstdc++
TEST_FLAGS = -lgtest -pthread
TEST_TARGET = all_tests

all: test

clean:
	@rm -rf *.o *.a *.out *.log all_tests.dSYM $(TEST_TARGET)

test: clean
	@$(CC) $(CFLAGS) -g tests/*.cpp $(TEST_FLAGS) -o $(TEST_TARGET)
	./$(TEST_TARGET)

leaks: clean
	@$(CC) $(CFLAGS) tests/*.cpp $(TEST_FLAGS) -o $(TEST_TARGET)
	leaks --atExit -- ./$(TEST_TARGET)

check_style:
	@find . \( -name '*.h' -o -name '*.tpp' -o -name '*.cpp' \) -print0 | xargs -0 clang-format -n -style=Google

format_style:
	@find . \( -name '*.h' -o -name '*.tpp' -o -name '*.cpp' \) -print0 | xargs -0 clang-format -i -style=Google
