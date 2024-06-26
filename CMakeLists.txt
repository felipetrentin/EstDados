cmake_minimum_required(VERSION 3.5)
project(estruturaDeDados)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

if ( MSVC )
    set(LIBRARY_OUTPUT_DIRECTORY_DEBUG ${RUNTIME_OUTPUT_DIRECTORY} )
    set(LIBRARY_OUTPUT_DIRECTORY_RELEASE ${RUNTIME_OUTPUT_DIRECTORY} )
    # etc for the other available configuration types (MinSizeRel, RelWithDebInfo)
endif ( MSVC )

#install SFML DearImgui and SFML-Imgui
add_subdirectory(dependencies)


file(GLOB SOURCES "src/*.cpp")
add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE ImGui-SFML::ImGui-SFML )

target_compile_features(main PRIVATE cxx_std_17)

add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/content/
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/content/)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()