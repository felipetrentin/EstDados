cmake_minimum_required(VERSION 3.5)
project(estruturaDeDados)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

#install SFML DearImgui and SFML-Imgui
add_subdirectory(dependencies)


file(GLOB SOURCES "src/*.cpp")
add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE ImGui-SFML::ImGui-SFML )

target_compile_features(main PRIVATE cxx_std_17)
