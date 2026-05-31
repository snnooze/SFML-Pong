cmake_minimum_required(VERSION 3.28)
project(SFML_Pong LANGUAGES CXX)

add_link_options(-static-libstdc++ -static-libgcc)

#Static link to libwinpthread-1.dll
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}
-Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

#Static link to SFML
set(SFML_STATIC_LIBRARIES TRUE)

#Output directory of the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Get the SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0 #Version of the SFML
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

#List files of the game

add_executable(SFML_Pong main.cpp Engine.cpp Button.cpp MainMenuScreen.cpp PauseScreen.cpp States.cpp)
target_compile_features(SFML_Pong PRIVATE cxx_std_17)

target_link_libraries(SFML_Pong PRIVATE SFML::Graphics SFML::Audio)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SFML_Pong) #for Visual studio projects