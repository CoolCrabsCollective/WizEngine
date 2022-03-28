cmake_minimum_required(VERSION 3.7)
project(WizEngine)

set(SFML_COMMIT 8f6903d00853fd3db395a557733ae65a14f37c01)
set(SFML_SWITCH_COMMIT master)

if(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)
    # Not for windows because windres.exe doesn't support those
    add_definitions(-Wall -ansi -Wno-deprecated -pthread -Wpedantic)
endif()

# applies OS type C++ macro
if(WIN32)
    add_compile_definitions(OS_WINDOWS)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_compile_definitions(OS_MAC)
elseif(UNIX)
    add_compile_definitions(OS_UNIX)
elseif(CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake")
    add_compile_definitions(OS_SWITCH)
    set(CMAKE_USER_MAKE_RULES_OVERRIDE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerOptionsOverride.cmake")
endif()

#
# Set C++ version
#
set(CMAKE_CXX_STANDARD 20)


#
# The following if-else chain makes the different platform output at different
# paths:
#
# bin/
#   windows64/
#   windows32/
#   mac/
#   linux64/
#   linux32/
#
if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/windows64/)
    else()
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/windows32/)
    endif()
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/mac/)
elseif(UNIX)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/linux64/)
    else()
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/linux32/)
    endif()
elseif(CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/switch/)
endif()


# Fetches SFML dependency and loads its CMakeLists.txt
include(FetchContent)
if(CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake")
    FetchContent_Declare(
            sfml
            URL https://github.com/WheezyWiseWizards/SFML-switch/archive/${SFML_SWITCH_COMMIT}.zip
    )
else()
    FetchContent_Declare(
            sfml
            URL https://github.com/SFML/SFML/archive/${SFML_COMMIT}.zip
    )
endif()
FetchContent_MakeAvailable(sfml)

# this creates the variables SFML_SOURCE_DIR, SFML_BINARY_DIR and SFML_POPULATED
# then SFML_SOURCE_DIR is used below to include the header files
FetchContent_GetProperties(SFML)

# Other dependencies

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL)
find_package(Threads REQUIRED)

# include and source files
include_directories(include ${SFML_SOURCE_DIR}/include)

if(CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake")
    include_directories(${LIBNX_INCLUDE_DIR})
endif()

file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.inl
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/include/*.hpp
        ${PROJECT_SOURCE_DIR}/src/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*.inl
        ${PROJECT_SOURCE_DIR}/include/*/*.h
        ${PROJECT_SOURCE_DIR}/include/*/*.hpp
        ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*/*.inl
        ${PROJECT_SOURCE_DIR}/include/*/*/*.h
        ${PROJECT_SOURCE_DIR}/include/*/*/*.hpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})



FetchContent_Declare(googletest
        # Version 1.11.0
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip)

set(GTEST_FORCE_SHARED_CRT ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)
add_executable(${PROJECT_NAME}_tests ${TEST_SRC_FILES})

target_link_libraries(${PROJECT_NAME}_tests gtest_main ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)