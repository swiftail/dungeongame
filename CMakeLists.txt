cmake_minimum_required(VERSION 3.24)
project(game LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/artifacts/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/artifacts/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/artifacts/)

if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
endif ()

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE game_SRC CONFIGURE_DEPENDS "game/src/*.h" "game/src/*.cpp")

add_executable(game ${game_SRC})
target_link_libraries(game PRIVATE sfml-graphics)
target_link_libraries(game PRIVATE sfml-audio)
target_compile_features(game PRIVATE cxx_std_20)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (WIN32)
    add_custom_command(
            TARGET game
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<BOOL:${ARCH_64BITS}>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:game>
            VERBATIM)
endif ()


file(
        COPY ${CMAKE_CURRENT_SOURCE_DIR}/game/res
        DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)

install(TARGETS game)