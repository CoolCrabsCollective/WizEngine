cmake_minimum_required(VERSION 3.7)
project(WizEngine)

set(SFML_COMMIT 8f6903d00853fd3db395a557733ae65a14f37c01)
set(SFML_SWITCH_COMMIT master)
set(BOX2D_CMAKE_COMMIT master)
set(GTEST_COMMIT e2239ee6043f73722e7aa812a459f54a28552929) # Version 1.11.0

if(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)
    # Not for windows because windres.exe doesn't support those
    add_definitions(-frtti -Wall -ansi -Wno-deprecated -pthread -Wpedantic)
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
#if(CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake")
#    FetchContent_Declare(sfml
#            GIT_REPOSITORY https://github.com/WheezyWiseWizards/SFML-switch.git
#            GIT_TAG ${SFML_SWITCH_COMMIT})
#else()
#    FetchContent_Declare(sfml
#            GIT_REPOSITORY https://github.com/SFML/SFML.git
#            GIT_TAG ${SFML_COMMIT})
#endif()
#FetchContent_MakeAvailable(sfml)

set(SFML_INCLUDE_DIR /home/william/android-ndk-r19/sources/third_party/sfml/include)
set(SFML_LIBRARY_DIR /home/william/android-ndk-r19/sources/third_party/sfml/lib/)
set(SFML_EXT_LIBRARY_DIR /home/william/android-ndk-r19/sources/third_party/sfml/extlibs/lib/)

include_directories(${SFML_INCLUDE_DIR})
link_directories("${SFML_LIBRARY_DIR}${ANDROID_ABI}/")
link_directories("${SFML_EXT_LIBRARY_DIR}${ANDROID_ABI}/")

# this creates the variables SFML_SOURCE_DIR, SFML_BINARY_DIR and SFML_POPULATED
# then SFML_SOURCE_DIR is used below to include the header files
#FetchContent_GetProperties(SFML)

# Fetches Box2D dependency and loads its CMakeLists.txt
FetchContent_Declare(Box2D
        GIT_REPOSITORY https://github.com/WheezyWiseWizards/Box2D-cmake.git
        GIT_TAG ${BOX2D_CMAKE_COMMIT})
FetchContent_MakeAvailable(Box2D)
FetchContent_GetProperties(Box2D SOURCE_DIR Box2D_SOURCE_DIR)

# Other dependencies

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL)
find_package(Threads REQUIRED)

# include and source files
include_directories(include ${SFML_SOURCE_DIR}/include ${Box2D_SOURCE_DIR}/Box2D/Box2D)

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

if(NOT CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake" AND NOT ANDROID)
    FetchContent_Declare(googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG ${GTEST_COMMIT})

    set(GTEST_FORCE_SHARED_CRT ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)
    add_executable(${PROJECT_NAME}_tests ${TEST_SRC_FILES})

    target_link_libraries(${PROJECT_NAME}_tests
            gtest_main
            ${PROJECT_NAME}
            WIZ::Box2D)

    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME}_tests)

endif()
