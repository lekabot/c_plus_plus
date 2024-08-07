CC = gcc
CXX = g++
CFLAGS = -Werror -Wall -Wextra
CXXFLAGS = -Werror -Wall -Wextra -std=c++17
LDFLAGS =
LIBRARIES = -lncurses
GCOV_FLAGS      := -fprofile-arcs -ftest-coverage
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log
CXXCOV 			:=  --coverage

DIST_DIR :=archive

DEBUGGER := brick_game/tetris/debugger/debugger.c
BACKEND := brick_game/tetris/backend/backend.c
COMMON :=   brick_game/common/block/block.c \
			brick_game/common/cell/cell.c \
			brick_game/common/collisions_checker/collisions_checker.c \
			brick_game/common/game_status/game_status.c \
			brick_game/common/board/board.c \
			brick_game/common/player/player.c \
			brick_game/common/records/records.c \
			brick_game/common/player/player_board/player_board.c \
 			brick_game/common/time_handler/time_handler.c
TETRIS :=brick_game/common/common/color_handler.c \
			brick_game/tetris/fsm/fsm_matrix.c

BACKEND_CXX:=brick_game/snake/controller/controller.cc \
			brick_game/snake/Model/model.cc \
			brick_game/snake/Action/action.cc \
			brick_game/snake/move_snake/move_snake.cc

FRONTEND:=gui/cli/frontend.c

SOURCES_FOR_TESTS := ${BACKEND} \
					${BACKEND_CXX} \
					${COMMON} \
                        tests/model_tests.cc \
					 	tests/tests.cc

APP_DESTINATION:=../build/
ifeq ($(OS_NAME), GNU/Linux)
    OPEN_COMMAND := xdg-open
	APP_DESTINATION:=../build
endif

OPEN_COMMAND =open
ifeq ($(OS), Linux)
	OPEN_COMMAND=xdg-open
else
	OPEN_COMMAND=open
endif

all: install run_cli

install: uninstall install_cli install_desktop

uninstall:
	@rm -f brickgame_cli.out
	@rm -rf ${DESKTOP_BUILD}
	@echo "Uninstallation is finished"

install_cli: ${BACKEND} ${BACKEND_CXX} ${COMMON} ${TETRIS} ${FRONTEND}
	$(CXX) $^ $(LIBRARIES) -o brickgame_cli.out

DESKTOP_SOURCES := gui/desktop/View
DESKTOP_BUILD := ../build

install_desktop:
	cmake -DCMAKE_BUILD_TYPE=Release -S ${DESKTOP_SOURCES} -B ${DESKTOP_BUILD}
	cmake --build ${DESKTOP_BUILD} --target brickgame_desktop -j 4

run_cli:
	@./brickgame_cli.out

run_desktop:
	@${APP_DESTINATION}/brickgame_desktop

dvi:
	@doxygen ./doxy/Doxyfile
	@${OPEN_COMMAND} ./docs/html/index.html

dist: clean_dist
	@cd ../ && mkdir -p ${DIST_DIR}
	@cd ../ && cp -rf src/brick_game ${DIST_DIR}/brick_game
	@cd ../ && cp -rf src/gui ${DIST_DIR}/gui
	@cd ../ && cp -rf src/Makefile ${DIST_DIR}/
	@cd ../ && tar -czvf archive.tar.gz ${DIST_DIR}
	@cd ../ && rm -rf ${DIST_DIR}
dist_unpack:
	@cd ../ && tar -xzvf archive.tar.gz

test: clean
	@${CXX} ${CXXFLAGS} ${CXXCOV} ${SOURCES_FOR_TESTS} -lgtest -lm  -o test.out
	@./test.out

test_valgrind:
	@${CXX} ${CXXFLAGS} ${CXXCOV} $(SOURCES_FOR_TESTS) -lgtest -lstdc++ -lm  -o test.out
	@valgrind ${VALGRIND_FLAGS} ./test.out

gcov_report: test
ifeq ($(OS), Linux)
	@${CXX} ${CXXFLAGS} ${CXXCOV} $(SOURCES_FOR_TESTS) -lgtest -lstdc++ -lm  -o gcov_report.out
else
	@${CXX} ${CXXFLAGS} ${CXXCOV} $(SOURCES_FOR_TESTS) -lgtest -lstdc++ -lm  -o gcov_report.out
endif
	./gcov_report.out
	lcov -t "gcov_report" --ignore-errors mismatch --no-external -c -d . -o report.info
	genhtml report.info -o report
	-@$(OPEN_COMMAND) ./report/index.html
	@make clean_gcov
	@make clean_lcov


style_check:
	@find .. -type f -name "*.cc" -exec clang-format --style=Google -n {} \;
	@find .. -type f -name "*.c" -exec clang-format --style=Google -n {} \;
	@find .. -type f -name "*.h" -exec clang-format --style=Google -n {} \;
	@find .. -type f -name "*.ccp" -exec clang-format --style=Google -n {} \;

	@find ./gui/desktop/View -type f -name "*.h" -exec clang-format --style=Google -n {} \;
	@find ./gui/desktop/View -type f -name "*.h" -exec clang-format --style=Google -n {} \;

	@find ./gui/cli -type f -name "*.h" -exec clang-format --style=Google -n {} \;
	@find ./gui/cli -type f -name "*.cpp" -exec clang-format --style=Google -n {} \;

style:
	@find .. -type f -name "*.cc" -exec clang-format --style=Google -i {} \;
	@find .. -type f -name "*.c" -exec clang-format --style=Google -i {} \;
	@find .. -type f -name "*.h" -exec clang-format --style=Google -i {} \;
	@find .. -type f -name "*.ccp" -exec clang-format --style=Google -i {} \;

	@find ./gui/desktop/View -type f -name "*.h" -exec clang-format --style=Google -i {} \;
	@find ./gui/desktop/View -type f -name "*.cpp" -exec clang-format --style=Google -i {} \;

	@find ./gui/cli -type f -name "*.h" -exec clang-format --style=Google -i {} \;
	@find ./gui/cli -type f -name "*.cpp" -exec clang-format --style=Google -i {} \;

clean: clean_project clean_static_lib clean_log clean_exec clean_obj clean_gcov clean_lcov clean_lcov_report clean_dist clean_docs clean_build

clean_project:
	@rm -rf *.records_

clean_build:
	@rm -rf ../build/
	@rm -rf ./cmake-build-debug/

clean_dist:
	@cd ../ && rm -rf archive
	@cd ../ && rm -rf archive.tar.gz
clean_after_building:
	@rm -rf ${OBJ_DIR}
clean_static_lib:
	@find .. -type f -name "*.a" -exec rm {} \;
clean_log:
	@find .. -type f -name "*.log" -exec rm {} \;
clean_exec:
	@find .. -type f -name "*.out" -exec rm {} \;
clean_obj:
	@find .. -type f -name "*.o" -exec rm {} \;
clean_gcov:
	@find .. -type f -name "*.gcda" -exec rm {} \;
	@find .. -type f -name "*.gcno" -exec rm {} \;
clean_lcov:
	@find .. -type f -name "*.info" -exec rm {} \;
clean_lcov_report:
	@rm -rf report
clean_docs:
	@rm -rf docs
