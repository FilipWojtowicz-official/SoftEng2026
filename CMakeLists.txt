cmake_minimum_required(VERSION 3.10)
project(ShapeLib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MDd")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MDd")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

# Szukaj plików .cpp i .h w katalogu src
file(GLOB SOURCES CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

file(GLOB HEADERS CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/src/*.h"
)


add_library(ShapeLib STATIC ${SOURCES} ${HEADERS})

#target_link_libraries(ShapeLib PUBLIC Lib::Lib)

target_compile_definitions(ShapeLib PRIVATE BUILDING_CLIENT_DLL)


enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(externals/googletest)

add_executable(test_shape1 src/tests/smoke/test_shape1.cpp)
target_link_libraries(test_shape1 gtest gtest_main ShapeLib)
target_include_directories(test_shape1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

#add_executable(test_shape2 src/tests/smoke/test_shape2.cpp)
#target_link_libraries(test_shape2 gtest gtest_main ShapeLib)
#target_include_directories(test_shape2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_test(NAME test_shape1 COMMAND test_shape1)
#add_test(NAME test_shape2 COMMAND test_shape2)