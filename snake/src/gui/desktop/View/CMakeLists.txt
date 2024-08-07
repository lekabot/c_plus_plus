cmake_minimum_required(VERSION 3.5)

project(brickgame_desktop VERSION 0.1)

enable_language(C)
enable_language(CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        ../../../brick_game/common/block/block.c
        ../../../brick_game/common/board/board.c
        ../../../brick_game/common/cell/cell.c
        ../../../brick_game/common/collisions_checker/collisions_checker.c
        ../../../brick_game/common/game_status/game_status.c
        ../../../brick_game/common/parameters/parameters.h
        ../../../brick_game/common/player/player.c
        ../../../brick_game/common/player/player_board/player_board.c
        ../../../brick_game/common/records/records.c
        ../../../brick_game/common/time_handler/time_handler.c
        ../../../brick_game/tetris/fsm/fsm_matrix.c
        ../../../brick_game/tetris/backend/backend.c
        ../../../brick_game/tetris/fsm/fsm.h

        main.cpp
        View.cpp
        View.h
        View.ui
        GridWidget.cpp
        GridWidget.h
        ViewTabSwitcher.cpp
        ViewTabSwitcher.h
        styleHandler.h
        styleHandler.cpp
        NextPlayerGridWidget.h
        NextPlayerGridWidget.cpp
        constants.h

        ../../../brick_game/snake/controller/controller.cc
        ../../../brick_game/snake/Model/model.cc
        ../../../brick_game/snake/Action/action.cc
        ../../../brick_game/snake/move_snake/move_snake.cc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(brickgame_desktop
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET brickgame_desktop APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(brickgame_desktop SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(brickgame_desktop
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(brickgame_desktop PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.View)
endif()
set_target_properties(brickgame_desktop PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS brickgame_desktop
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(brickgame_desktop)
endif()
