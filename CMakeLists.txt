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

# Biblioteka
add_library(ShapeLib STATIC ${SOURCES} ${HEADERS})
target_compile_definitions(ShapeLib PRIVATE BUILDING_CLIENT_DLL)

# TESTY
enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(externals/googletest)


# ===== TEST 1 =====
add_executable(test_shape1 src/tests/smoke/test_shape1.cpp)
target_link_libraries(test_shape1 gtest gtest_main ShapeLib)
target_include_directories(test_shape1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_shape1 COMMAND test_shape1)

add_executable(test_cylinder src/tests/test_cylinder.cpp)
target_link_libraries(test_cylinder gtest gtest_main ShapeLib)
target_include_directories(test_cylinder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_cylinder COMMAND test_cylinder)

#add_executable(test_shape2 src/tests/smoke/test_shape2.cpp)
#target_link_libraries(test_shape2 gtest gtest_main ShapeLib)
#target_include_directories(test_shape2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})


add_executable(test_torus src/tests/smoke/test_torus.cpp)
target_link_libraries(test_torus gtest gtest_main ShapeLib)
target_include_directories(test_torus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_torus COMMAND test_torus)

add_executable(test_rectangle src/tests/smoke/test_rectangle.cpp)
target_link_libraries(test_rectangle gtest gtest_main ShapeLib)
target_include_directories(test_rectangle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_rectangle COMMAND test_rectangle)


add_executable(test_trapeze src/tests/smoke/test_trapeze.cpp)
target_link_libraries(test_trapeze gtest gtest_main ShapeLib)
target_include_directories(test_trapeze PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_trapeze COMMAND test_trapeze)


add_executable(test_pyramid src/tests/smoke/test_pyramid.cpp)
target_link_libraries(test_pyramid gtest gtest_main ShapeLib)
target_include_directories(test_pyramid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_pyramid COMMAND test_pyramid)


add_executable(test_rhombus src/tests/smoke/test_rhombus.cpp)
target_link_libraries(test_rhombus gtest gtest_main ShapeLib)
target_include_directories(test_rhombus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_rhombus COMMAND test_rhombus)


add_executable(test_circle src/tests/smoke/test_circle.cpp)
target_link_libraries(test_circle gtest gtest_main ShapeLib)
target_include_directories(test_circle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_circle COMMAND test_circle)


# --- Testy jednostkowe (Unit Tests) ---
add_executable(test_unit_ellipsoid src/tests/unit/test_ellipsoid.cpp)
target_link_libraries(test_unit_ellipsoid gtest gtest_main ShapeLib)
target_include_directories(test_unit_ellipsoid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})

add_test(NAME test_unit_ellipsoid COMMAND test_unit_ellipsoid)


# ===== TEST 2 (TRIANGLE) =====
add_executable(test_triangle src/tests/smoke/test_triangle.cpp)
target_link_libraries(test_triangle gtest gtest_main ShapeLib)
target_include_directories(test_triangle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_triangle COMMAND test_triangle)


#  Testy dla Elipsy 
add_executable(test_ellipse src/tests/smoke/ellipse_test.cpp)
target_link_libraries(test_ellipse gtest gtest_main ShapeLib)
target_include_directories(test_ellipse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_ellipse COMMAND test_ellipse)


# TESTS for SPHERE
add_executable(test_sphere src/tests/smoke/test_sphere.cpp)
target_link_libraries(test_sphere gtest gtest_main ShapeLib)
target_include_directories(test_sphere PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_sphere COMMAND test_sphere)


add_executable(test_hexagon src/tests/smoke/test_hexagon.cpp)
target_link_libraries(test_hexagon gtest gtest_main ShapeLib)
target_include_directories(test_hexagon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_hexagon COMMAND test_hexagon)
